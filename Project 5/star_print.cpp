#include<iostream>
using namespace std;

int main(){
	int row, col;
	for (row = 1; row <= 7; row++){
		for (col = 1; col <= 7; col++){
			if (row == 1 || row == 7){
				cout << "* ";
				continue;
			}else if ((row == 2 || row == 6) && (col == 2 || col == 6)){
				cout << "* ";
				continue;
			}else if ((row == 3 || row == 5) && ( col == 3 || col == 5)){
				cout << "* ";
				continue;
			}else if (row == 4 && col == 4){
				cout << "* ";
				continue;
			}else
				cout << "  ";
			
		}
		cout << '\n'; 
	}
	
	cout << "\n\n\n";
	for (row = 1; row <= 7; row++){
		for (col = 1; col <= 7; col++){
			if (row == 1 || row == 7 || col == 1 || col == 7){
				cout << "* ";
				continue;
			}else if ((row == 2 || row == 6) && (col == 2 || col == 6)){
				cout << "* ";
				continue;
			}else if ((row == 3 || row == 5) && ( col == 3 || col == 5)){
				cout << "* ";
				continue;
			}else if (row == 4 && col == 4){
				cout << "* ";
				continue;
			}else
				cout << "  ";
			
		}
		cout << '\n'; 
	}
return 0;			
}
