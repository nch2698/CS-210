#include <iostream>
using namespace std;

int main(){
	char arr[1000];
	
	cout << "Enter a string: ";
	cin >> arr;
	
	for (int i = 0; i < 1000; ++i){
		if(arr[i] != '\0'){
	        if(arr[i] >= 'a' && arr[i] <= 'z'){
	        	arr[i] -= 32;
			}
		}else break;
	}
	cout << "UPPERCASE string: " << arr;
	return 0;	
}
