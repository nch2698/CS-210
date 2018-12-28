#include <iostream>
#include <cstring>
using namespace std;

//These function will not modify or change the initial array.
void toUpper(char *);
void toLower(char *);
void toReverse(char *);

int const SIZE = 50;
int main(){
    //Input string
    char word[SIZE];
    cout << "Enter any string (no more than " << SIZE << " characters and better with Lower case): \n";
    cin.getline(word,SIZE);

    //Output string
    cout << "Your original string: " << word;
    toUpper(word);
    toLower(word);
    toReverse(word);
    return 0;
}

void toUpper(char *str){
    size_t l = strlen(str);
    char ptr[l];
    for (int i=0;i < l;i++)
        ptr[i] = static_cast<char>(toupper(str[i]));
    cout << "\nYour string after call toUpper function: " << ptr;
}

void toLower(char *str){
    size_t l = strlen(str);
    char ptr[l];
    for (int i=0;i < l;i++)
        ptr[i] = static_cast<char>(tolower(str[i]));
    cout << "\nYour string after call toLower function: " << ptr;
}

void toReverse(char *str){
    size_t l = strlen(str);
    char ptr[l];
    for (int i=0;i < l;i++){
        if (islower(str[i])) ptr[i] = static_cast<char>(toupper(str[i]));
        else if (isupper(str[i])) ptr[i] = static_cast<char>(tolower(str[i]));
        else ptr[i] = str[i];
    }
    cout << "\nYour string after call toReverse function: " << ptr;
}