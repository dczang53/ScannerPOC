#pragma once
#include "Scanner.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO::Ports;
using namespace System::Windows::Forms;

extern Int32 SCROLLBARMAXOFFSET;

namespace SandTimages {
	/// <summary>
	/// Summary for frmSandTimages
	/// </summary>
	public ref class frmSandTimages : public System::Windows::Forms::Form
	{
	public:
		frmSandTimages(void)
		{
			InitializeComponent();
			this->m_scanner = (gcnew Scanner(this));
			this->pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
			this->pictureBox2->SizeMode = PictureBoxSizeMode::StretchImage;
			this->pictureBox3->SizeMode = PictureBoxSizeMode::StretchImage;
			this->pictureBox4->SizeMode = PictureBoxSizeMode::StretchImage;
			this->pictureBox5->SizeMode = PictureBoxSizeMode::StretchImage;
			array<Object^>^ objectArray = SerialPort::GetPortNames();
			this->comboBox1->Items->AddRange(objectArray);
			//
			//TODO: Add the constructor code here
			//
		}

		Void loadDisplayFrame()
		{
			this->pictureBox1->Image = m_scanner->getDisplayFrame();
			this->Refresh();
		}

		Void loadFrameCenter()
		{
			this->pictureBox5->Image = m_scanner->getFrameCenter();
			this->Refresh();
		}

		Void loadImageT()
		{
			this->pictureBox2->Image = m_scanner->getImageT();
			this->Refresh();
		}

		Void loadImageS()
		{
			this->pictureBox3->Image = m_scanner->getImageS();
			this->Refresh();
		}

		Void loadRGB(Int32 R)	//NOTE ONLY R IS IN USE
		{
			this->textBox16->Text = R.ToString();
			this->Refresh();
		}

		Void loadBoxAverages(Int32 St, Int32 Sr, Int32 Sb, Int32 Sl, Int32 T)	//NOTE ONLY R IS IN USE
		{
			this->textBox1->Text = St.ToString();
			this->textBox2->Text = Sr.ToString();
			this->textBox3->Text = Sb.ToString();
			this->textBox4->Text = Sl.ToString();
			this->textBox5->Text = T.ToString();
			this->Refresh();
		}

		/*
		Void loadImageCore()
		{
			this->pictureBox4->Image = m_scanner->getFrameCenter();
		}
		*/

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmSandTimages()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::TextBox^ textBox18;
	private: System::Windows::Forms::HScrollBar^ hScrollBar1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::HScrollBar^ hScrollBar2;
	private: System::Windows::Forms::HScrollBar^ hScrollBar3;
	private: System::Windows::Forms::HScrollBar^ hScrollBar4;
	private: System::Windows::Forms::VScrollBar^ vScrollBar1;
	private: System::Windows::Forms::VScrollBar^ vScrollBar2;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::TextBox^ textBox20;
	private: System::Windows::Forms::TextBox^ textBox21;
	private: System::Windows::Forms::TextBox^ textBox22;
	private: System::Windows::Forms::TextBox^ textBox23;
	private: System::Windows::Forms::TextBox^ textBox24;
	private: System::Windows::Forms::HScrollBar^ hScrollBar5;
	private: System::Windows::Forms::HScrollBar^ hScrollBar6;
	private: System::Windows::Forms::VScrollBar^ vScrollBar3;
	private: System::Windows::Forms::VScrollBar^ vScrollBar4;
	private: System::Windows::Forms::TextBox^ textBox25;
	private: System::Windows::Forms::TextBox^ textBox26;
	private: System::Windows::Forms::TextBox^ textBox27;
	private: System::Windows::Forms::TextBox^ textBox28;
	private: System::Windows::Forms::HScrollBar^ hScrollBar7;
	private: System::Windows::Forms::HScrollBar^ hScrollBar8;
	private: System::Windows::Forms::HScrollBar^ hScrollBar9;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::TextBox^ textBox29;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::TextBox^ textBox30;
	private: System::Windows::Forms::TextBox^ textBox31;
	private: System::Windows::Forms::TextBox^ textBox32;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		Scanner^ m_scanner;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar4 = (gcnew System::Windows::Forms::HScrollBar());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->vScrollBar2 = (gcnew System::Windows::Forms::VScrollBar());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBar5 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar6 = (gcnew System::Windows::Forms::HScrollBar());
			this->vScrollBar3 = (gcnew System::Windows::Forms::VScrollBar());
			this->vScrollBar4 = (gcnew System::Windows::Forms::VScrollBar());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBar7 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar8 = (gcnew System::Windows::Forms::HScrollBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar9 = (gcnew System::Windows::Forms::HScrollBar());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(181, 786);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 51);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Calculate T and S";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmSandTimages::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(28, 281);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 28);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Acquire Image";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmSandTimages::Button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::OrangeRed;
			this->button3->Location = System::Drawing::Point(28, 245);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 28);
			this->button3->TabIndex = 2;
			this->button3->Text = L"All Phases Off";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &frmSandTimages::Button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(28, 209);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(126, 28);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Connect to C4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmSandTimages::Button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(50, 545);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(108, 48);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Move Motor 1 Left";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmSandTimages::Button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(51, 601);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(108, 48);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Move Motor 1 Right";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &frmSandTimages::Button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(51, 657);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(108, 48);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Move Motor 2 Down";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &frmSandTimages::Button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(51, 713);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(108, 48);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Move Motor 2 Up";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &frmSandTimages::Button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(51, 769);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(108, 48);
			this->button9->TabIndex = 8;
			this->button9->Text = L"Acquire One Frame";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &frmSandTimages::Button9_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(493, 589);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(42, 22);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(555, 638);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(42, 22);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"0";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(493, 689);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(42, 22);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"0";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(434, 638);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(42, 22);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"0";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(494, 638);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(42, 22);
			this->textBox5->TabIndex = 13;
			this->textBox5->Text = L"0";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(475, 730);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(32, 22);
			this->textBox6->TabIndex = 14;
			this->textBox6->Text = L"320";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(531, 730);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(32, 22);
			this->textBox7->TabIndex = 15;
			this->textBox7->Text = L"120";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox7_TextChanged);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(564, 758);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(32, 22);
			this->textBox8->TabIndex = 16;
			this->textBox8->Text = L"480";
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox8_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(620, 758);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(32, 22);
			this->textBox9->TabIndex = 17;
			this->textBox9->Text = L"240";
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox9_TextChanged);
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(476, 786);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(32, 22);
			this->textBox10->TabIndex = 18;
			this->textBox10->Text = L"320";
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox10_TextChanged);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(531, 786);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(32, 22);
			this->textBox11->TabIndex = 19;
			this->textBox11->Text = L"360";
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox11_TextChanged);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(387, 758);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(32, 22);
			this->textBox12->TabIndex = 20;
			this->textBox12->Text = L"160";
			this->textBox12->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox12_TextChanged);
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(443, 758);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(32, 22);
			this->textBox13->TabIndex = 21;
			this->textBox13->Text = L"240";
			this->textBox13->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox13_TextChanged);
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(476, 758);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(32, 22);
			this->textBox14->TabIndex = 22;
			this->textBox14->Text = L"320";
			this->textBox14->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox14_TextChanged);
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(531, 758);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(32, 22);
			this->textBox15->TabIndex = 23;
			this->textBox15->Text = L"240";
			this->textBox15->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox15_TextChanged);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::WindowText;
			this->button10->Location = System::Drawing::Point(507, 730);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(24, 23);
			this->button10->TabIndex = 24;
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &frmSandTimages::Button10_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::WindowText;
			this->button11->Location = System::Drawing::Point(596, 758);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(24, 23);
			this->button11->TabIndex = 25;
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &frmSandTimages::Button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::SystemColors::WindowText;
			this->button12->Location = System::Drawing::Point(507, 786);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(24, 23);
			this->button12->TabIndex = 26;
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &frmSandTimages::Button12_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::SystemColors::WindowText;
			this->button13->Location = System::Drawing::Point(419, 757);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(27, 23);
			this->button13->TabIndex = 27;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &frmSandTimages::Button13_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::SystemColors::WindowText;
			this->button14->Location = System::Drawing::Point(507, 758);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(24, 23);
			this->button14->TabIndex = 28;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &frmSandTimages::Button14_Click);
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(705, 564);
			this->textBox16->Name = L"textBox16";
			this->textBox16->ReadOnly = true;
			this->textBox16->Size = System::Drawing::Size(65, 22);
			this->textBox16->TabIndex = 29;
			this->textBox16->Text = L"0";
			this->textBox16->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox16_TextChanged);
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(705, 589);
			this->textBox17->Name = L"textBox17";
			this->textBox17->ReadOnly = true;
			this->textBox17->Size = System::Drawing::Size(65, 22);
			this->textBox17->TabIndex = 30;
			this->textBox17->Text = L"NA";
			this->textBox17->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox17_TextChanged);
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(705, 614);
			this->textBox18->Name = L"textBox18";
			this->textBox18->ReadOnly = true;
			this->textBox18->Size = System::Drawing::Size(65, 22);
			this->textBox18->TabIndex = 31;
			this->textBox18->Text = L"NA";
			this->textBox18->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox18_TextChanged);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(211, 641);
			this->hScrollBar1->Maximum = 257;
			this->hScrollBar1->Minimum = 1;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(100, 20);
			this->hScrollBar1->TabIndex = 32;
			this->hScrollBar1->Value = 1;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar1_Scroll);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(370, 60);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 480);
			this->pictureBox1->TabIndex = 33;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &frmSandTimages::PictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Location = System::Drawing::Point(1094, 33);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(250, 250);
			this->pictureBox2->TabIndex = 34;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &frmSandTimages::PictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox3->Location = System::Drawing::Point(1094, 306);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(250, 250);
			this->pictureBox3->TabIndex = 35;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &frmSandTimages::PictureBox3_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox4->Location = System::Drawing::Point(1094, 583);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(250, 250);
			this->pictureBox4->TabIndex = 36;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &frmSandTimages::PictureBox4_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox5->Location = System::Drawing::Point(897, 431);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(84, 84);
			this->pictureBox5->TabIndex = 37;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &frmSandTimages::PictureBox5_Click);
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->Location = System::Drawing::Point(211, 749);
			this->hScrollBar2->Maximum = 649;
			this->hScrollBar2->Minimum = 1;
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Size = System::Drawing::Size(100, 20);
			this->hScrollBar2->TabIndex = 38;
			this->hScrollBar2->Value = 1;
			this->hScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar2_Scroll);
			// 
			// hScrollBar3
			// 
			this->hScrollBar3->Location = System::Drawing::Point(695, 730);
			this->hScrollBar3->Maximum = 209;
			this->hScrollBar3->Minimum = 5;
			this->hScrollBar3->Name = L"hScrollBar3";
			this->hScrollBar3->Size = System::Drawing::Size(100, 20);
			this->hScrollBar3->TabIndex = 39;
			this->hScrollBar3->Value = 5;
			this->hScrollBar3->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar3_Scroll);
			// 
			// hScrollBar4
			// 
			this->hScrollBar4->Location = System::Drawing::Point(886, 713);
			this->hScrollBar4->Maximum = 257;
			this->hScrollBar4->Minimum = 4;
			this->hScrollBar4->Name = L"hScrollBar4";
			this->hScrollBar4->Size = System::Drawing::Size(100, 20);
			this->hScrollBar4->TabIndex = 40;
			this->hScrollBar4->Value = 4;
			this->hScrollBar4->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar4_Scroll);
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Location = System::Drawing::Point(191, 561);
			this->vScrollBar1->Maximum = 257;
			this->vScrollBar1->Minimum = 1;
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(20, 100);
			this->vScrollBar1->TabIndex = 41;
			this->vScrollBar1->Value = 248;
			this->vScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::VScrollBar1_Scroll);
			// 
			// vScrollBar2
			// 
			this->vScrollBar2->Location = System::Drawing::Point(191, 669);
			this->vScrollBar2->Maximum = 489;
			this->vScrollBar2->Minimum = 1;
			this->vScrollBar2->Name = L"vScrollBar2";
			this->vScrollBar2->Size = System::Drawing::Size(20, 100);
			this->vScrollBar2->TabIndex = 42;
			this->vScrollBar2->Value = 480;
			this->vScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::VScrollBar2_Scroll);
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(237, 715);
			this->textBox19->Name = L"textBox19";
			this->textBox19->ReadOnly = true;
			this->textBox19->Size = System::Drawing::Size(34, 22);
			this->textBox19->TabIndex = 43;
			this->textBox19->Text = L"1";
			this->textBox19->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox19_TextChanged);
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(277, 715);
			this->textBox20->Name = L"textBox20";
			this->textBox20->ReadOnly = true;
			this->textBox20->Size = System::Drawing::Size(34, 22);
			this->textBox20->TabIndex = 44;
			this->textBox20->Text = L"1";
			this->textBox20->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox20_TextChanged);
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(772, 769);
			this->textBox21->Name = L"textBox21";
			this->textBox21->ReadOnly = true;
			this->textBox21->Size = System::Drawing::Size(34, 22);
			this->textBox21->TabIndex = 45;
			this->textBox21->Text = L"1";
			this->textBox21->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox21_TextChanged);
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(772, 791);
			this->textBox22->Name = L"textBox22";
			this->textBox22->ReadOnly = true;
			this->textBox22->Size = System::Drawing::Size(34, 22);
			this->textBox22->TabIndex = 46;
			this->textBox22->Text = L"1";
			this->textBox22->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox22_TextChanged);
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(237, 604);
			this->textBox23->Name = L"textBox23";
			this->textBox23->ReadOnly = true;
			this->textBox23->Size = System::Drawing::Size(34, 22);
			this->textBox23->TabIndex = 47;
			this->textBox23->Text = L"1";
			this->textBox23->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox23_TextChanged);
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(277, 604);
			this->textBox24->Name = L"textBox24";
			this->textBox24->ReadOnly = true;
			this->textBox24->Size = System::Drawing::Size(34, 22);
			this->textBox24->TabIndex = 48;
			this->textBox24->Text = L"1";
			this->textBox24->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox24_TextChanged);
			// 
			// hScrollBar5
			// 
			this->hScrollBar5->Location = System::Drawing::Point(669, 769);
			this->hScrollBar5->Maximum = 249;
			this->hScrollBar5->Minimum = 1;
			this->hScrollBar5->Name = L"hScrollBar5";
			this->hScrollBar5->Size = System::Drawing::Size(100, 20);
			this->hScrollBar5->TabIndex = 49;
			this->hScrollBar5->Value = 1;
			this->hScrollBar5->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar5_Scroll);
			// 
			// hScrollBar6
			// 
			this->hScrollBar6->Location = System::Drawing::Point(669, 791);
			this->hScrollBar6->Maximum = 249;
			this->hScrollBar6->Minimum = 1;
			this->hScrollBar6->Name = L"hScrollBar6";
			this->hScrollBar6->Size = System::Drawing::Size(100, 20);
			this->hScrollBar6->TabIndex = 50;
			this->hScrollBar6->Value = 1;
			this->hScrollBar6->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar6_Scroll);
			// 
			// vScrollBar3
			// 
			this->vScrollBar3->Location = System::Drawing::Point(675, 652);
			this->vScrollBar3->Maximum = 209;
			this->vScrollBar3->Minimum = 5;
			this->vScrollBar3->Name = L"vScrollBar3";
			this->vScrollBar3->Size = System::Drawing::Size(20, 100);
			this->vScrollBar3->TabIndex = 51;
			this->vScrollBar3->Value = 200;
			this->vScrollBar3->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::VScrollBar3_Scroll);
			// 
			// vScrollBar4
			// 
			this->vScrollBar4->Location = System::Drawing::Point(866, 633);
			this->vScrollBar4->Maximum = 257;
			this->vScrollBar4->Minimum = 4;
			this->vScrollBar4->Name = L"vScrollBar4";
			this->vScrollBar4->Size = System::Drawing::Size(20, 100);
			this->vScrollBar4->TabIndex = 52;
			this->vScrollBar4->TabStop = true;
			this->vScrollBar4->Value = 248;
			this->vScrollBar4->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::VScrollBar4_Scroll);
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(706, 695);
			this->textBox25->Name = L"textBox25";
			this->textBox25->ReadOnly = true;
			this->textBox25->Size = System::Drawing::Size(34, 22);
			this->textBox25->TabIndex = 53;
			this->textBox25->Text = L"5";
			this->textBox25->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox25_TextChanged);
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(746, 695);
			this->textBox26->Name = L"textBox26";
			this->textBox26->ReadOnly = true;
			this->textBox26->Size = System::Drawing::Size(34, 22);
			this->textBox26->TabIndex = 54;
			this->textBox26->Text = L"5";
			this->textBox26->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox26_TextChanged);
			// 
			// textBox27
			// 
			this->textBox27->Location = System::Drawing::Point(897, 679);
			this->textBox27->Name = L"textBox27";
			this->textBox27->ReadOnly = true;
			this->textBox27->Size = System::Drawing::Size(34, 22);
			this->textBox27->TabIndex = 55;
			this->textBox27->Text = L"4";
			this->textBox27->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox27_TextChanged);
			// 
			// textBox28
			// 
			this->textBox28->Location = System::Drawing::Point(937, 679);
			this->textBox28->Name = L"textBox28";
			this->textBox28->ReadOnly = true;
			this->textBox28->Size = System::Drawing::Size(33, 22);
			this->textBox28->TabIndex = 56;
			this->textBox28->Text = L"4";
			this->textBox28->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox28_TextChanged);
			// 
			// hScrollBar7
			// 
			this->hScrollBar7->Location = System::Drawing::Point(32, 382);
			this->hScrollBar7->Maximum = 159;
			this->hScrollBar7->Minimum = 1;
			this->hScrollBar7->Name = L"hScrollBar7";
			this->hScrollBar7->Size = System::Drawing::Size(100, 20);
			this->hScrollBar7->TabIndex = 57;
			this->hScrollBar7->Value = 1;
			this->hScrollBar7->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar7_Scroll);
			// 
			// hScrollBar8
			// 
			this->hScrollBar8->Location = System::Drawing::Point(32, 431);
			this->hScrollBar8->Maximum = 1509;
			this->hScrollBar8->Minimum = 1;
			this->hScrollBar8->Name = L"hScrollBar8";
			this->hScrollBar8->Size = System::Drawing::Size(100, 20);
			this->hScrollBar8->TabIndex = 58;
			this->hScrollBar8->Value = 500;
			this->hScrollBar8->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar8_Scroll);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(491, 560);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 26);
			this->label1->TabIndex = 59;
			this->label1->Text = L"S_top";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(555, 614);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 23);
			this->label2->TabIndex = 60;
			this->label2->Text = L"S_right";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(491, 663);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 23);
			this->label3->TabIndex = 61;
			this->label3->Text = L"S_bottom";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(434, 614);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 21);
			this->label4->TabIndex = 62;
			this->label4->Text = L"S_left";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(494, 614);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 23);
			this->label5->TabIndex = 63;
			this->label5->Text = L"T_ij";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(681, 567);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 23);
			this->label6->TabIndex = 64;
			this->label6->Text = L"R";
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(681, 592);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 23);
			this->label7->TabIndex = 65;
			this->label7->Text = L"G";
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(682, 616);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 23);
			this->label8->TabIndex = 66;
			this->label8->Text = L"B";
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(247, 561);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(88, 23);
			this->label9->TabIndex = 67;
			this->label9->Text = L"OBSOLETE";
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(252, 583);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 18);
			this->label10->TabIndex = 68;
			this->label10->Text = L"i";
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(291, 583);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(11, 18);
			this->label11->TabIndex = 69;
			this->label11->Text = L"j";
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(246, 669);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(89, 22);
			this->label12->TabIndex = 70;
			this->label12->Text = L"OBSOLETE";
			// 
			// label13
			// 
			this->label13->Location = System::Drawing::Point(248, 689);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(12, 19);
			this->label13->TabIndex = 71;
			this->label13->Text = L"x";
			// 
			// label14
			// 
			this->label14->Location = System::Drawing::Point(288, 689);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(12, 19);
			this->label14->TabIndex = 72;
			this->label14->Text = L"y";
			// 
			// label15
			// 
			this->label15->Location = System::Drawing::Point(813, 771);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(26, 22);
			this->label15->TabIndex = 73;
			this->label15->Text = L"dT";
			// 
			// label16
			// 
			this->label16->Location = System::Drawing::Point(812, 796);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(36, 21);
			this->label16->TabIndex = 74;
			this->label16->Text = L"dS";
			// 
			// label17
			// 
			this->label17->Location = System::Drawing::Point(894, 638);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(92, 38);
			this->label17->TabIndex = 75;
			this->label17->Text = L"Horiz-Vert Image Size";
			// 
			// label18
			// 
			this->label18->Location = System::Drawing::Point(713, 652);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(57, 22);
			this->label18->TabIndex = 76;
			this->label18->Text = L"Vectors";
			// 
			// label19
			// 
			this->label19->Location = System::Drawing::Point(703, 674);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(41, 18);
			this->label19->TabIndex = 77;
			this->label19->Text = L"Horiz";
			// 
			// label20
			// 
			this->label20->Location = System::Drawing::Point(746, 674);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(34, 18);
			this->label20->TabIndex = 78;
			this->label20->Text = L"Vert";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(32, 85);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 79;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmSandTimages::ComboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"9600", L"1200", L"2400", L"4800", L"19200", L"38400",
					L"57600", L"115200"
			});
			this->comboBox2->Location = System::Drawing::Point(31, 145);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 80;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &frmSandTimages::ComboBox2_SelectedIndexChanged);
			// 
			// label21
			// 
			this->label21->Location = System::Drawing::Point(29, 115);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(165, 24);
			this->label21->TabIndex = 81;
			this->label21->Text = L"C4 Controller COM Port";
			// 
			// label22
			// 
			this->label22->Location = System::Drawing::Point(28, 172);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(172, 23);
			this->label22->TabIndex = 82;
			this->label22->Text = L"Baud Rate (Default 9600)";
			// 
			// textBox29
			// 
			this->textBox29->Location = System::Drawing::Point(28, 34);
			this->textBox29->Name = L"textBox29";
			this->textBox29->ReadOnly = true;
			this->textBox29->Size = System::Drawing::Size(217, 22);
			this->textBox29->TabIndex = 83;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(29, 60);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(48, 17);
			this->label23->TabIndex = 84;
			this->label23->Text = L"Status";
			// 
			// textBox30
			// 
			this->textBox30->Location = System::Drawing::Point(136, 380);
			this->textBox30->Name = L"textBox30";
			this->textBox30->ReadOnly = true;
			this->textBox30->Size = System::Drawing::Size(54, 22);
			this->textBox30->TabIndex = 85;
			this->textBox30->Text = L"1";
			this->textBox30->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox30_TextChanged);
			// 
			// textBox31
			// 
			this->textBox31->Location = System::Drawing::Point(136, 432);
			this->textBox31->Name = L"textBox31";
			this->textBox31->ReadOnly = true;
			this->textBox31->Size = System::Drawing::Size(54, 22);
			this->textBox31->TabIndex = 86;
			this->textBox31->Text = L"500";
			this->textBox31->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox31_TextChanged);
			// 
			// label24
			// 
			this->label24->Location = System::Drawing::Point(38, 359);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(95, 23);
			this->label24->TabIndex = 87;
			this->label24->Text = L"Frame Delay";
			// 
			// label25
			// 
			this->label25->Location = System::Drawing::Point(38, 408);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(104, 23);
			this->label25->TabIndex = 88;
			this->label25->Text = L"Read Timeout";
			// 
			// hScrollBar9
			// 
			this->hScrollBar9->Location = System::Drawing::Point(32, 479);
			this->hScrollBar9->Maximum = 1509;
			this->hScrollBar9->Minimum = 1;
			this->hScrollBar9->Name = L"hScrollBar9";
			this->hScrollBar9->Size = System::Drawing::Size(99, 18);
			this->hScrollBar9->TabIndex = 89;
			this->hScrollBar9->Value = 500;
			this->hScrollBar9->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &frmSandTimages::HScrollBar9_Scroll);
			// 
			// textBox32
			// 
			this->textBox32->Location = System::Drawing::Point(136, 482);
			this->textBox32->Name = L"textBox32";
			this->textBox32->ReadOnly = true;
			this->textBox32->Size = System::Drawing::Size(54, 22);
			this->textBox32->TabIndex = 90;
			this->textBox32->Text = L"500";
			this->textBox32->TextChanged += gcnew System::EventHandler(this, &frmSandTimages::TextBox32_TextChanged);
			// 
			// label26
			// 
			this->label26->Location = System::Drawing::Point(38, 456);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(104, 23);
			this->label26->TabIndex = 91;
			this->label26->Text = L"Write Timeout";
			// 
			// label27
			// 
			this->label27->Location = System::Drawing::Point(370, 34);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(117, 23);
			this->label27->TabIndex = 92;
			this->label27->Text = L"Current Frame";
			// 
			// label28
			// 
			this->label28->Location = System::Drawing::Point(1091, 7);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(139, 23);
			this->label28->TabIndex = 93;
			this->label28->Text = L"Image (Transmitted)";
			// 
			// label29
			// 
			this->label29->Location = System::Drawing::Point(1091, 284);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(139, 23);
			this->label29->TabIndex = 94;
			this->label29->Text = L"Image (Scattered)";
			// 
			// label30
			// 
			this->label30->Location = System::Drawing::Point(1091, 559);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(100, 23);
			this->label30->TabIndex = 95;
			this->label30->Text = L"Image (Core)";
			// 
			// frmSandTimages
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1378, 849);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->textBox32);
			this->Controls->Add(this->hScrollBar9);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->textBox31);
			this->Controls->Add(this->textBox30);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->textBox29);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->hScrollBar8);
			this->Controls->Add(this->hScrollBar7);
			this->Controls->Add(this->textBox28);
			this->Controls->Add(this->textBox27);
			this->Controls->Add(this->textBox26);
			this->Controls->Add(this->textBox25);
			this->Controls->Add(this->vScrollBar4);
			this->Controls->Add(this->vScrollBar3);
			this->Controls->Add(this->hScrollBar6);
			this->Controls->Add(this->hScrollBar5);
			this->Controls->Add(this->textBox24);
			this->Controls->Add(this->textBox23);
			this->Controls->Add(this->textBox22);
			this->Controls->Add(this->textBox21);
			this->Controls->Add(this->textBox20);
			this->Controls->Add(this->textBox19);
			this->Controls->Add(this->vScrollBar2);
			this->Controls->Add(this->vScrollBar1);
			this->Controls->Add(this->hScrollBar4);
			this->Controls->Add(this->hScrollBar3);
			this->Controls->Add(this->hScrollBar2);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->textBox18);
			this->Controls->Add(this->textBox17);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmSandTimages";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"frmSandTimages";
			this->Load += gcnew System::EventHandler(this, &frmSandTimages::FrmSandTimages_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmSandTimages_Load(System::Object^ sender, System::EventArgs^ e) {}


//Calculate T and S (ORIGINAL WON'T WORK; USE THE SCANNER FUNCTION EQUIVALENT) (OBSOLETE; UPDATE TO USE CORE LATER; USED FOR TESTING RIGHT NOW)
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*
	'Note that this sub will no longer work because the objects called don't
		'   even exist, e.g., HSRingFrame, txtCoreij
		Dim x As Integer, y As Integer, dT As Integer, dS As Integer, Ring As Integer

		x = HSXcoordinate.Value
		y = VSYcoordinate.Value
		dT = HSTransmFrame.Value
		Ring = HSRingFrame.Value
		dS = HSScattFrame.Value

		Call CalcTandS(RedPic, x, y, dT, dS, Ring, Tij, Sij, Coreij)

		//txtSij.Text = Sij
		//txtCoreij.Text = Coreij
		txtTij.Text = Tij
	*/
	this->textBox29->Text = "Running Bitmap Test";
	m_scanner->acquireDisplayFrame();
	m_scanner->writeSquareT();
	m_scanner->writeAllSquareS();
	m_scanner->acquireFrameCenter();
	loadDisplayFrame();
	loadFrameCenter();
	loadImageT();
	loadImageS();
	this->textBox29->Text = "Bitmap Test Complete";
}



