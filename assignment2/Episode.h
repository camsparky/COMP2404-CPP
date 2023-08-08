#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode { // Stores episode related information (name of episode, content, name of podcast and episode number) and provides basic functions (getters, print and play)
    public:
        //Constructor
        Episode(const string& podcast, int number, const string& name, const string& content);

        //Getters
        const string& getName();
        const string& getContent();
        

        //Other Functions
        void play(); // Prints out the episode's member variables in this order: podcast->name->number->content
        void print(); //Prints member variables
        


    private:
        //Members
        string name;
        string content;
        string podcast;
        int number;
};

#endif