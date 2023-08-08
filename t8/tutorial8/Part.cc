#include "Part.h"

//Part Implementation////////////////////////////////////////////////////////////////////
//Constructor
Part::Part(const string& name) : name(name), flightHours(0), installationDate(){} 
Part::~Part(){} // Have no use for a destructor however the base destructor must be virtual so that all destructors are called.

//Getters / Setters
const string& Part::getName() const{return name;}

//Other
void Part::addFlightHours(int hours){flightHours+=hours;}
void Part::install(const Date& date){installationDate = date;}
void Part::print(ostream& ost) const{
    ost << "Part:" << endl;
    ost << "name: " << name << " flightHours: " << flightHours << " installationDate: " << installationDate << endl;
}
ostream& operator<<(ostream& ost, const Part& p){
    p.print(ost);
    return ost;
}
//////////////////////////////////////////////////////////////////////////////////////////

//FH_Part Implementation//////////////////////////////////////////////////////////////////
//Constructor
FH_Part::FH_Part(const string& name, int hours): Part(name), fh_inspect(hours){}
FH_Part::~FH_Part(){}

//Other
bool FH_Part::inspection(const Date& date) const{return flightHours>=fh_inspect;}
void FH_Part::print(ostream& ost) const{
    Part::print(ost);
    ost << "FH_Part:"<<endl;
    ost << " fh_inspect: " << fh_inspect<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////

//IT_Part Implementation//////////////////////////////////////////////////////////////////
//Constructor
IT_Part::IT_Part(const string& name, int days): Part(name), it_inspect(days){}
IT_Part::~IT_Part(){}

//Other
bool IT_Part::inspection(const Date& date) const{ // Returns true if the number of days between the installation and inspection is >= it_inspect, false otherwise.
    return (date.toDays() - installationDate.toDays())>=it_inspect;
}
void IT_Part::print(ostream& ost) const{ 
    Part::print(ost);
    ost << "IT_Part:"<<endl;
    ost << " it_inspect: " << it_inspect<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////

//FHIT_Part Implementation//////////////////////////////////////////////////////////////////
//Constructor
FHIT_Part::FHIT_Part(const string& name, int hours, int days): FH_Part(name,hours), IT_Part(name, days), Part(name){}

//Other
bool FHIT_Part::inspection(const Date& date) const{
    return (FH_Part::inspection(date) || IT_Part::inspection(date));
}
void FHIT_Part::print(ostream& ost) const{
    Part::print(ost);
    ost << "FH_Part:"<<endl;
    ost << " fh_inspect: " << fh_inspect<<endl;
    ost << "IT_Part:"<<endl;
    ost << " it_inspect: " << it_inspect<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////

