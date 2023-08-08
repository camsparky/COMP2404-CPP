#include "Network.h"

//Constructor / Destructor
Network::Network(const string& name) : name(name), numSubs(0), podcasts(new PodArray()) {}

Network::~Network(){
    delete podcasts; //Deleting all of the allocated podcasts that were stored within "podcasts"
    for(int i=0; i<numSubs; i++){ //Deleting each allocated subscriber
        delete subscribers[i];
    }
}

//Getters
bool Network::getPodcast(const string& podcastName, Podcast** podcastOut){ return podcasts->getPodcast(podcastName,podcastOut); } //For getting the podcast with the given podcastName and storing it within podcastOut output parameter.

//Add and Remove
bool Network::addPodcast(const string& podcast, const string& host){ //For adding a new podcast to the local "podcasts" array with the input podcast name and host
    Podcast* newPod = new Podcast(podcast,host);
    return podcasts->addPodcast(newPod);
}

bool Network::removePodcast(const string& podcast){ //For removing a podcast from the local "podcasts array" based on the input podcast name (DOES NOT RETURN IT THROUGH OUTPUT PARAMETERS)
    Podcast* removePod;
    if(podcasts->removePodcast(podcast,&removePod)){
        delete removePod; //Making sure to delete the memory related to the removed podcast
        return true;
    }
    else{
        return false;
    }
}

bool Network::addEpisode(const string& podcast, const string& title, const string& content){ //For adding a new episode to a particular podcast found within the "podcasts" array based on the input podcast name. Uses the "title" and "content" variables to populate the new episode.
    Podcast* tempPod;
    if(getPodcast(podcast,&tempPod)){ //Making sure the podcast exists before adding the episode
        tempPod->addEpisode(title,content);
        return true;
    }
    else{
        return false;
    }
}

bool Network::addSubscriber(const string& name, const string& creditcard){ //For adding a new subscriber to the "subscribers" array based on the input "name" and "creditcard" strings.
    if(numSubs >= MAX_SUBS) return false;

    subscribers[numSubs] = new Subscriber(name,creditcard);
    numSubs++;
    return true;

}

bool Network::hasSubscriber(const string& name){ //Checks if the subscriber exists within the "subscribers" array.
    for(int i=0; i<numSubs; i++){
        if(subscribers[i]->matches(name)){
            return true;
        }
    }
    return false;
}

bool Network::download(const string& subscriber, const string& podcastName, Podcast** podcastOut){ //Checks if both the input Subscriber and Podcast exist within their respective arrays and then returns the Podcast via the "podcastOut" output paramteter.
    Podcast* tempPod;
    bool podExists=getPodcast(podcastName,&tempPod), subExists=hasSubscriber(subscriber);
    if(subExists && podExists){ //Making sure both the subscriber and podcast exist before grabbing the podcast.
        *podcastOut = tempPod;
        return true;
    }
    else{
        if(subExists == false){ //Printing out each case where either the subscriber was not found, or the podcast was not found, or both.
            cout << "No Such Subscriber" << endl;
        }
        if(podExists == false){
            cout << "No such Podcast" << endl;
        }
        return false;
    }
}

bool Network::stream(const string& subscriber, const string& podcast, int episode, Episode** ep){ //Checks if the subscriber, podcast and episode # exists and then returns the Episode via the "ep" output parameter.
    Podcast* tempPod;
    Episode* tempEp;
    bool podExists=getPodcast(podcast,&tempPod), subExists=hasSubscriber(subscriber), epExists=false;

    if(podExists){ //Checking if each of the input parameters can be found within the proper local members
        epExists = tempPod->getEpisode(episode,&tempEp);
        if(epExists && subExists){
            *ep = tempEp;
            return true;
        }
    }
    if(subExists == false){ //Printing out each case where the input parameters were NOT found within the proper local members
        cout << "No Such Subscriber Exists" << endl;
    }
    if(podExists == false){
        cout << "No such Podcast Exists" << endl;
    }
    else{
        if(epExists ==false){
            cout << "No such Episode Exists" << endl;
        }
    }
    return false;
}

void Network::print(){
    cout << "~Network~" << endl;
    cout << "Name: " << name << endl;
    cout << "Subscribers: " << endl;
    for(int i=0; i<numSubs; i++){
        subscribers[i]->print();
    }
    cout << "Podcasts: " << endl;
    podcasts->print();
}