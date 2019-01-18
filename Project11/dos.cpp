#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void menu() {
    cout << "\n\tUSAGE: copy <copied_file_path> <destination_file_path>\n";
}

void fileFailed(fstream &fstr, const string &failMessage) {
    if (fstr.is_open()) return;

    cout << failMessage << endl;
    exit(1);
}

void openFile(char *path, bool read, bool write, fstream &fstr) {
    if (read && !write) {
        fstr.open(path, ios::in | ios::binary);
    } else if (write && !read) {
        fstr.open(path, ios::out | ios::binary);
    } else {
        fstr.open(path, ios::in | ios::out | ios::binary);
    }

    fileFailed(fstr, "Failed to open " + string(path));
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        cout << "Invalid syntax.\n";
        menu();
        return 1;
    }

    if (strcmp(argv[1], argv[2]) == 0) {
        cout << "Destination file is duplicated with copied file!" << endl;
        return 1;
    }

    fstream copiedFile;
    openFile(argv[1], true, false, copiedFile);


    fstream destFile;
    openFile(argv[2], false, true, destFile);

    copiedFile.seekg(0, ios::end);
    long size = copiedFile.tellg();
    copiedFile.seekg(0);

    char *buffer = new char[size];

    copiedFile.read(buffer, size);

    destFile.write(buffer, size);

    delete[] buffer;
    copiedFile.close();
    destFile.close();

    return 0;
}