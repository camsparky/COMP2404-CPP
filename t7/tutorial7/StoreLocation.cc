#include <iostream>
#include <string>
#include "StoreLocation.h"

const char StoreLocation::code = 'A'; // Setting class variables
const int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 1;

StoreLocation::StoreLocation() : Location(code,nextId) {nextId++;} // Calls on the Location constructor and passes in code and nextId as arguments, also increments nextId by one.

void StoreLocation::setProduct(const string& productName){product=productName;} //Sets the inherited product variable to the input productName

int StoreLocation::getFreeSpace() const {return (capacity-quantity);} // Returns the difference between capacity and quantity

int StoreLocation::getCapacity() const {return capacity;}

bool StoreLocation::add(const string& productName, const int amount){ // If possible it adds the input amount to the total number of products
    if(Location::isAvailable() && amount <= capacity){ //Checking if the Product is empty and if the input amount is less than the capacity
        product = productName;
        quantity+=amount;
        return true;
    }
    else if(productName != product || (amount + quantity)>capacity){return false;} //Checking if the input productName does not match the store's product or if the input amount is greater than the capacity
    else{
        quantity+=amount;
        return true;
    }
}

bool StoreLocation::remove(const int amount){ //If possible it removes the input amount from the total number of products
    if((quantity-amount) < 0){return false;}

    quantity-=amount;
    return true;
}

void StoreLocation::print() const { //Prints inherited member variables along with it's class variables
    Location::print();
    cout<< "StoreLocation:" << endl;
    cout<< "Code--> " << code << " Capacity--> " << capacity << " NextId--> " << nextId << endl;
}