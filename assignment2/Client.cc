#include "Client.h"

//Constructor / Destructor
Client::Client(const string& name) : name(name), podcasts(new PodArray()){}

Client::~Client(){
    delete podcasts;
}

//Other

bool Client::download(Network* network, const string& podcast){ //Searches through the "network" to find the given "podcast" input, if found create a copy and add to the local podcasts array.
    Podcast* tempPod;
    if(network->download(name,podcast,&tempPod)){ //Attempting to download the podcast with the given "podcast" string input.
        podcasts->addPodcast(new Podcast(*tempPod)); //Creating a copy of the podcast and adding it to the "podcasts" array.
        return true;
    }
    else{
        cout << "Download Failed! Unable to obtain podcast!" << endl;
        return false;
    }
}

bool Client::stream(Network* network, const string& podcast, int episode){ //Searches through the "network" to find the given "podcast" and "episode" input, if found it "plays" the episode.
    Episode* tempEp;
    if(network->stream(name,podcast,episode,&tempEp)){ //Attempting to find the episode within the network
        tempEp->play();
        return true;
    }
    else{
        return false;
    }
}

bool Client::playLocal(const string& podcast, int episode){ // Searches through the local podcast array for the given "podcast" and "episode" input, if found it "plays" the episode.
    Podcast* tempPod;
    Episode* tempEp;
    if(podcasts->getPodcast(podcast,&tempPod)){ //Attempting to find the podcast within the local podcast array.
        if(tempPod->getEpisode(episode,&tempEp)){ //Attempting to find the episode within the podcast
            tempEp->play();
            return true;
        }
        else{
            cout << "Episode Does not Exist!" << endl;
            return false;
        }
    }
    else{
        cout << "Podcast And Episode does not exist!" << endl;
        return false;
    }
}

void Client::print(){
    cout << "~Client~" << endl;
    cout << "Name: " << name << endl;
    cout << "Podcasts: " << endl;
    podcasts->print();
}