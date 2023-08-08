#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_ARRAY 100

#include <iostream>
#include <string>
#include "Reservation.h"

using namespace std;

class Library {
    public:
        //Constructors / Destructors
        Library();
        ~Library();

        //Getters++
        bool getStudent(const string& name, Student** student); //If a student with the same name as the input string exists store it within the student double pointer and return true, false otherwise
        bool getRoom(const string& roomName, Room** room); //If a room with the same name as the input string exists store it within the room double pointer and return true, false otherwise

        //Other
        bool addStudent(const string& name, const string& number); //Adds a student to the students array if it is not full, returns true if successful, false otherise. 
        bool addRoom(string, int=1, int=0, bool=false); //Adds a room to the rooms array if it is not full, returns true if successful, false otherise.
        bool isFree(const string& room, Date&); // Returns true if the room with the same name as the input string has the input date available, false otherwise.
        bool makeReservation(const string& student, const string& room, Date&); //Returns true if the room with the same name as the input string is free and adds a new reservation to the reservations array, false otherwise.
        void update(Date&); //Removes reservations from the reservations array that are lower then or on the same date as the input date.
        void printReservations();
        void print(); //Prints important member variables


    private:
        //Members
        Student** students; //Dynamic
        Room* rooms[MAX_ARRAY]; //Static
        Reservation** reservations; //Dynamic
        int studentCount, roomCount, reservationCount;


};


#endif