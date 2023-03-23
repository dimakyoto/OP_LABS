#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;


char* choose_filename();
void create_file(const char* filename);
char* read_file(const char* filename);
void append_text_to_file(const char* filename);

void find_hex_numbers(const char* input_filename, const char* output_filename);

void choose1();
void choose2();
void choose3();
void choose4();