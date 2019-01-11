#include <iostream>
#include <string>

#include "models.h"

using namespace std;

void getStudentOfGroup(Student *students, Group *groups) {
    Student student;
    cout << "Name of student:\t";
    getline(cin, student.name);
    cout << "Group of student:\t";
    do {
        cin >> student.group_id;
        if (student.group_id < 1 || student.group_id > groupsNumber) {
            cout << "Invalid Group ID, Try again";
        }
    } while (student.group_id < 1 || student.group_id > groupsNumber);

    student.id = ++studentsNumber;

    students[studentsNumber - 1] = student;
    groups[student.group_id - 1].students[groups[student.group_id - 1].num++] = student.id;
}

void getRawGroup(Student students[]) {
    cout << "How many groups are there?\t";
    cin >> groupsNumber;

    Group *groups = new Group[groupsNumber];

    for (int i = 0; i < groupsNumber; ++i) {
        cout << "Enter all students from group";
    }
}