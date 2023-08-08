#include "Library.h"

//Constructors
Library::Library(){
    studentCount=0;
    roomCount=0;
    reservationCount=0;
    students = new Student*[MAX_ARRAY];
    reservations = new Reservation*[MAX_ARRAY];
}

Library::~Library(){
    for(int i=0; i< studentCount; i++){ //First deleting each individual student object from the heap
        delete students[i];
    }
    for(int i=0; i< reservationCount; i++){ //Also deleting each individual reservation object from the heap
        delete reservations[i];
    }
    delete[] students; //Then deleting both dynamically allocated arrays
    delete[] reservations;
    for (int i = 0; i < roomCount; ++i){ //Finally deleting each individual room object from the heap
        delete rooms[i];
    }
}

//Getters++
bool Library::getStudent(const string& name, Student** student){ //If a student with the same name as the input string exists store it within the student double pointer and return true, false otherwise
    for(int i=0; i<studentCount; i++){ // Iterating through each student to possibly find a student with the same name as the input string
        if(students[i]->getName().compare(name)==0){
            *student = students[i]; //Found the student and storing it within the double pointer
            return true;
        }
    }
    return false;
}

bool Library::getRoom(const string& roomName, Room** room){ //If a room with the same name as the input string exists store it within the room double pointer and return true, false otherwise
    for(int i=0; i<roomCount; i++){ // Iterating through each room to possibly find a room with the same name as the input string
        if(rooms[i]->getName().compare(roomName)==0){
            *room = rooms[i]; //Found the room and storing it within the double pointer.
            return true;
        }
    }
    return false;
}


//Other
bool Library::addStudent(const string& name, const string& number){ //Adds a student to the students array if it is not full, returns true if successful, false otherise. 
    if (studentCount >= MAX_ARRAY) return false; //Returning false if the students array is full

    students[studentCount++] = new Student(name, number);

    for(int i=studentCount-1; i>0; i--){ //Iterating backwards through the students array and swaping the newest student backwards based on student number. Essentially ordering the array in increasing order.
        if(students[i]->lessThan(*students[i-1])==true){ //Swapping the place of students within the array
            Student* temp = students[i];
            students[i]=students[i-1];
            students[i-1]=temp;
        }
    }
    return true;
}

bool Library::addRoom(string name, int capacity, int computers, bool whiteboard){ //Adds a room to the rooms array if it is not full, returns true if successful, false otherise.
    if(roomCount >= MAX_ARRAY) return false; //Returning false if the rooms array is full

    rooms[roomCount++] = new Room(name,capacity,computers,whiteboard);

    for(int i=roomCount-1; i>0; i--){ //Iterating backwards through the rooms array and swaping the newest room backwards based on name. Essentially ordering the array in increasing order.
        if(rooms[i]->lessThan(*rooms[i-1])==true){ //Swapping the place of rooms within the array
            Room* temp = rooms[i]; 
            rooms[i]=rooms[i-1];
            rooms[i-1]=temp;
        }
    }
    return true;
}

bool Library::isFree(const string& room, Date& date){ // Returns true if the room with the same name as the input string has the input date available, false otherwise.
    Room* tempRoom;
    if(getRoom(room,&tempRoom)){ //First checking if the room with the input name exists
        for(int i=0; i<reservationCount; i++){
            if(reservations[i]->overlaps(room,date)){ //Checking if the room overlaps with the input date at any point
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

bool Library::makeReservation(const string& student, const string& room, Date& date){ //Returns true if the room with the same name as the input string is free and adds a new reservation to the reservations array, false otherwise.
    Student* tempStudent;
    Room* tempRoom;
    if(getStudent(student, &tempStudent)==false || getRoom(room,&tempRoom)==false) return false; //Checking if the student and room with the given string inputs exist.
    else{
        if(isFree(room,date) && reservationCount!=MAX_ARRAY){ //Checking if the room is free and if the reservations array is not full yet
            reservations[reservationCount++] = new Reservation(tempStudent,tempRoom,date); //Adding the new reservation to the reservations array
        }
        else{
            return false;
        }
    }
    for(int i=reservationCount-1; i>0; i--){ //Iterating backwards through the reservations array and swaping the newest reservation backwards based on date. Essentially ordering the array in increasing order.
        if(reservations[i]->lessThan(*reservations[i-1])==true){
            Reservation* temp = reservations[i];
            reservations[i]=reservations[i-1];
            reservations[i-1]=temp;
        }
    }
    return true;
}

void Library::update(Date& date){ //Removes reservations from the reservations array that are lower then or on the same date as the input date.
    int cutoffDate=0; //Storing the index where the local date is larger then the input date
    for(int i=0; i<reservationCount; i++){ //Iterating through each reservation trying to find the index of a date that is larger then the input date.
        if(reservations[i]->getDate().lessThan(date)==false){ //Checking to see that the reservation date is not less the input date
            if(reservations[i]->getDate().getYear() != date.getYear() || reservations[i]->getDate().getMonth() != date.getMonth() || reservations[i]->getDate().getDay() != date.getDay() || reservations[i]->getDate().getHour() != date.getHour()){ //Checking to see that the reservation date is not equal to the input date
                cutoffDate=i; //Reservation date must be greater then the input date to the index position can be stored and the loop can be stoped.
                break;
            }
        }
    }
    for(int i=0; i<cutoffDate; i++){ //Deleting each unwanted reservation from the heap
        delete reservations[i];
    }
    reservationCount = reservationCount - cutoffDate; // Shortening the new reservation count
    for(int i=0; i<reservationCount; i++){ // Shifting the reservations array downwards
        reservations[i] = reservations[i+cutoffDate];
    }
    for(int i=reservationCount; i<reservationCount+cutoffDate; i++){ //Making sure the previous positions of reservations point to nothing
        reservations[i]= NULL;
    }
}

void Library::printReservations(){
    cout << "~RESERVATIONS~" << endl;
    for(int i=0; i<reservationCount; i++){
        reservations[i]->print();
    }
}

void Library::print(){ //Prints important member variables
    cout << "~LIBRARY~" << endl;

    cout << endl<< "~STUDENTS~" << endl;
    for(int i=0; i<studentCount; i++){
        students[i]->print();
    }

    cout << endl << "~ROOMS~" <<endl;
    for(int i=0; i<roomCount; i++){
        rooms[i]->print();
    }
    cout << endl;

    printReservations();

}