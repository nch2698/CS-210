#include "menu.h"

using namespace std;

int groupInfo();
void clearScreen();

int getMenuChoice() {

    clearScreen();

    int choice;

    cout << "1. Group information." << endl
         << "2. Project (assignment) deadline declaration." << endl
         << "3. Statistic." << endl
         << "4. Overall Statistic." << endl
         << "5. Find groups do not complete or submit on time." << endl
         << "6. Quit." << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            groupInfo();
        default:
            return choice;
    }
}

int groupInfo() {
    clearScreen();
    cout << "1. Enter all students.\n";
    cout << "2. Enter all groups.\n";
}

void clearScreen() {
    for (int n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}

