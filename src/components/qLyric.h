//
//  qLyric.hpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#ifndef qLyric_h
#define qLyric_h

#include <stdio.h>
#include <fstream>
#include "ofMain.h"
#include "abzHelper.h"

class qLyric: public ofBaseApp{
    public:
        void setup(string path);
        void update();
        void draw(int startHeight, float bpm, float startTime);

        void keyPressed(int key);
        void loadSong();
    int w;
    int h;
    
    vector <string> setOfStrings;
    vector <string> txtFileStrs;
    ofTrueTypeFont myFont;
    
    
    // ~~~~ FONT FUN
    abzHelper ABZ;
    vector < ofPolyline > lines;
    ofEasyCam cam;
    
    size_t currentLyric = 0;
    size_t accumSize = 0;
    
    int currentIndex;
    ofDirectory dir;
    
    vector <string> lyricPaths;
};


#endif /* qLyric_h */
