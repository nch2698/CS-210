#include <iostream>
#include <iomanip>
using namespace std;

double getLength(){
	double length;
	cout << "Enter the length of the rectangle: ";
	cin >> length;
	return length;
}

double getWidth(){
	double width;
	cout << "Enter the width of the rectangle: ";
	cin >> width;
	return width;
}

double getArea(double length, double width){
	return length * width;
}

void displayData(double length, double width, double area){
	cout << "The length of the rectangle is: " << length << endl;
	cout << "The width of the rectangle is: " << width << endl;
	cout << "The area of the rectangle is: " << area << endl;
}

int main(){
	double length, width, area;
	length = getLength();
	width = getWidth();
	area = getArea(length, width);
	cout << endl;
	displayData(length, width, area);
}
