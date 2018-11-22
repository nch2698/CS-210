#include <iostream>
#include <iomanip>
using namespace std;

void getTime(int&, double&, double&);
void getAirFare(double&);
void getCarRent(double&);
void getPrivateDrive(double&);
void getMeeting(double&);
void getParking(double&, int&, double&);
void getTaxi(double&, int&, double&);
void getHotel(double&, int&, double&);
void getMeal(double&, double&, double&, double& );

int main(){
	int day;
	double depart, back, 
		   airFare, carRent, privateDrive, parking, taxi,
		   meeting, hotel, mealFee, total,
		   parkingAllowed, taxiAllowed, hotelAllowed, mealAllowed,
		   parkingExcess, taxiExcess, mealExcess, hotelExcess, totalExcess;

	cout << "Times for Business Trip" << endl
	 	 << "-----------------------" << endl;
	getTime(day, depart, back);
	cout << "\nUnallowable Fees" << endl
		 << "-----------------" << endl; 
	getAirFare(airFare);
	getCarRent(carRent);
	getPrivateDrive(privateDrive);
	getMeeting(meeting);
	cout << "\nAllowable Fees" << endl
		 << "---------------" << endl; 
	getParking(parking, day, parkingAllowed);
	    parkingExcess = parking - parkingAllowed;	
	
	getTaxi(taxi, day, taxiAllowed);
        taxiExcess = taxi - taxiAllowed;

	getHotel(hotel, day, hotelAllowed);
        hotelExcess = hotel - hotelAllowed;

	getMeal(mealFee, depart, back, mealAllowed);
        mealExcess = mealFee - mealAllowed;
	
    total = airFare + carRent + privateDrive + parking + taxi + meeting + hotel + mealFee;
    totalExcess = parkingExcess + taxiExcess + mealExcess;
	cout << "\nCalculations" << endl
		 << "-------------" << endl;
	cout << left << setw(20) << "\nDays: " << day << setw(20) << "\nAirFare: " << airFare <<  setw(20) << "\nCar Rentals" << carRent 
	     << setw(20) << "\nPrivateDrive: " << privateDrive << setw(20) << "\nParking: " << parking << setw(20) << "\nTaxi: " << taxi 
		 << setw(20) << "\nConference: "  << meeting << setw(20) << "\nHotel: " << hotel << setw(20) << "\nMeal Fee: " << mealFee
		 << setw(20) << "\n\nTotal Expense: " << total << setw(20) << "\nTotal Allowed:  " << parkingAllowed + taxiAllowed + hotelAllowed + mealAllowed;
	if (totalExcess >= 0){
		cout << left << setw(20) << "\nTotal Excess: " << totalExcess; 
	}else if (totalExcess < 0){
		cout << left << setw(20) << "\nTotal Save: " << -totalExcess; 
	}
	return 0;
 }

void getTime (int& day, double& depart, double& back){
    do {
		cout << "The total number of days spent on the trip? ";
	    cin >> day;
	    if (day < 1){
	    	cout << "Invalid number of days." << endl;
		}
	} while (day < 1);
    do{
	    cout << "The time of departure on the first day of the trip (from 5 to 23)? ";
	    cin >> depart;
	    if (depart < 5 || depart > 22){
	    	cout << "Invalid time." << endl;
		}
	} while (depart < 5 || depart > 22);
    do{
   	    cout << "The time of arrival back home on the last day of the trip (from 5 to 23)? ";
    	cin >> back;
    	 if (back < 5 || back > 23){
	    	cout << "Invalid time." << endl;
		} 
	} while (back < 5 || back > 23);		
}

void getAirFare (double& airFare){
	cout << "The amount of any round-trip airfare? ";
	cin >> airFare;
}

void getCarRent (double& carRent){
	cout << "The amount of any car rentals? ";
	cin >> carRent;
}

void getPrivateDrive (double& privateDrive){
	double mile;
 	
    do{
	 	cout << "Miles driven, if a private vehicle was used? ";
		cin >> mile;
		if (mile < 0){
			cout << "Invalid number of miles." << endl;
		} 
	} while (mile < 0);
	privateDrive = mile * 0.27;
}

void getParking (double& parking, int& day, double& parkingAllowed){
	cout << "Parking fees (allow 6$/day)? ";
	cin >> parking;
	parkingAllowed = 6.0 * day;
}

void getTaxi (double& taxi, int& day, double& taxiAllowed){
	cout << "Taxi fees, if a taxi was used anytime during the trip (allow 10$/day)? ";
	cin >> taxi;
	taxiAllowed = 10.0 * day;
}

void getMeeting (double& meeting){
    cout << "Conference or seminar registration fees? ";
	cin >> meeting;
}

void getHotel (double& hotel, int& day, double& hotelAllowed){
	cout << "Hotel expenses (allow 90$/day)? ";
	cin >> hotel;
	hotelAllowed = 90.0 * day;
}

void getMeal (double& mealFee, double& depart, double& back, double& mealAllowed){
	int breakfast = 0, lunch = 0, dinner = 0, i = 1;
	double meal;
	
	if (depart < 7){
		breakfast++;
	}else if (depart >= 7 && depart < 12){
		lunch++;
	}else if (depart >= 12 && depart < 18){
		dinner++;
	}
	
	if (back > 8 && back <= 13){
		breakfast++;
	}else if (back > 13 && back <= 19){
		lunch++;
	}else if (back > 19){
		dinner++;
	}
	
	cout << "You have " << breakfast + lunch + dinner << " allowable meal(s): "
		 << breakfast << " breakfast (allow 9$), " << lunch << " lunch (allow 12$), " << dinner << " dinner (allow 16$)." << endl;
	while (i > 0 && i <= breakfast + lunch + dinner){
		  cout << "\tThe price of meal " << i << "? ";
		  cin >> meal;
		  mealFee += meal;
		  i++;	
	}
	mealAllowed = 9 * breakfast + 12 * lunch + 16 * dinner;
}

