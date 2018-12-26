#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int *appearTimes(char *arr){
	static int counter[95];

	for (int i = 0; i < 95; i++) counter[i] = 0;
	for (int i = 0;i < strlen(arr); i++){
		if(isprint(arr[i])){
			counter[(arr[i]) - 32]++;		
		}
	}
	return counter;		
}

int *appearTimes(string arr){
	static int counter[95];
	
	for (int i = 0; i < 95; i++) counter[i] = 0;
	for (int i = 0;i < arr.length(); i++){
		if(isprint(arr[i])){
			counter[(arr[i]) - 32]++;		
		}
	}
	return counter;
}
int main() {
    string arr;
	int *counter;
	
	cout << "Enter a string: ";
	getline(cin, arr);
	counter = appearTimes(arr);
	
	int max = counter[0],
		maxIndex;
	int	i;
	
	for (i = 1; i < 95; i++){
		if (max < counter[i]){
			max = counter[i];
			maxIndex = i;
		}
	}
	
	cout << "The character " << "'" << static_cast<char>(maxIndex + 32) << "'" << " with " << max << " times.";
    return 0;
}
