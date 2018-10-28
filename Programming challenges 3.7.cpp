#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	double r1, r2, r3;
	string m1, m2, m3;
	cout << "Enter three months to calculate monthly rainfall,each separated by a space: ";
	cin >> m1 >> m2 >> m3;
	cout << "Enter respectively the rainfall for each month in inches,each separated by a space: ";
	cin >> r1 >> r2 >> r3;
	cout << "The average monthly rainfall for " << m1 << ", " << m2 << " and " << m3 << " was " << fixed << setprecision(2) << (r1 + r2 + r3) / 3.0 << " inches.";
	return 0;
}
