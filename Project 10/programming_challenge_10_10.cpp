#include <iostream>
#include <string>
using namespace std;

void replaceSubstring(string &str1, string &str2, string &str3){
	for (int i = 0; i <= str1.length() - str2.length() + 1; i++){
		if (str1.compare(i, str2.length(), str2) == 0){
			str1.replace(i, str2.length(), str3);
		}	
	}
}

int main(){
	string str1, str2, str3;
	
	cout << "The ocurrences of string 2 in string 1 will be replaced by string 3.\n";
	cout << "String 1: "; getline(cin, str1);
	cout << "String 2: "; getline(cin, str2);
	cout << "String 3: "; getline(cin, str3);
	replaceSubstring(str1, str2, str3);	
	cout << "Edited string 1: " << str1;
}


