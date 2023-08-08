
#include "Date.h"

//Constructors
Date::Date(){
	setDate(1901,1,1,0,1);
}

Date::Date(int y, int m, int d, int h, int dur){
	setDate(y,m,d,h,dur);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setHour(int h){
	if(h>23) h=23;
	if(h<0) h =0;
	this->hour = h;
}

void Date::setDuration(int dur){
	if(dur>MAX_DURATION) dur=MAX_DURATION;
	if(dur<1) dur=1;
	this->duration = dur;
}

void Date::setDate(int y, int m, int d, int h, int dur){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(dur);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
int Date::getHour(){ return hour;}
int Date::getDuration(){return duration;}
const string& Date::getMonthName(){return months[month-1];}


//other

bool Date::lessThan(Date& d){  //Returns true if the local date comes before the input date, returns false otherwise.
	if (year == d.year){ //Comparing each local member and input member against eachother.
		if (month == d.month){
			if(day == d.day){
				return hour < d.hour; // Returning true if some input member variable is larger then the local member variable. Returning false if an input member that is larger does not exist.
			}
			else{
				return day < d.day;
			}
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}
}

bool Date::overlaps(Date& d){ //Returns true if the local date and the input date overlap in time, returns false otherwise.
	if(year == d.year && month == d.month && day == d.day){ // Checking whether the year, month and day overlap
		if(hour==d.hour){ // Checking whether the hour overlaps
			return true;
		}
		else{
			if(hour < d.hour && hour+duration>d.hour){ // Checking whether the duration of the input date overlaps the local date
				return true;
			}
			else if(d.hour < hour && d.hour+d.duration>hour){ // Checking whether the duration of the local date overlaps the input date.
				return true;
			}
			else{
				return false;
			}
		}
	}
	else{
		return false;
	}
}

void Date::print(){ //Prints Member Variables
	cout <<"Date-> " << getMonthName()<<" "<<getDay()<<", "<<getYear()<<", "<<getHour() << ", " <<getDuration() <<endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

