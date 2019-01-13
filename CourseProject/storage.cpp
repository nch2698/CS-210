#include "storage.h"

Student *_STUDENTS;
Group *_GROUPS;

int _groupNum = 0;
int _cursor = 0;
int _currentStudentStorageSize = 0;


void expandStudentStorage(int newSize, Student **oldLoc) {
    Student *newLoc = new Student[newSize];

    for (int i = 0; i < getStudentStorageCursor(); ++i) {
        Student s = *(*oldLoc + i);
        newLoc[i] = *(*oldLoc + i);
    }

    delete[] *oldLoc;

    *oldLoc = newLoc;

    _currentStudentStorageSize = newSize;
}

void clearStudentStorage() {
    Student s = {};
    for (int i = 0; i < getStudentStorageCursor(); ++i) {
        _STUDENTS[i] = s;
    }
}

void *initStudentStorage() {
    _STUDENTS = new Student[DEFAULT_ARRAY_SIZE];
    _currentStudentStorageSize = DEFAULT_ARRAY_SIZE;
}

int getStudentStorageCursor() {
    return _cursor;
}

void advanceStudentCursor() {
    _cursor++;
}

int getCurrentGroupNumber() {
    return _groupNum;
}

void addStudent(Student &student) {
    addStudent(student, true);
}

void addStudent(Student &student, bool toGroup) {
    if (student.id >= (_currentStudentStorageSize-1) * .75)
        expandStudentStorage(_currentStudentStorageSize * 2, &_STUDENTS);

    _STUDENTS[student.id] = student;

    for (int i = 0; i < getStudentStorageCursor(); ++i) {
        printf("Name: %s\n", getStudentByID(i).name.c_str());
    }

    if (toGroup) {
        _GROUPS[student.group_id].group_id = student.group_id;

        int n = _GROUPS[student.group_id].num;
        _GROUPS[student.group_id]
                .students[n] = student.id;
        _GROUPS[student.group_id].num++;
    }
}

Student getStudentByID(int id) {
    return _STUDENTS[id];
}

Group getGroupByID(int id) {
    return _GROUPS[id];
}

void removeStudent(int studentID) {
    for (int i = 0; i < _groupNum; ++i) {

    }
}

int hasStudentWithName(std::string &name) {
    for (int i = 0; i < getStudentStorageCursor(); i++) {
        if (_STUDENTS[i].name == name) return i;
    }
    return -1;
}

Group *initGroupStorage(int size) {
    _GROUPS = new Group[size];
    Group g = {};
    _groupNum = size;
    for (int i = 0; i < size; ++i) {
        _GROUPS[i] = g;
    }
    clearStudentStorage();
    return _GROUPS;
}

void addAGroup(Group &group) {
    _groupNum++;
    Group *temp = new Group[_groupNum];
    Group g = {};
    for (int i = 0; i < _groupNum - 1; ++i) {
        temp[i] = _GROUPS[i];
    }
    temp[_groupNum - 1] = g;
    delete[] _GROUPS;
    _GROUPS = temp;

    _GROUPS[group.group_id] = group;
}

void modifyGroup(Group &group) {
    _GROUPS[group.group_id] = group;
}

Student *getAllStudents() {
    return _STUDENTS;
}

Group *getAllGroups() {
    return _GROUPS;
}