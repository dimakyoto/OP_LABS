#include "MyForm.h"
#include "SolveArctan.h"

MainForm::MainForm()
{
    InitializeComponents();
}

void MainForm::InitializeComponents()
{
    this->Text = "Arctan Calculator";
    this->Size = System::Drawing::Size(330, 380);

    startTextBox = gcnew TextBox();
    startTextBox->Location = System::Drawing::Point(10, 10);
    startTextBox->Width = 100;
    this->Controls->Add(startTextBox);

    endTextBox = gcnew TextBox();
    endTextBox->Location = System::Drawing::Point(10, 40);
    endTextBox->Width = 100;
    this->Controls->Add(endTextBox);

    stepTextBox = gcnew TextBox();
    stepTextBox->Location = System::Drawing::Point(10, 70);
    stepTextBox->Width = 100;
    this->Controls->Add(stepTextBox);

    calculateButton = gcnew Button();
    calculateButton->Text = "Calculate";
    calculateButton->Location = System::Drawing::Point(10, 100);
    calculateButton->Click += gcnew EventHandler(this, &MainForm::OnCalculateButtonClick);
    this->Controls->Add(calculateButton);

    clearButton = gcnew Button();
    clearButton->Text = "Clear";
    clearButton->Location = System::Drawing::Point(110, 100);
    clearButton->Click += gcnew EventHandler(this, &MainForm::OnClearButtonClick);
    this->Controls->Add(clearButton);

    resultListBox = gcnew ListBox();
    resultListBox->Location = System::Drawing::Point(10, 130);
    resultListBox->Width = 200;
    resultListBox->Height = 200;
    this->Controls->Add(resultListBox);

    Label^ startLabel = gcnew Label();
    startLabel->Text = "Start Interval";
    startLabel->Location = System::Drawing::Point(120, 10);
    this->Controls->Add(startLabel);

    Label^ endLabel = gcnew Label();
    endLabel->Text = "Finish Interval";
    endLabel->Location = System::Drawing::Point(120, 40);
    this->Controls->Add(endLabel);

    Label^ stepLabel = gcnew Label();
    stepLabel->Text = "Step";
    stepLabel->Location = System::Drawing::Point(120, 70);
    this->Controls->Add(stepLabel);

    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
}

void MainForm::OnCalculateButtonClick(Object^ sender, EventArgs^ e)
{
    if (!ValidateInput())
    {
        return;
    }

    double start = Double::Parse(startTextBox->Text);
    double end = Double::Parse(endTextBox->Text);
    double step = Double::Parse(stepTextBox->Text);

    resultListBox->Items->Clear();

    double x = start;
    while (x <= end)
    {
        SolveArctan^ solver = gcnew SolveArctan(x);
        double result = solver->Calculate();

        resultListBox->Items->Add(String::Format("x = {0}, arctan(x) = {1}", x, result));

        x += step;
    }
}

void MainForm::OnClearButtonClick(Object^ sender, EventArgs^ e)
{
    startTextBox->Clear();
    endTextBox->Clear();
    stepTextBox->Clear();
    resultListBox->Items->Clear();
}

bool MainForm::ValidateInput()
{
    try
    {
        double start, end, step;

        if (!Double::TryParse(startTextBox->Text, start) || !Double::TryParse(endTextBox->Text, end) || !Double::TryParse(stepTextBox->Text, step))
        {
            throw gcnew Exception("Invalid input format.");
        }

        if (start > end)
        {
            throw gcnew Exception("Invalid intervals, start can't be lower than end");
        }

        if (step == 0)
        {
            throw gcnew Exception("Step cannot be zero. Please enter a non-zero value.");
        }

        if (start < -100 || start > 100 || end < -100 || end > 100 || step <= 0)
        {
            throw gcnew Exception("Invalid input values. Please enter valid INTEGER numbers.");
        }

        return true;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

    return false;
}

void RunApplication(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MainForm^ mainForm = gcnew MainForm();
    Application::Run(mainForm);
}

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    array<System::String^>^ args = Environment::GetCommandLineArgs();
    RunApplication(args);
    return 0;
}
