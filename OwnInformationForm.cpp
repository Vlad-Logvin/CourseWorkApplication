#include "OwnInformationForm.h"

System::Void CourseWorkApplication::OwnInformationForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

System::Void CourseWorkApplication::OwnInformationForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool isExist = false;
	string login;
	MarshalString(textBox1->Text, login);
	List<User> tempUserList = user->getUsersList();
	for (List<User>::Iterator it = tempUserList.begin(); it != tempUserList.end() && !isExist; ++it) {
		if (!equal((*it).getLogin(), user->getLogin()) && equal(login.c_str(), (*it).getLogin())) {
			isExist = true;
		}
	}
	if (isExist == true) {
		MessageBox::Show("User with this login is exist! Think of another one!", "Error");
	}
	else {
		if (MessageBox::Show("Are you sure you want to change your personal information?", "Save changes", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
			== System::Windows::Forms::DialogResult::OK) {
			string temp;
			MarshalString(textBox1->Text, temp);
			user->setLogin(temp.c_str());
			if (textBox2->Text != "") {
				MarshalString(textBox2->Text, temp);
				user->setPassword(temp.c_str());
			}
			MarshalString(textBox3->Text, temp);
			user->setName(temp.c_str());
			MarshalString(textBox4->Text, temp);
			user->setSurname(temp.c_str());
			user->setAge(System::Convert::ToInt32(textBox5->Text));
			if (user->saveUsersInformation()) {
				MessageBox::Show("The changes are saved!", "Complete");
				this->Close();
			}
			else {
				MessageBox::Show("Failed to save information about yourself!", "Error");
			}
		}
	}
}

System::Void CourseWorkApplication::OwnInformationForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersInput(e);
}

System::Void CourseWorkApplication::OwnInformationForm::textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersInput(e);
}

System::Void CourseWorkApplication::OwnInformationForm::textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectNumberInput(e);
}

System::Void CourseWorkApplication::OwnInformationForm::textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersTip)));
}

System::Void CourseWorkApplication::OwnInformationForm::textBox3_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersTip)));
}

System::Void CourseWorkApplication::OwnInformationForm::textBox5_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(numbersTip)));
}
