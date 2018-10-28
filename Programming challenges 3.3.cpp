#include <iostream> 
#include <iomanip>
using namespace std;

int main(){
	double a, b, c, d;
	cout << "Enter the monthly expense for rent or mortgage payment, utilities, phones, cable, separated by spacebars: ";
	cin >> a >> b >> c >> d;
	
	cout << fixed << setprecision(2);
	
	cout << right << setw(41) << "Monthly" << setw(16) << "Annual" << endl;
	cout << left << setw(25) << "Rent or mortgage payment";
	cout << right << setw(15) << a << '$' << right << setw(15) << a * 12 << '$' << endl;
	cout << left << setw(25) << "Utilities";
	cout << right << setw(15) << b << '$' << right << setw(15) << b * 12 << '$' << endl;
	cout << left << setw(25) << "Phones";
	cout << right << setw(15) << c << '$' << right << setw(15) << c * 12 << '$' << endl;
	cout << left << setw(25) << "Cable";
	cout << right << setw(15) << d << '$' << right << setw(15) << d * 12 << '$' << endl;
	cout << left << setw(25) << "Total";
	cout << right << setw(15) << a + b + c + d << '$' << right << setw(15) << (a + b + c + d) * 12 << '$' << endl;
	return 0;
}
