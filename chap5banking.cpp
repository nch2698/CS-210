#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	cout << "Calculate money interest\n";
	double monthly_interest, anually_interest;
	int years;
 	double  so_du, monthly_profit, tien_dau_ky, original_money;
 	string name;
 	
 	cout << "Xin nhap ten chu tai khoan: ";
 	getline(cin,name);	
	do{
		cout << "Nhap lai suat % hang nam (VD 0.5) : ";
		cin >> anually_interest;
	}while (anually_interest <= 0);
	
	do{
		cout << "Nhap so tien muon gui: ";
		cin >> original_money;	
	}	while (original_money <= 0);
	
	do {
		cout << "Nhap so nam muon gui: ";
		cin >> years;
	}while (years <= 0);
	
	tien_dau_ky = original_money;
	monthly_interest = (anually_interest/100) /12;
	cout << "\nTai khoan khach hang " << name << endl;
	cout << setprecision(2) << fixed;
	
	for (int year = 1; year <= years; year++){
		cout << "\n Nam thu " << year << endl;
		for (int month = 1; month <= 12; month++)
		{
			monthly_profit = monthly_interest * tien_dau_ky;
			so_du = tien_dau_ky + monthly_profit;
			cout << setw(7) << "Thang" << setw(15) << "Tien dau ky" << setw(15) << "Tien lai" << setw(15) << "So du\n";
			cout << setw(7) <<month << setw(15) << tien_dau_ky << setw(15) << monthly_profit << setw(15) << so_du <<endl;
			tien_dau_ky = so_du;
		}
	}
	return 0;
}
