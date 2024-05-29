#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PlayList;

class Song {
private:
    int id;    
    string title;  
    string artist;
    string album;
    string mv_url;
    vector<PlayList*> playlists;
    static int id_counter;  

public:
    Song();
    Song(string ti, string ar, string al, string mv);
    ~Song();

    int get_id();
    string get_title();
    string get_artist();
    string get_album();
    string get_url();

    void print(ostream& out);

    void register_playlist(PlayList* ptr_plist);
    void unregister_playlist(string plist_name);
    void play();
};
