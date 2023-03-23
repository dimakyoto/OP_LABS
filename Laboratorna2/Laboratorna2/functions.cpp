#include "functions.h"


//Interface massages

//Describing the programm  
void greeting() {
    cout << endl << "This program can create a file with information about students:" << endl;
    cout << "Full name, date of birth, form of study, group, average grade point average." << endl;
    cout << "For each stream (stream groups have the same abbreviation), you can identify students," << endl;
    cout << "With the minimum grade point average and the groups in which they study." << endl;
    cout << "In a new file, it can also generate a list of full-time students sorted by name," << endl;
    cout << "Whose grade point average is not less than the specified one." << endl << "ENJOY!" << endl << endl;
}
//Interface for user
void interface() {
    cout << endl << "TYPE 1 to CREATE FILE." << endl;
    cout << "TYPE 2 to READ FILE." << endl;
    cout << "TYPE 3 to ADD text to FILE." << endl;
    cout << "TYPE 4 to FIND students with minimum score in each BRANCH." << endl;
    cout << "TYPE 5 to CREATE new FILE with students SORTED by last name," << endl;
    cout << "WHOSE average SCORE is not lower than specified one." << endl;
    cout << "TYPE 0 to EXIT." << endl;
    cout << "Enter your choice: " << endl;
}
//Printing error
void error_massage() {
    cout << "Oops, invalid choice,try again" << endl;
    cout << "You need to use only correct numbers like in instruction" << endl;
}


// Checks for error and open file

//For ifstream
bool check_file_open_ifstream(ifstream& fin, const string& name) {
    fin.open(name, ios::binary);
    if (!fin.is_open()) {
        cout << "Error opening file " << name << endl;
        return false;
    }
    return true;
}
//For ofstream
bool check_file_open_ofstream(ofstream& fout, const string& name) {
    fout.open(name, ios::binary);
    if (!fout.is_open()) {
        cout << "Error opening file " << name << endl;
        return false;
    }
    return true;
}


//Struct student for writing data in file
struct student {
    string name;
    string birthday;
    string educationFORM;
    string branch;
    string group;
    double averagemark;
};


// Work with FILE 

