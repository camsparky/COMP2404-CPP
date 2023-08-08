#ifndef STORELOCATION_H
#define STORELOCATION_H

#include <iostream>
#include <string>
#include "Location.h"
#include "defs.h"

using namespace std;

class StoreLocation : virtual public Location {
    public:
        //Constructors
        StoreLocation(); // Calls on the Location constructor and passes in code and nextId as arguments, also increments nextId by one.

        //Getters
        virtual int getCapacity() const;

        //Other
        void setProduct(const string& productName); //Sets the inherited product variable to the input productName
        int getFreeSpace() const; // Returns the difference between capacity and quantity
        virtual bool add(const string& productName, const int amount); // If possible it adds the input amount to the total number of products
        virtual bool remove(const int amount); //If possible it removes the input amount from the total number of products
        void print() const; //Prints inherited member variables



    private:
        //Members
        static const char code;
        static const int capacity;
        static int nextId;  

};

#endif