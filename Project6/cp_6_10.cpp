#include <iostream>
#include <iomanip>

using namespace std;

void showDollars(double); // Function prototype
int main()
{
    double payRate, hoursWorked, wages;
    cout << "How many hours have you worked? ";
    cin >> hoursWorked;
    cout << "What is your hourly pay rate? ";
    cin >> payRate;
    wages = hoursWorked * payRate;
    showDollars(wages);
    return 0;
}

//    You must write the definition of the function showDollars
//    here. It should take one parameter of the type double.
//    The function should display the message "Your wages are $"
//    followed by the value of the parameter. It should be displayed
//    with 2 places of precision after the decimal point, in fixed
//    notation, and the decimal point should always display.
void showDollars(double wage) {
    cout << fixed << showpoint << setprecision(2);
    cout << "Your wages are $" << wage;
}