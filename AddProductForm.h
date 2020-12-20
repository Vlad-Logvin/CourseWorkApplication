#pragma once

#include "Creator.h"
#include "ProductManagingForm.h"

namespace CourseWorkApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ AddProductForm
	/// </summary>
	public ref class AddProductForm : public System::Windows::Forms::Form
	{
	public:
		AddProductForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		AddProductForm(Admin user)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			if (user.getRole() == ADMIN) {
				this->user = new Admin(user.getLogin());
			}
			else {
				this->user = new Creator(user.getLogin());
			}
			this->isAdd = true;
		}

		AddProductForm(Admin user, Product& product)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			if (user.getRole() == ADMIN) {
				this->user = new Admin(user.getLogin());
			}
			else {
				this->user = new Creator(user.getLogin());
			}
			label1->Text = "Edit product";
			button1->Text = "Save";
			this->isAdd = false;
			char* productName = product.getName();
			int productNameLength = strlen(productName);
			this->productName = new char[productNameLength + 1];
			for (int i = 0; i < productNameLength; i++) {
				this->productName[i] = productName[i];
			}
			this->productName[productNameLength] = '\0';
			textBox1->Text = gcnew System::String(product.getName(), 0, strlen(product.getName()));
			textBox2->Text = product.getPrice().ToString();
			textBox3->Text = gcnew System::String(product.getGroup(), 0, strlen(product.getGroup()));
			textBox4->Text = gcnew System::String(product.getType(), 0, strlen(product.getType()));
			textBox5->Text = gcnew System::String(product.getIndividualAbility(), 0, strlen(product.getIndividualAbility()));
			textBox6->Text = gcnew System::String(product.getCountry(), 0, strlen(product.getCountry()));
			textBox7->Text = product.getBarCode().ToString();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AddProductForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddProductForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Dutch801 XBd BT", 32.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(42, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(262, 52);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add product";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Location = System::Drawing::Point(13, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Product name:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 98);
			this->textBox1->MaxLength = 50;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(313, 40);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddProductForm::textBox1_KeyPress);
			this->textBox1->MouseHover += gcnew System::EventHandler(this, &AddProductForm::textBox3_MouseHover);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Location = System::Drawing::Point(13, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Product price:";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(12, 164);
			this->textBox2->MaxLength = 20;
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(313, 40);
			this->textBox2->TabIndex = 4;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddProductForm::textBox2_KeyPress);
			this->textBox2->MouseHover += gcnew System::EventHandler(this, &AddProductForm::textBox2_MouseHover);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Location = System::Drawing::Point(13, 207);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Product group:";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(12, 230);
			this->textBox3->MaxLength = 50;
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(313, 40);
			this->textBox3->TabIndex = 6;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddProductForm::textBox1_KeyPress);
			this->textBox3->MouseHover += gcnew System::EventHandler(this, &AddProductForm::textBox3_MouseHover);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Location = System::Drawing::Point(13, 273);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 20);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Product type:";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(12, 296);
			this->textBox4->MaxLength = 50;
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(313, 40);
			this->textBox4->TabIndex = 8;
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddProductForm::textBox1_KeyPress);
			this->textBox4->MouseHover += gcnew System::EventHandler(this, &AddProductForm::textBox3_MouseHover);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label6->Location = System::Drawing::Point(13, 339);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(179, 20);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Product individual ability:";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(12, 362);
			this->textBox5->MaxLength = 1000;
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(313, 40);
			this->textBox5->TabIndex = 10;
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddProductForm::textBox1_KeyPress);
			this->textBox5->MouseHover += gcnew System::EventHandler(this, &AddProductForm::textBox3_MouseHover);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label7->Location = System::Drawing::Point(13, 405);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(124, 20);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Product country:";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(12, 428);
			this->textBox6->MaxLength = 50;
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(313, 40);
			this->textBox6->TabIndex = 12;
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddProductForm::textBox6_KeyPress);
			this->textBox6->MouseHover += gcnew System::EventHandler(this, &AddProductForm::textBox6_MouseHover);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label8->Location = System::Drawing::Point(13, 471);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(130, 20);
			this->label8->TabIndex = 13;
			this->label8->Text = L"Product barcode:";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(12, 494);
			this->textBox7->MaxLength = 8;
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(313, 40);
			this->textBox7->TabIndex = 14;
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddProductForm::textBox7_KeyPress);
			this->textBox7->MouseHover += gcnew System::EventHandler(this, &AddProductForm::textBox7_MouseHover);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(12, 557);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 47);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AddProductForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->Location = System::Drawing::Point(183, 557);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(155, 47);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &AddProductForm::button2_Click);
			// 
			// AddProductForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(350, 616);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Name = L"AddProductForm";
			this->Text = L"ProductForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool isAdd;
		Admin* user;
		char* productName;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox3_MouseHover(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox2_MouseHover(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox6_MouseHover(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox7_MouseHover(System::Object^ sender, System::EventArgs^ e);
};
}
