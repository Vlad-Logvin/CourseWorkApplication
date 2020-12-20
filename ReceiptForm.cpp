#include "ReceiptForm.h"

void CourseWorkApplication::ReceiptForm::fillDataGridView()
{
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();

	List<Product> products = (**receiptIterator).getProductsList();
	int i = 0;
	for (Product product : products) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Cells[0]->Value = gcnew System::String(product.getName(), 0, strlen(product.getName()));
		dataGridView1->Rows[i]->Cells[1]->Value = product.getPrice();
		i++;
	}
}

System::Void CourseWorkApplication::ReceiptForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((*receiptIterator) == receipts->begin()) {
		(*receiptIterator) = receipts->rend();
	}
	else {
		--(*receiptIterator);
	}
	label2->Text = "Summary price: " + (**receiptIterator).getSummaryPrice();
	label3->Text = "Date: " + (**receiptIterator).getDay() + "." + (**receiptIterator).getMonth() + "." + (**receiptIterator).getYear();
	label4->Text = "Time: " + (**receiptIterator).getHour() + ":" + (**receiptIterator).getMinute() + ":" + (**receiptIterator).getSecond();
	fillDataGridView();
}

System::Void CourseWorkApplication::ReceiptForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((*receiptIterator) == receipts->rend()) {
		(*receiptIterator) = receipts->begin();
	}
	else {
		++(*receiptIterator);
	}
	label2->Text = "Summary price: " + (**receiptIterator).getSummaryPrice();
	label3->Text = "Date: " + (**receiptIterator).getDay() + "." + (**receiptIterator).getMonth() + "." + (**receiptIterator).getYear();
	label4->Text = "Time: " + (**receiptIterator).getHour() + ":" + (**receiptIterator).getMinute() + ":" + (**receiptIterator).getSecond();
	fillDataGridView();
}

System::Void CourseWorkApplication::ReceiptForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
