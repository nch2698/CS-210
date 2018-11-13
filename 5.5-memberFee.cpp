#include <iostream>
#include <string>
using namespace std;

int main(){
	int const MEMBERSHIP_FEE = 2500;
	double const RATE = 0.04;
	double increased_fee = 0;
	
	cout << "The current membership fee is $2500 and it increases by 4% every year." << endl;
	
	for (int years=1; years <=6; years++){
		increased_fee = MEMBERSHIP_FEE + (MEMBERSHIP_FEE * RATE * years);
		cout << "After " << years << " year(s), the fee is " << increased_fee << endl;
	}
	return 0;
}
