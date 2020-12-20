#include "UserForm.h"

void CourseWorkApplication::UserForm::fillDataGridView1()
{
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();

	dataGridView1->Columns[6]->DefaultCellStyle->Font = gcnew System::Drawing::Font("Code 128", 72.0F, System::Drawing::FontStyle::Bold);
	*products = user->getProductsVector();
	for (int i = 0; i < products->getSize(); i++) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Cells[0]->Value = gcnew System::String((*products)[i].getName(), 0, strlen((*products)[i].getName()));
		dataGridView1->Rows[i]->Cells[1]->Value = (*products)[i].getPrice();
		dataGridView1->Rows[i]->Cells[2]->Value = gcnew System::String((*products)[i].getGroup(), 0, strlen((*products)[i].getGroup()));
		dataGridView1->Rows[i]->Cells[3]->Value = gcnew System::String((*products)[i].getType(), 0, strlen((*products)[i].getType()));
		dataGridView1->Rows[i]->Cells[4]->Value = gcnew System::String((*products)[i].getIndividualAbility(), 0, strlen((*products)[i].getIndividualAbility()));
		dataGridView1->Rows[i]->Cells[5]->Value = gcnew System::String((*products)[i].getCountry(), 0, strlen((*products)[i].getCountry()));
		dataGridView1->Rows[i]->Cells[6]->Value = (*products)[i].getBarCode();
	}
}

System::Void CourseWorkApplication::UserForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool isFind = false;
	for (int i = 0; i < dataGridView1->Rows->Count - 1; i++) {
		dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
		if (textBox1->Text->Equals(dataGridView1->Rows[i]->Cells[0]->Value)) {
			dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Yellow;
			isFind = true;
		}
	}
	if (!isFind) {
		MessageBox::Show("Product " + textBox1->Text + " doesn't exist!", "Not found");
	}
}

System::Void CourseWorkApplication::UserForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersAndSpaceInput(e);
}

System::Void CourseWorkApplication::UserForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool isFind = false;
	for (int i = 0; i < dataGridView1->Rows->Count - 1 && !isFind; i++) {
		if (dataGridView1->Rows[i]->Cells[0]->Value->Equals(textBox1->Text)) {
			dataGridView2->Rows->Add();
			dataGridView2->Rows[dataGridView2->Rows->Count - 2]->Cells[0]->Value = dataGridView1->Rows[i]->Cells[0]->Value;
			dataGridView2->Rows[dataGridView2->Rows->Count - 2]->Cells[1]->Value = dataGridView1->Rows[i]->Cells[1]->Value;
			isFind = true;
			string temp;
			MarshalString(textBox1->Text, temp);
			user->buyProduct(temp.c_str());
		}
	}
	if (!isFind) {
		MessageBox::Show("Product " + textBox1->Text + " doesn't exist!", "Not found");
	}
}

System::Void CourseWorkApplication::UserForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool isFind = false;
	for (int i = 0; i < dataGridView2->Rows->Count - 1 && !isFind; i++) {
		if (dataGridView2->Rows[i]->Cells[0]->Value->Equals(textBox1->Text)) {
			dataGridView2->Rows->RemoveAt(i);
			isFind = true;
			string temp;
			MarshalString(textBox1->Text, temp);
			user->deleteBuyingProduct(temp.c_str());
		}
	}
	if (!isFind) {
		MessageBox::Show("Product " + textBox1->Text + " was not purchased by you!", "Not found");
	}
}

System::Void CourseWorkApplication::UserForm::comboBox1_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (comboBox1->SelectedIndex == 0) {
		user->sortProductsByName();
	}
	else if (comboBox1->SelectedIndex == 1) {
		user->sortProductsByPrice();
	}
	else if (comboBox1->SelectedIndex == 2) {
		user->sortProductsByGroup();
	}
	else if (comboBox1->SelectedIndex == 3) {
		user->sortProductsByType();
	}
	else if (comboBox1->SelectedIndex == 4) {
		user->sortProductsByCountry();
	}
	else if (comboBox1->SelectedIndex == 5) {
		user->sortProductsByBarCode();
	}

	fillDataGridView1();
}

System::Void CourseWorkApplication::UserForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView2->Rows->Count != 1) {
		String^ receipt = "User: " + gcnew System::String(user->getSurname()) + " " + gcnew System::String(user->getName()) + "\n\n";
		for (int i = 0; i < dataGridView2->Rows->Count - 1; i++) {
			int numberOfTab = 5;
			numberOfTab -= dataGridView2->Rows[i]->Cells[0]->Value->ToString()->Length / 8;
			receipt += dataGridView2->Rows[i]->Cells[0]->Value;
			for (int i = 1; i < numberOfTab; i++) {
				receipt += "\t";
			}
			receipt += "\t";
			receipt += dataGridView2->Rows[i]->Cells[1]->Value + "\n";
		}
		Receipt* rec = this->user->getReceiptPointer();
		receipt += "\nSummary price:\t\t\t\t" + rec->getSummaryPrice();
		rec->setDate();
		receipt += "\n" + rec->getDay() + "." + rec->getMonth() + "." + rec->getYear() + "\t\t\t\t" + rec->getHour() + ":" + rec->getMinute() + ":" + rec->getSecond();

		if (MessageBox::Show("Are you sure you want to make a purchase?\n\n" + receipt + "\n", "Make a receipt", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
			== System::Windows::Forms::DialogResult::OK) {
			if ((*user).makeReceipt() && (*user).saveReceiptInformation()) {
				dataGridView2->Rows->Clear();
				dataGridView2->Refresh();
				MessageBox::Show("The purchase is completed successfully!", "Correct");
			}
			else {
				MessageBox::Show("The purchase failed!", "Error");
			}
		}
	}
	else {
		MessageBox::Show("You didn't buy any products!", "Error");
	}
}

System::Void CourseWorkApplication::UserForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Are you sure you want to log out of your account?", "Exit", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
		== System::Windows::Forms::DialogResult::OK) {
		this->Close();
		(gcnew AuthorizationForm)->Show();
	}
}

System::Void CourseWorkApplication::UserForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew OwnInformationForm(*user))->Show();
}

System::Void CourseWorkApplication::UserForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{

	this->Close();
	(gcnew ProductManagingForm(user->getLogin(), user->getRole()))->Show();
}

System::Void CourseWorkApplication::UserForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew UserManagingForm(user->getLogin(), user->getRole()))->Show();
}

System::Void CourseWorkApplication::UserForm::textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersAndSpaceTip)));
}

System::Void CourseWorkApplication::UserForm::dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e)
{
	if (e->RowIndex!=-1 && e->RowIndex != dataGridView1->Rows->Count - 1)
	{
		textBox1->Text = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
	}
}
