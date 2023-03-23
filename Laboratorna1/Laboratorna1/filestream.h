#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

void greeting();
void interface();
void error_massage();

bool check_file_open_ifstream(ifstream& fin, const string& name);
bool check_file_open_ofstream(ofstream& fout, const string& name);

string name_file();
void read_file(ifstream& fin, const string& name);
void append_to_file(ofstream& fout, const string& name);


void choice1(ofstream& fout);
void choice2(ifstream& fin);
void choice3(ofstream& fout);
void find_hex_numbers(ifstream& fin, ofstream& fout);