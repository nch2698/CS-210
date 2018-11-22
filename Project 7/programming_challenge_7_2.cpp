#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double rain[12], total = 0.0;
	
	for (int i = 0; i < 12; ++i){
		do{
			cout << "Enter the rain fall of month " << i + 1 << " (mm): ";
			cin >> rain[i];
			cin.ignore(256, '\n');
			if (rain[i] < 0)
				cout << "Invalid rainfall." << endl;
		total += rain[i];
		} while (rain[i] < 0);
	}
	
	int i_highest = 0, i_lowest = 0;
	double r_highest = rain[0], r_lowest = rain[0];
	for (int i = 1; i < 12; ++i){
		if(r_lowest > rain[i]){
			i_lowest = i;
			r_lowest = rain[i];
		}
		if(r_highest < rain[i+1]){
			i_highest = i;
			r_highest = rain[i];
		}
	}
	
	cout << fixed << setprecision(2)
	 	 << "The total rainfall for the year is " << total << " mm" << endl
	 	 << "The average monthly rainfall is " << total / 12.0 << " mm" << endl
		 << "The months with the highest amount is month " << i_highest + 1 << " with " << r_highest << endl
		 << "The months with the lowest amount is month " << i_lowest + 1 << " with " << r_lowest << endl;
	return 0;		 
}
