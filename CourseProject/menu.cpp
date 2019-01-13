#include "menu.h"

using namespace std;

void enterAllGroupMembers();

void enterOneGroup();

void modifyAGroup();

void getGroupInfoMenu();

void getDeadlineMenu();

void getStatisticMenu();

void getSubmissionMenu();

void loopInterface(char &c) {
    getChoice(c);

    switch (c) {
        case '1':
            getGroupInfoMenu();
            break;
        case '2':
            getDeadlineMenu();
            break;
        case '3':
            getStatisticMenu();
            break;
        case '4':
            getStatisticMenu();
            break;
        case '5':
            getSubmissionMenu();
            break;
        case '6':
            cout << "Exiting...\n";
            break;
        case '?':
        case 'h':
            getMenu();
            break;
        default:
            cout << "Enter ? to get all available services.\n";
    }

}

void getMenu() {
    cout << "\n1. Group information.\n"
         << "2. Project (assignment) deadline declaration.\n"
         << "3. Statistic.\n"
         << "4. Overall Statistic.\n"
         << "5. Find groups do not complete or submit on time.\n"
         << "6. Quit.\n" << endl;
}


void getGroupInfoMenu() {


    char c;
    getChoice(c);

    switch (c) {
        case '1':
            enterAllGroupMembers();
            break;
        case '2':
            enterOneGroup();
            break;
        case '3':
            modifyAGroup();
            break;
        case '4':
        case '5': {
            printLabels();
            for (int i = 0; i < getCurrentGroupNumber(); ++i) {
                printGroup(i);
            }
        }
            break;
        case '6':
            getMenu();
            return;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
            return;
    }

}

void getDeadlineMenu() {
    cout << "\nDeadline Menu\n"
         << "1. Return to main menu\n";

    char c;
    getChoice(c);

    switch (c) {
        case '1':
            return;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
            return;
    }
}

void getStatisticMenu() {
    cout << "\nStatistic Menu\n"
         << "1. Return to main menu\n";

    char c;
    getChoice(c);

    switch (c) {
        case '1':
            return;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
            return;
    }
}

void getSubmissionMenu() {
    cout << "\nSubmission Menu\n"
         << "1. Return to main menu\n";

    char c;
    getChoice(c);

    switch (c) {
        case '1':
            return;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
            return;
    }
}

void enterAllGroupMembers() {

    cout << "\n\n\n\n";

    int groupNum;
    cout << "How many groups are there?\t";
    assertInt(groupNum, 0, 1 << 8);

    initGroupStorage(groupNum);

    for (int i = 0; i < groupNum; ++i) {

        int groupId = i + 1;
        int studentNum = 0;

        cout << "===========================================\n";
        cout << "Entering Group " << groupId << " information.\n";
        cout << "How many students in group " << groupId << "?\t";
        assertInt(studentNum, MIN_GROUP_MEMBERS, MAX_GROUP_MEMBERS);

        for (int j = 0; j < studentNum; ++j) {
            Student s;
            cout << "- Student " << j + 1 << ":\n";
            cout << "\tStudent\'s name:\t";
            assertStringEmpty(s.name);

            if (assertStudentDuplicate(s)) {
                j--;
                continue;
            }

            s.group_id = i;
            s.id = getStudentStorageCursor();
            advanceStudentCursor();
            addStudent(s);
            cout << "\n";
        }
    }

    cin.putback('\n');
}

void enterOneGroup() {
    int groupId = getCurrentGroupNumber() + 1;
    int studentNum = 0;

    Group g = {};
    g.group_id = groupId - 1;

    cout << "===========================================\n";
    cout << "Entering Group " << groupId << " information.\n";
    cout << "How many students in group " << groupId << "?\t";
    assertInt(studentNum, MIN_GROUP_MEMBERS, MAX_GROUP_MEMBERS);

    for (int j = 0; j < studentNum; ++j) {
        Student s;
        cout << "- Student " << j + 1 << ":\n";
        cout << "\tStudent\'s name:\t";
        assertStringEmpty(s.name);

        if (assertStudentDuplicate(s)) {
            j--;
            continue;
        }

        s.group_id = groupId - 1;
        s.id = getStudentStorageCursor();
        advanceStudentCursor();
        addStudent(s, false);
        g.students[g.num++] = s.id;
        cout << "\n";
    }

    addAGroup(g);

    cin.putback('\n');
}

void modifyAGroup() {
    cout << "Which group do you want to modify?\t";
    int id;
    assertInt(id, 1, getCurrentGroupNumber());

    Group group = {};
    group.group_id = id;

    cout << "===========================================\n";
    cout << "Entering Group " << id + 1 << " information.\n";
    cout << "How many students in group " << id + 1 << "?\t";
    int studentNum;
    assertInt(studentNum, MIN_GROUP_MEMBERS, MAX_GROUP_MEMBERS);

    for (int j = 0; j < studentNum; ++j) {
        Student s;
        cout << "- Student " << j + 1 << ":\n";
        cout << "\tStudent\'s name:\t";
        assertStringEmpty(s.name);

        if (assertStudentDuplicate(s)) {
            j--;
            continue;
        }

        s.id = getStudentStorageCursor();
        advanceStudentCursor();
        addStudent(s, false);
        group.students[group.num++] = s.id;
        cout << "\n";
    }

    modifyGroup(group);
}