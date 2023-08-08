#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include "Episode.h"
#include "defs.h"
#include <string>

using namespace std;

class Podcast { //Stores podcast information (Title of podcast, host of podcast, episodes of the podcast, number of episodes) and provides basic functions (Getters, lessThan, print and functionality for adding and getting episodes)
    public:
        //Constructors / Destructor
        Podcast(const string& title, const string& host);
        Podcast(const Podcast&);
        ~Podcast();

        //Getters
        const string& getTitle();
        const string& getHost();
        int getNumEpisodes();
        

        //Other Functions
        bool addEpisode(const string& title,const string& content); //For adding a new episode with the input "title" and "content" to the local Dynamic Array of episode pointers (episodes)
        bool getEpisode(int index, Episode** ep); //For finding the episode with the input "index" or episode number. If the episode is found it is stored within the "ep" double pointer.
        bool lessThan(Podcast& pod); //Returns true if the local title is alphabetically lower than the input podcast title
        void print(); // Prints member variables
        


    private:
        //Members
        string title;
        string host;
        Episode** episodes;
        int numEps;

        
};

#endif