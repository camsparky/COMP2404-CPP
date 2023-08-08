#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Room.h"
#include "Date.h"

using namespace std;

class Reservation { //Stores Rervation related information (Student, Room, Date) and provides basic functions (overlaps, print and lessThan).
		
	public:
		//constructor
		Reservation(Student* student, Room* room, Date& date);
		
		//getters
        Student* getStudent();
        Room* getRoom();
        Date getDate();
		
		//other
        bool lessThan(Reservation& res); //Returns true if the local date comes before the input date, returns false otherwise.
        bool overlaps(const string& r, Date& d); //Returns true if the local room name matches the "r" string and the local date overlaps the input date, returns false otherwise.
        void print(); //Prints member variables
	
	private:
		//Members
        Student* student;
        Room* room;
        Date date;

	
};
#endif
