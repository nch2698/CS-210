#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

const int PRODUCTS = 9;

enum SORTED_TYPE {
    TITLE, ID, PRICE
};

SORTED_TYPE currentlySorted = ID;

string PRODUCT_TITLE[PRODUCTS] = {
        "Six Steps to Leadership",
        "Six Steps to Leadership",
        "The Road to Excellence",
        "Seven Lessons of Quality",
        "Seven Lessons of Quality",
        "Seven Lessons of Quality",
        "Teams Are Made, Not Born",
        "Leadership for the Future",
        "Leadership for the Future"
};

string PRODUCT_DESCRIPTION[PRODUCTS] = {
        "Book",
        "Audio CD",
        "DVD",
        "Book",
        "Audio CD",
        "DVD",
        "Book",
        "Book",
        "Audio CD"
};

int PRODUCT_NUMBER[PRODUCTS] = {
        914, 915, 916, 917, 918,
        919, 920, 921, 922
};

double PRODUCT_PRICE[PRODUCTS] = {
        12.95, 14.95, 18.95, 16.95,
        21.95, 31.95, 14.95, 14.95, 16.95
};

void printAllProducts() {
    cout << setw(30) << left << "Product Title"
         << setw(25) << "Product Description"
         << setw(20) << "Product Number"
         << setw(15) << "Unit Price"
         << endl;

    for (int i = 0; i < PRODUCTS; i++) {
        cout << setw(30) << left << PRODUCT_TITLE[i]
             << setw(25) << PRODUCT_DESCRIPTION[i]
             << setw(20) << PRODUCT_NUMBER[i] << '$'
             << setw(14) << PRODUCT_PRICE[i]
             << endl;
    }
}

void parallelSwap(int from, int to) {

    if (from == to)
        return;

    string tempTitle = PRODUCT_TITLE[to];
    string tempDesc = PRODUCT_DESCRIPTION[to];
    int tempNum = PRODUCT_NUMBER[to];
    double tempPrice = PRODUCT_PRICE[to];

    PRODUCT_TITLE[to] = PRODUCT_TITLE[from];
    PRODUCT_DESCRIPTION[to] = PRODUCT_DESCRIPTION[from];
    PRODUCT_NUMBER[to] = PRODUCT_NUMBER[from];
    PRODUCT_PRICE[to] = PRODUCT_PRICE[from];

    PRODUCT_TITLE[from] = tempTitle;
    PRODUCT_DESCRIPTION[from] = tempDesc;
    PRODUCT_NUMBER[from] = tempNum;
    PRODUCT_PRICE[from] = tempPrice;
}

void sortByPrice() {
    for (int i = 0; i < PRODUCTS; i++) {
        double temp = PRODUCT_PRICE[i];
        int k = i;
        for (int j = i; j < PRODUCTS; j++) {
            if (PRODUCT_PRICE[j] < temp) {
                temp = PRODUCT_PRICE[j];
                k = j;
            }
        }
        parallelSwap(i, k);
    }
    currentlySorted = PRICE;
}

void sortByName() {
    for (int i = 0; i < PRODUCTS; i++) {
        string temp = PRODUCT_TITLE[i];
        int k = i;
        for (int j = i; j < PRODUCTS; j++) {
            if (PRODUCT_TITLE[j] < temp) {
                temp = PRODUCT_TITLE[j];
                k = j;
            }
        }
        parallelSwap(i, k);
    }
    currentlySorted = TITLE;
}

void sortByNumber() {
    for (int i = 0; i < PRODUCTS; i++) {
        int temp = PRODUCT_NUMBER[i];
        int k = i;
        for (int j = i; j < PRODUCTS; j++) {
            if (PRODUCT_NUMBER[j] < temp) {
                temp = PRODUCT_NUMBER[j];
                k = j;
            }
        }
        parallelSwap(i, k);
    }
    currentlySorted = ID;
}

int binarySearch(int productID) {

    int leftBound = 0, rightBound = PRODUCTS - 1,
            cursor = (leftBound + rightBound) / 2;

    for (;;) {
        if (rightBound - leftBound <= 1
            && PRODUCT_NUMBER[cursor] != productID)
            return -1;

        if (PRODUCT_NUMBER[cursor] == productID) return cursor;
        else if (PRODUCT_NUMBER[cursor] > productID) {
            rightBound = cursor;
            cursor = (leftBound + rightBound) / 2;
        } else {
            leftBound = cursor;
            cursor = static_cast<int>(
                    ceil((leftBound + rightBound) / 2.0));
        }
    }
}

int binarySearch(const string &title) {
    int leftBound = 0, rightBound = PRODUCTS - 1,
            cursor = (leftBound + rightBound) / 2;

    for (;;) {
        if (rightBound - leftBound <= 1
            && PRODUCT_TITLE[cursor] != title)
            return -1;

        if (PRODUCT_TITLE[cursor] == title) return cursor;
        else if (PRODUCT_TITLE[cursor] > title) {
            rightBound = cursor;
            cursor = (leftBound + rightBound) / 2;
        } else {
            leftBound = cursor;
            cursor = static_cast<int>(
                    ceil((leftBound + rightBound) / 2.0));
        }
    }
}

