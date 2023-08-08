
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;
const int MAX_DURATION=3; //Maximum allowable booking duration

class Date { //Stores Date related information (Year, Month, Day, Hour, Duration of stay) and provides basic functions (overlaps, print and lessThan).
		
	public:
		//Constructors
		Date();
		Date(int year, int month, int day, int hour, int duration);
		
				
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setHour(int);
		void setDuration(int);
		void setDate(int y, int m, int d, int h, int dur);
		void setDate(Date&);
		
		//getters
		int getDay();
		int getMonth();
		int getYear();
		int getHour();
		int getDuration();
		const string& getMonthName();
		
		//other
		bool lessThan(Date& d); //Returns true if the local date comes before the input date, returns false otherwise.
		bool overlaps(Date& d); //Returns true if the local date and the input date overlap in time, returns false otherwise.
		void print(); //Prints member variables
	
	private:
		//functions
		int getMaxDay();
	
	
		//members
		int day;
		int month;
		int year;
		int hour;
		int duration;
		
		const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		const string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
	
};
#endif
