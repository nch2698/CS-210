#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){

	double farenheit =0,celcius;
	
	cout << left <<setw(10) << "Celcius" << setw(10) << "Farenheit" << endl;
	cout << setprecision(2) << fixed;
	
	for (celcius = 0; celcius <= 20; celcius ++){
		farenheit = (celcius*9/5) + 32;
		cout << left << setw(10) << celcius << setw(10) << farenheit << endl;
	}
	return 0;
}
