//
//  qVideo.hpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#ifndef qVideo_h
#define qVideo_h
#include "ofMain.h"
#include <stdio.h>


class qVideo: public ofBaseApp{
    
    public:
    void setup(string path);
    void update();
    void draw();
    void getPixels();
    void keyPressed(int key);
    
    int w;
    int h;
    
    ofVideoPlayer         videoClip;
    bool                frameByframe;
    float vidWidth;
    float scaleVidRatio;
    int videoHeight;
    int startHeight;

    
    
    
    
    
    //------------------ replace video with color
    ofImage videoImage;        //Declare image object
    int table[16];        //Declare table for color replacing
    
    // ----- -------------- SLIT SCAN VIDEO
    
    deque<ofPixels> frames;             //Frames buffer
    int bufferN;                        //Frames buffer size
    
    //Pixels array for constructing output image
    ofPixels slitImagePixels;
    ofImage slitImage;                  //Output image
    //computes the pixel color (x, y) using frames buffer
    ofColor getSlitPixelColor(int x, int y);
    
};

#endif /* qVideo_h */