int binarySearch(double price) {
    int leftBound = 0, rightBound = PRODUCTS - 1,
            cursor = (leftBound + rightBound) / 2;

    for (;;) {
        if (rightBound - leftBound <= 1
            && PRODUCT_PRICE[cursor] != price)
            return -1;

        if (PRODUCT_PRICE[cursor] == price) return cursor;
        else if (PRODUCT_PRICE[cursor] > price) {
            rightBound = cursor;
            cursor = (leftBound + rightBound) / 2;
        } else {
            leftBound = cursor;
            cursor = static_cast<int>(
                    ceil((leftBound + rightBound) / 2.0));
        }
    }
}

void printProduct(int productID) {
    int index = binarySearch(productID);

    if (index == -1) {
        cout << "Unable to find Product with id " << productID << endl;
    } else {

        cout << setw(30) << left << "Product Title"
             << setw(25) << "Product Description"
             << setw(20) << "Product Number"
             << setw(15) << "Unit Price"
             << endl;

        cout << setw(30) << left << PRODUCT_TITLE[index]
             << setw(25) << PRODUCT_DESCRIPTION[index]
             << setw(20) << PRODUCT_NUMBER[index] << '$'
             << setw(14) << PRODUCT_PRICE[index]
             << endl;

    }
}

void printProduct(double price) {
    int index = binarySearch(price);

    if (index == -1) {
        cout << "Unable to find Product with price $" << price << endl;
    } else {

        cout << setw(30) << left << "Product Title"
             << setw(25) << "Product Description"
             << setw(20) << "Product Number"
             << setw(15) << "Unit Price"
             << endl;

        cout << setw(30) << left << PRODUCT_TITLE[index]
             << setw(25) << PRODUCT_DESCRIPTION[index]
             << setw(20) << PRODUCT_NUMBER[index] << '$'
             << setw(14) << PRODUCT_PRICE[index]
             << endl;

    }
}

void printProduct(const string &title) {
    int index = binarySearch(title);

    if (index == -1) {
        cout << "Unable to find Product with title " << title << endl;
    } else {

        cout << setw(30) << left << "Product Title"
             << setw(25) << "Product Description"
             << setw(20) << "Product Number"
             << setw(15) << "Unit Price"
             << endl;

        cout << setw(30) << left << PRODUCT_TITLE[index]
             << setw(25) << PRODUCT_DESCRIPTION[index]
             << setw(20) << PRODUCT_NUMBER[index] << '$'
             << setw(14) << PRODUCT_PRICE[index]
             << endl;

    }
}

void getMenuChoice(int &choice) {
    cout << "\n\n\n\t\tBookstore Manager\t\t\n";
    cout << "\t1. Print All Products.\n";
    cout << "\t2. Search a product by id.\n";
    cout << "\t3. Search a product by title.\n";
    cout << "\t4. Search a product by price.\n";
    cout << "\t5. Sort products by title.\n";
    cout << "\t6. Sort products by id.\n";
    cout << "\t7. Sort products by price.\n";
    cout << "\t8. Exit program.\n\n";
    cout << "Your choice:\t";
    cin >> choice;
}

int main() {
    int choice;

    do {
        getMenuChoice(choice);
        // Each case content is wrapped inside a pair of brackets
        // because we want each case variable to be independent and
        // to be deleted in stack memory after each iteration.
        switch (choice) {
            case 1:
                printAllProducts();
                break;
            case 2: {
                // if not surrounded by a bracket
                // compiler will throw an error
                int id;
                cout << "\n\nWhich Product do you want to search (id):\t";
                cin >> id;
                if (currentlySorted != ID) sortByNumber();
                printProduct(id);
                break;
            }
            case 3: {
                string name;
                cout << "\n\nWhich Product do you want to search (name):\t";
                cin.ignore(256, '\n');
                getline(cin, name);
                if (currentlySorted != TITLE) sortByName();
                printProduct(name);
                break;
            }
            case 4: {
                double p;
                cout << "\n\nWhich Product do you want to search (price):\t";
                cin >> p;
                if (currentlySorted != PRICE) sortByPrice();
                printProduct(p);
                break;
            }
            case 5:
                sortByName();
                cout << "Sorted!\n";
                break;
            case 6:
                sortByNumber();
                cout << "Sorted!\n";
                break;
            case 7:
                sortByPrice();
                cout << "Sorted!\n";
                break;
            case 8:
                cout << "Quitting!\n";
                break;
            default:
                cout << "Something went wrong!\n" << endl;
        }
    } while (choice != 8);

    return 0;
}

