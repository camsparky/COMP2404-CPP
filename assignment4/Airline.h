#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Array.h"
#include "Part.h"
#include "Aircraft.h"

using namespace std;

class Airline {
    
    public:
        //Constructor
        Airline(const string& name); 
        ~Airline(); // Deleting all aircraft and parts associated with this airline from the heap.



        //Other
        void addAircraft(const string& type, const string& registration); //Adds a new aircraft with the give type and registration to the aircraft array (Dynamic)
        void addPart(const string& part, int fh_inspect, int it_inspect); //Adds a new type of part based on the given fh_inspect and it_inspect variables to the parts array (Dynamic)
        void takeFlight(const string& reg, int hours); //Adds the given flight hours to the aircraft matching the given registration
        void printAircraft() const; 
        void printParts() const;
        void print() const;
        void inspectionReport(const string& reg, const Date& date); //Using the given registration and date, this functions finds the related aircraft and prints all it's parts that need inspection.
        bool install(const string& aircraftReg, const string& partName, const Date& date); //Uses the given aircraftReg and partName to attempt to install a part into the specified aircraft.


    private:
        string name;
        Array<Part*> parts;
        Array<Aircraft*> aircraft;

        //Helper getters
        void getPart(const string& partName, Part** partOut); //Returns the part with the same name as "partName" within the "partOut" output variable.
        void getAircraft(const string& registration, Aircraft** aircraftOut); //Returns the aircraft with the same registration as "registration" within the "aircraftOut" output variable.

	
};

#endif