//Acquire Image
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->textBox29->Text = "Acquiring Image";
	m_scanner->acquireImageTandS();
	this->textBox29->Text = "Acquiring Image Complete";



	/*
	Dim Red As Integer, Green As Integer, Blue As Integer
	Dim Time1, Time2 As Long
	Dim I As Integer, J As Integer
	Dim IMAX As Integer, JMAX As Integer
	Dim ILong As Long, JLong As Long
	Dim ImageILong As Long, ImageJLong As Long
	Dim SAi As Integer, SAj As Integer
	Dim x, y As Integer
	Dim x1, y1, x2, y2 As Integer
	Dim xLong As Long, yLong As Long
	Dim xSingle, ySingle, RadiusSingle As Single
	Dim dT, dS As Integer
	Dim Marker As Integer
	Dim NS As Integer
	Dim NC As Integer
	Dim NCycles As Integer
	Dim IMAXdiv4 As Integer
	Dim Int1 As Integer, Int2 As Integer
	Dim Byte1 As Byte, Byte2 As Byte
	Dim Msg As String
	Dim CR As Long, LF As Long
	Dim CRLF As String
	CRLF = Chr$(13) + Chr$(10)
	SQRside = 21
	dSide = (SQRside - 1) / 2
	Time1 = HSTime1.Value
	Time2 = HSTime2.Value
	For I = 1 To 249
	  For J = 1 To 249
		xLong = I
		yLong = J
		EBW8Image1.SetPixel xLong, yLong, 255
		EBW8Image2.SetPixel xLong, yLong, 255
		EBW8Image3.SetPixel xLong, yLong, 255
		Next J
	Next I
	EBW8Image1.Refresh
	EBW8Image2.Refresh
	EBW8Image3.Refresh
	ECameraPicolo1.Grab
	Call WasteTime(Time1, Time2)
	ECameraPicolo2.Grab
	Const FramedX = 20
	Const FramedY = 20
	ECameraPicolo2.ImageOffsetX = HSXcoordinate.Value - FramedX
	ECameraPicolo2.ImageOffsetY = VSYcoordinate.Value - FramedY
	x = HSXcoordinate.Value
	y = VSYcoordinate.Value
	dT = HSTransmFrame.Value
	dS = HSScattFrame.Value
	x1 = x - dS - 5
	y1 = y - dS - 5
	x2 = x + dS + 5
	y2 = y + dS + 5
	xLong = x
	yLong = y
	ImageI = 0
	ImageJ = 0
	IMAX = HSImageI.Value
	JMAX = VSImageJ.Value
	NCycles = 4
	Call TurnMD2off
	Call TurnMD2on
	Time2 = 6 * HSTime2.Value
	Call MoveMotor18f(NC, Time1, Time2)
	Call MoveMotor18f(NC, Time1, Time2)
	Call WasteTime(Time1, Time2)
	Call MoveMotor18b(NC, Time1, Time2)
	Call MoveMotor18b(NC, Time1, Time2)
	Msg$ = "will start acquiring picture"
	MsgBox Msg$
	NC = 5
	For I = 1 To 5: Call MoveMotor28f(NCycles, Time1, Time2): Next I
	For ImageI = 1 To IMAX  'IMAX is the max number of horizontal points for image
	ImageILong = ImageI   'long form needed to write on image EBW8
	For I = 1 To 5: Call MoveMotor28b(NCycles, Time1, Time2): Next I
	  If x <> HSXcoordinate.Value Or y <> VSYcoordinate.Value _
			Or dT <> HSTransmFrame.Value Or dS <> HSScattFrame.Value Then
		x = HSXcoordinate.Value
		y = VSYcoordinate.Value
		dT = HSTransmFrame.Value
		dS = HSScattFrame.Value
		x1 = x - dS - 5
		y1 = y - dS - 5
		x2 = x + dS + 5
		y2 = y + dS + 5
		xLong = x
		yLong = y
	  End If
	For ImageJ = 1 To JMAX
		ImageJLong = ImageJ
		Call MoveMotor28b(NCycles, Time1, Time2)
		ECameraPicolo1.Grab
		Call WasteTime(Time1, Time2)
		ECameraPicolo2.Grab
		EC24Image1.Refresh
		EC24Image2.Refresh
		SAi = 0
		SAj = 0
		For J = YCenter - dSide To YCenter + dSide
		  JLong = J
		  SAj = SAj + 1
			For I = XCenter - dSide To XCenter + dSide
			  ILong = I
			  SAi = SAi + 1
			  EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			  SmallArea(SAi, SAj) = Red
			Next I
			SAi = 0
		Next J
		Call WriteSquareT(EC24Image1, XCenter, YCenter, dT)
		Call CalcOnePointImage(SmallArea, dSide, dT, Tij)
		txtTij.Text = Tij
		Tij = Tij
		Tr(ImageI, ImageJ) = Tij
		Int1 = Tij
		EBW8Image1.SetPixel ImageILong, ImageJLong, Int1
		SAi = 0
		SAj = 0
		XTopDiag = XTop + 0.707 * HShorizontalVector.Value
		YTopDiag = YTop + (1 - 0.707) * VSverticalVector.Value
		For J = YTopDiag - dSide To YTopDiag + dSide
		  JLong = J
		  SAj = SAj + 1
			For I = XTopDiag - dSide To XTopDiag + dSide
			  ILong = I
			  SAi = SAi + 1
			  EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			  SmallArea(SAi, SAj) = Red
			Next I
			SAi = 0
		Next J

		Call WriteSquareT(EC24Image1, XTopDiag, YTopDiag, dS)
		Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
		txtScTop.Text = Sij
		Sij = Sij
		ScTop(ImageI, ImageJ) = Sij
		Int1 = Sij
		SAi = 0
		SAj = 0
		For J = YBottom - dSide To YBottom + dSide
		  JLong = J
		  SAj = SAj + 1
			For I = XBottom - dSide To XBottom + dSide
			ILong = I
			  SAi = SAi + 1
			  EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			  SmallArea(SAi, SAj) = Red
			Next I
			SAi = 0
		Next J
		Call WriteSquareT(EC24Image1, XBottom, YBottom, dS)
		Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
		txtScBottom.Text = Sij
		Sij = Sij
		ScBottom(ImageI, ImageJ) = Sij
		Sc(ImageI, ImageJ) = Sij
		Int1 = Sij
		EBW8Image3.SetPixel ImageILong, ImageJLong, Int1
		SAi = 0
		SAj = 0
		For J = YLeft - dSide To YLeft + dSide
		  JLong = J
		  SAj = SAj + 1
			For I = XLeft - dSide To XLeft + dSide
			  ILong = I
			  SAi = SAi + 1
			  EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			  SmallArea(SAi, SAj) = Red
			Next I
			SAi = 0
		Next J
		Call WriteSquareT(EC24Image1, XLeft, YLeft, dS)
		Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
		txtScLeft.Text = Sij
		Sij = Sij
		ScLeft(ImageI, ImageJ) = Sij
		Sc(ImageI, ImageJ) = Sc(ImageI, ImageJ) + Sij
		Int1 = Sij
		SAi = 0
		SAj = 0
		For J = YRight - dSide To YRight + dSide
		  JLong = J
		  SAj = SAj + 1
			For I = XRight - dSide To XRight + dSide
			  ILong = I
			  SAi = SAi + 1
			  EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			  SmallArea(SAi, SAj) = Red
			Next I
			SAi = 0
		Next J
		Call WriteSquareT(EC24Image1, XRight, YRight, dS)
		Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
		txtScRight.Text = Sij
		Sij = Sij
		ScRight(ImageI, ImageJ) = Sij
		Sc(ImageI, ImageJ) = Sc(ImageI, ImageJ) + Sij
		Sc(ImageI, ImageJ) = Sc(ImageI, ImageJ) / 3
		Int1 = Sc(ImageI, ImageJ)
		EBW8Image2.SetPixel ImageILong, ImageJLong, Int1
		Int1 = Sij
		Call PutTickMarkOnImage(EC24Image1)
		ECameraPicolo2.Grab
		EC24Image1.Refresh
		EC24Image2.Refresh
		EC24Image1.GetPixel xLong, yLong, Red, Green, Blue
		txtRed.Text = Red
		txtGreen.Text = Green
		txtBlue.Text = Blue
		txtImageI.Text = ImageI
		txtImageJ.Text = ImageJ
		frmSandTimages.Refresh
		Call WasteTime(Time1, Time2)
		EBW8Image1.Refresh
		EBW8Image2.Refresh
		EBW8Image3.Refresh
		Red = Red
		Next ImageJ
		NCycles = NCycles + 1
		  If NCycles >= 5 Then NCycles = 1
		  T1 = 3 * Time1
		  Call MoveMotor12b(NCycles, T1, Time2)
		  NC = JMAX + 5
		  For I = 1 To JMAX + 5: Call MoveMotor28f(NCycles, Time1, Time2): Next I
		  NC = 1
	Next ImageI
	IMAXdiv4 = IMAX / 4
	For I = 1 To IMAXdiv4: Call MoveMotor18f(IMAX, Time1, Time2): Next I
	NCycles = 1
	For I = 1 To 5: Call MoveMotor28b(NCycles, Time1, Time2): Next I
	Call TurnMD2off
	MatrixStringTr = ""
	MatrixStringSc = ""
	MatrixStringScTop = ""
	MatrixStringScBottom = ""
	MatrixStringScLeft = ""
	MatrixStringScRight = ""
	For ImageJ = 1 To JMAX  'JMAX is the max number of vertical (y) points for image
	For ImageI = 1 To IMAX
		MatrixStringTr = MatrixStringTr & LTrim(Str(Tr(ImageI, ImageJ)))
		MatrixStringSc = MatrixStringSc & LTrim(Str(Sc(ImageI, ImageJ)))
		MatrixStringScTop = MatrixStringScTop & LTrim(Str(ScTop(ImageI, ImageJ)))
		MatrixStringScBottom = MatrixStringScBottom & LTrim(Str(ScBottom(ImageI, ImageJ)))
		MatrixStringScLeft = MatrixStringScLeft & LTrim(Str(ScLeft(ImageI, ImageJ)))
		MatrixStringScRight = MatrixStringScRight & LTrim(Str(ScRight(ImageI, ImageJ)))
		If ImageI < IMAX Then MatrixStringTr = MatrixStringTr & " " Else If ImageJ < JMAX Then MatrixStringTr = MatrixStringTr & CRLF
		If ImageI < IMAX Then MatrixStringSc = MatrixStringSc & " " Else If ImageJ < JMAX Then MatrixStringSc = MatrixStringSc & CRLF
		If ImageI < IMAX Then MatrixStringScTop = MatrixStringScTop & " " Else If ImageJ < JMAX Then MatrixStringScTop = MatrixStringScTop & CRLF
		If ImageI < IMAX Then MatrixStringScBottom = MatrixStringScBottom & " " Else If ImageJ < JMAX Then MatrixStringScBottom = MatrixStringScBottom & CRLF
		If ImageI < IMAX Then MatrixStringScLeft = MatrixStringScLeft & " " Else If ImageJ < JMAX Then MatrixStringScLeft = MatrixStringScLeft & CRLF
		If ImageI < IMAX Then MatrixStringScRight = MatrixStringScRight & " " Else If ImageJ < JMAX Then MatrixStringScRight = MatrixStringScRight & CRLF
	Next ImageI
Next ImageJ
	*/
}



