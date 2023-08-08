#include <string>
#include <iostream>
#define MAX_ARR 200
using namespace std;

class Song{
    public:
        Song(const string& t, const string& a) : title(t), artist(a){}
        const string& getTitle(){return title;}
        const string& getArtist(){return artist;}
        void play(){
            cout << "Artist: " << artist << " Title: " << title << endl;
        };
    private:
        string title;
        string artist;
};

class MusicPlay{
    public:
        MusicPlay(const string& subscriber);
        MusicPlay(const MusicPlay&);
        ~MusicPlay();

        void removeSong(const string& title, Song**);

        void getSong(const string& title, Song**) const;

        void playAllSongsBy(const string& artist) const;
    private:
        string subscriber;
        Song** songs;
        int numSongs;
};