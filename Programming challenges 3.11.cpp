#include <iostream> 
#include <iomanip>
using namespace std;

int main(){
	double c;
	cout << "Enter the temperature in Celsius: ";
	cin >> c;
	cout << fixed << setprecision(2);
	cout << "The temperature in Fahrenheit is: " << (9.0/5.0) * c + 32 << " F" << endl;
	return 0;
}
