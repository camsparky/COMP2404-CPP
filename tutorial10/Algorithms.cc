#include "Algorithms.h"

Algorithms::Algorithms(){}
Algorithms::~Algorithms(){}

void Algorithms::addStudent(const string& number, const string& name, float gpa){
    Student temp(number,name,gpa);
    students.push_back(temp);
}

void Algorithms::getPassingStudents(vector<Student>& v){
    for(int i=0; i<students.size(); i++){
        if(students[i].gpa >= 6.0){
            v.push_back(students[i]);
        }
    }
}

void Algorithms::sortByNumber(vector<Student>& v){
    for(int i=0; i<students.size(); i++){
        bool flag = false;
        vector<Student>::iterator temp = v.begin();
        for(int x=0; x<v.size(); x++){
            if(students[i].number<v[x].number){
                v.insert(temp, students[i]);
                flag=true;
                break;
            }
            temp++;
        }
        if(flag==false){
            v.push_back(students[i]);
        }
    }
}

void Algorithms::sortByName(vector<Student>& v){
    for(int i=0; i<students.size(); i++){
        bool flag = false;
        vector<Student>::iterator temp = v.begin();
        for(int x=0; x<v.size(); x++){
            if(students[i].name<v[x].name){
                v.insert(temp, students[i]);
                flag=true;
                break;
            }
            temp++;
        }
        if(flag==false){
            v.push_back(students[i]);
        }
    }
}

bool Algorithms::highestGpa(vector<Student>::iterator& stuIt){
    if(students.empty()){return false;}

    vector<Student>::iterator max = students.begin();
    vector<Student>::iterator current = students.begin();
    current++;
    float maxGpa = students[0].gpa;
    for(int i=1; i<students.size(); i++){
        if(students[i].gpa > maxGpa){
            max = current;
            maxGpa = students[i].gpa;
        }
        current++;
    }
    stuIt = max;
    return true;
}

bool Algorithms::findStudent(const string& name, vector<Student>::iterator& stuIt){
    vector<Student>::iterator current = students.begin();
    for(int i=0; i<students.size(); i++){
        if(students[i].name==name){
            stuIt = current;
            return true;
        }
        current++;
    }
    return false;
}