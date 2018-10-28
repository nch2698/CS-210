#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	double m_rate, an_rate, L, p;
	int n;
	cout << "Enter the annual rate in percentage: ";
	cin >> an_rate;
	cout << "Enter the number of payments: ";
	cin >> n;
	cout << "Enter the amount of loan: ";
	cin >> L;
	m_rate = an_rate / 12.0 / 100.0;
	p = m_rate * pow ((1 + m_rate), n) / (pow ((1 + m_rate), n) - 1) * L;
	cout << left << setw(25) << "Loan Amount:" << '$' << right << setw(10) << L << endl;
	cout << left << setw(25) << "Monthly Interest Rate:" << right << setw(10) << setprecision(2) << m_rate * 100.0 << '%' << endl;
	cout << left << setw(25) << "Number of Payments:" << right << setw(11) << n << endl;
	cout << fixed;
	cout << left << setw(25) << "Monthly Payment:" << '$' << right << setw(10) << p << endl;
	cout << left << setw(25) << "Amount Paid Back:" << '$' << right << setw(10) << p * n << endl;
	cout << left << setw(25) << "Interest Paid:" << '$' << right << setw(10) << (p * n) - L << endl;
	return 0;
}
