#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {

    const int RANGE = 3;

    // Seeding random
    srand(time(0));
    long rand = 1 + random() % RANGE;

    int i;

    cout << "Pick The Number Game\n\n";
    cout << "Enter a number:\t";
    cin >> i;

    if (i < rand) {
        cout << "That number is higher." << endl;
    } else if ( i > rand) {
        cout << "That number is lower." << endl;
    } else {
        cout << "CORRECT!!!" << endl;
    }
    
    return 0;
}