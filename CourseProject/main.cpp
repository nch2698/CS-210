#include <iostream>

#include "models.h"
#include "menu.h"
#include "storage.h"

using namespace std;

void init() {
    initStudentStorage();
    cin.putback('\n');
}

int main(int argc, char **argv) {

    init();

    cout << "\t\t\tPROJECT MANAGER" << endl;
    cout << "To show menu please enter ? or help.\n\n\n";
    getMenu();

    char choice;
    do {
        loopInterface(choice);
    } while (choice != '6');

    return 0;
}