//All Phases Off (SEMAPHORE ADDED HERE)
private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	m_scanner->lockScan();
	if (m_scanner->motorIsOpen())
	{
		this->textBox29->Text = "Aborting Motion";
		m_scanner->motorAbortMotion();
		this->textBox29->Text = "Motion Aborted";
	}
	else
		this->textBox29->Text = "C4 Controller Is Not Connected";
	m_scanner->unlockScan();
}



//Connect to C4
private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((this->comboBox1->Text != String::Empty) && (this->comboBox2->Text != String::Empty))
	{
		Boolean status = m_scanner->motorInitPort(this->comboBox1->Text, this->comboBox2->Text);
		if (status && m_scanner->motorIsOpen())
		{
			m_scanner->unlockScan();
			this->textBox29->Text = "C4 Controller Ready";
		}
		else
			this->textBox29->Text = "C4 Connection Failed";
	}
	else
		this->textBox29->Text = "Please Select C4 Configurations";
}



//Move Motor 1 Left
private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (m_scanner->motorIsOpen())
	{
		this->textBox29->Text = "Moving Motor 1 Left";
		if (m_scanner->motorMoveMotor(-8, 0))
			this->textBox29->Text = "Motor 1 Moved Left 8 Units";
		else
			this->textBox29->Text = "Motor 1 Move Left Failed";
	}
	else
		this->textBox29->Text = "C4 Controller Is Not Connected";
}



