#include "AddProductForm.h"

System::Void CourseWorkApplication::AddProductForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text != "" &&
		textBox2->Text != "" &&
		textBox3->Text != "" &&
		textBox4->Text != "" &&
		textBox5->Text != "" &&
		textBox6->Text != "" &&
		textBox7->Text != "")
	{
		if (isAdd && MessageBox::Show("Are you sure you want to add a new product?", "Add product", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
			== System::Windows::Forms::DialogResult::OK) {
			string name, group, type, individualAbility, country;
			MarshalString(textBox1->Text, name);
			MarshalString(textBox3->Text, group);
			MarshalString(textBox4->Text, type);
			MarshalString(textBox5->Text, individualAbility);
			MarshalString(textBox6->Text, country);

			Product product(name.c_str(),
				System::Convert::ToDouble(textBox2->Text),
				group.c_str(),
				type.c_str(),
				individualAbility.c_str(),
				country.c_str(),
				System::Convert::ToInt32(textBox7->Text));
			ofstream out(productsFile, ios::app);
			if (user->addProduct(product) && product.write(out)) {
				MessageBox::Show("Product added!", "Correct");
			}
			else {
				MessageBox::Show("Failed to add a new product!", "Error");
			}
			out.close();
		}
		else if (MessageBox::Show("Are you sure you want to edit the information about this product?", "Edit product", MessageBoxButtons::OKCancel, MessageBoxIcon::Question)
			== System::Windows::Forms::DialogResult::OK) {
			string name, group, type, individualAbility, country;
			MarshalString(textBox1->Text, name);
			MarshalString(textBox3->Text, group);
			MarshalString(textBox4->Text, type);
			MarshalString(textBox5->Text, individualAbility);
			MarshalString(textBox6->Text, country);
			if ((equal(productName, name.c_str()) || user->editProductName(productName, name.c_str())) &&
				user->editProductBarCode(name.c_str(), System::Convert::ToInt32(textBox7->Text)) &&
				user->editProductCountry(name.c_str(), country.c_str()) &&
				user->editProductIndividualAbility(name.c_str(), individualAbility.c_str()) &&
				user->editProductType(name.c_str(), type.c_str()) &&
				user->editProductGroup(name.c_str(), group.c_str()) &&
				user->editProductPrice(name.c_str(), System::Convert::ToDouble(textBox2->Text)) &&
				user->saveProductsToFile()) {
				MessageBox::Show("The changes are saved!", "Correct");
			}
			else {
				MessageBox::Show("Couldn't change the product! A product with this name already exists!", "Error");
			}
		}
	}
	else {
		MessageBox::Show("Fill in all fields!", "Error");
	}
}

System::Void CourseWorkApplication::AddProductForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	(gcnew ProductManagingForm(user->getLogin(), user->getRole()))->Show();
}

System::Void CourseWorkApplication::AddProductForm::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndNumbersAndSpaceInput(e);
}

System::Void CourseWorkApplication::AddProductForm::textBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectNumberInput(e);
}

System::Void CourseWorkApplication::AddProductForm::textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectDoubleNumberInput(e);
}

System::Void CourseWorkApplication::AddProductForm::textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	e->Handled = isCorrectLettersAndSpaceInput(e);
}

System::Void CourseWorkApplication::AddProductForm::textBox3_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndNumbersAndSpaceTip)));
}

System::Void CourseWorkApplication::AddProductForm::textBox2_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(doubleNumbersTip)));
}

System::Void CourseWorkApplication::AddProductForm::textBox6_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(lettersAndSpaceTip)));
}

System::Void CourseWorkApplication::AddProductForm::textBox7_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	(gcnew ToolTip)->SetToolTip((TextBox^)sender, (gcnew System::String(numbersTip)));
}
