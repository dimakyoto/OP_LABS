#include "functions.h"

//Describing the program
void greeting() {
    cout << endl << "Hello, this program define the class Numeral_2, whose member is a binary number." << endl;
    cout << "Implement several constructors, getters, methods for converting a number to decimal for this class." << endl;
    cout << " Overload operators: prefix ++ - for incrementing a binarynumber," << endl;
    cout << "+= - to increase it by the specified value, + - to add two binary numbers." << endl;
    cout << "Below the program makes the given actions, but you can change them as you like." << endl << "ENJOY!" << endl << endl;
}
//Printing error
int error_massage() {
    cout << "Oops, invalid choice,try again" << endl;
    cout << "You need to use only correct numbers like in instruction" << endl;
    return 1;
}
//main operations
void code() {

    int choice = 0;
    string binary1, binary2, binary3;
    int decimal1, decimal2, decimal3;

    Numeral_2 N1;
    Numeral_2 N2;
    Numeral_2 N3;

    cout << "In what form do you want to enter the number? 1 - Decimal, 2 - Binary" << endl;
    cin >> choice;

    cout << "Enter the first binary number: ";
    if (choice == 1) {
        cin >> decimal1;
        new (&N1) Numeral_2(decimal1);
    }
    else if (choice == 2) {
        cin >> binary1;
        new (&N1) Numeral_2(binary1);
    }
    else {
        error_massage();
    }

    cout << "In what form do you want to enter the number? 1 - Decimal, 2 - Binary" << endl;
    cin >> choice;

    cout << "Enter the second binary number: ";
    if (choice == 1) {
        cin >> decimal2;
        new (&N2) Numeral_2(decimal2);
    }
    else if (choice == 2) {
        cin >> binary2;
        new (&N2) Numeral_2(binary2);
    }
    else {
        error_massage();
    }

    cout << "In what form do you want to enter the number? 1 - Decimal, 2 - Binary" << endl;
    cin >> choice;

    cout << "Enter the third binary number: ";
    if (choice == 1) {
        cin >> decimal3;
        new (&N3) Numeral_2(decimal3);
    }
    else if (choice == 2) {
        cin >> binary3;
        new (&N3) Numeral_2(binary3);
    }
    else {
        error_massage();
    }


    ++N1; //1

    int incrementValue; //2
    cout << "Enter the value to increment N2: ";
    cin >> incrementValue;
    Numeral_2 incrementValueNumeral(incrementValue);
    N2 += incrementValueNumeral;


    N3 = N1 + N2; //3 


    int decimalN3 = N3.binaryToDecimal(N3.getBinaryNumber());//4


    cout << "N1: " << N1.getBinaryNumber() << endl;
    cout << "N2: " << N2.getBinaryNumber() << endl;
    cout << "N3: " << N3.getBinaryNumber() << " (decimal: " << decimalN3 << ")" << endl;

}