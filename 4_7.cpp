#include <iostream>
using namespace std;

int main(){
	int second, minute, hour, day;
	cout << "Enter the number of seconds: ";
	cin >> second;
	
	
	if (second > 0){
		if (second >=60 && second < 3600){
			minute = second / 60;
			second = second % 60;
			cout << minute << " minute(s) " << second << " second(s).";	
		}else if (second >= 3600 && second < 86400){
			hour = second / 3600;
			minute = second % 3600 / 60;
			second = second % 3600 % 60;
			cout << hour << " hour(s) " << minute << " minute(s) " << second << " second(s).";  
		}else if (second >= 86400){
			day = second / 86400;
			hour = second % 86400 / 3600;
			minute = second % 86400 % 3600 / 60;
			second = second % 86400 % 3600 % 60;
			cout << day << " day(s) " << hour << " hour(s) " << minute << " minute(s) " << second << " seconds.";
		
	}else{
		cout << "The second is invalid.";
	}
	}
return 0;	
}
