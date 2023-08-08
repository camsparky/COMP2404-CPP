#include "Student.h"

//Constructors
Student::Student(){
    this->name = "N/A"; //Chose N/A as default values for name and number
    this->number = "N/A";
}

Student::Student(string name, string number){
    this->name = name;
    this->number = number;
}

Student::Student(Student& s){
	this->name = s.name;
    this->number = s.number;
}

//Getters
string Student::getName(){return this->name;}
string Student::getNumber(){return this->number;}

//Setters
void Student::setName(string name) {this->name = name;}
void Student::setNumber(string number){this->number = number;}

//Other
bool Student::lessThan(Student& s){ //Returns true if the local students number comes before the input students number alphabetically, returns false otherwise.
    string baseStringLower =""; //Making a lowercase copy of both the base number string and input number string and then comparing them.
    string inputStringLower = ""; //Have to lower both number strings due to the compare function working via ASCII value and not Alphabetically.
    for(int i=0; i<s.number.size() ; i++){ //Lowering input string
        inputStringLower += tolower(s.number[i]);
    }
    for(int i=0; i<this->number.size(); i++){//Lowering base string
        baseStringLower += tolower(this->number[i]);
    }
    if(baseStringLower.compare(inputStringLower)<0){ //Finally comparing both the base and input number strings.
        return true;
    }
    else{
        return false;
    }
}

void Student::print(){
    cout << "Student-> Name: " << name << " Number: " << number << endl;
}