#include <iostream>
#include <iomanip>
using namespace std;

void outputMaxOrMinIndex(double max_or_min, double rainFall[], int name[], int size);

int main(){
	const int SIZE = 12;
	double rainFall[SIZE];
	int month[SIZE] {1,2,3,4,5,6,7,8,9,10,11,12};
	double total = 0, average;
	cout << "Enter amount of rainfall for next 12 months.\n";
	
	//Input validation
	for (int i=0; i < SIZE; i++){
		do {
			cout << "The amount of month " << (i+1) << " is: ";
			cin >> rainFall[i];
			if (rainFall[i] < 0) cout << "The amount cannot be a negative number.\n";
		}while(rainFall[i] < 0);
		
		
	}
	//Max,min,total,average
	double min = rainFall[0], max = rainFall[0];
	for (int i=0; i < SIZE; i++){
		total += rainFall[i];
		if (rainFall[i] > max)
			max = rainFall[i];
		
		if (rainFall[i] < min)
			min = rainFall[i];
	}
	cout << setprecision(2) << fixed;
	average = total / SIZE;
	
	//Display
	cout << "Total amount of rainfall is " << total << endl;
	cout << "Average amount of rainfall is " << average << endl;
	cout <<"highest " << "is " << max << " in month "; 
	outputMaxOrMinIndex(max,rainFall,month,SIZE);
	cout << "\nThe smallest amount is " << min << " in month ";
	outputMaxOrMinIndex(min,rainFall,month,SIZE) ;
	return 0;
}

void outputMaxOrMinIndex(double max_or_min, double rainFall[], int name[], int size){
	int index[size] {0};
	int j = 0;
	
	for (int i=0; i < size;i++){
		if (rainFall[i] == max_or_min) {
			index[j] = i;
			j++;
		}
	}
	for (int i=0; i < j;i++){
		cout << name[index[i]] << " ";
	}
}


