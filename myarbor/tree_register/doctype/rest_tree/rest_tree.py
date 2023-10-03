# Copyright (c) 2023, Tobias Helfenstein and contributors
# For license information, please see license.txt

import frappe
from frappe.model.document import Document
import re

class RestTree(Document):
    # this method will run every time a document is saved
    def before_save(self):
        self.tree_name = f'Rest Tree {self.tree_number}'

        self.gravesites_count = 0
        for key, value in self.__dict__.items():
            if re.match(r"gravesite\d+", key) and value:
                # update gravesite count
                self.gravesites_count += value

                # auto generate gravesite
                #gravesite = frappe.get_doc({"doctype":"Gravesite", "rest_tree":self.tree_number, "gravesite_number":re.sub(r"gravesite", "", key)})
                #gravesite.insert(ignore_permissions=True)

    def on_update(self):
        # update gravesite on submit
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

