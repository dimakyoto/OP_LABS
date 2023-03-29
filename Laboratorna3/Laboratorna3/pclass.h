#pragma once
#include <iostream>
#include <string>
using namespace std;

class Text {

private:
    string text;

public:

    Text();

    void text_append(string str);

    int countDoubleCharOccurrences();

    void print();
};