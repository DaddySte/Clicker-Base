#pragma once
#include "Loading.h"
#include "Clicker.h"
#pragma comment(lib, "winmm.lib")

namespace ClickerBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Riepilogo per GUIbase
	/// </summary>
	public ref class GUIBase : public System::Windows::Forms::Form
	{
	public:
		GUIBase(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		Point offset;
	private: Siticone::UI::WinForms::SiticoneButton^ Closer;
	private: Siticone::UI::WinForms::SiticoneButton^ Hider;
	private: System::ComponentModel::BackgroundWorker^ JitterThread;
	private: System::ComponentModel::BackgroundWorker^ ClickerThread;
	public:

	public:
		bool dragging;

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~GUIBase()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Siticone::UI::WinForms::SiticoneTrackBar^ CPSValue;
	private: Siticone::UI::WinForms::SiticoneLabel^ CPSCounter;
	private: Siticone::UI::WinForms::SiticoneCheckBox^ SmartMode;
	private: Siticone::UI::WinForms::SiticoneCheckBox^ ExtraRand;
	private: Siticone::UI::WinForms::SiticoneCheckBox^ Jitter;
	private: Siticone::UI::WinForms::SiticoneCheckBox^ Spike;
	private: Siticone::UI::WinForms::SiticoneCheckBox^ BlockHit;
	private: Siticone::UI::WinForms::SiticoneOSToggleSwith^ ONOFF;
	private: Siticone::UI::WinForms::SiticoneLabel^ status;

	private: Siticone::UI::WinForms::SiticoneTrackBar^ JitterValue;
	private: Siticone::UI::WinForms::SiticoneTrackBar^ BlockHitValue;

	private: Siticone::UI::WinForms::SiticoneTrackBar^ SpikeValue;

	private: Siticone::UI::WinForms::SiticoneLabel^ SpikeCounter;

	private: Siticone::UI::WinForms::SiticoneLabel^ BlockHitCounter;
	private: Siticone::UI::WinForms::SiticoneLabel^ JitterCounter;
	protected:


	private:
		/// <summary>
		/// Variabile di progettazione necessaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necessario per il supporto della finestra di progettazione. Non modificare
		/// il contenuto del metodo con l'editor di codice.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GUIBase::typeid));
			this->CPSValue = (gcnew Siticone::UI::WinForms::SiticoneTrackBar());
			this->CPSCounter = (gcnew Siticone::UI::WinForms::SiticoneLabel());
			this->SmartMode = (gcnew Siticone::UI::WinForms::SiticoneCheckBox());
			this->ExtraRand = (gcnew Siticone::UI::WinForms::SiticoneCheckBox());
			this->Jitter = (gcnew Siticone::UI::WinForms::SiticoneCheckBox());
			this->Spike = (gcnew Siticone::UI::WinForms::SiticoneCheckBox());
			this->BlockHit = (gcnew Siticone::UI::WinForms::SiticoneCheckBox());
			this->ONOFF = (gcnew Siticone::UI::WinForms::SiticoneOSToggleSwith());
			this->status = (gcnew Siticone::UI::WinForms::SiticoneLabel());
			this->JitterValue = (gcnew Siticone::UI::WinForms::SiticoneTrackBar());
			this->BlockHitValue = (gcnew Siticone::UI::WinForms::SiticoneTrackBar());
			this->SpikeValue = (gcnew Siticone::UI::WinForms::SiticoneTrackBar());
			this->SpikeCounter = (gcnew Siticone::UI::WinForms::SiticoneLabel());
			this->BlockHitCounter = (gcnew Siticone::UI::WinForms::SiticoneLabel());
			this->JitterCounter = (gcnew Siticone::UI::WinForms::SiticoneLabel());
			this->Closer = (gcnew Siticone::UI::WinForms::SiticoneButton());
			this->Hider = (gcnew Siticone::UI::WinForms::SiticoneButton());
			this->JitterThread = (gcnew System::ComponentModel::BackgroundWorker());
			this->ClickerThread = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// CPSValue
			// 
			this->CPSValue->BackColor = System::Drawing::Color::Transparent;
			this->CPSValue->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->CPSValue->HoveredState->Parent = this->CPSValue;
			this->CPSValue->Location = System::Drawing::Point(12, 65);
			this->CPSValue->Maximum = 20;
			this->CPSValue->Minimum = 1;
			this->CPSValue->Name = L"CPSValue";
			this->CPSValue->Size = System::Drawing::Size(328, 29);
			this->CPSValue->TabIndex = 0;
			this->CPSValue->ThumbColor = System::Drawing::Color::Silver;
			this->CPSValue->Value = 10;
			this->CPSValue->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &GUIBase::CPSValue_Scroll);
			// 
			// CPSCounter
			// 
			this->CPSCounter->BackColor = System::Drawing::Color::Transparent;
			this->CPSCounter->Font = (gcnew System::Drawing::Font(L"Minecraft", 13, System::Drawing::FontStyle::Bold));
			this->CPSCounter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->CPSCounter->Location = System::Drawing::Point(12, 47);
			this->CPSCounter->Name = L"CPSCounter";
			this->CPSCounter->Size = System::Drawing::Size(75, 22);
			this->CPSCounter->TabIndex = 1;
			this->CPSCounter->Text = L"CPS: 10";
			// 
			// SmartMode
			// 
			this->SmartMode->AutoSize = true;
			this->SmartMode->BackColor = System::Drawing::Color::Transparent;
			this->SmartMode->CheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->SmartMode->CheckedState->BorderRadius = 2;
			this->SmartMode->CheckedState->BorderThickness = 0;
			this->SmartMode->CheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->SmartMode->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SmartMode->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->SmartMode->Location = System::Drawing::Point(24, 149);
			this->SmartMode->Name = L"SmartMode";
			this->SmartMode->Size = System::Drawing::Size(120, 23);
			this->SmartMode->TabIndex = 2;
			this->SmartMode->Text = L"Smart Mode";
			this->SmartMode->UncheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->SmartMode->UncheckedState->BorderRadius = 2;
			this->SmartMode->UncheckedState->BorderThickness = 0;
			this->SmartMode->UncheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->SmartMode->UseVisualStyleBackColor = false;
			// 
			// ExtraRand
			// 
			this->ExtraRand->AutoSize = true;
			this->ExtraRand->BackColor = System::Drawing::Color::Transparent;
			this->ExtraRand->CheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->ExtraRand->CheckedState->BorderRadius = 2;
			this->ExtraRand->CheckedState->BorderThickness = 0;
			this->ExtraRand->CheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->ExtraRand->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExtraRand->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->ExtraRand->Location = System::Drawing::Point(24, 172);
			this->ExtraRand->Name = L"ExtraRand";
			this->ExtraRand->Size = System::Drawing::Size(192, 23);
			this->ExtraRand->TabIndex = 3;
			this->ExtraRand->Text = L"Extra Randomization";
			this->ExtraRand->UncheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->ExtraRand->UncheckedState->BorderRadius = 2;
			this->ExtraRand->UncheckedState->BorderThickness = 0;
			this->ExtraRand->UncheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->ExtraRand->UseVisualStyleBackColor = false;
			// 
			// Jitter
			// 
			this->Jitter->AutoSize = true;
			this->Jitter->BackColor = System::Drawing::Color::Transparent;
			this->Jitter->CheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Jitter->CheckedState->BorderRadius = 2;
			this->Jitter->CheckedState->BorderThickness = 0;
			this->Jitter->CheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Jitter->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Jitter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Jitter->Location = System::Drawing::Point(24, 195);
			this->Jitter->Name = L"Jitter";
			this->Jitter->Size = System::Drawing::Size(73, 23);
			this->Jitter->TabIndex = 4;
			this->Jitter->Text = L"Jitter";
			this->Jitter->UncheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->Jitter->UncheckedState->BorderRadius = 2;
			this->Jitter->UncheckedState->BorderThickness = 0;
			this->Jitter->UncheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->Jitter->UseVisualStyleBackColor = false;
			// 
			// Spike
			// 
			this->Spike->AutoSize = true;
			this->Spike->BackColor = System::Drawing::Color::Transparent;
			this->Spike->CheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Spike->CheckedState->BorderRadius = 2;
			this->Spike->CheckedState->BorderThickness = 0;
			this->Spike->CheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Spike->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Spike->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Spike->Location = System::Drawing::Point(24, 243);
			this->Spike->Name = L"Spike";
			this->Spike->Size = System::Drawing::Size(69, 23);
			this->Spike->TabIndex = 5;
			this->Spike->Text = L"Spike";
			this->Spike->UncheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->Spike->UncheckedState->BorderRadius = 2;
			this->Spike->UncheckedState->BorderThickness = 0;
			this->Spike->UncheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->Spike->UseVisualStyleBackColor = false;
			// 
			// BlockHit
			// 
			this->BlockHit->AutoSize = true;
			this->BlockHit->BackColor = System::Drawing::Color::Transparent;
			this->BlockHit->CheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->BlockHit->CheckedState->BorderRadius = 2;
			this->BlockHit->CheckedState->BorderThickness = 0;
			this->BlockHit->CheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->BlockHit->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BlockHit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->BlockHit->Location = System::Drawing::Point(24, 219);
			this->BlockHit->Name = L"BlockHit";
			this->BlockHit->Size = System::Drawing::Size(90, 23);
			this->BlockHit->TabIndex = 6;
			this->BlockHit->Text = L"BlockHit";
			this->BlockHit->UncheckedState->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->BlockHit->UncheckedState->BorderRadius = 2;
			this->BlockHit->UncheckedState->BorderThickness = 0;
			this->BlockHit->UncheckedState->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)), static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->BlockHit->UseVisualStyleBackColor = false;
			// 
			// ONOFF
			// 
			this->ONOFF->BackColor = System::Drawing::Color::Transparent;
			this->ONOFF->Checked = true;
			this->ONOFF->CheckedFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->ONOFF->Location = System::Drawing::Point(24, 100);
			this->ONOFF->Name = L"ONOFF";
			this->ONOFF->Size = System::Drawing::Size(35, 20);
			this->ONOFF->TabIndex = 7;
			this->ONOFF->Text = L"ONOFF";
			this->ONOFF->CheckedChanged += gcnew System::EventHandler(this, &GUIBase::ONOFF_CheckedChanged);
			// 
			// status
			// 
			this->status->BackColor = System::Drawing::Color::Transparent;
			this->status->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->status->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->status->Location = System::Drawing::Point(65, 98);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(36, 21);
			this->status->TabIndex = 8;
			this->status->Text = L": ON";
			// 
			// JitterValue
			// 
			this->JitterValue->BackColor = System::Drawing::Color::Transparent;
			this->JitterValue->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->JitterValue->HoveredState->Parent = this->JitterValue;
			this->JitterValue->Location = System::Drawing::Point(246, 192);
			this->JitterValue->Maximum = 10;
			this->JitterValue->Minimum = 1;
			this->JitterValue->Name = L"JitterValue";
			this->JitterValue->Size = System::Drawing::Size(218, 26);
			this->JitterValue->TabIndex = 9;
			this->JitterValue->ThumbColor = System::Drawing::Color::Silver;
			this->JitterValue->Value = 5;
			this->JitterValue->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &GUIBase::JitterValue_Scroll);
			// 
			// BlockHitValue
			// 
			this->BlockHitValue->BackColor = System::Drawing::Color::Transparent;
			this->BlockHitValue->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->BlockHitValue->HoveredState->Parent = this->BlockHitValue;
			this->BlockHitValue->Location = System::Drawing::Point(246, 216);
			this->BlockHitValue->Minimum = 1;
			this->BlockHitValue->Name = L"BlockHitValue";
			this->BlockHitValue->Size = System::Drawing::Size(218, 26);
			this->BlockHitValue->TabIndex = 10;
			this->BlockHitValue->ThumbColor = System::Drawing::Color::Silver;
			this->BlockHitValue->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &GUIBase::BlockHitValue_Scroll);
			// 
			// SpikeValue
			// 
			this->SpikeValue->BackColor = System::Drawing::Color::Transparent;
			this->SpikeValue->FillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->SpikeValue->HoveredState->Parent = this->SpikeValue;
			this->SpikeValue->Location = System::Drawing::Point(246, 240);
			this->SpikeValue->Minimum = 1;
			this->SpikeValue->Name = L"SpikeValue";
			this->SpikeValue->Size = System::Drawing::Size(218, 26);
			this->SpikeValue->TabIndex = 11;
			this->SpikeValue->ThumbColor = System::Drawing::Color::Silver;
			this->SpikeValue->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &GUIBase::SpikeValue_Scroll);
			// 
			// SpikeCounter
			// 
			this->SpikeCounter->BackColor = System::Drawing::Color::Transparent;
			this->SpikeCounter->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->SpikeCounter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->SpikeCounter->Location = System::Drawing::Point(470, 241);
			this->SpikeCounter->Name = L"SpikeCounter";
			this->SpikeCounter->Size = System::Drawing::Size(36, 21);
			this->SpikeCounter->TabIndex = 12;
			this->SpikeCounter->Text = L"50%";
			// 
			// BlockHitCounter
			// 
			this->BlockHitCounter->BackColor = System::Drawing::Color::Transparent;
			this->BlockHitCounter->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->BlockHitCounter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->BlockHitCounter->Location = System::Drawing::Point(470, 217);
			this->BlockHitCounter->Name = L"BlockHitCounter";
			this->BlockHitCounter->Size = System::Drawing::Size(36, 21);
			this->BlockHitCounter->TabIndex = 13;
			this->BlockHitCounter->Text = L"50%";
			// 
			// JitterCounter
			// 
			this->JitterCounter->BackColor = System::Drawing::Color::Transparent;
			this->JitterCounter->Font = (gcnew System::Drawing::Font(L"Minecraft", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(254)));
			this->JitterCounter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->JitterCounter->Location = System::Drawing::Point(470, 192);
			this->JitterCounter->Name = L"JitterCounter";
			this->JitterCounter->Size = System::Drawing::Size(25, 21);
			this->JitterCounter->TabIndex = 14;
			this->JitterCounter->Text = L"x5";
			// 
			// Closer
			// 
			this->Closer->BackColor = System::Drawing::Color::Transparent;
			this->Closer->CheckedState->Parent = this->Closer;
			this->Closer->CustomBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Closer->CustomBorderThickness = System::Windows::Forms::Padding(2);
			this->Closer->CustomImages->Parent = this->Closer;
			this->Closer->FillColor = System::Drawing::Color::Transparent;
			this->Closer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->Closer->ForeColor = System::Drawing::Color::White;
			this->Closer->HoveredState->Parent = this->Closer;
			this->Closer->Location = System::Drawing::Point(491, 0);
			this->Closer->Name = L"Closer";
			this->Closer->ShadowDecoration->Parent = this->Closer;
			this->Closer->Size = System::Drawing::Size(38, 23);
			this->Closer->TabIndex = 15;
			this->Closer->Text = L"X";
			this->Closer->Click += gcnew System::EventHandler(this, &GUIBase::Closer_Click);
			// 
			// Hider
			// 
			this->Hider->BackColor = System::Drawing::Color::Transparent;
			this->Hider->CheckedState->Parent = this->Hider;
			this->Hider->CustomBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(181)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->Hider->CustomBorderThickness = System::Windows::Forms::Padding(2);
			this->Hider->CustomImages->Parent = this->Hider;
			this->Hider->FillColor = System::Drawing::Color::Transparent;
			this->Hider->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->Hider->ForeColor = System::Drawing::Color::White;
			this->Hider->HoveredState->Parent = this->Hider;
			this->Hider->Location = System::Drawing::Point(455, 0);
			this->Hider->Name = L"Hider";
			this->Hider->ShadowDecoration->Parent = this->Hider;
			this->Hider->Size = System::Drawing::Size(38, 23);
			this->Hider->TabIndex = 16;
			this->Hider->Text = L"__";
			this->Hider->TextOffset = System::Drawing::Point(0, -6);
			this->Hider->Click += gcnew System::EventHandler(this, &GUIBase::Hider_Click);
			// 
			// JitterThread
			// 
			this->JitterThread->WorkerSupportsCancellation = true;
			this->JitterThread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUIBase::JitterThread_DoWork);
			// 
			// ClickerThread
			// 
			this->ClickerThread->WorkerSupportsCancellation = true;
			this->ClickerThread->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUIBase::ClickerThread_DoWork);
			// 
			// GUIBase
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(529, 299);
			this->Controls->Add(this->Hider);
			this->Controls->Add(this->Closer);
			this->Controls->Add(this->JitterCounter);
			this->Controls->Add(this->BlockHitCounter);
			this->Controls->Add(this->SpikeCounter);
			this->Controls->Add(this->SpikeValue);
			this->Controls->Add(this->BlockHitValue);
			this->Controls->Add(this->JitterValue);
			this->Controls->Add(this->status);
			this->Controls->Add(this->ONOFF);
			this->Controls->Add(this->BlockHit);
			this->Controls->Add(this->Spike);
			this->Controls->Add(this->Jitter);
			this->Controls->Add(this->ExtraRand);
			this->Controls->Add(this->SmartMode);
			this->Controls->Add(this->CPSCounter);
			this->Controls->Add(this->CPSValue);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GUIBase";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GUI Base";
			this->Load += gcnew System::EventHandler(this, &GUIBase::GUIBase_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GUIBase::GUIbase_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GUIBase::GUIbase_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GUIBase::GUIbase_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//On Load
	private: System::Void GUIBase_Load(System::Object^ sender, System::EventArgs^ e) {
		JitterThread->RunWorkerAsync(); //Starting Jitter Thread
		ClickerThread->RunWorkerAsync(); //Starting Clicker Thread
		timeBeginPeriod(1); //Set Minimum Delay Possible 
	}
	//Windows Movement (Moving a window while holding it with your mouse)
	private: System::Void GUIbase_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void GUIbase_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = false;
	}

	private: System::Void GUIbase_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}
	//Hide and Close
	private: System::Void Closer_Click(System::Object^ sender, System::EventArgs^ e) {
		timeEndPeriod(1); //Suggested
		Environment::Exit(0);
	}
	private: System::Void Hider_Click(System::Object^ sender, System::EventArgs^ e) {
		WindowState = FormWindowState::Minimized;
	}
	//Scrolls	   
	private: System::Void CPSValue_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		CPSCounter->Text = "CPS: " + CPSValue->Value.ToString(); //Displays the value in a label
	}
	private: System::Void JitterValue_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		JitterCounter->Text = "x" + JitterValue->Value.ToString(); //Displays the value in a label
	}
	private: System::Void BlockHitValue_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		BlockHitCounter->Text = BlockHitValue->Value.ToString() + "%"; //Displays the value in a label
		blockhitcountdown = 100;
	}
	private: System::Void SpikeValue_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
		SpikeCounter->Text = SpikeValue->Value.ToString() + "%"; //Displays the value in a label
		spikecountdown = 100;
	}
	//ON/OFF BUTTON
	private: System::Void ONOFF_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (ONOFF->Checked) { //If you prefer ONOFF->Checked == true
			status->Text = ": ON";
		}
		else {
			status->Text = ": OFF";
		}
	}
	//Clicker and Jitter Thread
	private: System::Void JitterThread_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		while (1) {
			if (ONOFF->Checked && Jitter->Checked && Minecraftattach()) {

				Thread::Sleep(1); //Prevents CPU to Run "Anything" as Fast as it Can (run over normal usage) while you're not holding left click

				while (SmartMode->Checked && cursor_visibility()) {
					Thread::Sleep(1); //Disable The Jitter Effect While Cursor is Shown
				}

				JitterFunction(JitterValue->Value);//Calling Jitter Function, If you prefer you can code
													//it there. A function looks better

			}
			else {
				Thread::Sleep(1); //Prevents CPU to Run "Anything" as Fast as it Can (run over normal usage) when the clicker is OFF
			}
		}
	}
		   int spikecountdown = 100, blockhitcountdown = 100;
	private: System::Void ClickerThread_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		static bool enablespike = false, enableblockhit = false;
		while (1) {
			if (ONOFF->Checked && Minecraftattach()) {

				Thread::Sleep(1); //Prevents CPU to Run "Anything" as Fast as it Can (run over normal usage) while you're not holding left click

				while (SmartMode->Checked && cursor_visibility()) {
					Thread::Sleep(1); //Disable The Jitter Effect While Cursor is Shown
				}

				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {

					if (BlockHit->Checked) {
						if (blockhitcountdown - BlockHitValue->Value == 0) {
							enableblockhit = true;
							blockhitcountdown = 100; //you can decide to add a + rand() to randomize blockhit
						}
						else {
							blockhitcountdown--;
						}
					}

					if (Spike->Checked) {
						if (spikecountdown - SpikeValue->Value == 0) {
							enablespike = true;
							spikecountdown = 100; //you can decide to add a + rand() to randomize spikes
						}
						else {
							spikecountdown--;
						}
					}

					ClickerFunction(CPSValue->Value, ExtraRand->Checked, enableblockhit, enablespike); //Calling Clicker Function, If you prefer you can code
																										//it there. A function looks better
				}

				enablespike = false;
				enableblockhit = false;
			}
			else {
				Thread::Sleep(1); //Prevents CPU to Run "Anything" as Fast as it Can (run over normal usage) when the clicker is OFF
			}
		}
}
};
}

