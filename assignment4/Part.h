#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Part {
    friend ostream& operator<<(ostream&, const Part&); //overloading the << operator

	public:
        //Constructor
        Part(const string& name); // Initializes the local name variable using "name", as well as the other variables.
        virtual ~Part(); // Have no use for a destructor however the base destructor must be virtual so that all destructors are called.

        //Getters / Setters
        const string& getName() const;

        //other
        void addFlightHours(int hours); // Adds the "hours" variable to the "flightHours" variable
        void install(const Date& date); //Replaces the installationDate with the new date

        //Virtual functions
        virtual bool inspection(const Date& date) const =0;
	
	protected:
        virtual void print(ostream& ost) const; //Enabling dynamic binding for the << operator
        string name;
        Date installationDate;
        int flightHours;

};

class FH_Part : virtual public Part{
    public:
        FH_Part(const string& name, int hours); // Initializes the local name variable using "name" and fh_inspect using "hours".
        virtual ~FH_Part(); 
        virtual bool inspection(const Date& date) const; // Returns true if flightHours >= fh_inspect, false otherwise.
    
    protected:
        virtual void print(ostream& ost) const;
        int fh_inspect;

};

class IT_Part : virtual public Part{
    public:
        IT_Part(const string& name, int days); // Initializes the local name variable using "name" and fh_inspect using "days".
        virtual ~IT_Part();
        virtual bool inspection(const Date& date) const; // Returns true if the number of days between the installation and inspection is >= it_inspect, false otherwise.

    protected:
        virtual void print(ostream& ost) const;
        int it_inspect;
};

class FHIT_Part : public FH_Part, public IT_Part{
    public:
        FHIT_Part(const string& name, int hours, int days); // Initializes the local name variable using "name", fh_inspect using "hours" and fh_inspect using "days".
        virtual bool inspection(const Date& date) const;
    protected:
        virtual void print(ostream& ost) const;
};
#endif