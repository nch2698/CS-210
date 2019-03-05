#include <iostream>
#include <iomanip>
#include "Matrix.h"
#include "Player.h"
#include "supplements.h"

using namespace std;

int main() {
    int choice;
    bool isNotPlayed = true;
    Matrix matrix;
    Player *player[3];

    do {
        printMenu();
        choice = validateInput(1, 5);
        switch (choice) {
            case 1: {
                matrix.printCoordinates();
                cout << "A random matrix is created.\n"
                     << "To customize your own matrix, select 2.\n";
                break;
            }
            case 2: {
                //need privilege to see and change the color
                cout << "Do you save privilege?[Y/N]";
                char isPrivilege = getYesNo();
                if (toupper(isPrivilege) == 'N') break;

                while (true) {
                    matrix.printColorLabels();
                    cout << "Enter the coordinate of the square you want to change color : ";

                    cout << "\n\tRow: ";
                    int row = validateInput(1, 5);

                    cout << "\tColumn: ";
                    int col = validateInput(1, 3);

                    cout << "\tColor (0-Blue, 1-Green, 2-Red): ";
                    int color = validateInput(0, 2);

                    matrix.changeSquareColor(row, col, color);
                    matrix.printColorLabels();

                    cout << "Do you want to continue?[Y/N] ";
                    char keepOn = getYesNo();
                    if (toupper(keepOn) == 'N') break;
                }
                break;
            }
            case 3: {
                int color[3];
                char *name;

                cout << "Get Information\n"
                     << "---------------";

                for (int i = 0; i < 3; ++i) {

                    cout << "\nPlayer " << i + 1 << ": \n";
                    cout << "\tEnter name :";
                    cin.ignore();
                    name = new char[50];
                    cin.getline(name, 50);


                    do {
                        cout << "\tChoose color(0-Blue, 1-Green, 2-Red) :";
                        color[i] = validateInput(0, 2);
                        if (isDuplicated(i, color))
                            cout << "Color is duplicated!\n";
                    } while (isDuplicated(i, color));
                    player[i] = new Player(name, color[i]);
                }


                cout << "\nGame Start\n"
                     << "----------\n";
                bool hasWinner = false;

                while (true) {

                    for (int i = 0; i < 3; ++i) {
                        matrix.printCoordinates();
                        cout << "Player " << i + 1
                             << " (" << toColorLabel(player[i]->getColor()) << "): "
                             << player[i]->getName() << endl;
                        player[i]->play(matrix);
                        if (player[i]->getScores() == 5) {
                            cout << "You win!\n";
                            hasWinner = true;
                            break;
                        }
                    }
                    /* if there is  winner, game end.
                     * if not, ask for  playing again until there is a winner.
                     */
                    if (hasWinner) break;
                    else {
                        cout << "Play again?[Y/N]";
                        char keepOn = getYesNo();
                        if (toupper(keepOn) == 'N') break;
                    }


                }

                isNotPlayed = false;
                break;
            }
            case 4: {
                if (isNotPlayed) {
                    cout << "The game is not played.\n";
                    break;
                }

                cout << "                Scoreboard               \n"
                     << "-----------------------------------------\n";
                cout << left;
                cout << setw(4) << "ID" << setw(25) << "Name"
                     << setw(6) << "Color" << setw(2) << "Scores" << endl;
                for (int j = 0; j < 3; ++j) {
                    cout << setw(4) << j + 1 << setw(25) << player[j]->getName()
                         << setw(6) << toColorLabel(player[j]->getColor())
                         << setw(2) << player[j]->getScores() << endl;
                }
                cout << endl;

                cout << "Lowest and highest result\n"
                     << "-------------------------\n";
                int min = player[0]->getScores(),
                        max = player[0]->getScores(),
                        minPlayer = 0, maxPlayer = 0;

                for (int k = 0; k < 3; ++k) {
                    if (min > player[k]->getScores()) {
                        min = player[k]->getScores();
                        minPlayer = k;
                    }
                    if (max < player[k]->getScores()) {
                        maxPlayer = k;
                    }
                }

                cout << "Player " << minPlayer + 1 << " has lowest scores.\n";
                cout << "Player " << maxPlayer + 1 << " has highest scores.\n\n";
                break;
            }
            default: {
            }
        }
    } while (choice != 5);
    delete[] *player;
    return 0;

}