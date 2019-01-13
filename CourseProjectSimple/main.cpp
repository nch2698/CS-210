#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

/**
 *  Configuration
 */
const int MAX_GROUP_MEMBERS = 20;
const int MIN_GROUP_MEMBERS = 1;
const int MAX_BUFFER = 256;
const int MAX_INT_16 = 65536;
const int MAX_PROJECTS_NUMBER = 10;
const int MIN_PROJECTS_NUMBER = 3;

const char *PROGRAM_NAME = "Project Manager";
const char *INITIAL = ">_ ";
const char *BAR = " | ";

const char *GROUPS_SAVED_PATH = "groups.txt";
const char *STATISTICS_SAVED_PATH = "Overall Statistics.txt";

const int MONTHS_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int MONTHS_DAYS_4[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 *  Structures
 */
enum PROJECT_STATUS {
    ON_TIME, LATE, NOT_YET
};

struct Student {
    string name;
    int group;
};

struct Date {
    int dd, mm, yy;
};

struct Group {
    Student members[MAX_GROUP_MEMBERS];
    int memberNumber;
    Date submitProjects[MAX_PROJECTS_NUMBER];
    bool submit[MAX_PROJECTS_NUMBER];
};

/**
 * Storage
 */
Group *_groups;
int currentNumberOfGroups = 0;

Date *_dueDates;

int currentNumberOfProjects = 0;

/**
 * Prototype
 */
void mainMenu();

void groupInfoMenu();

void enterGroupsInfo(Group **);

void printLabels();

void printLabels(bool);

void printGroup(int);

void saveToFile();

void deadlineMenu();

void editDueDate();

void editAllDueDate();

void submitProjectToGroup();

void statisticsMenu();

void statisticsOfAProject();

void statisticsOfAGroup();

void overallMenu();

void overallStatisticsForAPeriod(Date &finalDate);

void overAllStatisticForTheWhole();

void failGroups();

void getChar(char &);

void assertInt(int &, int, int);

void assertYesNo(char &);

void assertStringEmpty(string &);

bool assertStudentDuplicate(Student &);

void assertDate(Date &);

bool isBefore(Date &, Date &);

PROJECT_STATUS getProjectStatus(int, int);

void clearGroupMemory(int);

/**
 * Program start here
 */
int main() {
    _dueDates = new Date[MAX_PROJECTS_NUMBER];
    Date temp = {};
    for (int i = 0; i < MAX_PROJECTS_NUMBER; ++i) {
        _dueDates[i] = temp;
    }

    cout << PROGRAM_NAME << endl;
    mainMenu();
    cout << "To show main menu, please press ?" << endl;
    char choice;
    cin.putback('\n');
    do {
        getChar(choice);

        switch (choice) {
            case '1':
                groupInfoMenu();
                break;
            case '2':
                deadlineMenu();
                break;
            case '3':
                statisticsMenu();
                break;
            case '4':
                overallMenu();
                break;
            case '5':
                failGroups();
                break;
            case '6':
                cout << "Exiting...";
                break;
            case '?':
                mainMenu();
                break;
            default:
                cout << "To show main menu, please press ?" << endl;
        }
    } while (choice != '6');
}

/**
 * Menus
 */
void mainMenu() {
    cout << "\n1. Group information.\n"
         << "2. Project (assignment) deadline declaration.\n"
         << "3. Statistic.\n"
         << "4. Overall Statistic.\n"
         << "5. Find groups do not complete or submit on time.\n"
         << "6. Quit.\n" << endl;
}

void groupInfoMenu() {
    cout << "\nGroup Information Menu\n"
         << "1. Enter all groups information\n"
         << "2. Display all groups\' members\n"
         << "3. Display a groups' members\n"
         << "4. Save to file groups.txt\n"
         << "5. Back to main menu\n";

    char choice;
    getChar(choice);

    switch (choice) {
        case '1':
            enterGroupsInfo(&_groups);
            break;
        case '2': {
            printLabels();
            for (int i = 0; i < currentNumberOfGroups; ++i) {
                printGroup(i);
            }
        }
            break;
        case '3': {
            cout << "Which group do you want to check?\t";
            int groupName;
            assertInt(groupName, 1, currentNumberOfGroups);
            printLabels();
            printGroup(groupName - 1);
        }
            break;
        case '4':
            saveToFile();
            break;
        case '5':
            mainMenu();
            break;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
    }
}

void enterGroupsInfo(Group **oldGroupsLoc) {
    cout << "How many groups are there?\t";
    int groupNum;
    assertInt(groupNum, 0, MAX_INT_16);

    if (*oldGroupsLoc == nullptr) {
        *oldGroupsLoc = new Group[groupNum];
        currentNumberOfGroups = groupNum;
        clearGroupMemory(groupNum);
    } else {
        Group *temp = new Group[groupNum];

        for (int i = 0; i < currentNumberOfGroups; ++i) {
            temp[i] = *(*oldGroupsLoc + i);
        }

        delete[] *oldGroupsLoc;
        *oldGroupsLoc = temp;
        currentNumberOfGroups = groupNum;
        clearGroupMemory(groupNum);
    }

    for (int i = 0; i < groupNum; ++i) {
        int studentNum = 0;
        int groupName = i + 1;

        cout << "===========================================\n";
        cout << "Entering Group " << groupName << " information.\n";
        cout << "How many students in group " << groupName << "?\t";
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

            s.group = i;

            _groups[i].members[j] = s;
            _groups[i].memberNumber++;
            cout << "\n";
        }
    }
}

