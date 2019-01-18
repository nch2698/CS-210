#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
	ifstream inputFile;
	char fileName[20];
// The user should enter "demofile2.txt" for the shake of this exercise
	cout << "Enter the name of the file(recommended 'demofile2.txt'): ";
	cin.getline(fileName,20);
	inputFile.open(fileName);

//Error checking. Program closes if file cannot open.	
	if (!inputFile)
	{
		cout << "Error opening the file. Please close and check problems.\n";	
		return 1;
	}else
	{
		cout << "Opening file ...\n";
		int line = 0;
		int const SIZE = 80;
		char data[SIZE];
		
// With each 24 lines, the program will pause until any key is pressed
		while (!inputFile.eof())
		{
			inputFile.getline(data, SIZE);
			cout << data << endl;
			line++;
			if (line % 24 == 0)
				{
					cout << "Paused. Press again to printing the next 24 lines.";
					cin.get();
				}	
		}
		cout << "\nReached the end of this file. Now closing...";
		cin.get();
		inputFile.close();
	}
	return 0;
}
