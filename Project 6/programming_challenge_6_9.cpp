#include <iostream>
#include <cmath>
using namespace std;

double presentValue(double future, double a_rate, int year){
	return future / pow((1 + a_rate / 100.0), year);
}
int main(){
	double present, future, a_rate, year;
	
	cout << "Enter the future amount: ";
	cin >> future;
	cout << "Enter the annual rate: ";
	cin >> a_rate;
	cout << "Enter the numberof years: "; 
	cin >> year;
	present = presentValue(future, a_rate, year);
	cout << "The present amount should be " << present;
	return 0;
}
