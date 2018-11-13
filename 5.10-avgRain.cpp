#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	
	int years;
	double rainfall, average, total=0;
	do {
		cout << "Enter number of year for calculation (not less than 1): ";
		cin >> years;
	}while(years < 1);
	
	cout << "The program will ask you 12 times per year for calculation: " << endl;
	
	for (int year = 1; year <= years; year++){
		for (int month =1; month <= 12; month++){
			do {
				cout << "Enter the rain fall for month " << month << " :";
				cin >> rainfall;
			}while (rainfall < 0);
			
			total += rainfall;
		}
		average = total / 12;
		cout << "The average rainfall for year " << year << " is: " << average;
	}
	return 0;
}
