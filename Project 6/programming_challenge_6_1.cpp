#include <iostream>
#include <iomanip>
using namespace std;

double calculateRetail(double cost, double markup){
	return cost * (1 + markup / 100.0);
}
int main(){
	double cost, markup, retail;
	
	do{
		cout << "Enter the wholesale cost: ";
		cin >> cost;
		if (cost < 0){
			cout << "Invalid cost." << endl;
		}
	} while (cost < 0);
	do{
		cout << "Enter the markup percentage (e.g.10% --> 10): ";
		cin >> markup;
		if (markup < 0){
			cout << "Invalid markup percentage." << endl;
		}
	} while (markup < 0);
	retail = calculateRetail(cost, markup);
	cout << fixed << setprecision(2);
	cout << "Retail price: " << retail;
	return 0;
}
