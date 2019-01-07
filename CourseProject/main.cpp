#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_ARRAY_SIZE = 20;
const int DEFAULT_SUBMSSION_NUMBER = 7;

struct DATE {
    int day, month, year;
};

struct Project {
    string description;
    DATE due_date;
};

struct Student {
    int id, group_id;
    string name;
};

enum STATUS {
    ON_TIME, LATE
};

/**
 * Instead of using nested struct, using student id will improve performance
 * because less memory is required to process.
 */
struct Group {
    int students[DEFAULT_ARRAY_SIZE]= {};
    int group_id = 0;
    Project submission[DEFAULT_SUBMSSION_NUMBER];
};

int main(int argc, char **argv) {
    return 0;
}