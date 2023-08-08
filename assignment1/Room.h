#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room { //Stores Room related information (Name, capacity, # of computers and if there is a whiteboard) and provides basic functions (meetsCriteria, print and lessThan).
    public:
        //Constructors
        Room(string name, int capacity, int computers, bool whiteboard);
        Room(Room&);
        
        //Getters
        string getName();
        int getCapacity();
        int getComputers();
        bool hasWhiteboard();

        //Setters
        void setName(string name);
        void setCapacity(int capacity);
        void setComputers(int computers);
        void setWhiteboard(bool whiteboard);

        //Other
        bool meetsCriteria(int=1, int=0, bool=false); //Returns true if the room meets the criteria given by the input, returns false otherwise.
        bool lessThan(Room& r); //Returns true if the local rooms name comes before the input rooms name alphabetically, returns false otherwise.
        void print(); //Prints member variables


    private:
        //Members
        string name;
        int capacity;
        int computers;
        bool whiteboard;
        
};


#endif