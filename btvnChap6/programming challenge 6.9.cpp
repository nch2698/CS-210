#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double presentValue(double future_val, double annual_interest_rate, int years);

int main(){
	double future_money, interest;
	int years;
	cout << "This program calculate present value for deposition\n";
	do {
		cout << "How much money would you want in your account? $";
		cin >> future_money;
	}while(future_money < 0);
	
	do{
		cout << "For how many year you want to deposit? ";
		cin >> years;
	}while(years < 0);
	
	do{
		cout << "The yearly interest(%) of your bank? ";
		cin >> interest;
	}while(interest < 0);
	
	cout << fixed << setprecision(2);
	cout << "So you have to deposit for today an amount money of $" << presentValue(future_money, interest, years); 
	return 0;
}

double presentValue(double future_val, double annual_interest_rate , int years){
	return future_val / pow((1+ annual_interest_rate/100), years);
}
