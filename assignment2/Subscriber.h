#ifndef SUBSCRIBER_H 
#define SUBSCRIBER_H

#include <iostream>
#include <string>

using namespace std;

class Subscriber { // Stores subscriber related information (name and credit card #) and provides basic functions (print and matches)
    public:
        //Constructor
        Subscriber(string name, string creditcard); // Using "string" instead of "const string&" due to the specification explicitly mentioning the first.

        //Other Functions
        bool matches(const string& name); // Returns true if the input string is exactly the same as the local name variable.
        void print(); // Prints member variables


    private:
        //Members
        string name;
        string creditcard;
};

#endif