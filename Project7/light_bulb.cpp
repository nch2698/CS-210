#include <iostream>

using namespace std;

const int ROWS = 5, COLUMNS = 3;

void parseMenuChoice(int &);

void toggleByRow(int, int[ROWS][COLUMNS]);

void toggleByColumn(int, int[ROWS][COLUMNS]);

void toggleByPosition(int, int, int[ROWS][COLUMNS]);

void showLightMap(int[ROWS][COLUMNS]);

int main() {
    int theMap[ROWS][COLUMNS] = {0};

    int choice;
    do {
        parseMenuChoice(choice);
        int r = -1, c = -1;

        switch (choice) {
            case 1:
                cout << "Which row:\t";
                cin >> r;
                toggleByRow(r, theMap);
                break;
            case 2:
                cout << "Which column:\t";
                cin >> c;
                toggleByColumn(c, theMap);
                break;
            case 3:
                cout << "Which row - column:\t";
                cin >> r >> c;
                toggleByPosition(r, c, theMap);
                break;
            case 4:
                cout << "\n\n";
                showLightMap(theMap);
                break;
            case 5:
                cout << "Quitting...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 5);


    return 0;
}

void parseMenuChoice(int &choice) {
    cout << "\n\n";
    cout << "1. Switch on/off by row" << endl;
    cout << "2. Switch on/off by column" << endl;
    cout << "3. Switch on/off by position" << endl;
    cout << "4. Energy usage map." << endl;
    cout << "5. Quit." << endl;


    cout << "\nYour choice:\t";
    cin >> choice;
    cin.ignore(256, '\n');
}

void toggleByRow(int row, int lightMap[ROWS][COLUMNS]) {
    if (row >= ROWS || row < 0) return;

    for (int i = 0; i < COLUMNS; i++) {
        // 1 will be 0 and 0 will be 1,
        // 2,3,4 will be based on odd and even
        lightMap[row][i] = !lightMap[row][i];
    }
}

void toggleByColumn(int column, int lightMap[ROWS][COLUMNS]) {
    if (column >= COLUMNS || column < 0) return;
    for (int i = 0; i < ROWS; i++) {
        lightMap[i][column] = !lightMap[i][column];
    }
}

void toggleByPosition(int row, int column, int lightMap[ROWS][COLUMNS]) {
    lightMap[row][column] = !lightMap[row][column];
}

void showLightMap(int lightMap[ROWS][COLUMNS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int column = 0; column < COLUMNS; column++) {
            if (lightMap[row][column] == 0) {
                cout << "|  " << 0 << ' ';
                continue;
            }

            if (row % 2 == 0 && column % 2 == 0) {
                cout << "| " << 10 << ' ';
            } else if (row % 2 == 1 && column % 2 == 1) {
                cout << "| " << 20 << ' ';
            } else {
                cout << "| " << 15 << ' ';
            }
        }

        cout << '|' << endl;
    }
}

