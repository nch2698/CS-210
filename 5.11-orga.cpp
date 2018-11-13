#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "This program will predict the size of the population. \n";
	double starting_size, post_size;
	double increase_rate;
	int days;
	// Input and Data validation
	do {
		cout << "Enter the starting number of organisms (not less than 2): ";
		cin >> starting_size;
	}while (starting_size < 2);
	
	do {
		cout << "Enter the production rate in % (ex: 0.01): ";
		cin >> increase_rate;
	}while (increase_rate < 0);
	
	do {
		cout << "Enter the number of days they will multiply (not less than 1): ";
		cin >> days;
	}while (days < 1);
	
	cout << "\nInput: " << starting_size << " " << increase_rate << " " << days << endl;
	// Calculation and output
	for (int day = 1; day < days; day++){
		post_size = starting_size + (starting_size * increase_rate * day);
		cout << "After " << day << "(s) the size of the population is " << post_size << endl;
	}
	return 0;
}
