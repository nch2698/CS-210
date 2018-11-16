#include <iostream>
#include <iomanip>

using namespace std;

double getLength();

double getWidth();

double getArea(double, double);

void displayData(double, double, double);

int main() {
    double l = getLength(), w = getWidth();
    cout << "\n\n";
    displayData(l, w, getArea(l, w));
    return 0;
}

double getLength() {
    double l;
    cout << "Enter rectangle length:\t";
    do {
        cin >> l;
        if (l <= 0)
            cout << "Length must > 0. Enter again:\t";
    } while (l <= 0);
    return l;
}

double getWidth() {
    double w;
    cout << "Enter rectangle width:\t";
    do {
        cin >> w;
        if (w <= 0)
            cout << "Width must > 0. Enter again:\t";
    } while (w <= 0);
    return w;
}

double getArea(double width, double height) {
    return width * height;
}

void displayData(double length, double width, double area) {
    const int OFFSET = 20;
    int m_l = static_cast<int> (length);
    int m_w = static_cast<int> (width);
    bool b = false;

    m_l = m_l > 14 ? m_l : 14;
    m_w = m_w > 5 ? m_w : 5;

    cout << setw(OFFSET) << "" << setw(m_l) << "Length: " << length << endl;

    for (int i = 0; i < m_w; i++) {

        if (i == (m_w - 1) / 2)
            cout << setw(OFFSET - 3 - 6) << "Width: " << setw(6) << left << width << "   ";
        else
            cout << setw(OFFSET) << "";

        for (int j = 0; j < m_l; j++) {
            if (i == 0 || i == m_w - 1 || j == 0 || j == m_l - 1)
                cout << "* ";
            else if (i == (m_w - 1) / 2) {
                if (!b)
                    cout << setw(m_l - 2) << right<< " Area: "
                         << setw(6) << left << area
                         << setw((m_l - 2) - 6) << "";
                b = true;
            } else
                cout << "  ";
        }
        cout << "\n";
    }
}