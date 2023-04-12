#include "class.h"

    string Numeral_2 :: decimalToBinary(int decimalNumber) {

        string binaryStr = "";

        if (decimalNumber == 0) {
            return "0";
        }

        while (decimalNumber > 0) {

            binaryStr = ((decimalNumber & 1) ? "1" : "0") + binaryStr;


            decimalNumber >>= 1;
        }

        return binaryStr;
    }

    //constructors
    Numeral_2 :: Numeral_2() {
        binaryNumber = "0";
    }
    Numeral_2:: Numeral_2(const string& binaryNumber) {
        this->binaryNumber = binaryNumber;
    }
    Numeral_2:: Numeral_2(int decimalNumber) {
        this->binaryNumber = decimalToBinary(decimalNumber);
    }

    //methods
    string Numeral_2 :: getBinaryNumber() {
        return binaryNumber;
    }
    int Numeral_2 :: binaryToDecimal(const string& binaryNumber) {
        int decimalNumber = 0;


        for (int i = binaryNumber.length() - 1; i >= 0; i--) {

            if (binaryNumber[i] == '1') {
                decimalNumber += pow(2, binaryNumber.length() - 1 - i);
            }
        }

        return decimalNumber;
    }

    //operators
    Numeral_2 & Numeral_2 :: operator++() {
        int res = binaryToDecimal(binaryNumber);
        res++;
        this->binaryNumber = decimalToBinary(res);
        return *this;
    }
    Numeral_2 Numeral_2 :: operator+(Numeral_2& other) {

        int var1 = binaryToDecimal(this->binaryNumber);
        int var2 = binaryToDecimal(other.binaryNumber);

        int var3 = 0;
        var3 = var1 + var2;

        Numeral_2 temp = decimalToBinary(var3);
        return temp;
    }
    Numeral_2& Numeral_2 :: operator +=(Numeral_2& other) {

        int var1 = binaryToDecimal(this->binaryNumber);
        int var2 = binaryToDecimal(other.binaryNumber);

        var1 += var2;

        this->binaryNumber = decimalToBinary(var1);

        return *this;
    }