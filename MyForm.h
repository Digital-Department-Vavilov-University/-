#pragma once

#include <Windows.h>

namespace Project1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            InitializePollutants();
            ShowDescriptionPage();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Элементы управления для страницы описания
        System::Windows::Forms::Panel^ panelDescription;
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::Label^ labelDescription;
        System::Windows::Forms::Button^ buttonStart;

        // Элементы управления для страницы расчёта
        System::Windows::Forms::Panel^ panelCalculation;
        System::Windows::Forms::TextBox^ textBoxResult;
        System::Windows::Forms::Button^ buttonCalculate;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::Label^ label7;
        System::Windows::Forms::Label^ label8;
        System::Windows::Forms::Label^ label9;
        System::Windows::Forms::Label^ label10;
        System::Windows::Forms::TextBox^ textBoxOil;
        System::Windows::Forms::TextBox^ textBoxPhenol;
        System::Windows::Forms::TextBox^ textBoxCopper;
        System::Windows::Forms::TextBox^ textBoxLead;
        System::Windows::Forms::TextBox^ textBoxAmmonium;
        System::Windows::Forms::TextBox^ textBoxIron;
        System::Windows::Forms::TextBox^ textBoxManganese;
        System::Windows::Forms::TextBox^ textBoxNitrates;
        System::Windows::Forms::TextBox^ textBoxChlorides;
        System::Windows::Forms::TextBox^ textBoxSulfates;
        System::Windows::Forms::Button^ buttonBack;

        System::ComponentModel::Container^ components;

        // Класс для хранения данных о загрязняющих веществах
        ref class Pollutant
        {
        public:
            String^ name;
            double pdk;

            Pollutant(String^ n, double p) : name(n), pdk(p) {}
        };

        List<Pollutant^>^ pollutants;

        void InitializePollutants() {
            pollutants = gcnew List<Pollutant^>();
            pollutants->Add(gcnew Pollutant("Нефтепродукты", 0.05));
            pollutants->Add(gcnew Pollutant("Фенолы", 0.001));
            pollutants->Add(gcnew Pollutant("Медь (Cu)", 1.0));
            pollutants->Add(gcnew Pollutant("Свинец (Pb)", 0.01));
            pollutants->Add(gcnew Pollutant("Аммонийный азот (NH4)", 0.5));
            pollutants->Add(gcnew Pollutant("Железо (Fe)", 0.3));
            pollutants->Add(gcnew Pollutant("Марганец (Mn)", 0.1));
            pollutants->Add(gcnew Pollutant("Нитраты (NO3)", 45.0));
            pollutants->Add(gcnew Pollutant("Хлориды (Cl)", 350.0));
            pollutants->Add(gcnew Pollutant("Сульфаты (SO4)", 500.0));
        }

        void ShowDescriptionPage() {
            panelDescription->Visible = true;
            panelCalculation->Visible = false;
        }

        void ShowCalculationPage() {
            panelDescription->Visible = false;
            panelCalculation->Visible = true;
        }

        double CalculateWPI(array<double>^ concentrations) {
            double sum = 0.0;
            int n = pollutants->Count;

            for (int i = 0; i < n; i++) {
                double Ci = concentrations[i];
                double PДКi = pollutants[i]->pdk;
                sum += Ci / PДКi;
            }

            return sum / n;
        }

        String^ InterpretWPI(double wpi) {
            if (wpi < 0.3) {
                textBoxResult->BackColor = Color::LightGreen;
                return "Очень чистая";
            }
            else if (wpi < 1.0) {
                textBoxResult->BackColor = Color::LightGreen;
                return "Чистая";
            }
            else if (wpi < 2.0) {
                textBoxResult->BackColor = Color::Yellow;
                return "Умеренно загрязнённая";
            }
            else if (wpi < 4.0) {
                textBoxResult->BackColor = Color::Orange;
                return "Загрязнённая";
            }
            else {
                textBoxResult->BackColor = Color::LightCoral;
                return "Очень грязная";
            }
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panelDescription = (gcnew System::Windows::Forms::Panel());
            this->labelTitle = (gcnew System::Windows::Forms::Label());
            this->labelDescription = (gcnew System::Windows::Forms::Label());
            this->buttonStart = (gcnew System::Windows::Forms::Button());
            this->panelCalculation = (gcnew System::Windows::Forms::Panel());
            this->buttonBack = (gcnew System::Windows::Forms::Button());
            this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
            this->buttonCalculate = (gcnew System::Windows::Forms::Button());
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
            this->textBoxOil = (gcnew System::Windows::Forms::TextBox());
            this->textBoxPhenol = (gcnew System::Windows::Forms::TextBox());
            this->textBoxCopper = (gcnew System::Windows::Forms::TextBox());
            this->textBoxLead = (gcnew System::Windows::Forms::TextBox());
            this->textBoxAmmonium = (gcnew System::Windows::Forms::TextBox());
            this->textBoxIron = (gcnew System::Windows::Forms::TextBox());
            this->textBoxManganese = (gcnew System::Windows::Forms::TextBox());
            this->textBoxNitrates = (gcnew System::Windows::Forms::TextBox());
            this->textBoxChlorides = (gcnew System::Windows::Forms::TextBox());
            this->textBoxSulfates = (gcnew System::Windows::Forms::TextBox());
            this->panelDescription->SuspendLayout();
            this->panelCalculation->SuspendLayout();
            this->SuspendLayout();
            // 
            // panelDescription
            // 
            this->panelDescription->Controls->Add(this->buttonStart);
            this->panelDescription->Controls->Add(this->labelDescription);
            this->panelDescription->Controls->Add(this->labelTitle);
            this->panelDescription->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panelDescription->Location = System::Drawing::Point(0, 0);
            this->panelDescription->Name = L"panelDescription";
            this->panelDescription->Size = System::Drawing::Size(484, 511);
            this->panelDescription->TabIndex = 22;
            // 
            // labelTitle
            // 
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(20, 50);
            this->labelTitle->Name = L"labelTitle";
            this->labelTitle->Size = System::Drawing::Size(444, 50);
            this->labelTitle->TabIndex = 0;
            this->labelTitle->Text = L"Расчёт индекса\r\nзагрязнения воды (ИЗВ)";
            this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // labelDescription
            // 
            this->labelDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->labelDescription->Location = System::Drawing::Point(30, 120);
            this->labelDescription->Name = L"labelDescription";
            this->labelDescription->Size = System::Drawing::Size(424, 200);
            this->labelDescription->TabIndex = 1;
            this->labelDescription->Text = L"Программа рассчитывает индекс загрязнения воды (ИЗВ) на основе концентраций нескольких загрязняющих веществ. "
                "ИЗВ используется для оценки степени загрязнённости водоёмов.\r\n\r\n"
                "Для расчёта ИЗВ программа использует 10 основных показателей качества воды, сравнивая их с предельно допустимыми концентрациями (ПДК). "
                "Результат расчёта позволяет классифицировать воду по категориям от \"Очень чистая\" до \"Очень грязная\".";
            // 
            // buttonStart
            // 
            this->buttonStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->buttonStart->Location = System::Drawing::Point(167, 350);
            this->buttonStart->Name = L"buttonStart";
            this->buttonStart->Size = System::Drawing::Size(150, 40);
            this->buttonStart->TabIndex = 2;
            this->buttonStart->Text = L"Начать расчёт";
            this->buttonStart->UseVisualStyleBackColor = true;
            this->buttonStart->Click += gcnew System::EventHandler(this, &MyForm::buttonStart_Click);
            // 
            // panelCalculation
            // 
            this->panelCalculation->Controls->Add(this->buttonBack);
            this->panelCalculation->Controls->Add(this->textBoxResult);
            this->panelCalculation->Controls->Add(this->buttonCalculate);
            this->panelCalculation->Controls->Add(this->label1);
            this->panelCalculation->Controls->Add(this->label2);
            this->panelCalculation->Controls->Add(this->label3);
            this->panelCalculation->Controls->Add(this->label4);
            this->panelCalculation->Controls->Add(this->label5);
            this->panelCalculation->Controls->Add(this->label6);
            this->panelCalculation->Controls->Add(this->label7);
            this->panelCalculation->Controls->Add(this->label8);
            this->panelCalculation->Controls->Add(this->label9);
            this->panelCalculation->Controls->Add(this->label10);
            this->panelCalculation->Controls->Add(this->textBoxOil);
            this->panelCalculation->Controls->Add(this->textBoxPhenol);
            this->panelCalculation->Controls->Add(this->textBoxCopper);
            this->panelCalculation->Controls->Add(this->textBoxLead);
            this->panelCalculation->Controls->Add(this->textBoxAmmonium);
            this->panelCalculation->Controls->Add(this->textBoxIron);
            this->panelCalculation->Controls->Add(this->textBoxManganese);
            this->panelCalculation->Controls->Add(this->textBoxNitrates);
            this->panelCalculation->Controls->Add(this->textBoxChlorides);
            this->panelCalculation->Controls->Add(this->textBoxSulfates);
            this->panelCalculation->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panelCalculation->Location = System::Drawing::Point(0, 0);
            this->panelCalculation->Name = L"panelCalculation";
            this->panelCalculation->Size = System::Drawing::Size(484, 511);
            this->panelCalculation->TabIndex = 23;
            this->panelCalculation->Visible = false;
            // 
            // buttonBack
            // 
            this->buttonBack->Location = System::Drawing::Point(30, 370);
            this->buttonBack->Name = L"buttonBack";
            this->buttonBack->Size = System::Drawing::Size(80, 30);
            this->buttonBack->TabIndex = 22;
            this->buttonBack->Text = L"Назад";
            this->buttonBack->UseVisualStyleBackColor = true;
            this->buttonBack->Click += gcnew System::EventHandler(this, &MyForm::buttonBack_Click);
            // 
            // textBoxResult
            // 
            this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
            this->textBoxResult->Location = System::Drawing::Point(30, 410);
            this->textBoxResult->Multiline = true;
            this->textBoxResult->Name = L"textBoxResult";
            this->textBoxResult->ReadOnly = true;
            this->textBoxResult->Size = System::Drawing::Size(424, 60);
            this->textBoxResult->TabIndex = 0;
            // 
            // buttonCalculate
            // 
            this->buttonCalculate->Location = System::Drawing::Point(180, 370);
            this->buttonCalculate->Name = L"buttonCalculate";
            this->buttonCalculate->Size = System::Drawing::Size(120, 30);
            this->buttonCalculate->TabIndex = 1;
            this->buttonCalculate->Text = L"Рассчитать ИЗВ";
            this->buttonCalculate->UseVisualStyleBackColor = true;
            this->buttonCalculate->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculate_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(30, 20);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(120, 13);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Нефтепродукты (мг/л):";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(30, 50);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(80, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Фенолы (мг/л):";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(30, 80);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(90, 13);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Медь (Cu) (мг/л):";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(30, 110);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(100, 13);
            this->label4->TabIndex = 5;
            this->label4->Text = L"Свинец (Pb) (мг/л):";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(30, 140);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(160, 13);
            this->label5->TabIndex = 6;
            this->label5->Text = L"Аммонийный азот (NH4) (мг/л):";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(30, 170);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(90, 13);
            this->label6->TabIndex = 7;
            this->label6->Text = L"Железо (Fe) (мг/л):";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(30, 200);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(110, 13);
            this->label7->TabIndex = 8;
            this->label7->Text = L"Марганец (Mn) (мг/л):";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(30, 230);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(100, 13);
            this->label8->TabIndex = 9;
            this->label8->Text = L"Нитраты (NO3) (мг/л):";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(30, 260);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(100, 13);
            this->label9->TabIndex = 10;
            this->label9->Text = L"Хлориды (Cl) (мг/л):";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(30, 290);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(110, 13);
            this->label10->TabIndex = 11;
            this->label10->Text = L"Сульфаты (SO4) (мг/л):";
            // 
            // textBoxOil
            // 
            this->textBoxOil->Location = System::Drawing::Point(220, 17);
            this->textBoxOil->Name = L"textBoxOil";
            this->textBoxOil->Size = System::Drawing::Size(100, 20);
            this->textBoxOil->TabIndex = 12;
            // 
            // textBoxPhenol
            // 
            this->textBoxPhenol->Location = System::Drawing::Point(220, 47);
            this->textBoxPhenol->Name = L"textBoxPhenol";
            this->textBoxPhenol->Size = System::Drawing::Size(100, 20);
            this->textBoxPhenol->TabIndex = 13;
            // 
            // textBoxCopper
            // 
            this->textBoxCopper->Location = System::Drawing::Point(220, 77);
            this->textBoxCopper->Name = L"textBoxCopper";
            this->textBoxCopper->Size = System::Drawing::Size(100, 20);
            this->textBoxCopper->TabIndex = 14;
            // 
            // textBoxLead
            // 
            this->textBoxLead->Location = System::Drawing::Point(220, 107);
            this->textBoxLead->Name = L"textBoxLead";
            this->textBoxLead->Size = System::Drawing::Size(100, 20);
            this->textBoxLead->TabIndex = 15;
            // 
            // textBoxAmmonium
            // 
            this->textBoxAmmonium->Location = System::Drawing::Point(220, 137);
            this->textBoxAmmonium->Name = L"textBoxAmmonium";
            this->textBoxAmmonium->Size = System::Drawing::Size(100, 20);
            this->textBoxAmmonium->TabIndex = 16;
            // 
            // textBoxIron
            // 
            this->textBoxIron->Location = System::Drawing::Point(220, 167);
            this->textBoxIron->Name = L"textBoxIron";
            this->textBoxIron->Size = System::Drawing::Size(100, 20);
            this->textBoxIron->TabIndex = 17;
            // 
            // textBoxManganese
            // 
            this->textBoxManganese->Location = System::Drawing::Point(220, 197);
            this->textBoxManganese->Name = L"textBoxManganese";
            this->textBoxManganese->Size = System::Drawing::Size(100, 20);
            this->textBoxManganese->TabIndex = 18;
            // 
            // textBoxNitrates
            // 
            this->textBoxNitrates->Location = System::Drawing::Point(220, 227);
            this->textBoxNitrates->Name = L"textBoxNitrates";
            this->textBoxNitrates->Size = System::Drawing::Size(100, 20);
            this->textBoxNitrates->TabIndex = 19;
            // 
            // textBoxChlorides
            // 
            this->textBoxChlorides->Location = System::Drawing::Point(220, 257);
            this->textBoxChlorides->Name = L"textBoxChlorides";
            this->textBoxChlorides->Size = System::Drawing::Size(100, 20);
            this->textBoxChlorides->TabIndex = 20;
            // 
            // textBoxSulfates
            // 
            this->textBoxSulfates->Location = System::Drawing::Point(220, 287);
            this->textBoxSulfates->Name = L"textBoxSulfates";
            this->textBoxSulfates->Size = System::Drawing::Size(100, 20);
            this->textBoxSulfates->TabIndex = 21;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(484, 511);
            this->Controls->Add(this->panelCalculation);
            this->Controls->Add(this->panelDescription);
            this->Name = L"MyForm";
            this->Text = L"Расчёт индекса загрязнения воды (ИЗВ)";
            this->panelDescription->ResumeLayout(false);
            this->panelCalculation->ResumeLayout(false);
            this->panelCalculation->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
            ShowCalculationPage();
        }

        System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
            ShowDescriptionPage();
        }

        System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                // Проверка на пустые поля
                if (String::IsNullOrEmpty(textBoxOil->Text) ||
                    String::IsNullOrEmpty(textBoxPhenol->Text) ||
                    String::IsNullOrEmpty(textBoxCopper->Text) ||
                    String::IsNullOrEmpty(textBoxLead->Text) ||
                    String::IsNullOrEmpty(textBoxAmmonium->Text) ||
                    String::IsNullOrEmpty(textBoxIron->Text) ||
                    String::IsNullOrEmpty(textBoxManganese->Text) ||
                    String::IsNullOrEmpty(textBoxNitrates->Text) ||
                    String::IsNullOrEmpty(textBoxChlorides->Text) ||
                    String::IsNullOrEmpty(textBoxSulfates->Text))
                {
                    throw gcnew Exception("Не все поля заполнены");
                }

                array<double>^ concentrations = gcnew array<double> {
                    Double::Parse(textBoxOil->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxPhenol->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxCopper->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxLead->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxAmmonium->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxIron->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxManganese->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxNitrates->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxChlorides->Text, System::Globalization::CultureInfo::InvariantCulture),
                        Double::Parse(textBoxSulfates->Text, System::Globalization::CultureInfo::InvariantCulture)
                };

                double wpi = CalculateWPI(concentrations);
                String^ interpretation = InterpretWPI(wpi);

                textBoxResult->Text = String::Format(
                    "ИЗВ = {0:F2}\r\nКачество воды: {1}",
                    wpi, interpretation
                );
            }
            catch (FormatException^) {
                MessageBox::Show("Ошибка ввода данных! Пожалуйста, вводите только числа.", "Ошибка");
            }
            catch (Exception^ ex) {
                MessageBox::Show(ex->Message, "Ошибка");
            }
        }
    };
}