void printLabels() {
    printLabels(false);
}

void printLabels(bool withSubmission) {
    cout << BAR
         << left << setw(10) << "Group" << BAR << left << setw(25)
         << "Student\'s name" << BAR;

    if (withSubmission) {
        cout << left << setw(currentNumberOfProjects * 12 - 3) << "Check the submission" << BAR
             << endl;
        cout << BAR << setw(10) << "" << BAR << setw(25) << "" << BAR;

        cout << " |------------|---------------------------|";

        for (int i = 0; i < currentNumberOfProjects; ++i) {
            cout << "Project " << i + 1 << BAR;
        }

        cout << endl;

        for (int j = 0; j < currentNumberOfProjects; ++j) {
            cout << "-----------|";
        }

        cout << endl;
    } else {
        cout << "\n |------------|---------------------------|";
        cout << endl;
    }

}

void printGroup(int groupID) {
    cout << BAR
         << left << setw(10) << groupID + 1 << BAR
         << left << setw(25) << _groups[groupID].members[0].name << BAR
         << endl;

    for (int i = 1; i < _groups[groupID].memberNumber; ++i) {
        cout << BAR
             << setw(10) << "" << BAR
             << left << setw(25) << _groups[groupID].members[i].name << BAR
             << endl;

    }

    cout << " |------------|---------------------------|" << endl;
}

void saveToFile() {
    cout << "\nNow saving to file groups.txt...\n";

    ofstream saveFile;
    saveFile.open(GROUPS_SAVED_PATH);

    if (saveFile.fail()) {
        cout << "Failed to save the file. Please check if file "
                "is being opened by some other applications.\n";
        return;
    }

    saveFile << BAR
             << left << setw(10) << "Group" << BAR
             << left << setw(25) << "Student\'s name" << BAR
             << endl;
    saveFile << BAR << setw(10) << "" << BAR << setw(25) << "" << BAR;

    saveFile << '\n';

    saveFile << " |------------|---------------------------|";

    saveFile << '\n';

    for (int groupID = 0; groupID < currentNumberOfGroups; ++groupID) {
        saveFile << BAR
                 << left << setw(10) << groupID + 1 << BAR
                 << left << setw(25) << _groups[groupID].members[0].name << BAR
                 << '\n';

        for (int j = 1; j < _groups[groupID].memberNumber; ++j) {
            saveFile << BAR
                     << setw(10) << "" << BAR
                     << left << setw(25) << _groups[groupID].members[j].name << BAR
                     << '\n';

        }

        saveFile << " |------------|---------------------------|" << '\n';
    }

    cout << "Successfully save file.\n";
    saveFile.close();
}

void deadlineMenu() {
    cout << "\nDeadline Menu\n"
         << "1. Enter a deadline\n"
         << "2. Enter a all deadlines\n"
         << "3. Submit a group project\n"
         << "4. Return to main menu\n";

    char c;
    getChar(c);

    switch (c) {
        case '1':
            editDueDate();
            break;
        case '2':
            editAllDueDate();
            break;
        case '3':
            submitProjectToGroup();
            break;
        case '4':
            mainMenu();
            break;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
    }
}

