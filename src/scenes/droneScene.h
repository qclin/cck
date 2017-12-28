
#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGif.h"

#include "qLyric.h"
#include "qVideo.h"
#include "qSound.h"


class droneScene : public baseScene {
  
public:
    
     void setup();
     void update();
     void draw();
    
//    void start();
     void rainingPills(float timeElapsed);
     void runningManPerspective(float timeElapsed);
        
    
    // ----- raining pills in perspective with man running forth
    
    ofDirectory pillsDir;
    vector <ofxGIF::fiGifLoader> pillLoader;
    vector <int> pillIndexes;
    
//    float startTime;
//    int startTimeMillis; 
//    float duration;
//    int durationMillis;
    
    int w;
    int h; 
    int gundamIndex;
    ofxGIF::fiGifLoader gundamGif;
    
    
//    qVideo myVideo;
//    qLyric myLyric;
 
    
    
};
