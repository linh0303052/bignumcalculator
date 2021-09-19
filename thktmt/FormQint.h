#pragma once
#include <iostream>
#include "Qint.h"
#include "Qfloat.h"
#include "Header.h"

void MarshalString(System::String^ s, std::string& os) {
	using namespace System::Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}
//#include <msclr\marshal_cppstd.h>
namespace CppCLRWinformsProjekt {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Qint ans("0");
	char cal = '=';//+ - x / %
	string cache = "";
	Qfloat ans2("0.0");
	char cal2 = '=';
	string cache2 = "";
	/// <summary>
	/// Zusammenfassung für FormQint
	/// </summary>
	public ref class FormQint : public System::Windows::Forms::Form
	{
	public:
		FormQint(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~FormQint()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ buttonDivide;
	private: System::Windows::Forms::Button^ buttonDot;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonLeftShift;
	private: System::Windows::Forms::Button^ buttonRightShift;
	private: System::Windows::Forms::Button^ buttonFour;
	private: System::Windows::Forms::Button^ buttonSeven;
	private: System::Windows::Forms::Button^ buttonEight;
	private: System::Windows::Forms::Button^ buttonNine;
	private: System::Windows::Forms::Button^ buttonSix;
	private: System::Windows::Forms::Button^ buttonFive;
	private: System::Windows::Forms::Button^ buttonMinus;
	private: System::Windows::Forms::Button^ buttonTimes;
	private: System::Windows::Forms::Button^ buttonPorN;
	private: System::Windows::Forms::Button^ buttonOne;
	private: System::Windows::Forms::Button^ buttonTwo;
	private: System::Windows::Forms::Button^ buttonThree;
	private: System::Windows::Forms::Button^ buttonZero;
	private: System::Windows::Forms::Button^ buttonEqual;
	private: System::Windows::Forms::Button^ buttonPlus;
	private: System::Windows::Forms::Label^ labelHEX;
	private: System::Windows::Forms::Label^ labelDEC;
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Label^ labelBIN;
	private: System::Windows::Forms::RadioButton^ radioButtonQfloat;

	private: System::Windows::Forms::RadioButton^ radioButtonQinit;

	private: System::Windows::Forms::Label^ labelExpression;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonDivide = (gcnew System::Windows::Forms::Button());
			this->buttonDot = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonLeftShift = (gcnew System::Windows::Forms::Button());
			this->buttonRightShift = (gcnew System::Windows::Forms::Button());
			this->buttonFour = (gcnew System::Windows::Forms::Button());
			this->buttonSeven = (gcnew System::Windows::Forms::Button());
			this->buttonEight = (gcnew System::Windows::Forms::Button());
			this->buttonNine = (gcnew System::Windows::Forms::Button());
			this->buttonSix = (gcnew System::Windows::Forms::Button());
			this->buttonFive = (gcnew System::Windows::Forms::Button());
			this->buttonMinus = (gcnew System::Windows::Forms::Button());
			this->buttonTimes = (gcnew System::Windows::Forms::Button());
			this->buttonPorN = (gcnew System::Windows::Forms::Button());
			this->buttonOne = (gcnew System::Windows::Forms::Button());
			this->buttonTwo = (gcnew System::Windows::Forms::Button());
			this->buttonThree = (gcnew System::Windows::Forms::Button());
			this->buttonZero = (gcnew System::Windows::Forms::Button());
			this->buttonEqual = (gcnew System::Windows::Forms::Button());
			this->buttonPlus = (gcnew System::Windows::Forms::Button());
			this->labelHEX = (gcnew System::Windows::Forms::Label());
			this->labelDEC = (gcnew System::Windows::Forms::Label());
			this->label = (gcnew System::Windows::Forms::Label());
			this->labelBIN = (gcnew System::Windows::Forms::Label());
			this->radioButtonQfloat = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonQinit = (gcnew System::Windows::Forms::RadioButton());
			this->labelExpression = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(10, 102);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(538, 57);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// buttonDelete
			// 
			this->buttonDelete->BackColor = System::Drawing::Color::IndianRed;
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDelete->Location = System::Drawing::Point(484, 500);
			this->buttonDelete->Margin = System::Windows::Forms::Padding(5);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(70, 60);
			this->buttonDelete->TabIndex = 3;
			this->buttonDelete->Text = L"Del";
			this->buttonDelete->UseVisualStyleBackColor = false;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &FormQint::buttonDelete_Click);
			// 
			// buttonDivide
			// 
			this->buttonDivide->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonDivide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDivide->Location = System::Drawing::Point(404, 501);
			this->buttonDivide->Margin = System::Windows::Forms::Padding(5);
			this->buttonDivide->Name = L"buttonDivide";
			this->buttonDivide->Size = System::Drawing::Size(70, 60);
			this->buttonDivide->TabIndex = 4;
			this->buttonDivide->Text = L"/";
			this->buttonDivide->UseVisualStyleBackColor = false;
			this->buttonDivide->Click += gcnew System::EventHandler(this, &FormQint::clickButtonCalculate);
			// 
			// buttonDot
			// 
			this->buttonDot->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonDot->Enabled = false;
			this->buttonDot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDot->Location = System::Drawing::Point(404, 570);
			this->buttonDot->Margin = System::Windows::Forms::Padding(5);
			this->buttonDot->Name = L"buttonDot";
			this->buttonDot->Size = System::Drawing::Size(70, 60);
			this->buttonDot->TabIndex = 6;
			this->buttonDot->Text = L".";
			this->buttonDot->UseVisualStyleBackColor = false;
			this->buttonDot->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::Color::IndianRed;
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonClear->Location = System::Drawing::Point(484, 431);
			this->buttonClear->Margin = System::Windows::Forms::Padding(5);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(70, 60);
			this->buttonClear->TabIndex = 7;
			this->buttonClear->Text = L"C";
			this->buttonClear->UseVisualStyleBackColor = false;
			this->buttonClear->Click += gcnew System::EventHandler(this, &FormQint::buttonClear_Click);
			// 
			// buttonLeftShift
			// 
			this->buttonLeftShift->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonLeftShift->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLeftShift->Location = System::Drawing::Point(6, 432);
			this->buttonLeftShift->Margin = System::Windows::Forms::Padding(5);
			this->buttonLeftShift->Name = L"buttonLeftShift";
			this->buttonLeftShift->Size = System::Drawing::Size(70, 60);
			this->buttonLeftShift->TabIndex = 8;
			this->buttonLeftShift->Text = L">>";
			this->buttonLeftShift->UseVisualStyleBackColor = false;
			this->buttonLeftShift->Click += gcnew System::EventHandler(this, &FormQint::clickButtonCalculate);
			// 
			// buttonRightShift
			// 
			this->buttonRightShift->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonRightShift->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonRightShift->Location = System::Drawing::Point(6, 501);
			this->buttonRightShift->Margin = System::Windows::Forms::Padding(5);
			this->buttonRightShift->Name = L"buttonRightShift";
			this->buttonRightShift->Size = System::Drawing::Size(70, 60);
			this->buttonRightShift->TabIndex = 9;
			this->buttonRightShift->Text = L"<<";
			this->buttonRightShift->UseVisualStyleBackColor = false;
			this->buttonRightShift->Click += gcnew System::EventHandler(this, &FormQint::clickButtonCalculate);
			// 
			// buttonFour
			// 
			this->buttonFour->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonFour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonFour->Location = System::Drawing::Point(86, 501);
			this->buttonFour->Margin = System::Windows::Forms::Padding(5);
			this->buttonFour->Name = L"buttonFour";
			this->buttonFour->Size = System::Drawing::Size(70, 60);
			this->buttonFour->TabIndex = 20;
			this->buttonFour->Text = L"4";
			this->buttonFour->UseVisualStyleBackColor = false;
			this->buttonFour->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonSeven
			// 
			this->buttonSeven->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonSeven->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSeven->Location = System::Drawing::Point(86, 432);
			this->buttonSeven->Margin = System::Windows::Forms::Padding(5);
			this->buttonSeven->Name = L"buttonSeven";
			this->buttonSeven->Size = System::Drawing::Size(70, 60);
			this->buttonSeven->TabIndex = 19;
			this->buttonSeven->Text = L"7";
			this->buttonSeven->UseVisualStyleBackColor = false;
			this->buttonSeven->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonEight
			// 
			this->buttonEight->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonEight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonEight->Location = System::Drawing::Point(164, 432);
			this->buttonEight->Margin = System::Windows::Forms::Padding(5);
			this->buttonEight->Name = L"buttonEight";
			this->buttonEight->Size = System::Drawing::Size(70, 60);
			this->buttonEight->TabIndex = 18;
			this->buttonEight->Text = L"8";
			this->buttonEight->UseVisualStyleBackColor = false;
			this->buttonEight->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonNine
			// 
			this->buttonNine->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonNine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonNine->Location = System::Drawing::Point(244, 432);
			this->buttonNine->Margin = System::Windows::Forms::Padding(5);
			this->buttonNine->Name = L"buttonNine";
			this->buttonNine->Size = System::Drawing::Size(70, 60);
			this->buttonNine->TabIndex = 17;
			this->buttonNine->Text = L"9";
			this->buttonNine->UseVisualStyleBackColor = false;
			this->buttonNine->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonSix
			// 
			this->buttonSix->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonSix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSix->Location = System::Drawing::Point(244, 501);
			this->buttonSix->Margin = System::Windows::Forms::Padding(5);
			this->buttonSix->Name = L"buttonSix";
			this->buttonSix->Size = System::Drawing::Size(70, 60);
			this->buttonSix->TabIndex = 16;
			this->buttonSix->Text = L"6";
			this->buttonSix->UseVisualStyleBackColor = false;
			this->buttonSix->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonFive
			// 
			this->buttonFive->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonFive->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonFive->Location = System::Drawing::Point(164, 501);
			this->buttonFive->Margin = System::Windows::Forms::Padding(5);
			this->buttonFive->Name = L"buttonFive";
			this->buttonFive->Size = System::Drawing::Size(70, 60);
			this->buttonFive->TabIndex = 15;
			this->buttonFive->Text = L"5";
			this->buttonFive->UseVisualStyleBackColor = false;
			this->buttonFive->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonMinus
			// 
			this->buttonMinus->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonMinus->Location = System::Drawing::Point(324, 431);
			this->buttonMinus->Margin = System::Windows::Forms::Padding(5);
			this->buttonMinus->Name = L"buttonMinus";
			this->buttonMinus->Size = System::Drawing::Size(70, 60);
			this->buttonMinus->TabIndex = 14;
			this->buttonMinus->Text = L"-";
			this->buttonMinus->UseVisualStyleBackColor = false;
			this->buttonMinus->Click += gcnew System::EventHandler(this, &FormQint::clickButtonCalculate);
			// 
			// buttonTimes
			// 
			this->buttonTimes->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonTimes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonTimes->Location = System::Drawing::Point(404, 431);
			this->buttonTimes->Margin = System::Windows::Forms::Padding(5);
			this->buttonTimes->Name = L"buttonTimes";
			this->buttonTimes->Size = System::Drawing::Size(70, 60);
			this->buttonTimes->TabIndex = 13;
			this->buttonTimes->Text = L"x";
			this->buttonTimes->UseVisualStyleBackColor = false;
			this->buttonTimes->Click += gcnew System::EventHandler(this, &FormQint::clickButtonCalculate);
			// 
			// buttonPorN
			// 
			this->buttonPorN->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonPorN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonPorN->Location = System::Drawing::Point(324, 570);
			this->buttonPorN->Margin = System::Windows::Forms::Padding(5);
			this->buttonPorN->Name = L"buttonPorN";
			this->buttonPorN->Size = System::Drawing::Size(70, 60);
			this->buttonPorN->TabIndex = 30;
			this->buttonPorN->Text = L"+/-";
			this->buttonPorN->UseVisualStyleBackColor = false;
			this->buttonPorN->Click += gcnew System::EventHandler(this, &FormQint::buttonPorN_Click);
			// 
			// buttonOne
			// 
			this->buttonOne->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonOne->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonOne->Location = System::Drawing::Point(86, 570);
			this->buttonOne->Margin = System::Windows::Forms::Padding(5);
			this->buttonOne->Name = L"buttonOne";
			this->buttonOne->Size = System::Drawing::Size(70, 60);
			this->buttonOne->TabIndex = 29;
			this->buttonOne->Text = L"1";
			this->buttonOne->UseVisualStyleBackColor = false;
			this->buttonOne->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonTwo
			// 
			this->buttonTwo->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonTwo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonTwo->Location = System::Drawing::Point(164, 570);
			this->buttonTwo->Margin = System::Windows::Forms::Padding(5);
			this->buttonTwo->Name = L"buttonTwo";
			this->buttonTwo->Size = System::Drawing::Size(70, 60);
			this->buttonTwo->TabIndex = 28;
			this->buttonTwo->Text = L"2";
			this->buttonTwo->UseVisualStyleBackColor = false;
			this->buttonTwo->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonThree
			// 
			this->buttonThree->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonThree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonThree->Location = System::Drawing::Point(244, 571);
			this->buttonThree->Margin = System::Windows::Forms::Padding(5);
			this->buttonThree->Name = L"buttonThree";
			this->buttonThree->Size = System::Drawing::Size(70, 60);
			this->buttonThree->TabIndex = 27;
			this->buttonThree->Text = L"3";
			this->buttonThree->UseVisualStyleBackColor = false;
			this->buttonThree->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonZero
			// 
			this->buttonZero->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonZero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonZero->Location = System::Drawing::Point(6, 570);
			this->buttonZero->Margin = System::Windows::Forms::Padding(5);
			this->buttonZero->Name = L"buttonZero";
			this->buttonZero->Size = System::Drawing::Size(70, 60);
			this->buttonZero->TabIndex = 25;
			this->buttonZero->Text = L"0";
			this->buttonZero->UseVisualStyleBackColor = false;
			this->buttonZero->Click += gcnew System::EventHandler(this, &FormQint::clickButtonNumber);
			// 
			// buttonEqual
			// 
			this->buttonEqual->BackColor = System::Drawing::Color::SteelBlue;
			this->buttonEqual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonEqual->Location = System::Drawing::Point(484, 570);
			this->buttonEqual->Margin = System::Windows::Forms::Padding(5);
			this->buttonEqual->Name = L"buttonEqual";
			this->buttonEqual->Size = System::Drawing::Size(70, 60);
			this->buttonEqual->TabIndex = 24;
			this->buttonEqual->Text = L"=";
			this->buttonEqual->UseVisualStyleBackColor = false;
			this->buttonEqual->Click += gcnew System::EventHandler(this, &FormQint::clickButtonCalculate);
			// 
			// buttonPlus
			// 
			this->buttonPlus->BackColor = System::Drawing::Color::ForestGreen;
			this->buttonPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonPlus->Location = System::Drawing::Point(324, 501);
			this->buttonPlus->Margin = System::Windows::Forms::Padding(5);
			this->buttonPlus->Name = L"buttonPlus";
			this->buttonPlus->Size = System::Drawing::Size(70, 60);
			this->buttonPlus->TabIndex = 23;
			this->buttonPlus->Text = L"+";
			this->buttonPlus->UseVisualStyleBackColor = false;
			this->buttonPlus->Click += gcnew System::EventHandler(this, &FormQint::clickButtonCalculate);
			// 
			// labelHEX
			// 
			this->labelHEX->AutoSize = true;
			this->labelHEX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelHEX->Location = System::Drawing::Point(14, 166);
			this->labelHEX->Name = L"labelHEX";
			this->labelHEX->Size = System::Drawing::Size(76, 26);
			this->labelHEX->TabIndex = 37;
			this->labelHEX->Text = L"HEX 0";
			// 
			// labelDEC
			// 
			this->labelDEC->AutoSize = true;
			this->labelDEC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDEC->Location = System::Drawing::Point(13, 194);
			this->labelDEC->Name = L"labelDEC";
			this->labelDEC->Size = System::Drawing::Size(77, 26);
			this->labelDEC->TabIndex = 38;
			this->labelDEC->Text = L"DEC 0";
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label->Location = System::Drawing::Point(22, 221);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(49, 26);
			this->label->TabIndex = 40;
			this->label->Text = L"BIN";
			// 
			// labelBIN
			// 
			this->labelBIN->AutoSize = true;
			this->labelBIN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBIN->Location = System::Drawing::Point(66, 221);
			this->labelBIN->Name = L"labelBIN";
			this->labelBIN->Size = System::Drawing::Size(24, 26);
			this->labelBIN->TabIndex = 41;
			this->labelBIN->Text = L"0";
			// 
			// radioButtonQfloat
			// 
			this->radioButtonQfloat->AutoSize = true;
			this->radioButtonQfloat->Location = System::Drawing::Point(10, 41);
			this->radioButtonQfloat->Name = L"radioButtonQfloat";
			this->radioButtonQfloat->Size = System::Drawing::Size(77, 24);
			this->radioButtonQfloat->TabIndex = 42;
			this->radioButtonQfloat->Text = L"Qfloat";
			this->radioButtonQfloat->UseVisualStyleBackColor = true;
			this->radioButtonQfloat->CheckedChanged += gcnew System::EventHandler(this, &FormQint::radioButtonQfloat_CheckedChanged);
			// 
			// radioButtonQinit
			// 
			this->radioButtonQinit->AutoSize = true;
			this->radioButtonQinit->Checked = true;
			this->radioButtonQinit->Location = System::Drawing::Point(10, 12);
			this->radioButtonQinit->Name = L"radioButtonQinit";
			this->radioButtonQinit->Size = System::Drawing::Size(63, 24);
			this->radioButtonQinit->TabIndex = 43;
			this->radioButtonQinit->TabStop = true;
			this->radioButtonQinit->Text = L"Qint";
			this->radioButtonQinit->UseVisualStyleBackColor = true;
			this->radioButtonQinit->CheckedChanged += gcnew System::EventHandler(this, &FormQint::radioButtonQinit_CheckedChanged);
			// 
			// labelExpression
			// 
			this->labelExpression->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelExpression->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->labelExpression->Location = System::Drawing::Point(10, 66);
			this->labelExpression->MinimumSize = System::Drawing::Size(20, 20);
			this->labelExpression->Name = L"labelExpression";
			this->labelExpression->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->labelExpression->Size = System::Drawing::Size(536, 33);
			this->labelExpression->TabIndex = 45;
			this->labelExpression->Text = L"0";
			this->labelExpression->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// FormQint
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(560, 644);
			this->Controls->Add(this->labelExpression);
			this->Controls->Add(this->radioButtonQinit);
			this->Controls->Add(this->radioButtonQfloat);
			this->Controls->Add(this->labelBIN);
			this->Controls->Add(this->label);
			this->Controls->Add(this->labelDEC);
			this->Controls->Add(this->labelHEX);
			this->Controls->Add(this->buttonPorN);
			this->Controls->Add(this->buttonOne);
			this->Controls->Add(this->buttonTwo);
			this->Controls->Add(this->buttonThree);
			this->Controls->Add(this->buttonZero);
			this->Controls->Add(this->buttonEqual);
			this->Controls->Add(this->buttonPlus);
			this->Controls->Add(this->buttonFour);
			this->Controls->Add(this->buttonSeven);
			this->Controls->Add(this->buttonEight);
			this->Controls->Add(this->buttonNine);
			this->Controls->Add(this->buttonSix);
			this->Controls->Add(this->buttonFive);
			this->Controls->Add(this->buttonMinus);
			this->Controls->Add(this->buttonTimes);
			this->Controls->Add(this->buttonRightShift);
			this->Controls->Add(this->buttonLeftShift);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonDot);
			this->Controls->Add(this->buttonDivide);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->textBox1);
			this->KeyPreview = true;
			this->MaximumSize = System::Drawing::Size(582, 700);
			this->MinimumSize = System::Drawing::Size(582, 700);
			this->Name = L"FormQint";
			this->Text = L"SuperCalculator";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FormQint::keyPressed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void updateLabel(Qint qint) {//cap nhat cac nhan
		textBox1->Text = gcnew String(qint.toDec().c_str());
		labelHEX->Text = "HEX  " + convertEach4(DecToHex_string(qint).c_str());
		labelBIN->Text = gcnew String((convertBoolToString(DecToBin(qint))).c_str());
		labelDEC->Text = "DEC  " + textBox1->Text;
		if (cal != '=')//neu khac dau bang
		{
			switch (cal)//cap nhat binh thuong tru dau shift left va shift right
			{
			case '>':labelExpression->Text = gcnew String((ans.toDec() + cal + ">" + cache).c_str());
				break;
			case '<':labelExpression->Text = gcnew String((ans.toDec() + cal + "<" + cache).c_str());
				break;
			default:
				labelExpression->Text = gcnew String((ans.toDec() + cal + cache).c_str()); break;
			}
		}
		else//neu la dau bang thi tinh
			if (cache.length() == 0)
				labelExpression->Text = gcnew String((ans.toDec()).c_str());
			else
				labelExpression->Text = gcnew String((cache).c_str());
		EnabelButtonCalculate(cache, cal);
	}
	private: System::Void updateLabel(Qfloat qfloat) {//cap nhat cac nhan
		textBox1->Text = gcnew String(cache2.c_str());
		labelDEC->Text = "DEC  " + gcnew String(qfloat.toDec().c_str());
		labelBIN->Text = gcnew String(convertBoolToString(Qfloat::DecToBin(qfloat)).c_str());
		if (cal2 != '=')//neu khac dau bang
			labelExpression->Text = gcnew String((ans2.toDec() + cal2 + cache2).c_str());
		else//neu la dau bang thi tinh
			if (cache2.length() == 0)
				labelExpression->Text = gcnew String((ans2.toDec()).c_str());
			else
				labelExpression->Text = gcnew String((cache2).c_str());
		EnabelButtonCalculate(cache2, cal2);
	}
	private:System::Boolean CheckEqualZero(string cache) {//kiem tra bo nho dem dang bang 0 hay khong
		for (int i = 0; i < cache.length(); i++)
		{
			if ((cache[i] > '1') && (cache[i] < '9')) return false;//neu co 1 so nam trong 1-9 thi khac 0
		}
		return true;
	}
	private: System::Void EnabelButtonCalculate(string cache, char cal) {
		if ((cal == '/') && (CheckEqualZero(cache)))//neu dang chia ma so hien tai bang 0 thi khong cho tinh
		{
			(*this->buttonPlus).Enabled = false;
			(*this->buttonMinus).Enabled = false;
			(*this->buttonEqual).Enabled = false;
			(*this->buttonDivide).Enabled = false;
			(*this->buttonTimes).Enabled = false;
			if ((*this->radioButtonQinit).Checked == true) {
				(*this->buttonLeftShift).Enabled = false;
				(*this->buttonRightShift).Enabled = false;
			}
		}
		else//nguoc lai bat cho phep tinh
		{
			(*this->buttonPlus).Enabled = true;
			(*this->buttonMinus).Enabled = true;
			(*this->buttonEqual).Enabled = true;
			(*this->buttonDivide).Enabled = true;
			(*this->buttonTimes).Enabled = true;
			if ((*this->radioButtonQinit).Checked == true) {
				(*this->buttonLeftShift).Enabled = true;
				(*this->buttonRightShift).Enabled = true;
			}
		}
	}
	private: System::Void clickButtonNumber(System::Object^ sender, System::EventArgs^ e) {//ham click cac so
		if ((*this->radioButtonQinit).Checked == true) {
			if (cal == '=')//phep tinh moi
				ans = Qint("0");
			//neu dang thuc hien phep tinh Qint
			if (cal == '=') ans = Qint("0");
			string str;
			MarshalString(textBox1->Text, str);
			cache += (sender->ToString()[35]);
			str = cache;

			Qint qint(str);

			updateLabel(qint);
		}
		else
		{//neu dang thuc hien phep tinh Qfloat
			if (cal2 == '=')//phep tinh moi
				ans2 = Qfloat("0");
			if (sender->ToString()[35] == '.') {
				if (cache2.find(".") == string::npos)
				{
					cache2 += (sender->ToString()[35]);
					(*this->textBox1).Text = gcnew String(cache2.c_str());
					//Qfloat qfloat(cache2);
					//updateLabel(qfloat);
				}
			}
			else
			{
				cache2 += (sender->ToString()[35]);
				Qfloat qfloat;
				if (!CheckEqualZero(cache2))
				{
					qfloat = Qfloat(cache2);
				}
				else
				{
					qfloat = Qfloat("0");
				}
				updateLabel(qfloat);

			}
		}
	}
	private: System::Void clickButtonCalculate(System::Object^ sender, System::EventArgs^ e) {//ham click cac phep tinh
		if ((*this->radioButtonQinit).Checked == true) {
			//QInt
			switch (cal)
			{
			case '+':
				ans = ans + Qint(cache); break;
			case 'x':
				ans = ans * Qint(cache); break;
			case '-':
				ans = ans - Qint(cache);
				break;
			case '/':
				ans = ans / Qint(cache);
				break;
			case '=':
				if (ans == Qint("0"))
				{
					ans = Qint(cache);
				}
				break;
			case '<':
				ans = ans << stoi(cache);
				break;
			case '>':
				ans = ans >> stoi(cache);
				break;

			default:
				break;
			}
			//sau khi tinh thi luu tru dem bang khoang trang
			//ans cap nhat moi
			//cal la dau vua nhan
			cache = "";
			cal = sender->ToString()[35];
			if (cal == '/') (*this->buttonZero).Enabled = false;
			updateLabel(ans);
		}
		else
		{
			switch (cal2)
			{
			case '+':
				ans2 = ans2 + Qfloat(cache2); break;
			case 'x':
				ans2 = ans2 * Qfloat(cache2); break;
			case '-':
				ans2 = ans2 - Qfloat(cache2);
				break;
			case '/':
				ans2 = ans2 / Qfloat(cache2);
				break;
			case '=':
				if (ans2 == Qfloat("0.0"))
				{
					ans2 = Qfloat(cache2);
				}
				break;
			default:
				break;
			}
			//sau khi tinh thi luu tru dem bang khoang trang
			//ans cap nhat moi
			//cal la dau vua nhan
			cache2 = "";
			cal2 = sender->ToString()[35];
			EnabelButtonCalculate(cache2, cal2);
			updateLabel(ans2);
		}
	}
	private: System::Void buttonPorN_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((*this->radioButtonQinit).Checked == true) {
			//QInt
			if (cache.length() < 1) return;
			if (cache[0] == '-') cache = cache.substr(1, cache.length() - 1);
			else
				cache = '-' + cache;
			updateLabel(Qint(cache));
		}
		else
		{
			//Qfloat
			if (CheckEqualZero(cache2)) return;
			if (cache2[0] == '-') cache2 = cache2.substr(1, cache2.length() - 1);
			else
				cache2 = '-' + cache2;
			updateLabel(Qfloat(cache2));//update some label
		}
	}
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {//button xoa 1 ki tu
		if ((*this->radioButtonQinit).Checked == true) {//neu qinit
			if (cache.length() > 0)//neu co nhieu hon 1 ki tu
			{
				cache = cache.substr(0, cache.length() - 1);//cat string
				if (CheckEqualZero(cache))
				{
					(*this->textBox1).Text = gcnew String(cache.c_str());
				}
				else
					updateLabel(Qint(cache));//cap nhat
			}
		}
		else//neu qfloat
		{
			if (cache2.length() > 0)//neu co nhieu hon 1 ki tu
			{
				cache2 = cache2.substr(0, cache2.length() - 1);;//cat string
				if (CheckEqualZero(cache2))
				{
					(*this->textBox1).Text = gcnew String(cache2.c_str());
				}
				else
					updateLabel(Qfloat(cache2));
			}
		}

	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {//button xoa het
		if ((*this->radioButtonQinit).Checked == true) {//neu qinit
			cache = "";
			ans = Qint("0");
			cal = '=';
			updateLabel(ans);
		}
		else//neu qfloat
		{
			cache2 = "";
			ans2 = Qfloat("0");
			cal2 = '=';
			updateLabel(ans);
		}
	}
	private: System::Void radioButtonQfloat_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {//lang nghe radio button cua Qint
		//Something for Float
		(*this->buttonLeftShift).Enabled = false;
		(*this->buttonRightShift).Enabled = false;
		(*this->buttonDot).Enabled = true;
		(*this->labelHEX).Visible = false;
		ans2 = Qfloat("0");
		cal2 = '=';//+ - x / %
		cache2 = "";
		updateLabel(ans2);
	}
	private: System::Void radioButtonQinit_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {//lang nghe radio button cua Qfloat
		//Enable something for Integer
		(*this->buttonLeftShift).Enabled = true;
		(*this->buttonRightShift).Enabled = true;
		(*this->buttonDot).Enabled = false;
		(*this->labelHEX).Visible = true;
		cache = "";
		ans = Qint("0");
		cal = '=';//+ - x / %
		updateLabel(ans);
	}

	private: System::Void keyPressed(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {//lang nghe tu ban phim
		if (((e->KeyChar >= '0') && (e->KeyChar <= '9')) || (e->KeyChar == '.'))//neu go cac ki tu 0-9 hoac dau "."
		{
			if ((e->KeyChar != '.') && ((*this->radioButtonQinit).Checked == true)) {//neu dang qint
				if (cal == '=')//phep tinh moi
					ans = Qint("0");
				//neu dang thuc hien phep tinh Qint
				if (cal == '=') ans = Qint("0");
				string str;
				MarshalString(textBox1->Text, str);
				cache += (e->KeyChar);
				str = cache;
				Qint qint(str);
				updateLabel(qint);
			}
			else
			{//neu dang thuc hien phep tinh Qfloat
				if (cal2 == '=')//phep tinh moi
					ans2 = Qfloat("0");
				if (e->KeyChar == '.') {
					if (cache2.find(".") == string::npos)
					{
						cache2 += (e->KeyChar);
						(*this->textBox1).Text = gcnew String(cache2.c_str());
					}
				}
				else
				{
					cache2 += (e->KeyChar);//cap nhat hien tai
					Qfloat qfloat;
					if (!CheckEqualZero(cache2))
					{
						qfloat = Qfloat(cache2);
					}
					else
					{
						qfloat = Qfloat("0");
					}
					updateLabel(qfloat);
				}
			}
		}
		else
		{
			if ((e->KeyChar == '+') ||
				(e->KeyChar == '-') ||
				(e->KeyChar == '*') ||
				(e->KeyChar == '/') ||
				(e->KeyChar == '='))//neu la dau
			{
				if ((*this->radioButtonQinit).Checked == true) {
					//QInt
					switch (cal)
					{
					case '+':
						ans = ans + Qint(cache); break;
					case '*':
						ans = ans * Qint(cache); break;
					case '-':
						ans = ans - Qint(cache);
						break;
					case '/':
						ans = ans / Qint(cache);
						break;
					case '=':
						if (ans == Qint("0"))
						{
							ans = Qint(cache);
						}
						break;
					case '<':
						ans = ans << stoi(cache);
						break;
					case '>':
						ans = ans >> stoi(cache);
						break;

					default:
						break;
					}
					//sau khi tinh thi luu tru dem bang khoang trang
					//ans cap nhat moi
					//cal la dau vua nhan
					cache = "";
					cal = e->KeyChar;
					if (cal == '/') (*this->buttonZero).Enabled = false;
					updateLabel(ans);
				}
				else
				{
					switch (cal2)
					{
					case '+':
						ans2 = ans2 + Qfloat(cache2); break;
					case 'x':
						ans2 = ans2 * Qfloat(cache2); break;
					case '-':
						ans2 = ans2 - Qfloat(cache2);
						break;
					case '/':
						ans2 = ans2 / Qfloat(cache2);
						break;
					case '=':
						if (ans2 == Qfloat("0.0"))
						{
							ans2 = Qfloat(cache2);
						}
						break;
					default:
						break;
					}
					//sau khi tinh thi luu tru dem bang khoang trang
					//ans cap nhat moi
					//cal la dau vua nhan
					cache2 = "";
					cal2 = e->KeyChar;
					EnabelButtonCalculate(cache2, cal2);
					updateLabel(ans2);
				}
			}
		}
	}
	};

}
