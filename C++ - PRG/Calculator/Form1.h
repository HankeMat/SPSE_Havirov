#pragma once

namespace calculator2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  display;
	protected:
	private: System::Windows::Forms::Button^  btn1;
	private: System::Windows::Forms::Button^  btn2;
	private: System::Windows::Forms::Button^  btn3;
	private: System::Windows::Forms::Button^  btn4;
	private: System::Windows::Forms::Button^  btn5;
	private: System::Windows::Forms::Button^  btn6;
	private: System::Windows::Forms::Button^  btn7;
	private: System::Windows::Forms::Button^  btn8;
	private: System::Windows::Forms::Button^  btn9;
	private: System::Windows::Forms::Button^  btn0;
	private: System::Windows::Forms::Button^  bckSpc;

	private: System::Windows::Forms::Button^  btnSqrt;
	private: System::Windows::Forms::Button^  plusMinus;
	private: System::Windows::Forms::Button^  btnCarka;
	private: System::Windows::Forms::Button^  btnabs;
	private: System::Windows::Forms::Button^  btnRound;
	private: System::Windows::Forms::Button^  btnOneDevideByX;
	private: System::Windows::Forms::Button^  btnFactorial;
	private: System::Windows::Forms::Button^  btnPlus;
	private: System::Windows::Forms::Button^  btnMinus;
	private: System::Windows::Forms::Button^  btnKrat;
	private: System::Windows::Forms::Button^  btnDeleno;
	private: System::Windows::Forms::Button^  btnRovnaSe;
	private: System::Windows::Forms::Button^  btnC;
	private: System::Windows::Forms::Button^  btnCE;
	private: System::Windows::Forms::Button^  btnXPowY;
	private: System::Windows::Forms::Button^  btnSin;
	private: System::Windows::Forms::Button^  btnCos;
	private: System::Windows::Forms::Button^  btnTan;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btnUnit;



	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->display = (gcnew System::Windows::Forms::Label());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->bckSpc = (gcnew System::Windows::Forms::Button());
			this->btnSqrt = (gcnew System::Windows::Forms::Button());
			this->plusMinus = (gcnew System::Windows::Forms::Button());
			this->btnCarka = (gcnew System::Windows::Forms::Button());
			this->btnabs = (gcnew System::Windows::Forms::Button());
			this->btnRound = (gcnew System::Windows::Forms::Button());
			this->btnOneDevideByX = (gcnew System::Windows::Forms::Button());
			this->btnFactorial = (gcnew System::Windows::Forms::Button());
			this->btnPlus = (gcnew System::Windows::Forms::Button());
			this->btnMinus = (gcnew System::Windows::Forms::Button());
			this->btnKrat = (gcnew System::Windows::Forms::Button());
			this->btnDeleno = (gcnew System::Windows::Forms::Button());
			this->btnRovnaSe = (gcnew System::Windows::Forms::Button());
			this->btnC = (gcnew System::Windows::Forms::Button());
			this->btnCE = (gcnew System::Windows::Forms::Button());
			this->btnXPowY = (gcnew System::Windows::Forms::Button());
			this->btnSin = (gcnew System::Windows::Forms::Button());
			this->btnCos = (gcnew System::Windows::Forms::Button());
			this->btnTan = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnUnit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// display
			// 
			this->display->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->display->Location = System::Drawing::Point(12, 9);
			this->display->Name = L"display";
			this->display->Size = System::Drawing::Size(273, 42);
			this->display->TabIndex = 0;
			this->display->Text = L"0";
			this->display->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// btn1
			// 
			this->btn1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn1->Location = System::Drawing::Point(67, 59);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(50, 50);
			this->btn1->TabIndex = 1;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &Form1::btn1_Click);
			// 
			// btn2
			// 
			this->btn2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn2->Location = System::Drawing::Point(123, 59);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(50, 50);
			this->btn2->TabIndex = 1;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &Form1::btn2_Click);
			// 
			// btn3
			// 
			this->btn3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn3->Location = System::Drawing::Point(179, 59);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(50, 50);
			this->btn3->TabIndex = 1;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &Form1::btn3_Click);
			// 
			// btn4
			// 
			this->btn4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn4->Location = System::Drawing::Point(67, 115);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(50, 50);
			this->btn4->TabIndex = 1;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &Form1::btn4_Click);
			// 
			// btn5
			// 
			this->btn5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn5->Location = System::Drawing::Point(123, 115);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(50, 50);
			this->btn5->TabIndex = 1;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &Form1::btn5_Click);
			// 
			// btn6
			// 
			this->btn6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn6->Location = System::Drawing::Point(179, 115);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(50, 50);
			this->btn6->TabIndex = 1;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &Form1::btn6_Click);
			// 
			// btn7
			// 
			this->btn7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn7->Location = System::Drawing::Point(67, 171);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(50, 50);
			this->btn7->TabIndex = 1;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &Form1::btn7_Click);
			// 
			// btn8
			// 
			this->btn8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn8->Location = System::Drawing::Point(123, 171);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(50, 50);
			this->btn8->TabIndex = 1;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &Form1::btn8_Click);
			// 
			// btn9
			// 
			this->btn9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn9->Location = System::Drawing::Point(179, 171);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(50, 50);
			this->btn9->TabIndex = 1;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &Form1::btn9_Click);
			// 
			// btn0
			// 
			this->btn0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn0->Location = System::Drawing::Point(123, 227);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(50, 50);
			this->btn0->TabIndex = 1;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &Form1::btn0_Click);
			// 
			// bckSpc
			// 
			this->bckSpc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->bckSpc->Location = System::Drawing::Point(235, 59);
			this->bckSpc->Name = L"bckSpc";
			this->bckSpc->Size = System::Drawing::Size(50, 50);
			this->bckSpc->TabIndex = 1;
			this->bckSpc->Text = L"<=";
			this->bckSpc->UseVisualStyleBackColor = true;
			this->bckSpc->Click += gcnew System::EventHandler(this, &Form1::bckSpc_Click);
			// 
			// btnSqrt
			// 
			this->btnSqrt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnSqrt->Location = System::Drawing::Point(235, 171);
			this->btnSqrt->Name = L"btnSqrt";
			this->btnSqrt->Size = System::Drawing::Size(50, 50);
			this->btnSqrt->TabIndex = 1;
			this->btnSqrt->Text = L"2√x";
			this->btnSqrt->UseVisualStyleBackColor = true;
			this->btnSqrt->Click += gcnew System::EventHandler(this, &Form1::btnSqrt_Click);
			// 
			// plusMinus
			// 
			this->plusMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->plusMinus->Location = System::Drawing::Point(235, 227);
			this->plusMinus->Name = L"plusMinus";
			this->plusMinus->Size = System::Drawing::Size(50, 50);
			this->plusMinus->TabIndex = 1;
			this->plusMinus->Text = L"+/-";
			this->plusMinus->UseVisualStyleBackColor = true;
			this->plusMinus->Click += gcnew System::EventHandler(this, &Form1::plusMinus_Click);
			// 
			// btnCarka
			// 
			this->btnCarka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnCarka->Location = System::Drawing::Point(179, 227);
			this->btnCarka->Name = L"btnCarka";
			this->btnCarka->Size = System::Drawing::Size(50, 50);
			this->btnCarka->TabIndex = 1;
			this->btnCarka->Text = L",";
			this->btnCarka->UseVisualStyleBackColor = true;
			this->btnCarka->Click += gcnew System::EventHandler(this, &Form1::btnCarka_Click);
			// 
			// btnabs
			// 
			this->btnabs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnabs->Location = System::Drawing::Point(235, 283);
			this->btnabs->Name = L"btnabs";
			this->btnabs->Size = System::Drawing::Size(50, 50);
			this->btnabs->TabIndex = 1;
			this->btnabs->Text = L"abs";
			this->btnabs->UseVisualStyleBackColor = true;
			this->btnabs->Click += gcnew System::EventHandler(this, &Form1::btnabs_Click);
			// 
			// btnRound
			// 
			this->btnRound->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnRound->Location = System::Drawing::Point(179, 283);
			this->btnRound->Name = L"btnRound";
			this->btnRound->Size = System::Drawing::Size(50, 50);
			this->btnRound->TabIndex = 1;
			this->btnRound->Text = L"round";
			this->btnRound->UseVisualStyleBackColor = true;
			this->btnRound->Click += gcnew System::EventHandler(this, &Form1::btnRound_Click);
			// 
			// btnOneDevideByX
			// 
			this->btnOneDevideByX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnOneDevideByX->Location = System::Drawing::Point(123, 283);
			this->btnOneDevideByX->Name = L"btnOneDevideByX";
			this->btnOneDevideByX->Size = System::Drawing::Size(50, 50);
			this->btnOneDevideByX->TabIndex = 1;
			this->btnOneDevideByX->Text = L"1/x";
			this->btnOneDevideByX->UseVisualStyleBackColor = true;
			this->btnOneDevideByX->Click += gcnew System::EventHandler(this, &Form1::btnOneDevideByX_Click);
			// 
			// btnFactorial
			// 
			this->btnFactorial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnFactorial->Location = System::Drawing::Point(67, 283);
			this->btnFactorial->Name = L"btnFactorial";
			this->btnFactorial->Size = System::Drawing::Size(50, 50);
			this->btnFactorial->TabIndex = 1;
			this->btnFactorial->Text = L"x!";
			this->btnFactorial->UseVisualStyleBackColor = true;
			this->btnFactorial->Click += gcnew System::EventHandler(this, &Form1::btnFactorial_Click);
			// 
			// btnPlus
			// 
			this->btnPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnPlus->Location = System::Drawing::Point(11, 339);
			this->btnPlus->Name = L"btnPlus";
			this->btnPlus->Size = System::Drawing::Size(50, 50);
			this->btnPlus->TabIndex = 1;
			this->btnPlus->Text = L"+";
			this->btnPlus->UseVisualStyleBackColor = true;
			this->btnPlus->Click += gcnew System::EventHandler(this, &Form1::btnPlus_Click);
			// 
			// btnMinus
			// 
			this->btnMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnMinus->Location = System::Drawing::Point(67, 339);
			this->btnMinus->Name = L"btnMinus";
			this->btnMinus->Size = System::Drawing::Size(50, 50);
			this->btnMinus->TabIndex = 1;
			this->btnMinus->Text = L"-";
			this->btnMinus->UseVisualStyleBackColor = true;
			this->btnMinus->Click += gcnew System::EventHandler(this, &Form1::btnMinus_Click);
			// 
			// btnKrat
			// 
			this->btnKrat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnKrat->Location = System::Drawing::Point(123, 339);
			this->btnKrat->Name = L"btnKrat";
			this->btnKrat->Size = System::Drawing::Size(50, 50);
			this->btnKrat->TabIndex = 1;
			this->btnKrat->Text = L"*";
			this->btnKrat->UseVisualStyleBackColor = true;
			this->btnKrat->Click += gcnew System::EventHandler(this, &Form1::btnKrat_Click);
			// 
			// btnDeleno
			// 
			this->btnDeleno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnDeleno->Location = System::Drawing::Point(179, 339);
			this->btnDeleno->Name = L"btnDeleno";
			this->btnDeleno->Size = System::Drawing::Size(50, 50);
			this->btnDeleno->TabIndex = 1;
			this->btnDeleno->Text = L"/";
			this->btnDeleno->UseVisualStyleBackColor = true;
			this->btnDeleno->Click += gcnew System::EventHandler(this, &Form1::btnDeleno_Click);
			// 
			// btnRovnaSe
			// 
			this->btnRovnaSe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnRovnaSe->Location = System::Drawing::Point(235, 339);
			this->btnRovnaSe->Name = L"btnRovnaSe";
			this->btnRovnaSe->Size = System::Drawing::Size(50, 50);
			this->btnRovnaSe->TabIndex = 1;
			this->btnRovnaSe->Text = L"=";
			this->btnRovnaSe->UseVisualStyleBackColor = true;
			this->btnRovnaSe->Click += gcnew System::EventHandler(this, &Form1::btnRovnaSe_Click);
			// 
			// btnC
			// 
			this->btnC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnC->Location = System::Drawing::Point(11, 59);
			this->btnC->Name = L"btnC";
			this->btnC->Size = System::Drawing::Size(50, 50);
			this->btnC->TabIndex = 1;
			this->btnC->Text = L"C";
			this->btnC->UseVisualStyleBackColor = true;
			this->btnC->Click += gcnew System::EventHandler(this, &Form1::btnC_Click);
			// 
			// btnCE
			// 
			this->btnCE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnCE->Location = System::Drawing::Point(11, 115);
			this->btnCE->Name = L"btnCE";
			this->btnCE->Size = System::Drawing::Size(50, 50);
			this->btnCE->TabIndex = 1;
			this->btnCE->Text = L"CE";
			this->btnCE->UseVisualStyleBackColor = true;
			this->btnCE->Click += gcnew System::EventHandler(this, &Form1::btnCE_Click);
			// 
			// btnXPowY
			// 
			this->btnXPowY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnXPowY->Location = System::Drawing::Point(67, 229);
			this->btnXPowY->Name = L"btnXPowY";
			this->btnXPowY->Size = System::Drawing::Size(50, 50);
			this->btnXPowY->TabIndex = 1;
			this->btnXPowY->Text = L"^";
			this->btnXPowY->UseVisualStyleBackColor = true;
			this->btnXPowY->Click += gcnew System::EventHandler(this, &Form1::btnXPowY_Click);
			// 
			// btnSin
			// 
			this->btnSin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->btnSin->Location = System::Drawing::Point(12, 171);
			this->btnSin->Name = L"btnSin";
			this->btnSin->Size = System::Drawing::Size(50, 50);
			this->btnSin->TabIndex = 1;
			this->btnSin->Text = L"sin";
			this->btnSin->UseVisualStyleBackColor = true;
			this->btnSin->Click += gcnew System::EventHandler(this, &Form1::btnSin_Click);
			// 
			// btnCos
			// 
			this->btnCos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->btnCos->Location = System::Drawing::Point(11, 226);
			this->btnCos->Name = L"btnCos";
			this->btnCos->Size = System::Drawing::Size(50, 50);
			this->btnCos->TabIndex = 1;
			this->btnCos->Text = L"cos";
			this->btnCos->UseVisualStyleBackColor = true;
			this->btnCos->Click += gcnew System::EventHandler(this, &Form1::btnCos_Click);
			// 
			// btnTan
			// 
			this->btnTan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->btnTan->Location = System::Drawing::Point(11, 280);
			this->btnTan->Name = L"btnTan";
			this->btnTan->Size = System::Drawing::Size(50, 50);
			this->btnTan->TabIndex = 1;
			this->btnTan->Text = L"tan";
			this->btnTan->UseVisualStyleBackColor = true;
			this->btnTan->Click += gcnew System::EventHandler(this, &Form1::btnTan_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->button1->Location = System::Drawing::Point(234, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"sin";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::btnSin_Click);
			// 
			// btnUnit
			// 
			this->btnUnit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnUnit->Location = System::Drawing::Point(234, 116);
			this->btnUnit->Name = L"btnUnit";
			this->btnUnit->Size = System::Drawing::Size(50, 50);
			this->btnUnit->TabIndex = 1;
			this->btnUnit->Text = L"Deg";
			this->btnUnit->UseVisualStyleBackColor = true;
			this->btnUnit->Click += gcnew System::EventHandler(this, &Form1::btnUnit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(296, 401);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btnXPowY);
			this->Controls->Add(this->btnCE);
			this->Controls->Add(this->btnC);
			this->Controls->Add(this->btn0);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btnCarka);
			this->Controls->Add(this->btnRovnaSe);
			this->Controls->Add(this->btnDeleno);
			this->Controls->Add(this->btnKrat);
			this->Controls->Add(this->btnMinus);
			this->Controls->Add(this->btnPlus);
			this->Controls->Add(this->btnFactorial);
			this->Controls->Add(this->btnOneDevideByX);
			this->Controls->Add(this->btnRound);
			this->Controls->Add(this->btnabs);
			this->Controls->Add(this->plusMinus);
			this->Controls->Add(this->btnSqrt);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btnTan);
			this->Controls->Add(this->btnCos);
			this->Controls->Add(this->btnUnit);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnSin);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->bckSpc);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->display);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Calculator";
			this->ResumeLayout(false);

		}
