#include "Reservation.h"

//Constructors
Reservation::Reservation(Student* student, Room* room, Date& date){
    this->student = student;
    this->room = room;
    this->date.setDate(date);
}

//getters
Student* Reservation::getStudent(){ return this->student; }
Room* Reservation::getRoom(){ return this->room;}
Date Reservation::getDate(){ return this->date;}


//other
bool Reservation::lessThan(Reservation& res){ //Returns true if the local date comes before the input date, returns false otherwise.
    if(this->date.lessThan(res.date)){ //Reusing the date lessThan function
        return true;
    }
    else{
        return false;
    }
}

bool Reservation::overlaps(const string& r, Date& d){ //Returns true if the local room name matches the "r" string and the local date overlaps the input date, returns false otherwise.
    if(this->room->getName() == r && this->date.overlaps(d)){ //Reusing the date overlaps function
        return true;
    }
    else{
        return false;
    }
}

void Reservation::print(){ //Prints member variables
    cout << "Reservation:"<< endl;
    this->student->print();
    this->room->print();
    this->date.print();
    cout << endl;
}