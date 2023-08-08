#include "Airline.h"
#include "Aircraft.h"

Airline::Airline(const string& name) : name(name) {}

Airline::~Airline(){ // Deleting all aircraft and parts associated with this airline from the heap.
    for(int i=0; i<parts.getSize(); i++){
        delete parts[i];
    }
    for(int i=0; i<aircraft.getSize(); i++){
        delete aircraft[i];
    }
}

void Airline::getPart(const string& partName, Part** partOut){ //Returns the part with the same name as "partName" within the "partOut" output variable.
    (*partOut)=NULL;
    for(int i=0; i<parts.getSize(); i++){
        if(parts[i]->getName() == partName){
            *partOut = parts[i];
            break;
        }
    }
}

void Airline::getAircraft(const string& registration, Aircraft** airOut){ //Returns the aircraft with the same registration as "registration" within the "aircraftOut" output variable.
    (*airOut)=NULL;
    for(int i=0; i<aircraft.getSize(); i++){
        if(aircraft[i]->getRegistration()==registration){
            *airOut = aircraft[i];
            break;
        }
    }
}

void Airline::addAircraft(const string& type, const string& registration){aircraft.add(new Aircraft(type, registration));} //Adds a new aircraft with the give type and registration to the aircraft array (Dynamic)

void Airline::addPart(const string& part, int fh_inspect, int it_inspect){ //Adds a new type of part based on the given fh_inspect and it_inspect variables to the parts array (Dynamic)
    if(it_inspect!=0 && fh_inspect != 0){
        parts.add(new FHIT_Part(part,fh_inspect,it_inspect));
    }
    else if(fh_inspect!=0 && it_inspect==0){
        parts.add(new FH_Part(part,fh_inspect));
    }
    else if(fh_inspect==0 && it_inspect!=0){
        parts.add(new IT_Part(part,it_inspect));
    }
    else{
        cout << "Cannot add a part with both fh_inspect and it_inspect = 0";
    }
}

void Airline::takeFlight(const string& reg, int hours){ //Adds the given flight hours to the aircraft matching the given registration
    Aircraft* tempCraft;
    getAircraft(reg, &tempCraft);
    if(tempCraft != NULL){
        tempCraft->takeFlight(hours);
    }
    else{
        cout << "Aircraft with registration: " << reg <<" does not exist!" << endl;
    }
}

void Airline::printAircraft() const{
    for(int i=0; i<aircraft.getSize(); i++){
        cout << (*aircraft[i]); //Printing each aircraft out manually, because using the "<<" operator on an Array<Aircraft*> would print memory locaions.
        cout << endl;
    }
}

void Airline::printParts() const {
    for(int i=0; i<parts.getSize(); i++){
        cout << (*parts[i]); //Printing each part out manually, because using the "<<" operator on an Array<Part*> would print memory locaions.
        cout << endl;
    }
}

void Airline::print() const{
    cout << "Airline Name: " << name << endl;
    cout << "Associated Aircraft:" << endl;
    printAircraft();
    cout << "Associated Parts:" << endl;
    printParts();
}

void Airline::inspectionReport(const string& reg, const Date& date){ //Using the given registration and date, this functions finds the related aircraft and prints all it's parts that need inspection.
    Aircraft* tempCraft;
    Array<Part*> inspectionParts;
    getAircraft(reg, &tempCraft);
    if(tempCraft != NULL){
        tempCraft->inspectionReport(date, inspectionParts);
        cout << "Aircraft Registration: " << reg << endl;
        cout << "Current Date: " << date;
        cout << "Parts that need Inspection: " << endl;
        for(int i=0; i<inspectionParts.getSize(); i++){
            cout << (*inspectionParts[i]);
            cout << endl;
        }
        cout << endl;
    }
    else{
        cout << "Aircraft with registration: " << reg <<" does not exist!" << endl;
    }
}

bool Airline::install(const string& aircraftReg, const string& partName, const Date& date){ //Uses the given aircraftReg and partName to attempt to install a part into the specified aircraft.
    Aircraft* tempCraft=NULL;
    Part* tempPart=NULL;
    getAircraft(aircraftReg, &tempCraft);
    getPart(partName,&tempPart);
    if(tempCraft !=NULL && tempPart !=NULL){
        tempCraft->install(tempPart,date);
        return true;
    }
    else{
        cout << "Either the aircraft with given registration or a part with the given name does not exist!" << endl;
        return false;
    }
}
