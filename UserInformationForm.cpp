#include "UserInformationForm.h"

System::Void CourseWorkApplication::UserInformationForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew UserManagingForm(admin->getLogin(), admin->getRole()))->Show();
}

System::Void CourseWorkApplication::UserInformationForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isAdd) {
		if (textBox1->Text != "" &&
			textBox2->Text != "")
		{
			if (MessageBox::Show("Are you sure you want to add a new user?", "Add user", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
				== System::Windows::Forms::DialogResult::OK)
			{
				string login, password, name, surname;
				int age, role;

				MarshalString(textBox1->Text, login);
				MarshalString(textBox2->Text, password);
				if (textBox3->Text != "") {
					MarshalString(textBox3->Text, name);
				}
				else {
					name = undefined;
				}

				if (textBox4->Text != "") {
					MarshalString(textBox4->Text, surname);
				}
				else {
					surname = undefined;
				}

				if (textBox5->Text != "") {
					age = System::Convert::ToInt32(textBox5->Text);
				}
				else {
					age = defaultNumber;
				}

				if (textBox6->Text != "") {
					role = System::Convert::ToInt32(textBox6->Text);
				}
				else {
					role = 0;
				}
				Authorization newUser(login.c_str(), password.c_str(), role);

				if (newUser.registration(name.c_str(), surname.c_str(), age)) {
					User user(login.c_str());
					if (admin->addAccount(user)) {
						MessageBox::Show("User is added!", "Correct");
					}
					else {
						MessageBox::Show("Failed to add user!", "Error");
					}
				}
				else {
					MessageBox::Show("Failed to add user!", "Error");
				}
			}
		}
		else {
			MessageBox::Show("Required fields are not filled in!", "Error");
		}
	}
	else {
		if (textBox1->Text != "") {

			if (MessageBox::Show("Are you sure you want to change the information about this user?", "Edit user information", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
				== System::Windows::Forms::DialogResult::OK)
			{

				string login, password, name, surname;
				int age, role;

				MarshalString(textBox1->Text, login);
				if (admin->editUserLogin(userLogin, login.c_str()))
				{


					if (textBox2->Text != "") {
						MarshalString(textBox2->Text, password);
						admin->editUserPassword(login.c_str(), password.c_str());
					}

					if (textBox3->Text != "") {
						MarshalString(textBox3->Text, name);
					}
					else {
						name = undefined;
					}
					admin->editUserName(login.c_str(), name.c_str());

					if (textBox4->Text != "") {
						MarshalString(textBox4->Text, surname);
					}
					else {
						surname = undefined;
					}
					admin->editUserSurname(login.c_str(), surname.c_str());

					if (textBox5->Text != "") {
						age = System::Convert::ToInt32(textBox5->Text);
					}
					else {
						age = defaultNumber;
					}
					admin->editUserAge(login.c_str(), age);

					if (textBox6->Text == "1") {
						role = System::Convert::ToInt32(textBox5->Text);
					}
					else {
						role = 0;
					}
					admin->changeRole(login.c_str(), role);
					if (admin->saveUsersInformation()) {
						MessageBox::Show("The changes are saved!", "Correct");
					}
					else {
						MessageBox::Show("Failed to save information!", "Error");
					}
				}
				else {
					MessageBox::Show("User with this login has already existed", "Error");
				}
			}
		}
		else {
			MessageBox::Show("Required fields are not filled in!", "Error");
		}

	}
}

System::Void CourseWorkApplication::UserInformationForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersInput(e);
}

System::Void CourseWorkApplication::UserInformationForm::textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersTip)));
}

System::Void CourseWorkApplication::UserInformationForm::textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectNumberInput(e);
}

System::Void CourseWorkApplication::UserInformationForm::textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersTip)));
}

System::Void CourseWorkApplication::UserInformationForm::textBox3_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersTip)));
}

System::Void CourseWorkApplication::UserInformationForm::textBox5_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(numbersTip)));
}

System::Void CourseWorkApplication::UserInformationForm::textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	if (e->KeyChar != 8 && e->KeyChar != '0' && e->KeyChar != '1')
	{
		e->Handled = true;
	}
}

System::Void CourseWorkApplication::UserInformationForm::textBox6_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, "The field can contains:\n0 - User;\n1 - Admin.\n");
}
