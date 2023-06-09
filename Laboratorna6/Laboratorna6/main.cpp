#include "hashtable.h"

int main() {
    int choice;
    cout << "Choose the type of data (1 - int(int), 2 - string(int), 3 - double(int), 4 - char(int)): " << endl;
    cout << "5 - int(string), 6 - double(char)" << endl;
    cin >> choice;

    int size;
    cout << "Enter the size of the table : " << endl;
    cin >> size;

    if (choice == 1) {
        HashTable<int, int> ht(size);
        ht.interface();
    }
    else if (choice == 2) {
        HashTable<string, int> ht(size);
        ht.interface();
    }
    else if (choice == 3) {
        HashTable<double, int> ht(size);
        ht.interface();
    }
    else if (choice == 4) {
        HashTable<char, int> ht(size);
        ht.interface();
    }
    else if (choice == 5) {
        HashTable<int, string> ht(size);
        ht.interface();
    }
    else if (choice == 6) {
        HashTable<double, char> ht(size);
        ht.interface();
    }
    else {
        cout << "Invalid choice." << endl;
    }
    return 0;
}
