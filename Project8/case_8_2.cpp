#include <iostream>
#include <iomanip>

using namespace std;

enum PRODUCT_TYPE {
    BOOK, AUDIO_CD, DVD
};

struct BookProduct {
    string name;
    PRODUCT_TYPE type;
    int number;
    double price;
};

const string prodTypeStr[] = {"Book", "Audio CD", "DVD"};

BookProduct STORE[] = {
        {"Six Steps to Leadership",   BOOK,     914, 12.95},
        {"Six Steps to Leadership",   AUDIO_CD, 915, 14.95},
        {"The Road to Excellence",    DVD,      916, 18.95},
        {"Seven Lessons of Quality",  BOOK,     917, 16.95},
        {"Seven Lessons of Quality",  AUDIO_CD, 918, 21.95},
        {"Seven Lessons of Quality",  DVD,      919, 31.95},
        {"Teams Are Made, Not Born",  BOOK,     920, 14.95},
        {"Leadership for the Future", BOOK,     921, 14.95},
        {"Leadership for the Future", AUDIO_CD, 922, 16.95}
};

int binarySearch(const int entity) {
    const int size = 9;
    int left_bound = 0,
            right_bound = size - 1,
            cursor = (left_bound + right_bound) / 2;
    while (true) {
        if (right_bound - left_bound <= 1 && STORE[cursor].number != entity) return -1;

        if (STORE[cursor].number == entity) {
            return cursor;
        } else if (STORE[cursor].number > entity) {
            right_bound = cursor;
            cursor = (left_bound + right_bound) / 2;
        } else {
            left_bound = cursor;
            cursor = (left_bound + right_bound) / 2;
        }
    }
}

void printProduct(int id) {
    int prodID = binarySearch(id);

    if (prodID == -1) {
        cout << "Unable to find Product with id " << id << endl;
    } else {
        cout << setw(30) << left << "Product Title"
             << setw(25) << "Product Description"
             << setw(20) << "Product Number"
             << setw(15) << "Unit Price"
             << endl;

        cout << setw(30) << left << STORE[prodID].name
             << setw(25) << prodTypeStr[STORE[prodID].type]
             << setw(20) << STORE[prodID].number << '$'
             << setw(14) << STORE[prodID].price
             << endl;
    }
}

void printAllProducts() {
    cout << setw(30) << left << "Product Title"
         << setw(25) << "Product Description"
         << setw(20) << "Product Number"
         << setw(15) << "Unit Price"
         << endl;

    for (int i = 0; i < 9; i++) {
        cout << setw(30) << left << STORE[i].name
             << setw(25) << prodTypeStr[STORE[i].type]
             << setw(20) << STORE[i].number << '$'
             << setw(14) << STORE[i].price
             << endl;
    }
}

void sortByPrice(const int size) {

    for (int i = 0; i < size; i++) {
        double temp = STORE[i].price;
        int index = i;
        for (int j = i; j < size; j++) {
            if (temp > STORE[j].price) {
                temp = STORE[j].price;
                index = j;
            }
        }
        BookProduct bp = STORE[i];
        STORE[i] = STORE[index];
        STORE[index] = bp;
    }
}

void sortByName(const int size) {
    for (int i = 0; i < size; i++) {
        string temp = STORE[i].name;
        int index = i;
        for (int j = i; j < size; j++) {
            if (temp > STORE[j].name) {
                temp = STORE[j].name;
                index = j;
            }
        }
        BookProduct bp = STORE[i];
        STORE[i] = STORE[index];
        STORE[index] = bp;
    }
}

void sortByID(const int size) {
    for (int i = 0; i < size; i++) {
        int temp = STORE[i].number;
        int index = i;
        for (int j = i; j < size; j++) {
            if (temp > STORE[j].number) {
                temp = STORE[j].number;
                index = j;
            }
        }
        BookProduct bp = STORE[i];
        STORE[i] = STORE[index];
        STORE[index] = bp;
    }
}

int main() {
    return 0;
}