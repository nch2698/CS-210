#include <iostream>
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main(){
	int num, guess;
	unsigned seed = time(0);
	srand(seed);
	
	num = 1 + rand() % 10;
	
	cout << "Guess a number: ";
	cin >> guess;
	
	if (guess >=1 && guess <= 10){
		if(guess > num){
			cout << "High!";
			cout << "The random number is " << num;
		}else if (guess < num){
			cout << "Low!" << endl;
			cout << "The random number is " << num;
		}else {
			cout << "Correct!";
			cout << "The random number is " << num;
		}
	}else{
		cout << "Your guess is out of range.";
	}

return 0;
}
