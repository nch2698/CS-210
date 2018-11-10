#include <iostream>
using namespace std;

int main(){
	int month;
	cout << "Enter a month: ";
	cin >> month;				
	if(month > 0 && month < 13){
		int up_bound, low_bound; // bounds for the numbers of day in a month
		switch(month){
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:
				{
					up_bound = 32 ;
					low_bound = 0; 
					break;
				}
			case 4:case 6:case 9:case 11:
				{
					up_bound = 31;
					low_bound = 0;
					break;
				}
			case 2:
				{
					up_bound = 29;
					low_bound = 0;
					break;
				}
		}
		
		int year;
		cout << "Enter 2-digits year: ";
		cin >> year;
		if (year >= 0 && year <=99){ // check for leap year.
			if (year % 4 == 0 && month == 2){
				up_bound = 30;
				low_bound = 0;
			}
			
			int day;
			cout << "Enter a day: ";
			cin >> day;
			if (day > low_bound && day < up_bound){
				if (day * month == year){
					cout << "Day * Month = " << day * month << endl;
					cout << "The date is magic.";
				}
				else{
					cout << "Day * Month = " << day * month << endl;
					cout << "The date is not magic.";
				}
			}
			else{
				cout << "The day is invalid.";	
			}		
		
		}
		else{
			cout << "The year is invalid.";
		}
			
	}
	else{
		cout << "The month is invalid";
	}
	
return 0;
}
		
			
