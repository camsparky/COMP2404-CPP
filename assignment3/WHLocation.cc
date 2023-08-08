#include <iostream>
#include <string>
#include "WHLocation.h"

const char WHLocation::code = 'B'; // Setting class variables
const int WHLocation::capacity = WHLOC_CAPACITY;
int WHLocation::nextId = 1;

WHLocation::WHLocation() : Location(code,nextId) {nextId++;} // Calls on the Location constructor and passes in code and nextId as arguments, also increments nextId by one.

int WHLocation::getCapacity() const {return capacity;}

bool WHLocation::add(const string& productName, const int amount){ // If the product is currently empty and the amount to add is less than or equal to the capacity, add it to the quantity.
    if(Location::isAvailable() && amount <= capacity){ //Checking if the Product is empty and if the input amount is less than or equal to the capacity
        product = productName;
        quantity=amount;
        return true;
    }
    else{
        return false;
    }
}

bool WHLocation::remove(const int amount){ //If possible it removes the input amount from the total number of products
    if((quantity-amount) < 0){return false;}
    else if((quantity-amount)==0){product=NONE;} //Setting product to empty if the quantity is now 0

    quantity-=amount;
    return true;
}

void WHLocation::print() const { //Prints inherited member variables
    Location::print();
}