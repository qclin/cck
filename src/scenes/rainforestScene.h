//
//  rainforestScene.hpp
//  consonantKaroake
//
//  Created by Qiao Lin on 11/12/17.
//

#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGif.h"

#include "qLyric.h"
#include "qVideo.h"
#include "qSound.h"


class rainforestScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    void bloomingAnimation(float duration);
    void monkeyHair(float duration); 
    
    int w;
    int h;
    
    ofDirectory flowerDir;
    vector <ofxGIF::fiGifLoader> flowerLoader;
    vector <int> flowerIndexes;
    
    
    /// beautiful pineapple
    int monkeyIndex;
    ofxGIF::fiGifLoader monkeyGif;
    
    int manIndex;
    ofxGIF::fiGifLoader manGif;
    
};

