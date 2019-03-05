//
// Created by nch on 2/27/2019.
//
#include "supplements.h"
#include <iostream>

using namespace std;

void printMenu() {
    cout << "\n--------Menu--------\n"
         << "1. Create a matrix\n"
         << "2. Change the matrix color\n"
         << "3. Play\n"
         << "4. Scoreboard\n"
         << "5. Quit\n"
         << "Your choice ? ";
}

string toColorLabel(int colorValue) {
    string colorName;
    if (colorValue == 0) colorName = "Blue";
    if (colorValue == 1) colorName = "Green";
    if (colorValue == 2) colorName = "Red";
    return colorName;
}

int validateInput(int min, int max) {
    int input;

    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Incorrect type of input\n";
            cout << "Please re-enter: ";
        } else if (input < min || input > max) {
            cin.ignore(256, '\n');
            cout << "Input is out of range.\n";
            cout << "Please re-enter: ";
        } else break;
    }
    return input;
}

char getYesNo() {
    char input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Incorrect type of input\n";
            cout << "Please re-enter: ";
        } else if (toupper(input) != 'Y' && toupper(input) != 'N') {
            cin.ignore(256, '\n');
            cout << "Please re-enter: ";
        } else break;
    }
    return input;
}

bool isDuplicated(int i, int arr[]){
    for (int  k = 0; k < i; ++k) {
        if (arr[i] == arr[k])
            return true;
    }
    return false;
}