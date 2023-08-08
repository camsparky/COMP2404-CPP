#include "Aircraft.h"

Aircraft::Aircraft(const string& type, const string& registration): type(type), registration(registration), flighthours(0) {} //Initializes all local variables, except for parts.

const string& Aircraft::getRegistration() const {return registration;}

void Aircraft::install(Part* part, const Date& date){ //Adds the given part to the local Array and installs it using one of part's functions
    parts.add(part);
    parts[parts.getSize()-1]->install(date); //Installing the new part
}

void Aircraft::takeFlight(int hours){ //Adds the given amount of hours to the local flightHours, also updates the flighthours of all parts on the aircraft
    flighthours+=hours;
    for(int i=0; i<parts.getSize(); i++){
        parts[i]->addFlightHours(hours);
    }
}

void Aircraft::inspectionReport(const Date& date, Array<Part*>& partsOut){ //Returns all parts on the aircraft that need to be inspected within the "partsOut" output parameter
    for(int i=0; i<parts.getSize(); i++){
        if(parts[i]->inspection(date)){
            partsOut.add(parts[i]);
        }
    }
}

ostream& operator<<(ostream& output, const Aircraft& aircraft)
{
    output << "Aircraft: " << aircraft.type << endl << "Registration: " << aircraft.registration << endl << "Flighthours: " << aircraft.flighthours << endl;
    return output;
  
}