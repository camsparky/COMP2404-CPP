#include "Episode.h"

//Constructors
Episode::Episode(const string& podcast, int number, const string& name, const string& content){
    this->podcast = podcast;
    this->number = number;
    this->name = name;
    this->content = content;
}

const string& Episode::getContent(){return content;}
const string& Episode::getName(){return name;}


//Other
void Episode::play(){ // Prints out the episode's member variables in this order: podcast->name->number->content
    cout << "You are listening to: " << podcast << " | Episode name: " << name << " | Episode number: " << number << " | Content: " << content << endl;
}

void Episode::print(){
    cout << "Episode-> Podcast: " << podcast << " Number: " << number << " Name: " << name << " Content: " << content << endl;
}

