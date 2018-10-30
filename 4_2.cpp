#include <iostream>
using namespace std;

int main(){
	int num;
	cout << "Enter a number from 1 to 10 to see its Roman version: ";
	cin >> num;
	
	if (num > 0 && num < 11 ){
		switch (num){
			case 1: 
				cout << "The Roman version is: I.";
				break;
			case 2: 
				cout << "The Roman version is: II.";
				break;
			case 3: 
				cout << "The Roman version is: III.";
				break;
			case 4: 
				cout << "The Roman version is: IV.";
				break;
			case 5: 
				cout << "The Roman version is: V.";
				break;
			case 6: 
				cout << "The Roman version is: VI.";
				break;
			case 7: 
				cout << "The Roman version is: VII.";
				break;
			case 8: 
				cout << "The Roman version is: VIII.";
				break;
			case 9: 
				cout << "The Roman version is: IX.";
				break;
			case 10: 
				cout << "The Roman version is: X.";
				break;
		}
	}
	else{
		cout << "Your number is out of range.";
	}
	
	return 0;
}
