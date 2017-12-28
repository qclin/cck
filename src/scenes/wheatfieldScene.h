#pragma once

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGif.h"

#include "qLyric.h"
#include "qVideo.h"
#include "qSound.h"


class wheatfieldScene : public baseScene {
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    int w;
    int h;
};

