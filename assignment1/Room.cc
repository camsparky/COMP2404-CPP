#include "Room.h"

//Constructors
Room::Room(string name, int capacity, int computers, bool whiteboard){
    this->name = name;
    this->capacity = capacity;
    this->computers = computers;
    this->whiteboard = whiteboard;
}

Room::Room(Room& r){
    this->name = r.name;
    this->capacity = r.capacity;
    this->computers = r.computers;
    this->whiteboard = r.whiteboard;
}

//Getters
string Room::getName(){return name;}
int Room::getCapacity(){return capacity;}
int Room::getComputers(){return computers;}
bool Room::hasWhiteboard(){return whiteboard;}


//Setters
void Room::setName(string name){this->name = name;}
void Room::setCapacity(int capacity){this->capacity = capacity;}
void Room::setComputers(int computers){this->computers = computers;}
void Room::setWhiteboard(bool whiteboard){this->whiteboard = whiteboard;}

//Other
bool Room::meetsCriteria(int capacity, int computers, bool whiteboard){ //Returns true if the room meets the criteria given by the input, returns false otherwise.
    if(this->capacity>=capacity && this->computers>=computers){ // Checking whether the room meets the capacity and computer criteria
        if(this->whiteboard==false && whiteboard==true){ //Checking if the room has the required whiteboard
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}

bool Room::lessThan(Room& r){ //Returns true if the local rooms name comes before the input rooms name alphabetically, returns false otherwise
    string baseStringLower =""; //Functions nearly the same as the Student lessThan function, however the compared member is different
    string inputStringLower = "";
    for(int i=0; i<r.name.size() ; i++){ //Lowering input string
        inputStringLower += tolower(r.name[i]);
    }
    for(int i=0; i<this->name.size(); i++){//Lowering base string
        baseStringLower += tolower(this->name[i]);
    }
    if(baseStringLower.compare(inputStringLower)<0){
        return true;
    }
    else{
        return false;
    }
}

void Room::print(){ //Prints member variables
    cout << "Room-> Name: "<< name << " Capacity: " << capacity << " Computers: " << computers << " Whiteboard: " << whiteboard << endl;
}