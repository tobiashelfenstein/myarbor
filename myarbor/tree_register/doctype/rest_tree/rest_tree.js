// Copyright (c) 2023, Tobias Helfenstein and contributors
// For license information, please see license.txt

//frappe.ui.form.on("Rest Tree", {
//	on_submit: function(frm) {
//		frappe.msgprint({
//			title: __('Notification'),
//			indicator: 'green',
//			message: __('Ruheplätze werden automatisch generiert.')
//			});
//	},
//});

frappe.provide("myarbor.tree_register");
myarbor.tree_register.RestTreeController = class RestTreeController extends frappe.ui.form.Controller {
	diameter() {
		frappe.db.get_doc('Category', null, { min_diameter: '30' })
			.then(doc => {
				frm.set_value("category", doc.name);
				console.log(doc)
			})
	}
};

cur_frm.cscript = new myarbor.tree_register.RestTreeController({
	frm: cur_frm
});

frappe.ui.form.on("Rest Tree", "refresh", function(frm) {
	frm.set_df_property("tree_type", "read_only", frm.doc.gravesites_count > 0 ? true : false);
	//if (frm.doc.gravesites_count > 0) {
	//	frm.toggle_enable('tree_type', false);
	//}
	//else {
	//	frm.toggle_enable('tree_type', true);
	//}
});
