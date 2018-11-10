#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double rate;
	unsigned day, organ, i;
	
	do{
		cout << "The starting number of organisms? " ;
		cin >> organ;
		if (organ < 2)
			cout << "The starting number of organisms cannot be less than 2." << endl;
	} while (organ <2);
	do{
		cout << "Their average daily population increase (as a percentage)? ";
		cin >> rate;
		if (rate < 0)
			cout << "The average daily population increase cannot be negative." << endl;
	} while (rate <0);
	do{
		cout << "The number of days they will multiply? ";
		cin >> day;
		if (day < 1)
			cout << "The number of days they will multiply cannot be less than 1." << endl;
	} while (day < 1);
	
	cout << "Days" << "          Size of population" << endl;
	for (i = 1; i <= day; i++){
		cout << left << setw(5) << i << right << setw(20) << static_cast<unsigned>(organ * (1+ rate / 100)) << endl;
		organ *= (1 + rate / 100);	
	} 
return 0;	
}
