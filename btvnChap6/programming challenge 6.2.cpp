#include <iostream>
using namespace std;

double getLength();
double getWidth();
double getArea(double, double);
void displayArea(double, double, double);

int main(){
	double length, width ,area;
	length = getLength();
	width = getWidth();
	area = getArea(length, width);
	displayArea(length, width ,area);
	return 0;
}

double getLength(){
	double length;
	do {
		cout << "Enter the length of the rectangle: ";
		cin >> length;
	}while (length <= 0);
	
	return length;
}

double getWidth(){
	double width;
	do {
		cout << "Enter the length of the rectangle: ";
		cin >> width;
	}while (width <= 0);
	
	return width;
}

double getArea(double length, double width){
	return length * width;
}

void displayArea(double length, double width, double area){
	cout << "The width of rectangle is " << width
	<< " and its length is " << length <<".";
	cout << "\nThe area of rectangle is " << area << " unit sqare."<< endl;
	
}