//Move Motor 1 Right
private: System::Void Button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (m_scanner->motorIsOpen())
	{
		this->textBox29->Text = "Moving Motor 1 Right";
		if (m_scanner->motorMoveMotor(8, 0))
			this->textBox29->Text = "Motor 1 Moved Right 8 Unit";
		else
			this->textBox29->Text = "Motor 1 Move Right Failed";
	}
	else
		this->textBox29->Text = "C4 Controller Is Not Connected";
}



//Move Motor 2 Down
private: System::Void Button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (m_scanner->motorIsOpen())
	{
		this->textBox29->Text = "Moving Motor 2 Down";
		if (m_scanner->motorMoveMotor(0, -8))
			this->textBox29->Text = "Motor 2 Moved Down 8 Unit";
		else
			this->textBox29->Text = "Motor 2 Move Down Failed";
	}
	else
		this->textBox29->Text = "C4 Controller Is Not Connected";
}



//Move Motor 2 Up
private: System::Void Button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (m_scanner->motorIsOpen())
	{
		this->textBox29->Text = "Moving Motor 2 Up";
		if (m_scanner->motorMoveMotor(0, 8))
			this->textBox29->Text = "Motor 2 Moved Up 8 Unit";
		else
			this->textBox29->Text = "Motor 2 Move Up Failed";
	}
	else
		this->textBox29->Text = "C4 Controller Is Not Connected";
}



