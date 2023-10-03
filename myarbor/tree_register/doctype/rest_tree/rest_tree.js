// Copyright (c) 2023, Tobias Helfenstein and contributors
// For license information, please see license.txt

frappe.ui.form.on("Rest Tree", {
	on_submit: function(frm) {
		frappe.msgprint({
			title: __('Notification'),
			indicator: 'green',
			message: __('Ruheplätze werden automatisch generiert.')
			});
	},
});
