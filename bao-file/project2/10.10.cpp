#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
void find_and_replace(string &str1,string str2, string str3){
	int index = str1.find(str2) ;
	if (index == string::npos)
	{
		cout << "No change can be made in this string.\n";
		return;
	}else
	{
		str1.erase(index,str2.length());
		str1.insert(index,str3);		
	}
}
int main(){
	string str1 = "hello hewdio hewdio";
	string str2 = "el";
	string str3 = "aaaa";
	int index, found_index;
	index = str1.find(str2);
	while (index != string::npos){
		if (str1.find(str2) == string::npos)
		cout << "false";
		else
			find_and_replace(str1,str2,str3);
		index = str1.find(str2);
			
	}
	
	cout << str1;
		
		
	return 0;
}


