#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include "Episode.h"
#include "defs.h"
#include <string>

using namespace std;

class Podcast {
    public:
        //Constructors
        Podcast(const string& title, const string& host);
        Podcast(const Podcast&);
        ~Podcast();

        //Getters
        const string& getTitle();
        const string& getHost();
        int getNumEpisodes();
        

        //Other Functions
        bool addEpisode(const string& title,const string& content);
        bool getEpisode(int index, Episode** ep);
        bool lessThan(Podcast& pod);
        void print();
        


    private:
        //Members
        string title;
        string host;
        Episode** episodes;
        int numEps;

        
};

#endif