//Acquire One Frame
private: System::Void Button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->textBox29->Text = "Acquiring Frame";
	m_scanner->acquireDisplayFrame();
	m_scanner->acquireFrameCenter();
	m_scanner->writeSquareT();
	m_scanner->writeAllSquareS();
	loadDisplayFrame();
	loadFrameCenter();
	loadRGB(m_scanner->calcTBoxAverage());
	loadBoxAverages(m_scanner->calcStBoxAverage(), m_scanner->calcSrBoxAverage(), m_scanner->calcSbBoxAverage(), m_scanner->calcSlBoxAverage(), m_scanner->calcTBoxAverage());
	this->textBox29->Text = "Finished Acquiring Frame";



	/*
	Dim Msg As String
	Dim Red As Integer, Green As Integer, Blue As Integer
	Dim Time1, Time2 As Long
	Dim T1, T2 As Long
	Dim I As Integer, J As Integer
	Dim ILong As Long, JLong As Long
	Dim x, y As Integer
	Dim SmallArea(1 To 40, 1 To 40) As Integer
	Dim SAi As Integer, SAj As Integer
	Dim x1, y1, x2, y2 As Integer
	Dim xLong As Long, yLong As Long
	Dim xSingle, ySingle, RadiusSingle As Single
	Dim dT, dS As Integer
	Dim Ring As Integer
	Dim Marker As Integer
	Dim NS As Integer
	SQRside = 21
	dSide = (SQRside - 1) / 2
	Const FramedX = 20  'Not allowed to just stick the constant onto instruction
	Const FramedY = 20
	ECameraPicolo2.ImageOffsetX = HSXcoordinate.Value - FramedX
	ECameraPicolo2.ImageOffsetY = VSYcoordinate.Value - FramedY
	x = HSXcoordinate.Value
	y = VSYcoordinate.Value
	dT = HSTransmFrame.Value
	dS = HSScattFrame.Value
	x1 = x - dS - 5
	y1 = y - dS - 5
	x2 = x + dS + 5
	y2 = y + dS + 5
	xLong = x
	yLong = y
	ImageI = 0
	ImageJ = 0
	NS = 1
	ECameraPicolo1.Grab
	Time1 = HSTime1.Value   'HSTime1 = 10,000 by default
	Time2 = 25 * HSTime2.Value   'HSTime2 = 1 by default
	Call WasteTime(Time1, Time2)
	ECameraPicolo2.Grab
	Time2 = 25 * HSTime2.Value
	Call WasteTime(Time1, Time2)
    Call WriteSquareT(EC24Image1, XCenter, YCenter, dT)
	Call PutTickMarkOnImage1(EC24Image1)
	xLong = XCenter
	yLong = YCenter
    EC24Image1.GetPixel xLong, yLong, Red, Green, Blue
	txtRed.Text = Red
	txtGreen.Text = Green
	txtBlue.Text = Blue
	EC24Image1.Refresh
	SAi = 0
	SAj = 0
	For J = YCenter - dSide To YCenter + dSide
		JLong = J
		SAj = SAj + 1
		For I = XCenter - dSide To XCenter + dSide
			ILong = I
			SAi = SAi + 1
			EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			SmallArea(SAi, SAj) = Red
		Next I
		SAi = 0
	Next J
	Call WriteSquareT(EC24Image1, XCenter, YCenter, dT)
	Call CalcOnePointImage(SmallArea, dSide, dT, Tij)
	txtTij.Text = Tij
	Tij = Tij
	SAi = 0
	SAj = 0
	For J = YLeft - dSide To YLeft + dSide
		JLong = J
		SAj = SAj + 1
		For I = XLeft - dSide To XLeft + dSide
			ILong = I
			SAi = SAi + 1
			EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			SmallArea(SAi, SAj) = Red
		Next I
		SAi = 0
	Next J
	Call WriteSquareS(EC24Image1, XLeft, YLeft, dS)
	Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
	txtScLeft.Text = Sij
	Sij = Sij
    SAi = 0
	SAj = 0
	For J = YRight - dSide To YRight + dSide
		JLong = J
		SAj = SAj + 1
		For I = XRight - dSide To XRight + dSide
			ILong = I
			SAi = SAi + 1
			EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			SmallArea(SAi, SAj) = Red
		Next I
		SAi = 0
	Next J
	Call WriteSquareS(EC24Image1, XRight, YRight, dS)
	Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
	txtScRight.Text = Sij
	Sij = Sij
    SAi = 0
	SAj = 0
	XTopDiag = XTop + 0.707 * HShorizontalVector.Value
	YTopDiag = YTop + (1 - 0.707) * VSverticalVector.Value
	XTopDiag = XTopDiag         'for debugging only
	For J = YTopDiag - dSide To YTopDiag + dSide
		JLong = J
		SAj = SAj + 1
		For I = XTopDiag - dSide To XTopDiag + dSide
			ILong = I
			SAi = SAi + 1
			EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			SmallArea(SAi, SAj) = Red
		Next I
		SAi = 0
	Next J
	Call WriteSquareS(EC24Image1, XTopDiag, YTopDiag, dS)
	Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
	txtScTop.Text = Sij
	Sij = Sij
    SAi = 0
	SAj = 0
	For J = YBottom - dSide To YBottom + dSide
		JLong = J
		SAj = SAj + 1
		For I = XBottom - dSide To XBottom + dSide
			ILong = I
			SAi = SAi + 1
			EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			SmallArea(SAi, SAj) = Red
		Next I
		SAi = 0
	Next J
	Call WriteSquareS(EC24Image1, XBottom, YBottom, dS)
	Call CalcOnePointImage(SmallArea, dSide, dS, Sij)
	txtScBottom.Text = Sij
	Sij = Sij
    Call PutTickMarkOnImage(EC24Image1)
	ECameraPicolo2.Grab
	EC24Image1.Refresh
	EC24Image2.Refresh
	For J = y1 To y2
		JLong = J
		For I = x1 To x2
			ILong = I
			EC24Image1.GetPixel ILong, JLong, Red, Green, Blue
			RedPic(I, J) = Red
		Next I
	Next J
	*/
}



