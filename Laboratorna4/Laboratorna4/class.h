#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Numeral_2 {

private:

    string binaryNumber;
    string decimalToBinary(int decimalNumber);

public:

    //constructors
    Numeral_2();
    Numeral_2(const string& binaryNumber);
    Numeral_2(int decimalNumber);

    //methods
    string getBinaryNumber();
    int binaryToDecimal(const string& binaryNumber);

    //operators
    Numeral_2& operator++();
    Numeral_2 operator+(Numeral_2& other);
    Numeral_2& operator +=(Numeral_2& other);

};