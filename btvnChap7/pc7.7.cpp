#include <iostream>
#include <string>
using namespace std;
bool checkLowerCase(char c);
char toUpperCase(char c);
int main(){
	char word[20] = {0};
	cout << "Type some word(maximum 20 characters): ";
	cin.getline(word,20);
	cout << "All the lowercase character will turn to uppercase\n";

	for (int i=0;i<20;i++){
		if (checkLowerCase(word[i]))
			word[i] = toUpperCase(word[i]);
		cout << word[i];
	}
	
	return 0;
}

bool checkLowerCase(char c){
	int position =  static_cast<int>(c);
	if (position >= 97 && position <= 122) return true;
	else return false;
}

char toUpperCase(char c){
	int position = static_cast<int>(c);
	position -= 32;
	return static_cast<char>(position);
}

