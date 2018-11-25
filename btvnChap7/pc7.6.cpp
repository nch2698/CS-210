#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int tr(){
	return 3,4;
}
int main(){
	ifstream inputFile;
	int const SIZE = 10;
	int count=0;
	double arr[SIZE] = {0};
	//Read file and display
	inputFile.open("text.txt");
	while(count < SIZE && inputFile >> arr[count])
		count++;	
	inputFile.close();
	
	for (int i=0; i < count;i++)
		cout << arr[i] << "\n";
		
	//Max,min,total,average and display
	double total = 0;
	double average;
	double min = arr[0]; 
	double max = arr[0];
	for (int i=0; i < count;i++){
		total += arr[i];
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	average = total / count;
	cout << "Total is :" << total << endl;
	cout << "Average is :" << average << endl;
	cout << "max is :" << max << ", min is "<< min<< endl;
	
	return 0;
}


