# Copyright (c) 2023, Tobias Helfenstein and contributors
# For license information, please see license.txt

import frappe
from frappe import _
from frappe.model.document import Document
import re
import pyproj
import json

class RestTree(Document):

    # autoname document
    def autoname(self):
        # define document name
        self.tree_name = _("Rest Tree {0}").format(self.tree_number)

    # this method will run every time a document is saved
    def before_save(self):

        # update gravesite count
        self.gravesites_count = 0
        for key, value in self.__dict__.items():
            if re.match(r"gravesite\d+", key) and value:
                self.gravesites_count += value

        # update GeoJSON
        if self.x_value and self.y_value:
            proj = pyproj.Transformer.from_crs(25832, 4326, always_xy=True)
            x, y = proj.transform(self.x_value, self.y_value)

            self.location = json.dumps({
                    "type":"FeatureCollection",
                    "features":[
                        {
                            "type":"Feature",
                            "properties":{},
                            "geometry":{"type":"Point","coordinates":[x,y]},
                        }
                        ],
                    })

    def on_update(self):
        # update gravesite if changed
        for key, value in self.__dict__.items():
            if re.match(r"gravesite\d+", key):
                gravesite_number = re.sub(r"gravesite", "", key)

                if value:

                    if not frappe.db.exists({"doctype": "Gravesite", "rest_tree":self.tree_number, "gravesite_number":gravesite_number}):
                        gravesite = frappe.get_doc({"doctype":"Gravesite", "rest_tree":self.tree_number, "gravesite_number":gravesite_number})
                        gravesite.insert(ignore_permissions=True)

                else:
                    if frappe.db.exists({"doctype": "Gravesite", "rest_tree":self.tree_number, "gravesite_number":gravesite_number}):
                        gravesite = frappe.get_last_doc('Gravesite', filters={"rest_tree":self.tree_number, "gravesite_number":gravesite_number})
                        gravesite.delete()