void editDueDate() {
    cout << "Do you have an adequate privilege? (y or n)\t";
    char yn;
    assertYesNo(yn);
    if (toupper(yn) == 'N') {
        cout << "You are not allowed to edit due date!";
        return;
    }

    cout << "Which project do you want to set due date?\t";
    int proj;
    assertInt(proj, 1, MAX_PROJECTS_NUMBER);

    if (currentNumberOfProjects < proj) currentNumberOfProjects = proj;

    cout << "Which date you want to set?(dd/mm/yyyy)\t";
    Date date = {};
    assertDate(date);

    _dueDates[proj - 1] = date;
}

void editAllDueDate() {
    cout << "Do you have an adequate privilege? (y or n)\t";
    char yn;
    assertYesNo(yn);
    if (toupper(yn) == 'N') {
        cout << "You are not allowed to edit due date!";
        return;
    }

    cout << "How many projects are there in this course?\t";
    int projNum;
    assertInt(projNum, MIN_PROJECTS_NUMBER, MAX_PROJECTS_NUMBER);
    currentNumberOfProjects = projNum;

    for (int i = 0; i < currentNumberOfProjects; ++i) {
        cout << "\nEditing Due Date For Project " << i + 1 << "\n";

        cout << "\tWhich date you want to set?(dd/mm/yyyy)\t";
        Date date = {};
        assertDate(date);

        _dueDates[i] = date;
    }
}

void submitProjectToGroup() {
    cout << "Which group do you want to submit?\t";
    int groupName;
    assertInt(groupName, 1, currentNumberOfGroups);

    cout << "Which project do you want to submit?\t";
    int proj;
    assertInt(proj, 1, currentNumberOfProjects);

    cout << "When does this group submit? (dd/mm/yyyy)\t";
    Date submitDate = {};
    assertDate(submitDate);

    _groups[groupName - 1].submitProjects[proj - 1] = submitDate;
    _groups[groupName - 1].submit[proj - 1] = true;
}

void statisticsMenu() {
    cout << "\nStatistic Menu\n"
         << "1. Statistics of a project\n"
         << "2. Statistics of a group\n"
         << "3. Return to main menu\n";

    char c;
    getChar(c);

    switch (c) {
        case '1':
            statisticsOfAProject();
            break;
        case '2':
            statisticsOfAGroup();
            break;
        case '3':
            mainMenu();
            break;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
    }
}

void statisticsOfAProject() {
    cout << "Which project do you want to check?\t";
    int proj;
    assertInt(proj, 1, currentNumberOfProjects);

    cout << BAR << setw(15) << "";
    for (int i = 0; i < currentNumberOfGroups; ++i) {
        cout << BAR << "Group "
             << left << setw(3) << i + 1;
    }

    cout << BAR << endl;

    cout << BAR << "Project "
         << left << setw(7) << proj;
    for (int i = 0; i < currentNumberOfGroups; ++i) {
        string res = "NOT YET";
        switch (getProjectStatus(proj - 1, i)) {
            case ON_TIME:
                res = "ON TIME";
                break;
            case LATE:
                res = "LATE";
                break;
            case NOT_YET:
                res = "NOT YET";
                break;
            default:
                res = "NOT YET";
        }
        cout << BAR << left << setw(9) << res;
    }

    cout << BAR << endl;
}

void statisticsOfAGroup() {
    cout << "Which group do you want to check?\t";
    int groupName;
    assertInt(groupName, 1, currentNumberOfGroups);

    cout << BAR << setw(15) << "";
    for (int i = 0; i < currentNumberOfProjects; ++i) {
        cout << BAR << "Project "
             << left << setw(3) << i + 1;
    }

    cout << BAR << endl;

    cout << BAR << "Group "
         << left << setw(9) << groupName;

    for (int i = 0; i < currentNumberOfProjects; ++i) {
        string res = "NOT YET";
        switch (getProjectStatus(i, groupName - 1)) {
            case ON_TIME:
                res = "ON TIME";
                break;
            case LATE:
                res = "LATE";
                break;
            case NOT_YET:
                res = "NOT YET";
                break;
            default:
                res = "NOT YET";
        }
        cout << BAR << left << setw(11) << res;
    }

    cout << BAR << endl;
}

