#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	const float STATE_RATE = 0.04f, COUNTY_RATE = 0.02f, SALE_RATE = 1.06f;
	string time;
	double total;
	
	cout << "Enter the month and the year, separated by spacebars: ";
	getline(cin, time);
	
	cout << "Enter the total amount collected: ";
	cin >> total;
	
	cout << "Month: " << time << endl;
	c<< "------------" << endl;
	
	cout << fixed << setprecision(2);
	cout << left << setw(20) << "Total collected:" << '$' << right << setw(10) << total << endl;
	cout << left << setw(20) << "Sale:" << "$" << right << setw(10) << total / SALE_RATE << endl;
	cout << left << setw(20) << "County Sales Tax:" << '$' << right << setw(10) << total * COUNTY_RATE << endl;
	cout << left << setw(20) << "State Sales Tax:" << '$' << right << setw(10) << total * STATE_RATE << endl;
	cout << left << setw(20) << "Total Sales Tax:" << '$' << right << setw(10) << total * (COUNTY_RATE + STATE_RATE) << endl;
	return 0;
}
