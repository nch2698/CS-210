#include <iostream> 
#include <iomanip>
using namespace std;

int main(){
	double c;
	cout << "Enter the temperature in Celsius: ";
	cin >> c;
	cout << "The temperature in Fahrenheit is: " << fixed << setprecision(2) << (9.0/5.0) * c + 32;
	return 0;
}
