#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "PodArray.h"
#include "Network.h"
#include <string>

using namespace std;

class Client {
    public:
        //Constructors
        Client(const string& name);
        ~Client();

        //Other
        bool download(Network* network, const string& podcast); //Searches through the "network" to find the given "podcast" input, if found create a copy and add to the local podcasts array.
        bool stream(Network* network, const string& podcast, int episode); //Searches through the "network" to find the given "podcast" and "episode" input, if found it "plays" the episode.
        bool playLocal(const string& podcast, int episode); // Searches through the local podcast array for the given "podcast" and "episode" input, if found it "plays" the episode.
        void print(); //Prints member variables
        


    private:
        //Members
        PodArray* podcasts;
        string name;

};

#endif