//xy Coordinates for who knows what
	//Load S_top
private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load S_right
private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load S_bottom
private: System::Void TextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load S_left
private: System::Void TextBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load Tij
private: System::Void TextBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {}



//xy S Coordinates?
	//xy Top
		//Load Top x Change
private: System::Void TextBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Top y Change
private: System::Void TextBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Top Coordinates
private: System::Void Button10_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		if (!m_scanner->setTopXY(Convert::ToInt32(textBox6->Text), Convert::ToInt32(textBox7->Text)))
		{
			Int32 x, y;
			m_scanner->getTopXY(x, y);
			textBox6->Text = x.ToString();
			textBox7->Text = y.ToString();
		}
	}
	catch (FormatException^)
	{
		Int32 x, y;
		m_scanner->getTopXY(x, y);
		textBox6->Text = x.ToString();
		textBox7->Text = y.ToString();
	}
	catch (OverflowException^)
	{
		Int32 x, y;
		m_scanner->getTopXY(x, y);
		textBox6->Text = x.ToString();
		textBox7->Text = y.ToString();
	}
}
	//xy Right
		//Load Right x Change
private: System::Void TextBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Right y Change
private: System::Void TextBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Right Coordinates
private: System::Void Button11_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		if (!m_scanner->setRightXY(Convert::ToInt32(textBox8->Text), Convert::ToInt32(textBox9->Text)))
		{
			Int32 x, y;
			m_scanner->getRightXY(x, y);
			textBox8->Text = x.ToString();
			textBox9->Text = y.ToString();
		}
	}
	catch (FormatException^)
	{
		Int32 x, y;
		m_scanner->getRightXY(x, y);
		textBox8->Text = x.ToString();
		textBox9->Text = y.ToString();
	}
	catch (OverflowException^)
	{
		Int32 x, y;
		m_scanner->getRightXY(x, y);
		textBox8->Text = x.ToString();
		textBox9->Text = y.ToString();
	}
}
	//xy Bottom
		//Load Bottom x Change
