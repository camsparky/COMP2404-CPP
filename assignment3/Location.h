#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

using namespace std;

class Location {
    public:
        //Constructors
        Location(char charCode, int num); // Takes a character code and a number and concatenates them into the "id" member variable.

        //Getters
        const string& getId() const;
        const string& getProduct() const ;
        int getQuantity() const;

        //Other
        bool isEmpty() const; // Returns true if the quantity member is 0, false otherwise
        bool isAvailable() const; // Returns true if the product member is equal to the NONE member, false otherwise.
        void print() const ; // Prints member variables, NONE is a class variable so it is not printed.

        //Pure Virtual Functions
        virtual int getCapacity() const =0;
        virtual bool add(const string& productName, const int quantity)=0;
        virtual bool remove(const int quantity)=0;

    protected:
        //Members
        string id;
        string product;
        int quantity;
        static const string NONE;

};

#endif