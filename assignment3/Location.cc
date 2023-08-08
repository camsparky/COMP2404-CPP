#include <iostream>
#include <string>
#include "Location.h"

const string Location::NONE = "Empty"; 

Location::Location(char charCode, int num) : product(NONE), quantity(0){ // Takes a character code and a number and concatenates them into the "id" member variable.
    id = (charCode + to_string(num));
}

const string& Location::getId() const {return id;}
const string& Location::getProduct() const{return product;}
int Location::getQuantity() const{return quantity;}

bool Location::isEmpty() const{ return quantity==0 ? true : false; } // Returns true if the quantity member is 0, false otherwise
bool Location::isAvailable() const{return product==NONE ? true : false;} // Returns true if the product member is equal to the NONE member, false otherwise.

void Location::print() const{ // Prints member variables, NONE is a class variable so it is not printed.
    cout << "Location:" << endl;
    cout << "Id--> " << id << " Product--> " << product << " Quantity--> " << quantity << endl;
}

