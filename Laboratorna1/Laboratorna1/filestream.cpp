#include "filestream.h"


//Intro and error massage
void greeting() {
    cout << "\n" << "Hello, this is program, where you can create your own text file," << endl;
    cout << "This program also can convert hexadecimal numbers into decimal numbers," << endl;
    cout << "If you write a number in hexadecimal while typing, the program will create another file," << endl;
    cout << "in which it converts all such numbers to decimal." << endl;
    cout << "For that choose 4 OPTION in any mode." << endl << "ENJOY!" << endl << endl;
}
void interface() {
    cout << "\n" << "TYPE 1 to CREATE FILE" << endl;
    cout << "TYPE 2 to READ FILE" << endl;
    cout << "TYPE 3 to ADD text to FILE" << endl;
    cout << "TYPE 4 to CONVERT HEXADECIMAL NUMBERS IN DECIMAL in FILE" << endl;
    cout << "TYPE 0 to EXIT" << endl;
    cout << "Enter your choice: " << endl;
}
void error_massage() {
    cout << "Oops, invalid choice,try again" << endl;
    cout << "You need to use only correct numbers like in instruction" << endl;
}

// Checks for open file C++ style
bool check_file_open_ifstream(ifstream& fin, const string& name) {
    fin.open(name);
    if (!fin.is_open()) {
        cout << "Error opening file " << name << endl;
        return false;
    }
    return true;
}
bool check_file_open_ofstream(ofstream& fout, const string& name) {
    fout.open(name);
    if (!fout.is_open()) {
        cout << "Error opening file " << name << endl;
        return false;
    }
    return true;
}

// Work with FILE C++ style
string name_file() {
    cout << "Enter please name of the file(For example file.txt):" << endl;
    string nameFile;
    cin >> nameFile;
    return nameFile;
}
void read_file(ifstream& fin, const string& name) {
    check_file_open_ifstream(fin, name);
    char letter;
    while (fin.get(letter)) {
        cout << letter;
    }
}
void append_to_file(ofstream& fout, const string& name) {
    string textAdd;
    fout.open(name, ofstream::app);
    if (!fout.is_open()) {
        cout << "Error opening file" << name << endl;
    }
    else {
        cout << "Enter text you want to ADD to created FILE: " << endl;
        cin.ignore();
        getline(cin, textAdd);
        fout << textAdd << endl;
    }
}

// Cases C++ style
void choice1(ofstream& fout) {

    string textInput, name = name_file();
    check_file_open_ofstream(fout, name);
    cout << "Enter text you want to ADD: " << endl;
    cin.ignore();

    getline(cin, textInput);
    fout << textInput << endl;

    cout << "Your file was successfully created" << endl;
    fout.close();
}
void choice2(ifstream& fin) {
    string name = name_file();
    read_file(fin, name);
    fin.close();
}
void choice3(ofstream& fout) {
    string name = name_file();
    append_to_file(fout, name);
    cout << "Your DATA was successfully added" << endl;
    fout.close();
}

void find_hex_numbers(ifstream& fin, ofstream& fout) {
    string name = name_file();
    check_file_open_ifstream(fin, name);

    cout << endl << "Now you need too choose name file to which you convert your numbers!" << endl << endl;

    string output_filename = name_file();
    check_file_open_ofstream(fout, output_filename);


    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            bool is_hex = true;
            for (char c : word) {
                if (!isxdigit(c)) {
                    is_hex = false;
                    break;
                }
            }
            if (is_hex) {
                int num = stoi(word, nullptr, 16);
                fout << word << " is " << num << " in decimal" << endl;
            }
        }
    }

    cout << "Conversion complete, you can prove it, just READ your new file" << endl;

    fin.close();
    fout.close();
}