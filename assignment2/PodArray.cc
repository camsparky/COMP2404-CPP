
#include "PodArray.h"

PodArray::PodArray(){
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

PodArray::PodArray(PodArray& pa){
	podcasts = new Podcast*[MAX_PODS];
	for (int i =0 ; i < pa.numPods; ++i){
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}
	numPods = pa.numPods;

}


PodArray::~PodArray(){
	for(int i=0; i< numPods; i++){ //First deleting every allocated podcast within "podcasts"
        delete podcasts[i];
    }
    delete[] podcasts; //Deleting the allocated "podcasts" array
}

bool PodArray::addPodcast(Podcast* p){
	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
}

bool PodArray::removePodcast(const string& title, Podcast** pod){ // For removing a podcast with the given input title. If the podcast is found it is stored within a Podcast double pointer and removed from the local "podcasts" array
	int index=-1; //Keeping track of which index the podcast was removed at. -1 is the value if nothing is removed.
	for(int i=0; i<numPods; i++){ //Finding the podcast to remove based on the input title
		if(podcasts[i]->getTitle() == title){
			*pod = podcasts[i];
			index = i;
		}
	}
	if(index != -1){ //Shifting each podcast down one array index starting from where the podcast was removed.
		for(int i=index;i<numPods;i++){
			podcasts[i] = podcasts[i+1];
		}
		numPods--;
		return true;
	}
	else{
		return false;
	}
}

bool PodArray::getPodcast(const string& title, Podcast** pod){ // For finding a podcast with the given input title. If the podcast is found it is stored within a Podcast double pointer.
	for(int i=0; i<numPods; i++){
		if(podcasts[i]->getTitle() == title){ //Finding the podcast to "get" based on the input title
			*pod = podcasts[i];
			return true;
		}
	}
	return false;
}

bool PodArray::isFull(){
	return numPods >= MAX_PODS;
}

int PodArray::size(){
	return numPods;
}

void PodArray::print(){
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