//Returning name_file
string name_file() {
    cout << "ENTER please NAME of the FILE(For example file.bin):" << endl;
    string nameFile;
    cin >> nameFile;
    return nameFile;
}
//Function for reading binary file
void read_binary_file(const string& name) {

    ifstream fin;
    check_file_open_ifstream(fin, name); //Open file 

    size_t count_strct = 0;
    fin.seekg(0, ios::end);
    count_strct = fin.tellg() / sizeof(student); //These lines determine the size of the file in bytes and calculate the number of student structs it contains.                                               
    fin.seekg(0, ios::beg);                      //They then allocate memory for an array of student structs using the new operator.
    student* std = new student[count_strct];

    for (size_t i = 0; i < count_strct; ++i) {                              //This loop reads each student struct from the file into the array of student structs std. 
        if (!fin.read(reinterpret_cast<char*>(&std[i]), sizeof(student))) { //If there is an error reading from the file, it prints an error message

            cerr << "Failed to read from " << name << endl;
            break;
        }
        cout << "Name: " << std[i].name << endl;                            //Output
        cout << "Birthday: " << std[i].birthday << endl;
        cout << "Education form: " << std[i].educationFORM << endl;
        cout << "Branch: " << std[i].branch << endl;
        cout << "Group: " << std[i].group << endl;
        cout << "Average mark: " << std[i].averagemark << endl;
        cout << "--------------------------------------------------" << endl;
    }
    //
    fin.close();

}
//Function for appending text in file
void append_text_to_file(const string& name) {

    ofstream fout(name, ios::binary | ios::app);
    if (!fout.is_open()) {
        cout << "Error opening file " << name << endl;   //Open file in append mode and checks for error
        return;
    }

    student std;

    int choice = 1;
    while (choice != 0) {
        cout << "ENTER STUDENT DATA:" << endl;
        cout << "ENTER student`s name (in format Zghurovkiy V.Y): " << endl;  //Output

        cin.ignore();
        getline(cin, std.name);

        cout << "ENTER student`s birthday (in format xx.xx.xxxx): " << endl;

        getline(cin, std.birthday);

        cout << "ENTER student`s education form: (in format Denna)" << endl;

        getline(cin, std.educationFORM);

        cout << "ENTER student`s branch (in format IP): " << endl;

        getline(cin, std.branch);

        cout << "ENTER student`s group (in format IP-XX): " << endl;

        getline(cin, std.group);

        cout << "ENTER student`s mark (in format x): " << endl;

        cin >> std.averagemark;

        cout << "PRESS 0, if you want to FINISH or PRESS 1 to CONTINUE" << endl;

        cin >> choice;

        fout.write((char*)&std, sizeof(student));
    }
    cout << "Your file was successfully updated" << endl;
    fout.close();
}
//Function for finding students with min mark in eaach branch
void find_min_students(const string& name) {

    ifstream fin;
    check_file_open_ifstream(fin, name);

    size_t count_strct = 0;
    fin.seekg(0, ios::end);
    count_strct = fin.tellg() / sizeof(student);
    fin.seekg(0, ios::beg);
    student* std = new student[count_strct];

    map<string, double> min_scores; // map to store the minimum score for each branch
    map<string, vector<student>> students_by_branch; // map to store students by branch

    // read all students and group them by branch
    for (size_t i = 0; i < count_strct; ++i) {
        if (!fin.read(reinterpret_cast<char*>(&std[i]), sizeof(student))) {
            cerr << "Failed to read from " << name << endl;
            break;
        }
        students_by_branch[std[i].branch].push_back(std[i]);

        // update minimum score for this branch if needed
        if (min_scores.find(std[i].branch) == min_scores.end() || std[i].averagemark < min_scores[std[i].branch]) {
            min_scores[std[i].branch] = std[i].averagemark;
        }
    }
    fin.close();

    // output the students with the minimum score for each branch
    for (auto it = students_by_branch.begin(); it != students_by_branch.end(); ++it) {
        const string& branch = it->first;
        const double min_score = min_scores[branch];

        cout << endl << "Minimum score for branch " << branch << ": " << min_score << endl;
        for (const auto& student : it->second) {
            if (student.averagemark == min_score) {
                cout << "Name: " << student.name << endl;
                cout << "Branch: " << student.branch << endl;
                cout << "Group: " << student.group << endl;
                cout << "Average mark: " << student.averagemark << endl;
                cout << "------------------------" << endl;
            }
        }
    }
    //
}
//Function for sorting students in new file, mark which is higher than given one
void sort_and_save_by_name(const string& name, double min_avg) {

    ifstream fin;
    check_file_open_ifstream(fin, name);

    vector<student> students;
    student* temp = new student[100];
    int i = 0;
    while (fin.read(reinterpret_cast<char*>(&temp[i]), sizeof(student))) {
        if (temp[i].educationFORM == "Denna" && temp[i].averagemark >= min_avg) {
            students.push_back(temp[i]);
        }
        ++i;
    }

    sort(students.begin(), students.end(), [](const student& a, const student& b) {
        string a_last_name = a.name.substr(a.name.find_last_of(' ') + 1);
        string b_last_name = b.name.substr(b.name.find_last_of(' ') + 1);
        return a_last_name < b_last_name;
        });

    fin.close();

    string output_name = name_file();
    ofstream fout;
    check_file_open_ofstream(fout, output_name);

    for (int i = 0; i < students.size(); ++i) {
        fout.write(reinterpret_cast<const char*>(&students[i]), sizeof(student));
    }

    fout.close();

    cout << "Full-time students sorted by name, whose average score is not less than " << min_avg << ", saved to file " << output_name << endl;
}


//Switch cases

//case1
void choice1() {

    ofstream outFile; student std; int choice = 1;
    string name = name_file();

    check_file_open_ofstream(outFile, name); //Open file

    while (choice != 0) {

        cout << "ENTER STUDENT DATA:" << endl;
        cout << "ENTER student`s name (in format Zghurovskyi V.Y.): " << endl; //Output

        cin.ignore();
        getline(cin, std.name);

        cout << "ENTER student`s birthday (in format xx.xx.xxxx): " << endl;

        getline(cin, std.birthday);

        cout << "ENTER student`s education form: (in format Denna)" << endl;

        getline(cin, std.educationFORM);

        cout << "ENTER student`s branch (in format IP): " << endl;

        getline(cin, std.branch);

        cout << "ENTER student`s group (in format IP-XX): " << endl;

        getline(cin, std.group);

        cout << "ENTER student`s mark (in format x): " << endl;

        cin >> std.averagemark;

        cout << "PRESS 0, if you want to FINISH or PRESS 1 to CONTINUE" << endl;

        cin >> choice;

        outFile.write((char*)&std, sizeof(student));
    }
    cout << "Your file was successfully created" << endl;
    outFile.close();
}
//case2
void choice2() {
    string name = name_file();
    cout << endl;
    read_binary_file(name);
}
//case3
void choice3() {
    string name = name_file();
    append_text_to_file(name);
}
//case4
void choice4() {
    string name = name_file();
    find_min_students(name);
}
//case5
void choice5() {

    string name; double mark = 0;
    name = name_file();

    cout << "Enter minimal average mark:" << endl;
    cin >> mark;

    sort_and_save_by_name(name, mark);
}