#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int age;
    double multiplier = 1.0, cost = 7.0;
    string clazz, movie, date = "Weekday";

    const int WIDTH_COLUMN1 = 35,
            WIDTH_COLUMN2 = 15;
    const int CHILD_AGE_CEIL = 18,
            SENIOR_AGE_FLOOR = 65;

    const int MAX_BUFFER = 256;

    const float CHILD_DISCOUNT_RATE = 0.5,
            SENIOR_DISCOUNT_RATE = 0.3;

    cout << setw(WIDTH_COLUMN1) << left << "How old are you:";
    cin >> age;

    // Initialize Customer Class and adjust multiplier
    // so that the price will be calculated after discount
    // Also announce customer his discount
    if (age < CHILD_AGE_CEIL) {
        multiplier = 1 - CHILD_DISCOUNT_RATE;
        clazz = "Child";
        cout << "Child: Discount " << CHILD_DISCOUNT_RATE * 100 << '%' << endl;
    } else if (age < SENIOR_AGE_FLOOR) {
        clazz = "Adult";
    } else {
        multiplier = 1 - SENIOR_DISCOUNT_RATE;
        clazz = "Senior Citizen";
        cout << "Senior Citizen: Discount " << SENIOR_DISCOUNT_RATE * 100
             << '%' << endl;
    }

    char y_or_n;
    cin.ignore(MAX_BUFFER, '\n');
    cout << setw(WIDTH_COLUMN1) << left << "Is your ticket on weekend: (Y/N)";
    cin.get(y_or_n);
    switch (y_or_n) {
        case 'y':
        case 'Y':
            cost = 10.0;
            date = "Weekend";
            break;
        case 'n':
        case 'N':
            break;
        default:
            cout << "\nYou enter an invalid information."
                 << "Please restart the program.\n";
            return 1;
    }

    // Select pre-selected movie or a movie of
    // customer preference
    int choice;
    cout << setw(WIDTH_COLUMN1) << left << "Which movie would you like to see:"
         << endl;
    cout << setw(WIDTH_COLUMN1) << left << "1. Venom" << endl;
    cout << setw(WIDTH_COLUMN1) << left << "2. Mr.Bean" << endl;
    cout << setw(WIDTH_COLUMN1) << left << "3. X-men" << endl;
    cout << setw(WIDTH_COLUMN1) << left << "4. Other (Enter name)" << endl;
    cout <<  "Your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            movie = "Venom";
            break;
        case 2:
            movie = "Mr.Bean";
            break;
        case 3:
            movie = "X-men";
            break;
        case 4:
            cout << setw(WIDTH_COLUMN1) << left << "Then enter your preferred movie:";
            cin.ignore(MAX_BUFFER, '\n');
            getline(cin, movie);
            break;
        default:
            cout << "\nYou enter an invalid information."
                 << "Please restart the program.\n";
            return 1;
    }

    cout << setw(WIDTH_COLUMN1) << left << "Movie selected:" << movie << endl;

    cout << "\n\n\n\n\n" << endl;

    cout << fixed << showpoint << setprecision(1);


    /**
     * The following code will look like this:
     *     -----------------------------------------------
     *     |Movie:                                  Venom|
     *     |Class:                                  Child|
     *     |Date:                                 Weekday|
     *     |Regular Price:                     $      7.0|
     *     |Discount Price:                    $      3.5|
     *     -----------------------------------------------
     */
    cout << setfill('-') << setw(WIDTH_COLUMN1 + WIDTH_COLUMN2 + 2)
         << "" << setfill(' ') << endl;
    cout << '|' << left << setw(WIDTH_COLUMN1) << "Movie:" << right
         << setw(WIDTH_COLUMN2) << movie << '|' << endl;
    cout << '|' << left << setw(WIDTH_COLUMN1) << "Class:" << right
         << setw(WIDTH_COLUMN2) << clazz << '|' << endl;
    cout << '|' << left << setw(WIDTH_COLUMN1) << "Date:" << right
         << setw(WIDTH_COLUMN2) << date << '|' << endl;
    cout << '|' << left << setw(WIDTH_COLUMN1) << "Regular Price:"
         << '$' << right << setw(WIDTH_COLUMN2 - 1) << 7.0
         << '|'
         << endl;
    cout << '|' << left << setw(WIDTH_COLUMN1) << "Discount Price:"
         << '$' << right << setw(WIDTH_COLUMN2 - 1)
         << cost * multiplier << '|'
         << endl;
    cout << setfill('-') << setw(WIDTH_COLUMN1 + WIDTH_COLUMN2 + 2) << "" << endl;

    return 0;
}