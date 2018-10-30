#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int quantity;
	double cost = 99.0;
	
	cout << "Enter the number of units sold: ";
	cin >> quantity;
	cout << fixed << setprecision(2);
	if (quantity >0 ){
		if (quantity >= 10 && quantity <= 19){
			cost = cost * 0.8;
			cout << "The total cost is " << cost << '$';
		}else if (quantity >=20 && quantity <= 49){
			cost = cost * 0.7;
			cout << "The total cost is " << cost << '$';
		}else if (quantity >= 50 && quantity <= 99){
			cost = cost * 0.6;
			cout << "The total cost is " << cost << '$';
		}else if (quantity >= 100){
			cost = cost * 0.5;
			cout << "The total cost is " << cost << '$';
		}
	}else {
		cout << "The quantity is invalid.";
	}
	
return 0;	
}

