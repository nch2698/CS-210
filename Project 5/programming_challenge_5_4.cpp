#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	const double caloriesPerMin = 3.90;
	int min;
	
	cout << "Minutes" << "     Calories burnt" << endl;
	for (min = 5; min <= 30; min +=5 ){
		cout << fixed << setprecision(2);
		cout << left << setw(8) << min << right << setw(15) << caloriesPerMin * min << endl;
	}	
return 0;
}
