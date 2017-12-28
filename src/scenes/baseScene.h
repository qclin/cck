
#pragma once

#include "ofMain.h"
#include "qVideo.h"
#include "qSound.h"
#include "qLyric.h"

#include "ofMain.h"

class baseScene {
  
public:
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
    virtual void start() {
        startTime = ofGetElapsedTimef();
        startTimeMillis  = ofGetElapsedTimeMillis();
        mySound.track.play();
        myVideo.videoClip.play();
        myLyric.currentLyric = 0;
        myLyric.accumSize = 0;
//        myLyric.setOfStrings;
//        myLyric.txtFileStrs;
        duration = 0;
        durationMillis = 0;
    }
    
    virtual void stop(){
        mySound.track.stop();
        myVideo.videoClip.stop();
        
    }
    qSound mySound;
    qVideo myVideo;
    qLyric myLyric;
    float startTime;
    int startTimeMillis;
    float duration;
    int durationMillis;
};