private: System::Void TextBox10_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Bottom y Change
private: System::Void TextBox11_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Bottom Coordinates
private: System::Void Button12_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		if (!m_scanner->setBottomXY(Convert::ToInt32(textBox10->Text), Convert::ToInt32(textBox11->Text)))
		{
			Int32 x, y;
			m_scanner->getBottomXY(x, y);
			textBox10->Text = x.ToString();
			textBox11->Text = y.ToString();
		}
	}
	catch (FormatException^)
	{
		Int32 x, y;
		m_scanner->getBottomXY(x, y);
		textBox10->Text = x.ToString();
		textBox11->Text = y.ToString();
	}
	catch (OverflowException^)
	{
		Int32 x, y;
		m_scanner->getBottomXY(x, y);
		textBox10->Text = x.ToString();
		textBox11->Text = y.ToString();
	}
}
	//xy Left
		//Load Left x Change
private: System::Void TextBox12_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Left y Change
private: System::Void TextBox13_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Left Coordinates
private: System::Void Button13_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		if (!m_scanner->setLeftXY(Convert::ToInt32(textBox12->Text), Convert::ToInt32(textBox13->Text)))
		{
			Int32 x, y;
			m_scanner->getLeftXY(x, y);
			textBox12->Text = x.ToString();
			textBox13->Text = y.ToString();
		}
	}
	catch (FormatException^)
	{
		Int32 x, y;
		m_scanner->getLeftXY(x, y);
		textBox12->Text = x.ToString();
		textBox13->Text = y.ToString();
	}
	catch (OverflowException^)
	{
		Int32 x, y;
		m_scanner->getLeftXY(x, y);
		textBox12->Text = x.ToString();
		textBox13->Text = y.ToString();
	}
}
	//xy Center
		//Load Center x Coordinates
private: System::Void TextBox14_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Center y Coordinates
private: System::Void TextBox15_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
		//Load Center Coordinates
private: System::Void Button14_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*
	Dim DeltaY As Integer
    Dim DeltaX As Integer
    DeltaY = VSverticalVector.Value
    DeltaX = HShorizontalVector.Value
    txtXCenter.Text = HSXcoordinate.Value
    txtYCenter.Text = VSYcoordinate.Value
    XCenter = HSXcoordinate.Value
    YCenter = VSYcoordinate.Value
    txtXTop.Text = HSXcoordinate.Value
    txtYTop.Text = VSYcoordinate.Value - DeltaY
    XTop = HSXcoordinate.Value
    YTop = VSYcoordinate.Value - DeltaY
    txtXBottom.Text = HSXcoordinate.Value
    txtYBottom.Text = VSYcoordinate.Value + DeltaY
    XBottom = HSXcoordinate.Value
    YBottom = VSYcoordinate.Value + DeltaY
    txtXLeft.Text = HSXcoordinate.Value - DeltaX
    txtYLeft.Text = VSYcoordinate.Value
    XLeft = HSXcoordinate.Value - DeltaX
    YLeft = VSYcoordinate.Value
    txtXRight.Text = HSXcoordinate.Value + DeltaX
    txtYRight.Text = VSYcoordinate.Value
    XRight = HSXcoordinate.Value + DeltaX
    YRight = VSYcoordinate.Value
	*/
	try
	{
		if (!m_scanner->setCenterXY(Convert::ToInt32(textBox14->Text), Convert::ToInt32(textBox15->Text)))
		{
			Int32 x, y;
			m_scanner->getCenterXY(x, y);
			textBox14->Text = x.ToString();
			textBox15->Text = y.ToString();
		}
	}
	catch (FormatException^)
	{
		Int32 x, y;
		m_scanner->getCenterXY(x, y);
		textBox14->Text = x.ToString();
		textBox15->Text = y.ToString();
	}
	catch (OverflowException^)
	{
		Int32 x, y;
		m_scanner->getCenterXY(x, y);
		textBox14->Text = x.ToString();
		textBox15->Text = y.ToString();
	}
}



