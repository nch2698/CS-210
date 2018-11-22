#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect(int num){
	int sum = 0;
	
	for (int count = 1; count < num; ++count){
		if (num % count == 0) 
		   sum += count;
	}
	if (sum == num) 
	   return true;
    return false;
}

bool isPrime(int num){
	int bound;
	bound  = sqrt(num);
	
	if (num == 2){
		return true;	
	}else{
		for (int count = 2; count <= bound ; ++count){
			if((num % count) == 0){
				return false;
				break;
			}else if (count == bound)
	            return true;
		}
	}
}

int main(){
	int choice, n = 10, i , j;
		
	do{
	   cout << "\n------" << endl
	   		<< " Menu" << endl
	   		<< "------" << endl
	   		<< "1.Enter a number N (default value = 10)." << endl
	 		<< "2.Print perfect numbers from 1 to N." << endl
			<< "3.Print prime numbers from 1 to N." << endl
			<< "4.Print all divisors of N." << endl
			<< "5.Quit." << endl
			<< "------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch(choice){
			case 1: cout << "Enter a number: ";
				 	cin >> n;
				 	break;
			case 2: cout << "Perfect numbers from 1 to " << n << endl;
				 	j = 0;
				 	for (i = 2; i <= n; ++i){
				 		if (isPerfect(i) == true){
				 			cout << i << "  ";
				 			j++;
				 			if (j == 10){
							cout << endl;
							j = 0;
							}
	 					}
			        }
				    break;
			case 3: cout << "Prime numbers from 1 to " << n << endl;
				 	j = 0;
				 	for (i = 2; i <= n; ++i){
				 		if (isPrime(i) == true){
				 			cout << i << "  ";
				 			j++;
				 			if (j == 10){
							cout << endl;
							j = 0;
							}
	 					}
			        }
					break;
			case 4: cout << "All divisors of " << n << endl;
				 	j = 0;
				 	for (i = 1; i <= n; ++i){
				 		if (n % i == 0){
				 			cout << i << "  " << -i << "  ";
				 			j += 2;
				 			if (j == 10){
							cout << endl;
							j = 0;
							}
					    }
			        }
					break;
			default: cout << "Have a problem with numbers?";
		}
    } while (choice != 5);	
return 0;
} 
