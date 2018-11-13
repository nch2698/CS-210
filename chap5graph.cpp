#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	
//	RETANGLE
	for (int row = 0; row <= 6; row++){ 
		for (int col =0; col <=6; col++ ){
			if (row == 0 || row == 6 || col == 0 || col == 6){
				cout << "*";
			}else{
				cout << " ";
			}
		}
		cout << endl;
	}
	
	cout << "\b";
//	Z letter
	for (int row = 0; row <= 6; row++){ 	
		for (int col =0; col <=6; col++ ){
			if (col == row || row == 0 || row == 6 )
				cout << "*";
			else
				cout << " ";		
					
		}
		cout << endl;
	}
	cout << "\b";
	
	//Z letter inverse
	for (int row = 0; row <= 6; row++){ 	
		for (int col =0; col <=6; col++ ){
			if ( (6-col) == row || row == 0 || row == 6 )
				cout << "*";
			else
				cout << " ";		
					
		}
		cout << endl;
	}
	
	cout << "\b";
	
	// Dong ho cat
	for (int row = 0; row <= 6; row++){ 	
		for (int col =0; col <=6; col++ ){
			if ( (6-col) == row || row == col || row == 0 || row == 6 )
				cout << "*";
			else
				cout << " ";		
					
		}
		cout << endl;
	}
	cout << "\b";
	
	for (int row = 0; row <= 6; row++){ 	
		for (int col =0; col <=6; col++ ){
			if ( (6-col) == row || row == 0 || row == 6 || col == row || col==0 || col ==6 )
				cout << "*";
			else
				cout << " ";		
					
		}
		cout << endl;
	}
	
	
	
	return 0;
}
