#include "UserManagingForm.h"

void CourseWorkApplication::UserManagingForm::fillDataGridView()
{
	dataGridView1->Rows->Clear();
	dataGridView1->Refresh();

	List<User> users = admin->getUsersList();
	int i = 0;
	for (List<User>::Iterator it = users.begin(); it != users.end(); ++it, ++i) {
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Cells[0]->Value = gcnew System::String((*it).getLogin(), 0, strlen((*it).getLogin()));
		dataGridView1->Rows[i]->Cells[1]->Value = gcnew System::String((*it).getName(), 0, strlen((*it).getName()));
		dataGridView1->Rows[i]->Cells[2]->Value = gcnew System::String((*it).getSurname(), 0, strlen((*it).getSurname()));
		dataGridView1->Rows[i]->Cells[3]->Value = (*it).getAge();
	}
}

System::Void CourseWorkApplication::UserManagingForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew UserForm(admin->getLogin(), admin->getRole()))->Show();
}

System::Void CourseWorkApplication::UserManagingForm::comboBox1_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (comboBox1->SelectedIndex == 0) {
		admin->sortUsersByLogin();
	}
	else if (comboBox1->SelectedIndex == 1) {
		admin->sortUsersByName();
	}
	else if (comboBox1->SelectedIndex == 2) {
		admin->sortUsersBySurname();
	}
	else if (comboBox1->SelectedIndex == 3) {
		admin->sortUsersByAge();
	}

	fillDataGridView();
}

System::Void CourseWorkApplication::UserManagingForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Are you sure you want to delete this user?", "Delete user", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
		== System::Windows::Forms::DialogResult::OK) {
		string login;
		MarshalString(textBox1->Text, login);

		if (admin->deleteAccount(login.c_str()) && admin->saveUsersInformation()) {
			MessageBox::Show("User is deleted!", "Correct");
			fillDataGridView();
		}
		else {
			MessageBox::Show("User " + textBox1->Text + " was not found or user's permission is higher!", "Error");
		}
	}
}

System::Void CourseWorkApplication::UserManagingForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew UserInformationForm(admin->getLogin(), admin->getRole()))->Show();
}

System::Void CourseWorkApplication::UserManagingForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text != "") {
		string login;
		MarshalString(textBox1->Text, login);
		bool isFind = false;
		List<User> users = admin->getUsersList();
		for (List<User>::Iterator it = users.begin(); it != users.end() && !isFind; ++it) {
			if (equal((*it).getLogin(), login.c_str())) {
				if (equal((*it).getLogin(), admin->getLogin()) || ((*it).getRole() < admin->getRole())) {
					isFind = true;
					this->Close();
					(gcnew UserInformationForm(admin->getLogin(), admin->getRole(), admin->findUser(login.c_str())))->Show();
				}
				else {
					isFind = true;
					MessageBox::Show("User has more permission than you!", "Not enough permission");
				}
			}
		}
		if (!isFind) {
			MessageBox::Show("User " + textBox1->Text + " was not found!", "Not found");
		}
	}
	else {
		MessageBox::Show("Input login field", "Error");
	}
}

System::Void CourseWorkApplication::UserManagingForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	string login;
	MarshalString(textBox1->Text, login);
	bool isFind = false;
	List<User> users = admin->getUsersList();
	for (List<User>::Iterator user = users.begin(); user != users.end() && !isFind; ++user) {
		if (equal(login.c_str(), (*user).getLogin())) {
			if ((*user).getReceiptsList().getSize() != 0) {
				(gcnew ReceiptForm(login.c_str()))->Show();
			}
			else {
				MessageBox::Show("User has not made any purchases yet", "No buys");
			}
			isFind = true;
		}
	}
	if (!isFind) {
		MessageBox::Show("User " + textBox1->Text + " was not found!", "Not found");
	}

}

System::Void CourseWorkApplication::UserManagingForm::textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersTip)));
}

System::Void CourseWorkApplication::UserManagingForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersInput(e);
}

System::Void CourseWorkApplication::UserManagingForm::dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e)
{
	if (e->RowIndex != -1 && e->RowIndex != dataGridView1->Rows->Count - 1)
	{
		textBox1->Text = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
	}
}

System::Void CourseWorkApplication::UserManagingForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
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
		MessageBox::Show("User " + textBox1->Text + " doesn't exist!", "Not found");
	}
}
