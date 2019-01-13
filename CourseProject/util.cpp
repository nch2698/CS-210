#include "util.h"

const char *BAR = " | ";

void assertInt(int &i, int min, int max) {
    do {
        if (cin.fail()) {
            cout << "Expecting a number, try again!" << endl;
            cin.clear();
            cin.ignore(MAX_BUFFER, '\n');
            cin.putback('\n');
        }
        cin >> i;

        if (i < min) {
            cout << "Entered value " << i << " is too small. Required to be greater than " << min << ". Enter again\n";
        } else if (i > max) {
            cout << "Entered value " << i << " is too large. Required to be smaller than " << min << ". Enter again\n";
        }
    } while (i < min || i > max);
}

void assertYesNo(char &c) {
    do {
        getChoice(c);
        if (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
            cout << "Only accept (Y)es or (N)o value.\n";
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
}

bool assertStudentDuplicate(Student &s) {
    int i = hasStudentWithName(s.name);
    if (i != -1) {
        Student dub = getStudentByID(i);
        cout << "Do you mean student " << dub.name
             << " of group " << dub.group_id + 1
             << "? (y or n)" << endl;
        char c;
        assertYesNo(c);
        if (c == 'y' || c == 'Y') {
            cout << "Student cannot belong to 2 groups at the same time.\n";
            return true;
        }
    }
    return false;
}

void assertStringEmpty(string &s) {
    do {
        cin.ignore(MAX_BUFFER, '\n');
        getline(cin, s);
        cin.putback('\n');
        if (s.empty())
            cout << "Do not accept empty string, string must have something.\n";
    } while (s.empty());
}

void getChoice(char &c) {
    cout << "\nPM> ";
    cin.ignore(MAX_BUFFER, '\n');
    cin >> c;
}

void printLabels() {
    cout << BAR
         << left << setw(10) << "Group" << BAR
         << left << setw(25) << "Student\'s name" << BAR
         << left << setw(69) << "                    Check the submission" << BAR
         << endl;
    cout << BAR << setw(10) << "" << BAR << setw(25) << "" << BAR;

    for (int i = 0; i < 6; ++i) {
        cout << "Project " << i + 1 << BAR;
    }

    cout << endl;

//    for (int j = 0; j < 10 + 25 + 69 + 3 * 4; ++j) {
//        if (j == 10 + 3);
//        cout << '-';
//    }

    cout << " |------------|---------------------------|-----------|"
            "-----------|-----------|-----------|-----------|-----------|" << endl;
}

void printGroup(Group group) {
    cout << BAR
         << left << setw(10) << group.group_id + 1 << BAR
         << left << setw(25) << getStudentByID(group.students[0]).name << BAR
         << endl;

    for (int i = 1; i < group.num; ++i) {
        int studentID = group.students[i];

        cout << BAR
             << setw(10) << "" << BAR
             << left << setw(25) << getStudentByID(studentID).name << BAR
             << endl;

    }
}

void printGroup(int groupID) {
    cout << BAR
         << left << setw(10) << groupID + 1 << BAR
         << left << setw(25) << getStudentByID(getGroupByID(groupID).students[0]).name << BAR
         << endl;

    for (int i = 1; i < getGroupByID(groupID).num; ++i) {
        int studentID = getGroupByID(groupID).students[i];

        cout << BAR
             << setw(10) << "" << BAR
             << left << setw(25) << getStudentByID(studentID).name << BAR
             << endl;

    }

}