void overallMenu() {
    cout << "Overall Statistics Menu\n"
         << "1. Statistics for the whole course\n"
         << "2. Statistics until a certain date\n"
         << "3. Back to main menu\n"
         << endl;

    char choice;
    getChar(choice);

    switch (choice) {
        case '1':
            overAllStatisticForTheWhole();
            break;
        case '2': {
            cout << "Until which date do you want to check? (dd/mm/yyyy)\t";
            Date date = {};
            assertDate(date);
            overallStatisticsForAPeriod(date);
        }
            break;
        case '3':
            mainMenu();
            break;
        default:
            cout << "Invalid argument. Returning to main menu.\n";
    }
}

void overallStatisticsForAPeriod(Date &finalDate) {

    bool validProject[MAX_PROJECTS_NUMBER] = {false};
    int n = 0;
    for (int i = 0; i < currentNumberOfProjects; ++i) {
        if (isBefore(_dueDates[i], finalDate)) {
            validProject[i] = true;
            n++;
        }
    }

    cout << BAR
         << left << setw(10) << "Group" << BAR << left << setw(25)
         << "Student\'s name" << BAR;


    cout << left << setw(n * 12 - 3) << "Check the submission" << BAR
         << endl;
    cout << BAR << setw(10) << "" << BAR << setw(25) << "" << BAR;


    for (int i = 0; i < currentNumberOfProjects; ++i) {
        if (validProject[i])
            cout << "Project " << i + 1 << BAR;
    }

    cout << endl;

    cout << " |------------|---------------------------|";

    for (int j = 0; j < n; ++j) {
        cout << "-----------|";
    }

    cout << endl;


    for (int groupID = 0; groupID < currentNumberOfGroups; ++groupID) {

        cout << BAR
             << left << setw(10) << groupID + 1 << BAR
             << left << setw(25) << _groups[groupID].members[0].name;

        for (int i = 0; i < currentNumberOfProjects; ++i) {
            if (validProject[i]) {
                string res = "NOT YET";
                switch (getProjectStatus(i, groupID)) {
                    case ON_TIME:
                        res = "ON TIME";
                        break;
                    case LATE:
                        res = "LATE";
                        break;
                    case NOT_YET:
                        res = "NOT YET";
                        break;
                    default:
                        res = "NOT YET";
                }

                cout << BAR << left << setw(9) << res;
            }
        }

        cout << BAR << endl;

        for (int i = 1; i < _groups[groupID].memberNumber; ++i) {
            cout << BAR
                 << setw(10) << "" << BAR
                 << left << setw(25) << _groups[groupID].members[i].name << BAR
                 << setw(12 * n - 3) << "" << BAR
                 << endl;

        }

        cout << " |------------|---------------------------|";

        for (int j = 0; j < n; ++j) {
            cout << "-----------|";
        }

        cout << endl;
    }

    ofstream saveFile;
    saveFile.open(STATISTICS_SAVED_PATH);
    if (saveFile.fail()) {
        cout << "File could not be saved! Please check if there is any "
                "other application using the file.\n";
    } else {
        saveFile << BAR
                 << left << setw(10) << "Group" << BAR << left << setw(25)
                 << "Student\'s name" << BAR;


        saveFile << left << setw(n * 12 - 3) << "Check the submission" << BAR
                 << endl;
        saveFile << BAR << setw(10) << "" << BAR << setw(25) << "" << BAR;


        for (int i = 0; i < currentNumberOfProjects; ++i) {
            if (validProject[i])
                saveFile << "Project " << i + 1 << BAR;
        }

        saveFile << endl;

        saveFile << " |------------|---------------------------|";

        for (int j = 0; j < n; ++j) {
            saveFile << "-----------|";
        }

        saveFile << endl;


        for (int groupID = 0; groupID < currentNumberOfGroups; ++groupID) {

            saveFile << BAR
                     << left << setw(10) << groupID + 1 << BAR
                     << left << setw(25) << _groups[groupID].members[0].name;

            for (int i = 0; i < currentNumberOfProjects; ++i) {
                if (validProject[i]) {
                    string res = "NOT YET";
                    switch (getProjectStatus(i, groupID)) {
                        case ON_TIME:
                            res = "ON TIME";
                            break;
                        case LATE:
                            res = "LATE";
                            break;
                        case NOT_YET:
                            res = "NOT YET";
                            break;
                        default:
                            res = "NOT YET";
                    }

                    saveFile << BAR << left << setw(9) << res;
                }
            }

            saveFile << BAR << endl;

            for (int i = 1; i < _groups[groupID].memberNumber; ++i) {
                saveFile << BAR
                         << setw(10) << "" << BAR
                         << left << setw(25) << _groups[groupID].members[i].name << BAR
                         << setw(12 * n - 3) << "" << BAR
                         << endl;

            }

            saveFile << " |------------|---------------------------|";

            for (int j = 0; j < n; ++j) {
                saveFile << "-----------|";
            }
            saveFile << '\n';
        }
    }

    cout << "Successfully saved!\n";
    saveFile.close();
}

