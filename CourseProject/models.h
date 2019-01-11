//
// Created by danielng on 07/01/2019.
//

#ifndef PROJECT_MODELS_H
#define PROJECT_MODELS_H

#include <string>
#include "config.h"

struct DATE {
    int day, month, year;
};

struct Project {
    std::string description;
    DATE due_date;
};

struct Student {
    int id, group_id;
    std::string name;
};

/**
 * Instead of using nested struct, using student id will improve performance
 * because less memory is required to process.
 */
struct Group {
    int students[DEFAULT_ARRAY_SIZE]= {};
    int num;
    int group_id = 0;
    Project submission[DEFAULT_SUBMISSION_NUMBER];
};

#endif //PROJECT_MODELS_H
