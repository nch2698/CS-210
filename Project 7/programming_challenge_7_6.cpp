#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void countNum(unsigned&);
void getNum(unsigned&);

int main(){
	unsigned count;
	
	countNum(count);
	getNum(count);
	return 0;
}

void countNum(unsigned& count){
	ifstream inputFile;
	
	inputFile.open("numbersFor7.6.txt");
	if(!inputFile) cout << "Error opening file." << endl;
	
	double a;
	
	while (inputFile >> a)
		  count++;
	cout << "The file contains " << count << " numbers." << endl;	  
}

void getNum(unsigned& count){
	ifstream inputFile;
	
	inputFile.open("numbersFor7.6.txt");
	if(!inputFile) cout << "Error opening file." << endl;
	// get numbers
	double arr[count], total = 0.0;
	
	for (int i = 0; i < count; ++i){
		inputFile >> arr[i];
		total += arr[i];	
	}
	// highest, lowest
	double highest = arr[0], lowest = arr[0];
 	for(int i = 1; i < count; ++i){
 		if (lowest > arr[i]){
 			lowest = arr[i];
 		}
 		if (highest < arr[i]){
 			highest = arr[i];
        }
	}
	// display data
	int j = 0;
	for (int i = 0; i < count; ++i){
		cout << arr[i] << "   ";
		j++;
		if (j == 10) {
		   cout << endl;
		   j = 0;
        }
	}
	cout << endl
		 << fixed << setprecision(2)
		 << "Total: " << total << endl
		 << "Average: " << total / count << endl
	 	 << "Highest: " << highest << endl
	 	 << "Lowest: " << lowest << endl;
}
