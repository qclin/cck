
#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGif.h"
#include "particle.h"


#include "qLyric.h"
#include "qVideo.h"
#include "qSound.h"

class oceanScene : public baseScene {
  
public:
    
    void setup();
    void update();
    void updateParticles(float duration);
    void draw();
//    void start();
    
    void drawGhostingAnimation(float duration);
    void beautifulPinaepple(float duration);
    int w;
    int h;
    
    /// GHOSTING animation
    int wowFighterIndex;
    ofxGIF::fiGifLoader wowFighterGif;
    
    int unicornIndex;
    ofxGIF::fiGifLoader unicornGif;
    
    
    /// beautiful pineapple
    int flipPhoneIndex;
    ofxGIF::fiGifLoader flipPhoneGif;
    
    int sphereIndex;
    ofxGIF::fiGifLoader sphereGif;
    
    int time;
//    qVideo myVideo;
//    qLyric myLyric;
    
    
//    
//    float startTime;
//    int startTimeMillis;
//    float duration;
//    int durationMillis;
    
    particle dude;
    vector <particle> dude_catchers;

};
