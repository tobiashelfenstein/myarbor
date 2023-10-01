# Copyright (c) 2023, Tobias Helfenstein and contributors
# For license information, please see license.txt

# import frappe
from frappe.model.document import Document

class Customer(Document):
    # this method will run every time a document is saved
    def before_save(self):
        self.display_name = f'{self.last_name}, {self.first_name}, {self.city}'

