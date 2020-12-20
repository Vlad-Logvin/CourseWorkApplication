#include "ProductManagingForm.h"

System::Void CourseWorkApplication::ProductManagingForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew UserForm(user->getLogin(), user->getRole()))->Show();
}

void CourseWorkApplication::ProductManagingForm::fillDataGridView()
{
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();

	dataGridView1->Columns[6]->DefaultCellStyle->Font = gcnew System::Drawing::Font("Code 128", 17.0F, System::Drawing::FontStyle::Bold);
	Vector<Product> products = user->getProductsVector();
	for (int i = 0; i < products.getSize(); i++) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Cells[0]->Value = gcnew System::String(products[i].getName(), 0, strlen(products[i].getName()));
		dataGridView1->Rows[i]->Cells[1]->Value = products[i].getPrice();
		dataGridView1->Rows[i]->Cells[2]->Value = gcnew System::String(products[i].getGroup(), 0, strlen(products[i].getGroup()));
		dataGridView1->Rows[i]->Cells[3]->Value = gcnew System::String(products[i].getType(), 0, strlen(products[i].getType()));
		dataGridView1->Rows[i]->Cells[4]->Value = gcnew System::String(products[i].getIndividualAbility(), 0, strlen(products[i].getIndividualAbility()));
		dataGridView1->Rows[i]->Cells[5]->Value = gcnew System::String(products[i].getCountry(), 0, strlen(products[i].getCountry()));
		dataGridView1->Rows[i]->Cells[6]->Value = products[i].getBarCode();
	}
}

System::Void CourseWorkApplication::ProductManagingForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew AddProductForm(*user))->Show();
}

System::Void CourseWorkApplication::ProductManagingForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Are you sure you want to delete the product?", "Delete product", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
		== System::Windows::Forms::DialogResult::OK) {
		bool isFind = false;
		for (int i = 0; i < dataGridView1->Rows->Count - 1 && !isFind; i++) {
			if (dataGridView1->Rows[i]->Cells[0]->Value->Equals(textBox1->Text)) {
				dataGridView1->Rows->RemoveAt(i);
				isFind = true;
				string temp;
				MarshalString(textBox1->Text, temp);
				if (user->deleteProduct(temp.c_str()) && user->saveProductsToFile()) {
					MessageBox::Show("The product is removed!", "Correct");
				}
				else {
					MessageBox::Show("Couldn't delete the product!", "Error");
				}
			}
		}
		if (!isFind) {
			MessageBox::Show("Product " + textBox1->Text + " was not purchased by you!", "Not found");
		}
	}
}

System::Void CourseWorkApplication::ProductManagingForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	Vector<Product> products = user->getProductsVector();
	int productsSize = products.getSize();
	string productName;
	MarshalString(textBox1->Text, productName);
	bool isFind = false;
	for (int i = 0; i < productsSize && !isFind; i++) {
		if (equal(products[i].getName(), productName.c_str())) {
			isFind = true;
			(gcnew AddProductForm(*user, products[i]))->Show();
			this->Close();
		}
	}
	if (!isFind) {
		MessageBox::Show("Product " + textBox1->Text + " doesn't exist!", "Error");
	}
}

System::Void CourseWorkApplication::ProductManagingForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew UserForm(user->getLogin(), user->getRole()))->Show();
}

System::Void CourseWorkApplication::ProductManagingForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersAndSpaceInput(e);
}

System::Void CourseWorkApplication::ProductManagingForm::textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersAndSpaceTip)));
}

System::Void CourseWorkApplication::ProductManagingForm::dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e)
{
	if (e->RowIndex != -1 && e->RowIndex != dataGridView1->Rows->Count - 1)
	{
		textBox1->Text = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
	}
}
