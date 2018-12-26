#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char mostFrequentCharacter(char *word);
char mostFrequentCharacter(string word);

int main(){
	//Choose input type
	int choice;
	do {
		cout << "Do you like to enter a c-style string or string object (0,1)?";
		cin >> choice;	
	}while(choice != 0 && choice != 1);
	
	//function for each situations
	if (choice == 0){
		int SIZE = 50;
		char word[50];
		cout << "Enter any string for calculation: ";
		cin.getline(word,SIZE);
		mostFrequentCharacter(word);
	}else{
		string str;
		cout << "Enter any string for calculation: ";
		cin >> str;
		mostFrequentCharacter(str);
	}
	
	cout << endl;
	
	return 0;
}

char mostFrequentCharacter(char *word){
	int count[27] {0};
	int index;
	int i=0;
	char c;
	
	//Find the frequency of each character
	while (word[i] != '\0'){
		c = word[i];
		index = static_cast<int>(char (c - 'a'));
		count[index]++;	
		i++;
	}
	
	//Print out the magnitude list
	for (int j=0; j < 26; j++){
		cout << static_cast<char>(char(j + 'a')) << ":" << count[j] << endl; 
	}
	
	//Find the most frequent character
	int max = count[0]; 
	int max_index = 0;
	for (int j=0; j < 26; j++)
		{
		if (count[j] > max)
		{
			max = count[j];
			max_index = j;
		}
	}
	//Output result
	if (max == 0)
		cout << "The string doesnot have the most frequent character.\n";
	else
	{
		cout << "The first most frequent character is '" << static_cast<char>(char(max_index + 'a')) << "' with " << max << " times appears.";
		return static_cast<char>(char(max_index + 'a'));
	}
}

char mostFrequentCharacter(string str){
	int count[27] = {0};
	char c;
	int i=0;
	int index;
	while (i < str.length()){
		c = tolower(str[i]);	
		index= static_cast<int>(char(c - 'a'));
		count[index]++;
		i++;
	}
	for (int i = 0; i < 26;i++)
		cout << static_cast<char>(i+'a') << " : " << count[i] << endl;
	
	//Find the most frequent character
	int max = count[0]; 
	int max_index = 0;
	for (int j=0; j < 26; j++)
		{
		if (count[j] > max)
		{
			max = count[j];
			max_index = j;
		}
	}
	//Output result
	if (max == 0)
		cout << "The string doesnot have the most frequent character.\n";
	else
	{
		cout << "The first most frequent character is '" << static_cast<char>(char(max_index + 'a')) << "' with " << max << " times appears.";
		return static_cast<char>(char(max_index + 'a'));
	}
}

