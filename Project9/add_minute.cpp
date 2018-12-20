#include <iostream>

using namespace std;

void add_a_minute(int *h, int *m, char *ap) {

    *ap = *ap == 'a' || *ap == 'p' ? *ap : 'a';
    *m += 1;

    if ((*m %= 60) == 0) {
        *h += 1;
    }

    if (*h % 12 == 0) {
        *ap = *ap == 'a' ? 'p' : 'a';
        *h = 12;
    } else *h %= 12;
}

int main() {

    int hour = 10, minute = 59;
    char am_or_pm = 'p';

    cout << "Add 1 minute to "
         << hour << ':' << minute << ' ' << "PM";

    add_a_minute(&hour, &minute, &am_or_pm);

    cout << " and it becomes "
         << hour << ':' << minute << ' '
         << (am_or_pm == 'a' ? "AM" : "PM") << endl;

    return 0;
}