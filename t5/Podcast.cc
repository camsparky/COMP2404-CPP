#include "Podcast.h"

//Constructors
Podcast::Podcast(const string& title, const string& host) : title(title), host(host), numEps(0), episodes(new Episode*[MAX_EPS]){}

Podcast::Podcast(const Podcast& podcast) : title(podcast.title), host(podcast.host){
    numEps=0;
    episodes = new Episode*[MAX_EPS];
    for(int i=0; i<podcast.numEps; i++){
        addEpisode(podcast.episodes[i]->getName(),podcast.episodes[i]->getContent());
    }
}

Podcast::~Podcast(){
    for(int i=0; i< numEps; i++){
        delete episodes[i];
    }
    delete[] episodes;
}

//Getters
const string& Podcast::getTitle(){
    return title;
}
const string& Podcast::getHost(){
    return host;
}
int Podcast::getNumEpisodes(){
    return numEps;
}


//Other Functions
bool Podcast::addEpisode(const string& title,const string& content){
    if (numEps >= MAX_EPS) return false; //Returning false if the students array is full

    episodes[numEps] = new Episode(this->title, numEps, title, content);
    numEps++;
    return true;
}

bool Podcast::getEpisode(int index, Episode** ep){
    if((numEps-1) >= index){
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
