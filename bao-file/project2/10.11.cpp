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
	int i=0;
	char ptr[SIZE];
	for (int i=0;i < strlen(str);i++)
		ptr[i] = str[i];
	while (ptr[i] != '\0'){
		ptr[i] = toupper(ptr[i]);
		i++;
	}
	cout << "\nYour string after call toUpper function: " << ptr;
}

void toLower(char *str){
	int i=0;
	char ptr[SIZE];
	for (int i=0;i < strlen(str);i++)
		ptr[i] = str[i];
	while (ptr[i] != '\0'){
		ptr[i] = tolower(ptr[i]);
		i++;
	}
	cout << "\nYour string after call toLower function: " << ptr;
}

void toReverse(char *str){
	int i=0;
	char ptr[SIZE];
	for (int i=0;i < strlen(str);i++)
		ptr[i] = str[i];
		
	while (ptr[i] != '\0'){
		if (islower(ptr[i])) ptr[i] = toupper(ptr[i]);
		else if (isupper(ptr[i])) ptr[i] = tolower(ptr[i]);
		i++;
	}
	cout << "\nYour string after call toReverse function: " << ptr;
}


