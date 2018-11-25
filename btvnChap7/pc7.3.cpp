#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void outputMinOrMaxIndex(int max_or_min, int jar[], string name[], int size);
	
using namespace std;
int main(){
	int const SIZE = 5;
	string name[SIZE] = {"mild","medium", "sweet" ,"hot","zesty"};
	int jarSold[SIZE];
	long int total = 0;
	
	//input + validation + total
	for (int i=0; i < SIZE; i++){
		cout << "Enter the number jar sold for product " << name[i] << " salsa :";
		cin >> jarSold[i];
		
		while (jarSold < 0){
			cout << "The number of jar cannot be a negative number";
			cout << "Enter the number jar sold for product " << name[i] << " :";
			cin >> jarSold[i];
		} 
		
		total += jarSold[i];
	}
	
	//Max,min product
	int max=jarSold[0], min=jarSold[0];
	for (int i=0; i < SIZE; i++){
		if (jarSold[i] > max){
			max = jarSold[i];
		}
		
		if (jarSold[i] < min){
			min = jarSold[i];
		}
	}
	cout << "\n------------------------------\n";
	cout << left << setw(8) <<"Product" << "  "<< setw(10) << "Jar sold" << endl;
	for (int i=0; i < SIZE; i++){
		cout << left << setw(8) <<name[i] << ": "<< setw(10) << jarSold[i] << endl;
	}

	cout <<"highest " << "is "; 
	outputMinOrMaxIndex(max,jarSold,name,SIZE) ;
	cout << "salsa with " << max << " jars" << endl;
	
	cout <<"Lowest " << "is "; 
	outputMinOrMaxIndex(min,jarSold,name,SIZE);
	cout << "salsa with " << min << " jars";
	return 0;
}

void outputMinOrMaxIndex(int max_or_min, int jar[], string name[], int size){
	int index[size] {0};
	int j = 0;
	
	for (int i=0; i < size;i++){
		if (jar[i] == max_or_min) {
			index[j] = i;
			j++;
		}
	}
	for (int i=0; i < j;i++){
		cout << name[index[i]] << " ";
	}
}


