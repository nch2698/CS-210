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

    int hour = 11, minute = 59;
    char am_or_pm = 'p';

    // 11:59 PM
    cout << "Add 1 minute to "
         << hour << ':' << minute << ' ' << "PM";

    add_a_minute(&hour, &minute, &am_or_pm);

    // 12:00 AM
    cout << " and it becomes "
         << hour << ':' << minute << ' '
         << (am_or_pm == 'a' ? "AM" : "PM") << endl;

    hour = 12;
    minute = 59;
    am_or_pm = 'a';

    // 12:59 AM
    cout << "Then reset to "
         << hour << ':' << minute << ' ' << "AM. ";

    cout << "Add 1 minute to "
         << hour << ':' << minute << ' ' << "AM";

    add_a_minute(&hour, &minute, &am_or_pm);

    // 01:00 AM
    cout << " and it becomes "
         << hour << ':' << minute << ' '
         << (am_or_pm == 'a' ? "AM" : "PM") << endl;

    cout << "Add 1 minute to "
         << hour << ':' << minute << ' ' << "AM";

    add_a_minute(&hour, &minute, &am_or_pm);

    // 01:01 AM
    cout << " and it becomes "
         << hour << ':' << minute << ' '
         << (am_or_pm == 'a' ? "AM" : "PM") << endl;

    return 0;
}