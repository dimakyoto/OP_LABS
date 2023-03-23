#include "filepointer.h"

// Work with FILE C style
char* choose_filename() {
    char* name = new char[500];

    cout << "Enter name of the file (for example, file.txt): ";
    cin >> name;

    return name;
}
void create_file(const char* filename) {
    const char* text = nullptr;
    FILE* file = fopen(filename, "w");

    if (file == nullptr) {
        cout << "Unable to open file " << filename << endl;
        exit(1);
    }

    cout << "Enter text to write to the file: " << endl;
    cin.ignore();
    char input[5000];
    cin.getline(input, sizeof(input));

    if (fputs(input, file) == EOF) {
        cout << "Error writing to file " << filename << endl;
        exit(1);
    }

    if (fclose(file) != 0) {
        cout << "Error closing file " << filename << endl;
        exit(1);
    }
}
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        cout << "Unable to open file " << filename << endl;
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    rewind(file);

    char* buffer = new char[size + 1];
    size_t bytesRead = fread(buffer, sizeof(char), size, file);
    buffer[bytesRead] = '\0';

    if (fclose(file) != 0) {
        cout << "Error closing file " << filename << endl;
        exit(1);
    }

    return buffer;
}
void append_text_to_file(const char* filename) {
    const char* text = nullptr;
    FILE* file = fopen(filename, "a");

    if (file == nullptr) {
        cout << "Unable to open file " << filename << endl;
        exit(1);
    }

    cout << "Enter text to add to the file: " << endl;
    cin.ignore();
    char input[5000];
    cin.getline(input, sizeof(input));

    if (fputs("\n", file) == EOF) {
        cout << "Error writing to file " << filename << endl;
        exit(1);
    }

    if (fputs(input, file) == EOF) {
        cout << "Error writing to file " << filename << endl;
        exit(1);
    }

    if (fclose(file) != 0) {
        cout << "Error closing file " << filename << endl;
        exit(1);
    }
}

//Hexadecimal CONVERTATION C
void find_hex_numbers(const char* input_filename, const char* output_filename) {
    FILE* input_file = fopen(input_filename, "r");
    FILE* output_file = fopen(output_filename, "a");

    char* buffer = read_file(input_filename);
    char* line = strtok(buffer, "\r\n");
    while (line != nullptr) {
        stringstream ss(line);
        char* word = new char[100];
        while (ss >> word) {
            bool is_hex = true;
            for (int i = 0; i < strlen(word); i++) {
                if (!isxdigit(word[i])) {
                    is_hex = false;
                    break;
                }
            }
            if (is_hex) {
                int num = strtol(word, nullptr, 16);
                fprintf(output_file, "%s is %d in decimal\n", word, num);
            }
        }
        delete[] word;
        line = strtok(nullptr, "\r\n");
    }

    cout << "Conversion complete, you can prove it, just READ your new file" << endl;

    fclose(input_file);
    fclose(output_file);
    delete[] buffer;
}

// Cases C style
void choose1() {
    char* filename = choose_filename();
    create_file(filename);
    cout << "Your file was successfully created" << endl;
    delete[] filename;
}
void choose2() {
    char* filename = choose_filename();
    char* text = read_file(filename);
    cout << text << endl;
    delete[] text;
}
void choose3() {
    char* filename = choose_filename();
    append_text_to_file(filename);
    cout << "Your DATA was successfully added" << endl;
    delete[] filename;
}
void choose4() {
    char* input_filename = choose_filename();
    cout << endl << "Now you need too choose name file to which you convert your numbers!" << endl << endl;
    char* output_filename = choose_filename();
    find_hex_numbers(input_filename, output_filename);
}