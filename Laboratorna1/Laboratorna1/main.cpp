#include "filestream.h"
#include "filepointer.h"



int main(int argc, char* argv[]) {
    ofstream outFile;
    ifstream inFile;
    int choiceMethod;


    if (argc != 3) {
        cout << "Invalid number of arguments. Usage: program_name [-mode FilePointer | -mode FileStream ]" << endl;
        return 1;
    }
    if (strcmp(argv[1], "-mode") != 0 || (strcmp(argv[2], "FilePointer") != 0 && strcmp(argv[2], "FileStream") != 0)) {
        cout << "Invalid argument. Usage: program_name -mode [FilePointer | FileStream ]";
        return 1;
    }

    greeting();

    do {
        interface();
        cin >> choiceMethod;

        if (strcmp(argv[2], "FileStream") == 0) {

            switch (choiceMethod) {
            case 1:
                choose1();
                break;

            case 2:
                choose2();
                break;

            case 3:
                choose3();
                break;

            case 4:
                choose4();
                break;
            default:
                error_massage();
            }
        }

        else if (strcmp(argv[2], "FilePointer") == 0) {
            switch (choiceMethod) {
            case 1:
                choice1(outFile);
                break;

            case 2:
                choice2(inFile);
                break;

            case 3:
                choice3(outFile);
                break;

            case 4:
                find_hex_numbers(inFile, outFile);
                break;

            default:
                error_massage();
            }
        }
        else {
            error_massage();
        }
    } while (choiceMethod != 0);
}




