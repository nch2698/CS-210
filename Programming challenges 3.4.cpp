#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	const float RATE = 0.8f;
	double cost;
	cout << "Enter the replacement cost of a building: $";
	cin >> cost;
	cout << "The minimum amount of insurance that should be purchased: $" << fixed << setprecision(2) << RATE * cost;
	return 0;
}
