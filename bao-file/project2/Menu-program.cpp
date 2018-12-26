#include <iostream>
#include <cstring>
using namespace std;

int countVowels(char []);
int countConsonants(char []);
void toUpper(char[]);
void toLower(char[]);
char getString(char [], int);
void printString(char []);
void displayMenu();

int main (){
	int const SIZE = 100;
	char words[SIZE];
	getString(words, SIZE);
	
	int choice;
	displayMenu();
	do {
	
		do{
			cout << "Enter your choice: ";
			cin >> choice;
		}while(0> choice || choice > 8);
		
	switch (choice){
		case 1:
			cout <<"The number of vowel is "<< countVowels(words) << endl;
			break;
		case 2:
			cout << "The number of Consonant is "<< countConsonants(words) << endl;
			break;
		case 3:
			toUpper(words);
			break;
		case 4:
			toLower(words);
			break;
		case 5:
			printString(words);
			break;
		case 6:
			getString(words, SIZE);
			break;
		case 7:
			displayMenu();
			break;
	}
		
		
	}while(choice != 8);
	
	
	return 0;
}

void displayMenu(){
		cout << "\n-----MENU PROGRAM-----\n";
		cout << "1. Count the number of vowels.\n";
		cout << "2. Count the number of consonants.\n";
		cout << "3. Convert string to upper case.\n";
		cout << "4. Convert string to lower case.\n";
		cout << "5. Display the current string.\n";
		cout << "6.	Enter another string.\n";
		cout << "7. Display this menu.\n";
		cout << "8. Exit the program.\n";
}

char getString(char *arr, int size){
	cout << "Input any strings (Press enter to end):";
	cin.ignore();
	cin.getline(arr, size);
}

int countVowels(char arr[]){
	int count = 0;
	for (int i=0; i < strlen(arr); i++){
		char ch = tolower(arr[i]);
		if (arr[i] == 'u' || arr[i] =='e'|| arr[i] =='o' || arr[i] =='a' || arr[i] =='i')
			count++;
	}	
	return count;
}

int countConsonants(char arr[]){
	int count=0;
	int consonant, vowel;
	
	for (int i=0; i < strlen(arr); i++)
		if (isalpha(arr[i])) count++;
	
	vowel = countVowels(arr);
	consonant = count - vowel;
	return consonant;	
}

void toUpper(char arr[]){
	for (int i=0; i < strlen(arr); i++)
		arr[i] = toupper(arr[i]);
}

void toLower(char arr[]){
	for (int i=0; i < strlen(arr); i++)
		arr[i] = tolower(arr[i]);
}

void printString(char arr[]){
	for (int i=0; i < strlen(arr); i++)
		cout << arr[i];
	cout <<endl;
}
