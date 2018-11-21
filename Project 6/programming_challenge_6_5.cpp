#include <iostream>
using namespace std;
const double g = 9.8;

double fallingDistance(int t){
	return 0.5 * g * t * t;
}
int main(){
	double d;
	for (int t = 1; t <= 10; ++t){
		d = fallingDistance(t);
		cout << "The distance that the object has fallen during " << t << " second(s) is " << d << " meters." << endl;
	}
	return 0;	
}
