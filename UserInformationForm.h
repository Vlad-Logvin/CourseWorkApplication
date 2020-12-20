#pragma once
#include "UserManagingForm.h"

namespace CourseWorkApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ UserInformationForm
	/// </summary>
	public ref class UserInformationForm : public System::Windows::Forms::Form
	{
	public:
		UserInformationForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		UserInformationForm(const char* login, int role)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			admin = new Creator(login);
			isAdd = true;
			if (role == ADMIN) {
				textBox6->Enabled = false;
				textBox6->Text = "0";
			}
		}

		UserInformationForm(const char* login, int role, User& user)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			admin = new Creator(login);
			isAdd = false;
			label1->Text = "Edit user";
			label4->Text = "Password";
			button1->Text = "Save";
			if (role == ADMIN) {
				textBox6->Enabled = false;
			}
			textBox1->Text = gcnew System::String(user.getLogin(), 0, strlen(user.getLogin()));
			textBox3->Text = gcnew System::String(user.getName(), 0, strlen(user.getName()));
			textBox4->Text = gcnew System::String(user.getSurname(), 0, strlen(user.getSurname()));
			textBox5->Text = user.getAge().ToString();
			textBox6->Text = user.getRole().ToString();
			if (user.getRole() == CREATOR) {
				textBox6->Enabled = false;
			}
			int userLoginLength = strlen(user.getLogin());
			userLogin = new char[userLoginLength + 1];
			for (int i = 0; i < userLoginLength; i++) {
				userLogin[i] = user.getLogin()[i];
			}
			userLogin[userLoginLength] = '\0';
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~UserInformationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserInformationForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Dutch801 XBd BT", 32.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(72, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 52);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add user";
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
			this->button2->FlatAppearance->BorderSize = 2;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(176, 557);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(145, 41);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UserInformationForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::RoyalBlue;
			this->button1->FlatAppearance->BorderSize = 2;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 557);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 41);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserInformationForm::button1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(9, 405);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 20);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Age";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(12, 428);
			this->textBox5->MaxLength = 2;
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(307, 34);
			this->textBox5->TabIndex = 23;
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UserInformationForm::textBox5_KeyPress);
			this->textBox5->MouseHover += gcnew System::EventHandler(this, &UserInformationForm::textBox5_MouseHover);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(12, 354);
			this->textBox4->MaxLength = 40;
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(307, 34);
			this->textBox4->TabIndex = 22;
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UserInformationForm::textBox3_KeyPress);
			this->textBox4->MouseHover += gcnew System::EventHandler(this, &UserInformationForm::textBox3_MouseHover);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(9, 331);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(74, 20);
			this->label6->TabIndex = 21;
			this->label6->Text = L"Surname";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(12, 275);
			this->textBox3->MaxLength = 40;
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(307, 34);
			this->textBox3->TabIndex = 20;
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UserInformationForm::textBox3_KeyPress);
			this->textBox3->MouseHover += gcnew System::EventHandler(this, &UserInformationForm::textBox3_MouseHover);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(9, 252);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 20);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Name";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(12, 193);
			this->textBox2->MaxLength = 30;
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(307, 34);
			this->textBox2->TabIndex = 18;
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UserInformationForm::textBox1_KeyPress);
			this->textBox2->MouseHover += gcnew System::EventHandler(this, &UserInformationForm::textBox1_MouseHover);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(8, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 20);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Password*";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 115);
			this->textBox1->MaxLength = 30;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(307, 34);
			this->textBox1->TabIndex = 16;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UserInformationForm::textBox1_KeyPress);
			this->textBox1->MouseHover += gcnew System::EventHandler(this, &UserInformationForm::textBox1_MouseHover);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(8, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 20);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Username*";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(9, 479);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 20);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Role";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(12, 502);
			this->textBox6->MaxLength = 1;
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(307, 34);
			this->textBox6->TabIndex = 28;
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &UserInformationForm::textBox6_KeyPress);
			this->textBox6->MouseHover += gcnew System::EventHandler(this, &UserInformationForm::textBox6_MouseHover);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(9, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(198, 16);
			this->label2->TabIndex = 14;
			this->label2->Text = L"required fields are marked with *";
			// 
			// UserInformationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(333, 610);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Name = L"UserInformationForm";
			this->Text = L"UserInformationForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Creator* admin;
		bool isAdd;
		char* userLogin;
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox1_MouseHover(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox3_MouseHover(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox5_MouseHover(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void textBox6_MouseHover(System::Object^ sender, System::EventArgs^ e);
	};
}
