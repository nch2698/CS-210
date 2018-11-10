#include <iostream>

using namespace std;

int main() {

    const int size = 7;

    cout << "a>\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if (i == 0 || i == size -1) cout << "* ";
            else if (j == 0 || j == size -1) cout << "* ";
            else cout << "  ";
        }
        cout << '\n';
    }

    cout << "b>\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if (i == 0 || i == size -1) cout << "* ";
            else if (j == i) cout << "* ";
            else cout << "  ";
        }
        cout << '\n';
    }

    cout << "c>\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if (i == 0 || i == size -1) cout << "* ";
            else if (j == size - i - 1) cout << "* ";
            else cout << "  ";
        }
        cout << '\n';
    }

    cout << "d>\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if (i == 0 || i == size -1) cout << "* ";
            else if (j == size - i - 1 || j == i) cout << "* ";
            else cout << "  ";
        }
        cout << '\n';
    }

    cout << "e>\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            if (i == 0 || i == size -1) cout << "* ";
            else if (j == size - i - 1 || j == i || j == 0 || j == size - 1) cout << "* ";
            else cout << "  ";
        }
        cout << '\n';
    }

    return 0;
}