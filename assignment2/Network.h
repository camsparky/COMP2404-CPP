#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include "PodArray.h"
#include "Subscriber.h"
#include "defs.h"
#include <string>

using namespace std;

class Network {
    public:
        //Constructors
        Network(const string& name);
        ~Network();


        //Getters
        bool getPodcast(const string& podcastName, Podcast** podcastOut); //For getting the podcast with the given podcastName and storing it within podcastOut output parameter.

        //Add and Remove
        bool addPodcast(const string& podcast, const string& host); //For adding a new podcast to the local "podcasts" array with the input podcast name and host
        bool removePodcast(const string& podcast); //For removing a podcast from the local "podcasts array" based on the input podcast name (DOES NOT RETURN IT THROUGH OUTPUT PARAMETERS)
        bool addEpisode(const string& podcast, const string& title, const string& content); //For adding a new episode to a particular podcast found within the "podcasts" array based on the input podcast name. Uses the "title" and "content" variables to populate the new episode.
        bool addSubscriber(const string& name, const string& creditcard); //For adding a new subscriber to the "subscribers" array based on the input "name" and "creditcard" strings.

        //Client Services
        bool download(const string& subscriber, const string& podcastName, Podcast** podcastOut); //Checks if both the input Subscriber and Podcast exist within their respective arrays and then returns the Podcast via the "podcastOut" output paramteter.
        bool stream(const string& subscriber, const string& podcast, int episode, Episode** ep); //Checks if the subscriber, podcast and episode # exists and then returns the Episode via the "ep" output parameter.
        bool hasSubscriber(const string& name); //Checks if the subscriber exists within the "subscribers" array.
        void print(); // Prints member variables.
        


    private:
        //Members
        int numSubs;
        string name;
        PodArray* podcasts;
        Subscriber* subscribers[MAX_SUBS];
};

#endif