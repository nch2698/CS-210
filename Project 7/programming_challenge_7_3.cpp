#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	string salsaType[5] = {"mild", "medium", "sweet", "hot", "zesty"};
	int jarSold[5], total = 0;
	
	cout << "Enter the jars sold for each type of salsa: " << endl;
	for(int i = 0; i < 5; ++i){
		cout << "\t" << salsaType[i] << ": ";
		cin >> jarSold[i];
		cin.ignore(256,'\n');
		total += jarSold[i]; 
	}
	string highestType = salsaType[0],
		   lowestType = salsaType[0];	   
	int highestJar = jarSold[0],
		lowestJar = jarSold[0];
	for (int i = 1; i < 5; ++i){
		if (highestJar < jarSold[i]){
			highestJar = jarSold[i];
			highestType = salsaType[i];
		}
			if (lowestJar > jarSold[i]){
			lowestJar = jarSold[i];
			lowestType = salsaType[i];
		}
	}
	
	cout << left << setw(10) << "Type" << setw(25) << "Numbers of Jars Sold" << endl;
	for (int i = 0; i < 5; ++i){
		cout << setw(10) << salsaType[i] << setw(10) << jarSold[i] << endl;
	}
	cout << setw(10) << "Total" << setw(25) << total << endl;
	cout << "The highest selling product is " << highestType << " with " << highestJar  << " jars" << endl;
	cout << "The lowest selling product is " << lowestType << " with " << lowestJar << " jars" <<  endl;
	return 0;	
}
