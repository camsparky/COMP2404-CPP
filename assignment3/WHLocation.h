#ifndef WHLOCATION_H
#define WHLOCATION_H

#include <iostream>
#include <string>
#include "Location.h"
#include "defs.h"

using namespace std;

class WHLocation : virtual public Location {
    public:
        //Constructors
        WHLocation(); // Calls on the Location constructor and passes in code and nextId as arguments, also increments nextId by one.

        //Getters
        virtual int getCapacity() const;

        //Other
        virtual bool add(const string& productName, const int amount);  // If the product is currently empty and the amount to add is less than or equal to the capacity, add it to the quantity.
        virtual bool remove(const int amount); //If possible it removes the input amount from the total number of products
        void print() const; //Prints inherited member variables along with it's class variables



    private:
        //Members
        static const char code;
        static const int capacity;
        static int nextId;  

};

#endif