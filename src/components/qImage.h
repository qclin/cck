//
//  qImage.hpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#ifndef qImage_h
#define qImage_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxGif.h"

class qImage : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
    
        void animateScale(int value);
        void animateRotate(int value);
        void animateSpiral(int value);
        void distort(int value);
        void filter(int value);

    ofDirectory dir;

    int singleIndex;
    ofxGIF::fiGifLoader singleGif;
    
    vector <ofxGIF::fiGifLoader> gifsLoader;
    vector <int> pageIndexes;
    
    

};

#endif /* qImage_h */
