#include "Registration.h"
#include "AuthorizationForm.h"

System::Void CourseWorkApplication::Registration::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew AuthorizationForm)->Visible = true;
}

System::Void CourseWorkApplication::Registration::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBox1->Text != "" && this->textBox2->Text != "") {
		string login, password, name, surname;
		MarshalString(this->textBox1->Text, login);
		MarshalString(this->textBox2->Text, password);

		if (this->textBox3->Text != "") {
			MarshalString(this->textBox3->Text, name);
		}
		else {
			name = undefined;
		}
		
		if (this->textBox4->Text != "") {
			MarshalString(this->textBox4->Text, surname);
		}
		else {
			surname = undefined;
		}
		int age = defaultNumber;

		if (this->textBox5->Text != "") {
			 age = System::Convert::ToInt32(this->textBox5->Text);
		}

		Authorization authorizaton(login.c_str(), password.c_str());
		if (authorizaton.registration(name.c_str(), surname.c_str(), age) == true) {
			MessageBox::Show("Registration is complete", "Complete");
		}
		else {
			MessageBox::Show("User with this login already exists", "Error");
		}
		this->Close();
		(gcnew AuthorizationForm)->Visible = true;
	}
	else {
		MessageBox::Show("Not valid login or password", "Error");
		this->textBox1->Text = "";
		this->textBox2->Text = "";
	}
}

System::Void CourseWorkApplication::Registration::textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectNumberInput(e);
}

System::Void CourseWorkApplication::Registration::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersInput(e);
}

System::Void CourseWorkApplication::Registration::textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersInput(e);
}

System::Void CourseWorkApplication::Registration::textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersTip)));
}

System::Void CourseWorkApplication::Registration::textBox3_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersTip)));
}

System::Void CourseWorkApplication::Registration::textBox5_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(numbersTip)));
}