//RGB (Obsolete?)
	//Load R Change
private: System::Void TextBox16_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load G Change
private: System::Void TextBox17_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load B Change
private: System::Void TextBox18_TextChanged(System::Object^ sender, System::EventArgs^ e) {}



//Current i and j
	//Load i change
private: System::Void TextBox23_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load j change
private: System::Void TextBox24_TextChanged(System::Object^ sender, System::EventArgs^ e) {}



//Current i and j (OBSOLETE; DELETE THIS)
	//i scrollbar
private: System::Void HScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	/*
	txtImageI.Text = HSI.Value
	ImageI = HSI.Value
	txtImageJ.Text = VSJ.Value
	ImageJ = VSJ.Value
	txtTij.Text = T(ImageI, ImageJ)
	'txtSij.Text = S(ImageI, ImageJ)
	'txtCoreij.Text = Core(ImageI, ImageJ)
	*/
	this->textBox23->Text = this->hScrollBar1->Value.ToString();
}
	//j scrollbar
private: System::Void VScrollBar1_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	/*
	txtImageI.Text = HSI.Value
	ImageI = HSI.Value
	txtImageJ.Text = VSJ.Value
	ImageJ = VSJ.Value
	txtTij.Text = T(ImageI, ImageJ)
	'txtSij.Text = S(ImageI, ImageJ)
	'txtCoreij.Text = Core(ImageI, ImageJ)
	*/
	this->textBox24->Text = ((this->vScrollBar1->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar1->Minimum) - this->vScrollBar1->Value).ToString();
}



//Set x and y Coordinates (OBSOLETE: XCenter and YCenter not in use; CenterX and CenterY in use) (FORGET ABOUT THIS; DELETE THIS)
	//Load x Change
private: System::Void TextBox19_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load y Change
private: System::Void TextBox20_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//x Coordinate Scrollbar
private: System::Void HScrollBar2_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	/*
	txtCenterX.Text = HSXcoordinate.Value
    txtRed.Text = RedPic(HSXcoordinate.Value, VSYcoordinate.Value)
    txtGreen.Text = GreenPic(HSXcoordinate.Value, VSYcoordinate.Value)
    txtBlue.Text = BluePic(HSXcoordinate.Value, VSYcoordinate.Value)
	*/
	this->textBox19->Text = this->hScrollBar2->Value.ToString();
}
	//y Coordinate Scrollbar
private: System::Void VScrollBar2_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	/*
	txtCenterY.Text = VSYcoordinate.Value
    txtRed.Text = RedPic(HSXcoordinate.Value, VSYcoordinate.Value)
    txtGreen.Text = GreenPic(HSXcoordinate.Value, VSYcoordinate.Value)
    txtBlue.Text = BluePic(HSXcoordinate.Value, VSYcoordinate.Value)
	*/
	this->textBox20->Text = ((this->vScrollBar2->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar2->Minimum) - this->vScrollBar2->Value).ToString();
}



//dT and dS
	//Load dT Change
private: System::Void TextBox21_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load dS Change
private: System::Void TextBox22_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//dT Scrollbar
private: System::Void HScrollBar5_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox21->Text = this->hScrollBar5->Value.ToString();
	m_scanner->setDT(this->hScrollBar5->Value);
}
	//dS Scrollbar
private: System::Void HScrollBar6_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox22->Text = this->hScrollBar6->Value.ToString();
	m_scanner->setDS(this->hScrollBar6->Value);
}



//Horizontal and Vertical Vectors
	//Load Horizontal Change
private: System::Void TextBox25_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load Vertical Change
private: System::Void TextBox26_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Horizontal Scrollbar
private: System::Void HScrollBar3_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox25->Text = this->hScrollBar3->Value.ToString();
	m_scanner->setTopDiag(this->hScrollBar3->Value, ((this->vScrollBar3->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar3->Minimum) - this->vScrollBar3->Value));
}
	//Vertical Scrollbar
private: System::Void VScrollBar3_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox26->Text = ((this->vScrollBar3->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar3->Minimum) - this->vScrollBar3->Value).ToString();
	m_scanner->setTopDiag(this->hScrollBar3->Value, ((this->vScrollBar3->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar3->Minimum) - this->vScrollBar3->Value));
}



//Image Size (Scanner Var Here)
	//Load Horizontal Image Size
private: System::Void TextBox27_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Load Vertical Image Size
private: System::Void TextBox28_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Horizontal Size Scrollbar
private: System::Void HScrollBar4_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox27->Text = this->hScrollBar4->Value.ToString();
	m_scanner->setImageSize(this->hScrollBar4->Value, ((this->vScrollBar4->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar4->Minimum) - this->vScrollBar4->Value));
}
	//Vertical Size Scrollbar
private: System::Void VScrollBar4_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox28->Text = ((this->vScrollBar4->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar4->Minimum) - this->vScrollBar4->Value).ToString();
	m_scanner->setImageSize(this->hScrollBar4->Value, ((this->vScrollBar4->Maximum - SCROLLBARMAXOFFSET + this->vScrollBar4->Minimum) - this->vScrollBar4->Value));
}



//Delay Values (Scanner Var Here)
	//Frame Grabber Delay
private: System::Void TextBox30_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Motor Serial Read Timeout
private: System::Void TextBox31_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Motor Serial Write Timeout
private: System::Void TextBox32_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	//Display Current Frame Grabber Delay
private: System::Void HScrollBar7_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox30->Text = this->hScrollBar7->Value.ToString();
	//m_scanner->fgSetDelay(this->hScrollBar7->Value);
}
	//Display Current Read Timeout
private: System::Void HScrollBar8_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox31->Text = this->hScrollBar8->Value.ToString();
	m_scanner->motorSetReadTimeout(this->hScrollBar8->Value);
}
	//Display Current Write Timeout
private: System::Void HScrollBar9_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e)
{
	this->textBox32->Text = this->hScrollBar9->Value.ToString();
	m_scanner->motorSetWriteTimeout(this->hScrollBar9->Value);
}



//C4 Motor Controller Configurations
	//C4 Motor Controller COM Port
private: System::Void ComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
	//C4 Motor Controller Baud Rate (default 9600)
private: System::Void ComboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}



//Picture Boxes
	//Current Frame (with boxes) (EC24Image1)
private: System::Void PictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {}
	//Current Frame (original) (EC24Image2)
private: System::Void PictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {}
	//R (EBW8Image1)
private: System::Void PictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {}
	//G (EBW8Image2)
private: System::Void PictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {}
	//B (EBW8Image3)
private: System::Void PictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {}

};
}

/*
TODO:
-textBox16 values represent brightness of aggregate frame (box T); aka brightness of the pixel to put in image T
-button2 (Aquire Image)
-button9 (Acquire One Frame)
*/