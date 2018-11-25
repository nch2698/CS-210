#include <iostream>
using namespace std;

double calculateRetail(double original_cost, double markup_percent){
	double retail_cost = original_cost + original_cost * (markup_percent/100);
	return retail_cost;
}

int main(){
	double wholesale_price, markup_percent;
	cout << "This program calculates retail price.\n";
	
	do {
		cout << "Enter the wholesale price: $";
		cin >> wholesale_price;
		if (wholesale_price < 0) cout << "The price can not be a negative number. Please Reinput.\n";	
	}while (wholesale_price < 0);
		
	do {
		cout << "Enter the markup percent (%): ";
		cin >> markup_percent;
		if (markup_percent < 0) cout << "The percent can not be a negative number. Please Reinput.\n";
	}while(markup_percent < 0);
	
	cout << "The retail price is $" << calculateRetail(wholesale_price, markup_percent);
	return 0;
}
