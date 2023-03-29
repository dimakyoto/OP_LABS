#include  "functions.h"


//Describing the program
void greeting() {
    cout << endl << "This program has a class that is an abstraction of text and supports," << endl;
    cout << "The operations of adding string to the text and determining the number" << endl;
    cout << "Of doubled characters in the text." << endl;
    cout << "Create an array of objects of this class. Add new lines to several texts." << endl;
    cout << "In a new file, it can also generate a list of full-time students sorted by name," << endl;
    cout << "Determine the text with the largest number of doubled characters." << endl << "ENJOY!" << endl << endl;
}
//Printing error
int error_massage() {
    cout << "Oops, invalid choice,try again" << endl;
    cout << "You need to use only correct numbers like in instruction" << endl;
    return 1;
}
// Sorts the given array of Text objects by the number of doubled characters in each text
void sortByDoubledChars(Text* texts, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (texts[i].countDoubleCharOccurrences() < texts[j].countDoubleCharOccurrences()) {
                swap(texts[i], texts[j]);
            }
        }
    }
}
//Main
void code() {
    int stringnumbers;
    int choice = 0;

    //Number of strings input
    cout << "Enter the number of texts: ";
    cin >> stringnumbers;
    cout << endl;


    //Allocating memory for text array
    Text* texts = new Text[stringnumbers];

    // Input Text by user
    for (int i = 0; i < stringnumbers; ++i) {
        if (choice != 1) {
            cin.ignore();
        }
        string userinput, additional_text;

        cout << "Enter text " << i + 1 << " in format(abrakadabra): ";

        getline(cin, userinput);

        cout << "Do you want to add smth to you string? (Prees 1 - YES, 2 - NO): ";
        cin >> choice;


        if (choice == 1) {
            cout << "Enter additional text: ";
            cin.ignore();
            getline(cin, additional_text);
            userinput = userinput + additional_text;
            texts[i].text_append(userinput);
        }
        else if (choice == 2) {
            texts[i].text_append(userinput);
        }
        else {
            error_massage();
        }
    }

    // Show User`s Input
    cout << endl << "Your input:" << endl;
    for (int i = 0; i < stringnumbers; i++) {
        cout << "Text " << i + 1 << ": ";
        texts[i].print();
    }

    // Find Duplicates
    cout << endl << "Duplicate Character Occurrences:" << endl;
    for (int i = 0; i < stringnumbers; i++) {
        cout << "Text " << i + 1 << ": " << texts[i].countDoubleCharOccurrences() << endl;
    }

    // Sort texts by the number of doubled characters 
    sortByDoubledChars(texts, stringnumbers);

    // Print text with the most doubled characters
    cout << endl << "Text with the most doubled characters: " << endl;
    texts[0].print();
    delete[] texts;
}