#pragma endregion
		int reset = 0;
		bool operandPressed = 0;
		double prvniCislo;
		char operand;
		void zadani(String ^btnFromNumber) {
			if (display->Text == "0" || reset == 1) {
				display->Text = btnFromNumber;
				reset = 0;
			}
			else {
				display->Text = display->Text + btnFromNumber;
			}

		}

		void vypocet() {
			double result;
			switch (operand)
			{
			case '+':
				result = prvniCislo + System::Convert::ToDouble(display->Text);
				display->Text = System::Convert::ToString(result);
				operandPressed = 0;
				break;
			case '-':
				result = prvniCislo - System::Convert::ToDouble(display->Text);
				display->Text = System::Convert::ToString(result);
				break;
			case '*':
				result = prvniCislo * System::Convert::ToDouble(display->Text);
				display->Text = System::Convert::ToString(result);
				break;
			case '/':
				result = prvniCislo / System::Convert::ToDouble(display->Text);
				display->Text = System::Convert::ToString(result);
				break;
			case '^':
				result = Math::Pow(prvniCislo, System::Convert::ToDouble(display->Text));
				display->Text = System::Convert::ToString(result);
				break;
			default:
				break;
			}
		}

	private: System::Void btn1_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn1->Text);
	}
	private: System::Void btn2_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn2->Text);
	}
	private: System::Void btn3_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn3->Text);
	}
	private: System::Void btn8_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn8->Text);
	}
	private: System::Void btn0_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn0->Text);
	}
	private: System::Void btn9_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn9->Text);
	}
	private: System::Void btn6_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn6->Text);
	}
	private: System::Void btn5_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn5->Text);
	}
	private: System::Void btn7_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn7->Text);
	}
	private: System::Void btn4_Click(System::Object^  sender, System::EventArgs^  e) {
		zadani(btn4->Text);
	}
	private: System::Void bckSpc_Click(System::Object^  sender, System::EventArgs^  e) {
		if (display->Text->Length == 1) {
			display->Text = "0";
			return;
		}

		display->Text = display->Text->Remove((display->Text->Length) - 1);
		
		if (display->Text == "-") {
			display->Text = "0";
			return;
		}
	}
	private: System::Void btnPow_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);

		double vysledek = cislo * cislo;

		display->Text = System::Convert::ToString(vysledek);
		reset = 1;
	}
	private: System::Void btnSqrt_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);

		double vysledek = Math::Sqrt(cislo);

		display->Text = System::Convert::ToString(vysledek);
		reset = 1;
	}
	private: System::Void plusMinus_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);
		cislo = cislo * -1;
		display->Text = System::Convert::ToString(cislo);
	}
	private: System::Void btnCarka_Click(System::Object^  sender, System::EventArgs^  e) {
		if (display->Text->Contains(",") == false) {
			display->Text = display->Text + ",";
		}
	}
	private: System::Void btnabs_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);
		if (cislo < 0) {
			cislo = cislo * -1;
		}
		display->Text = System::Convert::ToString(cislo);
	}
	private: System::Void btnRound_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);
		cislo = Math::Round(cislo);
		display->Text = System::Convert::ToString(cislo);
	}
	private: System::Void btnOneDevideByX_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);
		cislo = 1 / cislo;
		display->Text = System::Convert::ToString(cislo);
		reset = 1;
	}
	private: System::Void btnFactorial_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);
		double vysledek = 1;
		int i;
		for (i = cislo; i > 1; --i) {
			vysledek = vysledek * i;
		}
		display->Text = System::Convert::ToString(vysledek);
		reset = 1;
	}
	private: System::Void btnKrat_Click(System::Object^  sender, System::EventArgs^  e) {
		if (operandPressed == 1) {
			vypocet();
		}
		prvniCislo = System::Convert::ToDouble(display->Text);
		operand = '*';
		operandPressed = 1;
		reset = 1;
	}
	private: System::Void btnRovnaSe_Click(System::Object^  sender, System::EventArgs^  e) {
		if (operandPressed == 1) {
			vypocet();
		}
		operandPressed = 0;
		reset = 1;
	}
	private: System::Void btnDeleno_Click(System::Object^  sender, System::EventArgs^  e) {
		if (operandPressed == 1) {
			vypocet();
		}
		prvniCislo = System::Convert::ToDouble(display->Text);
		operand = '/';
		operandPressed = 1;
		reset = 1;
	}
	private: System::Void btnMinus_Click(System::Object^  sender, System::EventArgs^  e) {
		if (operandPressed == 1) {
			vypocet();
		}
		prvniCislo = System::Convert::ToDouble(display->Text);
		operand = '-';
		operandPressed = 1;
		reset = 1;
	}
	private: System::Void btnPlus_Click(System::Object^  sender, System::EventArgs^  e) {
		if (operandPressed == 1) {
			vypocet();
		}
		prvniCislo = System::Convert::ToDouble(display->Text);
		operand = '+';
		operandPressed = 1;
		reset = 1;
	}
	private: System::Void btnC_Click(System::Object^  sender, System::EventArgs^  e) {
		prvniCislo = 0;
		operandPressed = 0;
		display->Text = "0";
	}
	private: System::Void btnCE_Click(System::Object^  sender, System::EventArgs^  e) {
		display->Text = "0";
	}
	private: System::Void btnXPowY_Click(System::Object^  sender, System::EventArgs^  e) {
		if (operandPressed == 1) {
			vypocet();
		}
		prvniCislo = System::Convert::ToDouble(display->Text);
		operand = '^';
		operandPressed = 1;
		reset = 1;
	}
	private: System::Void btnCos_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);
		
		if (btnUnit->Text == "Deg") {
			cislo = (cislo * Math::PI) / 180;
		}

		cislo = Math::Cos(cislo);
		display->Text = System::Convert::ToString(cislo);
	}
	private: System::Void btnTan_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);

		if (btnUnit->Text == "Deg") {
			cislo = (cislo * Math::PI) / 180;
		}

		cislo = Math::Tan(cislo);
		display->Text = System::Convert::ToString(cislo);
	}

	private: System::Void btnSin_Click(System::Object^  sender, System::EventArgs^  e) {
		double cislo = System::Convert::ToDouble(display->Text);

		if (btnUnit->Text == "Deg") {
			cislo = (cislo * Math::PI) / 180;
		}

		cislo = Math::Sin(cislo);
		display->Text = System::Convert::ToString(cislo);
	}

	private: System::Void btnUnit_Click(System::Object^  sender, System::EventArgs^  e) {
		if (btnUnit->Text == "Deg") {
			btnUnit->Text = "Rad";
		}
		else{
			btnUnit->Text = "Deg";
		}

	}
};
}