void overAllStatisticForTheWhole() {
    Date d = _dueDates[0];
    for (int i = 0; i < currentNumberOfProjects; ++i) {
        if (isBefore(d, _dueDates[i])) {
            d = _dueDates[i];
        }
    }
    overallStatisticsForAPeriod(d);
}

void failGroups() {
    int n = 0;
    for (int i = 0; i < currentNumberOfGroups; ++i) {
        for (int j = 0; j < currentNumberOfProjects; ++j) {
            if (!isBefore(_groups[i].submitProjects[j], _dueDates[j]) || !_groups[i].submit[j]) {
                cout << "Group " << i + 1 << ", ";
                n++;
                break;
            }
        }
    }
    if (n >= 1)
        cout << "did not complete the course.\n";
    else
        cout << "All groups complete the course.\n";
}

/**
 *  Get Input
 */
void getChar(char &c) {
    cout << '\n' << INITIAL;
    cin.ignore(MAX_BUFFER, '\n');
    cin >> c;
}

void assertInt(int &i, int min, int max) {
    if (min > max) {
        cout << "Invalid action. May be you want to enter data first.\n";
    }
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
            cout << "Entered value " << i << " is too large. Required to be smaller than " << max << ". Enter again\n";
        }
    } while (i < min || i > max);
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

void assertYesNo(char &c) {
    do {
        getChar(c);
        if (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
            cout << "Only accept (Y)es or (N)o value.\n";
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
}

Student hasStudentWithName(string &s) {
    for (int i = 0; i < currentNumberOfGroups; ++i) {
        for (int j = 0; j < _groups[i].memberNumber; ++j) {
            if (_groups[i].members[j].name == s)
                return _groups[i].members[j];
        }
    }

    return {};
}

bool assertStudentDuplicate(Student &student) {
    Student dup = hasStudentWithName(student.name);

    if (!dup.name.empty()) {
        cout << "Do you mean student " << dup.name
             << " of group " << dup.group + 1
             << "? (y or n)" << endl;

        char yn;
        assertYesNo(yn);

        if (toupper(yn) == 'Y') {
            cout << "Student cannot belong to 2 groups at the same time.\n";
            return true;
        }

    }

    return false;
}

bool validMonth(Date &date) {
    return date.mm > 0 && date.mm < 13;
}

bool validDay(Date &date) {
    if (date.yy % 4 == 0)
        return date.dd > 0 && date.dd <= MONTHS_DAYS_4[date.mm -1];
    else
        return date.dd > 0 && date.dd <= MONTHS_DAYS[date.mm - 1];
}

void assertDate(Date &date) {
    do {
        if (cin.fail()) {
            cout << "Expecting a number, try again!" << endl;
            cin.clear();
            cin.ignore(MAX_BUFFER, '\n');
            cin.putback('\n');
        }
        cin >> date.dd >> date.mm >> date.yy;
        if (!validMonth(date)) {
            cout << "Invalid month! Enter again.\n";
            continue;
        }
        if (!validDay(date)) {
            cout << "Invalid Day! Enter again.\n";
        }
    } while (!validMonth(date) || !validDay(date));
}

bool isBefore(Date &date1, Date &date2) {
    if (date1.yy < date2.yy) return true;
    else if (date1.yy > date2.yy) return false;

    if (date1.mm < date2.mm) return true;
    else if (date1.mm > date2.mm) return false;

    if (date1.dd < date2.dd) return true;
    else if (date1.dd > date2.dd) return false;

    return true;
}

PROJECT_STATUS getProjectStatus(int projectID, int groupID) {
    if (!_groups[groupID].submit[projectID]) return NOT_YET;

    if (isBefore(_groups[groupID].submitProjects[projectID], _dueDates[projectID]))
        return ON_TIME;
    else return LATE;
}

/**
 * Utilities
 */
void clearGroupMemory(int size) {
    Group g = {};
    for (int i = 0; i < size; ++i) {
        _groups[i] = g;
    }
}
