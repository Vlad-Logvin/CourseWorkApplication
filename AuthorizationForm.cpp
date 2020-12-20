#include "AuthorizationForm.h"
#include <Windows.h>

#include "Authorization.h"
#include "Registration.h"
#include "UserForm.h"

using namespace CourseWorkApplication;
using namespace System;
using namespace Runtime::InteropServices;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew AuthorizationForm);

	return 0;
}

System::Void CourseWorkApplication::AuthorizationForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBox1->Text != "" && this->textBox2->Text != "") {
		string login, password;
		MarshalString(this->textBox1->Text, login);
		MarshalString(this->textBox2->Text, password);
		Authorization authorizaton(login.c_str(), password.c_str());
		if (authorizaton.enter() == true) {
			this->Visible = false;
			UserForm^ userForm = gcnew UserForm(login.c_str(), authorizaton.getRole());
			userForm->Show();
		}
		else {
			MessageBox::Show("There is no user with such username and password", "Not found");
			this->textBox1->Text = "";
			this->textBox2->Text = "";
		}
	}
	else {
		MessageBox::Show("Not valid login or password", "Error");
		this->textBox1->Text = "";
		this->textBox2->Text = "";
	}
}

System::Void CourseWorkApplication::AuthorizationForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Visible = false;
	Registration^ reg = gcnew Registration();
	reg->Show();
	
}

System::Void CourseWorkApplication::AuthorizationForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersInput(e);
}

System::Void CourseWorkApplication::AuthorizationForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Are you sure you want to log out?", "Exit", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
		== System::Windows::Forms::DialogResult::OK) {
		Application::Exit();
	}
}

System::Void CourseWorkApplication::AuthorizationForm::textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersTip)));
}
