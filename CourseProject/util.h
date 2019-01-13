//
// Created by danielng on 11/01/2019.
//

#ifndef PROJECT_UTIL_H
#define PROJECT_UTIL_H

#include <iostream>
#include "config.h"
#include "models.h"
#include "storage.h"
#include <iomanip>


using namespace std;

void assertInt(int &i, int min, int max);

void assertYesNo(char &);

bool assertStudentDuplicate(Student &);

void assertStringEmpty(string&);

void getChoice(char &);

void printLabels();

void printGroup(int);

#endif //PROJECT_UTIL_H
