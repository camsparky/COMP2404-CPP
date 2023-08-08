#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Array.h"
#include "Part.h"

using namespace std;

class Aircraft {
    friend ostream& operator<<(ostream&, const Aircraft&); //overloading the << operator
    public:
        //Constructor
        Aircraft(const string& type, const string& registration); //Initializes all local variables, except for parts.

        //Getters
        const string& getRegistration() const;

        //Other
        void install(Part* part, const Date& date); //Adds the given part to the local Array and installs it using one of part's functions
        void takeFlight(int hours); //Adds the given amount of hours to the local flightHours, also updates the flighthours of all parts on the aircraft
        void inspectionReport(const Date& date, Array<Part*>& partsOut); //Returns all parts on the aircraft that need to be inspected within the "partsOut" output parameter


    private:
        string type;
        string registration;
        int flighthours;
        Array<Part*> parts;
	
};

#endif