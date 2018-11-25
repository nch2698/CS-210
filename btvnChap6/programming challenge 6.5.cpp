#include <iostream>
#include <cmath>
using namespace std;

double const g = 9.8;

double fallingDistance(double time){
	double distance =  (g * time * time)/2;
	return distance;
}

int main(){
	cout << "The program calls value time from 1 to 10 and displays the distance. \n";
	for (double t = 0; t <= 10; t++){
		cout << "\n Falling time: " << t << " Falling distance : " << fallingDistance(t) << endl;
	}
	return 0;
}
