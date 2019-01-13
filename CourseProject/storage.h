//
// Created by danielng on 11/01/2019.
//

#ifndef PROJECT_STORAGE_H
#define PROJECT_STORAGE_H

#include "models.h"
#include "config.h"
#include <string>

void *initStudentStorage();

Group *initGroupStorage(int size);

int hasStudentWithName(std::string &);

void addStudent(Student &);

Student getStudentByID(int);

Group *getAllGroups();

Group getGroupByID(int);

int getCurrentGroupNumber();

int getStudentStorageCursor();

void advanceStudentCursor();

void addAGroup(Group &);

void addStudent(Student &student, bool toGroup);

void modifyGroup(Group &group);

#endif //PROJECT_STORAGE_H
