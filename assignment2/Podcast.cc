#include "Podcast.h"

//Constructors
Podcast::Podcast(const string& title, const string& host) : title(title), host(host), numEps(0), episodes(new Episode*[MAX_EPS]){} // Assigning "episodes" a new array of Episode pointers, along with initializing every other member variable with "Member Initializer Syntax"

Podcast::Podcast(const Podcast& podcast) : title(podcast.title), host(podcast.host){
    numEps=0;
    episodes = new Episode*[MAX_EPS];
    for(int i=0; i<podcast.numEps; i++){ //Deep copying every episode found within the input podcast into the local podcast
        addEpisode(podcast.episodes[i]->getName(),podcast.episodes[i]->getContent()); //Instead of rewriting code might as well just add it through a local class function
    }
}

Podcast::~Podcast(){
    for(int i=0; i< numEps; i++){ //First deleting every allocated episode within "episodes"
        delete episodes[i];
    }
    delete[] episodes; //Deleting the allocated Episode pointer array
}

//Getters
const string& Podcast::getTitle(){return title;}
const string& Podcast::getHost(){return host;}
int Podcast::getNumEpisodes(){return numEps;}


//Other Functions
bool Podcast::addEpisode(const string& title,const string& content){ //For adding a new episode with the input "title" and "content" to the local Dynamic Array of episode pointers (episodes)
    if (numEps >= MAX_EPS) return false; //Returning false if the episodes array is full

    episodes[numEps] = new Episode(this->title, numEps, title, content);
    numEps++;
    return true;
}

bool Podcast::getEpisode(int index, Episode** ep){ //For finding the episode with the input "index" or episode number. If the episode is found it is stored within the "ep" double pointer.
    if((numEps-1) >= index && index >= 0){ //Making sure the input index is within the local arrays bounds
        *ep = episodes[index];
        return true;
    }
    else{
        return false;
    }
}
bool Podcast::lessThan(Podcast& pod){ //Reusing some of my lessThan code from assignment 1
    string baseStringLower =""; //Making a lowercase copy of both the base number string and input number string and then comparing them.
    string inputStringLower = ""; //Have to lower both number strings due to the compare function working via ASCII value and not Alphabetically.
    for(int i=0; i<pod.getTitle().size() ; i++){ //Lowering input string
        inputStringLower += tolower(pod.getTitle()[i]);
    }
    for(int i=0; i<title.size(); i++){//Lowering base string
        baseStringLower += tolower(title[i]);
    }
    if(baseStringLower.compare(inputStringLower)<0){ //Finally comparing both the base and input number strings.
        return true;
    }
    else{
        return false;
    }
}
void Podcast::print(){
    cout << "Poscast-> Title: " << title << " Host: " << host << " # of Episodes: " << numEps << endl << "~Episodes~" <<endl;
    for(int i=0; i<numEps; i++){
        episodes[i]->print();
    }

}
