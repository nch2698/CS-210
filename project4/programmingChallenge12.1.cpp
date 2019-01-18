#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
	
	ifstream inputFile;
	char fileName[20];
	
	// The user should type in "demofile.txt" which prepared for this exercise
	cout << "Enter the name of the file(recommended 'demofile.txt'): ";
	cin.getline(fileName,20);
	
	//Open file 
	inputFile.open(fileName);
	
	//Error checking
	if (!inputFile)
	{
		cout << "Error opening the file. Please close and check problems.\n";	
		return 0;
	}else
	{
		cout << "Opening file ...\n";
		int line = 0;
		int const SIZE = 80;
		char data[SIZE];
		
	//Only print first 10 lines
		while ((!inputFile.eof()) && line < 10)
		{
			inputFile.getline(data,SIZE);
			cout << data << "\n";
			line++; 	
		}
		
	//Output required message 
		if (line < 10 && line >= 0)
			cout << "That is all the content of demofile. Demofile's lines is less than 10 lines.\n";
		else 
			cout << "That is the content of the first 10 lines of demofile.\n";
		inputFile.close();
	}
	
	return 0;
}
