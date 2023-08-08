#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student { //Stores student related information (Name and student number) and provides basic functions (print and lessThan).
    public:
        //Constructors
        Student();
        Student(string name, string number);
        Student(Student&);

        //Getters
        string getName();
        string getNumber();

        //Setters
        void setName(string name);
        void setNumber(string number);

        //Other Functions
        bool lessThan(Student& s); //Returns true if the local students number comes before the input students number alphabetically, returns false otherwise.
        void print(); //Prints member variables


    private:
        //Members
        string name;
        string number;
};


#endif