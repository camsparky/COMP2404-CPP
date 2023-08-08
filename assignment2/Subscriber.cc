#include "Subscriber.h"

//Constructors
Subscriber::Subscriber(string name, string creditcard){
    this->name = name;
    this->creditcard = creditcard;
}

//Other
bool Subscriber::matches(const string& name){
    return (this->name.compare(name) == 0) ? true : false; //Returning true if the local "name" matches the input "name", false otherwise.
}

void Subscriber::print(){
    cout << "Subscriber-> Name: " << name << " Credit card number: " << creditcard << endl;
}