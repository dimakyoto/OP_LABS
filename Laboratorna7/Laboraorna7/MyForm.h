#pragma once

#include <Windows.h>
#include <cmath>
#include <string>

using namespace System;
using namespace System::Windows::Forms;

ref class MainForm : public Form
{
private:
    TextBox^ startTextBox;
    TextBox^ endTextBox;
    TextBox^ stepTextBox;
    Button^ calculateButton;
    Button^ clearButton;
    ListBox^ resultListBox;

public:
    MainForm();

private:
    void InitializeComponents();
    void OnCalculateButtonClick(Object^ sender, EventArgs^ e);
    void OnClearButtonClick(Object^ sender, EventArgs^ e);
    bool ValidateInput();
};

void RunApplication(array<System::String^>^ args);
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
