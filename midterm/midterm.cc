#include "midterm.h"

MusicPlay::MusicPlay(const string& subscriber) : subscriber(subscriber), songs(new Song*[MAX_ARR]), numSongs(0){}
MusicPlay::MusicPlay(const MusicPlay& tempPlay) : subscriber(tempPlay.subscriber), numSongs(tempPlay.numSongs){
    songs = new Song*[MAX_ARR];
    for (int i =0 ; i < tempPlay.numSongs; ++i){
		songs[i] = new Song(*tempPlay.songs[i]);
	}
}

MusicPlay::~MusicPlay(){
    for(int i=0; i<numSongs; i++){
        delete songs[i];
    }
    delete[] songs;
}

void MusicPlay::removeSong(const string& title, Song** outputSong){
    int index=-1;
	for(int i=0; i<numSongs; i++){ 
		if(songs[i]->getTitle() == title){
			*outputSong = songs[i];
			index = i;
            break;
		}
	}
	if(index != -1){ 
		for(int i=index;i<numSongs;i++){
			songs[i] = songs[i+1];
		}
		numSongs--;
	}
    else{
        *outputSong = NULL;
    }
}

void MusicPlay::getSong(const string& title, Song** outputSong) const{
    *outputSong = NULL;
    for(int i=0; i<numSongs; i++){
        if(songs[i]->getTitle() == title){
            *outputSong = songs[i];
            break;
        }
    }
}

void MusicPlay::playAllSongsBy(const string& artist) const{
    for(int i=0; i<numSongs; i++){
        if(songs[i]->getArtist() == artist){
            songs[i]->play();
        }
    }
}