#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int y, m, year;
	double rainfall, total = 0.0;
	
	do{	
		cout << "The number of years? ";
		cin >> year;
		if (year < 1)
			cout << "Invalid input." << endl;
	} while (year < 1);
	
	for(y = 1; y <= year; y++){
		cout << "Year "<< y << ":" << endl;
		for(m = 1; m <= 12 ; m++){
			do{
				cout << "\tThe rainfall in inches of month " << m << ": ";
				cin >> rainfall;
				cin.ignore(256, '\n');
				if (rainfall < 0)
					cout << "Input invalid." << endl;
			} while (rainfall < 0);
			
			total += rainfall;
		} 
	}
	cout << fixed << setprecision(2);
	cout << "The total inches of rainfall is " << total << " inches." << endl;
	cout << "The average rainfall per month over the entire period is: " << total / (year * 12) << " inches.";
return 0;
}
