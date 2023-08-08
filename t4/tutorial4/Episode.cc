#include "Episode.h"

//Constructors
Episode::Episode(){
    this->podcast = "N/A";
    this->number= 0;
    this->name = "N/A";
    this->content= "N/A";
}

Episode::Episode(const string& podcast, int number, const string& name, const string& content){
    this->podcast = podcast;
    this->number = number;
    this->name = name;
    this->content = content;
}


//Other
void Episode::play(){
    cout << "You are listening to: " << podcast << " | Episode name: " << name << " | Episode number: " << number << " | Content: " << content << endl;
}

void Episode::print(){
    cout << "Episode-> Podcast: " << podcast << " Number: " << number << " Name: " << name << " Content: " << content << endl;
}

