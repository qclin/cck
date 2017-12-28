//
//  qImage.cpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#include "qImage.h"

void qImage:: setup(){
    singleIndex = 0;
    singleGif.load("gifs/scene_beach/handSpin.gif");

    
//    dir.listDir("gifs/scene_beach/");
//
//    for (int i = 0; i < dir.size(); i++){
//        string path = dir.getPath(i);
//        ofxGIF::fiGifLoader gif;
//        gif.load(path);
//        gifsLoader.push_back(gif);
//        pageIndexes.push_back(0);
//    }
    

    
}


void qImage:: update(){
    
    //--------- single gif -----------
    if (ofGetElapsedTimeMillis() % 3){
        singleIndex++;
        if (singleIndex > singleGif.pages.size()-1) singleIndex = 0;
    }
    
//    //--------- bunch of gifs -----------
//    for (int i = 0; i< gifsLoader.size(); i++){
//        if (ofGetElapsedTimeMillis() % 3){
//            pageIndexes[i]++;
//            if (pageIndexes[i] > gifsLoader[i].pages.size()-1) pageIndexes[i] = 0;
//        }
//    }

    
    

    
}

void qImage:: draw(){
    
    ofEnableAlphaBlending();
    float wave = sin(ofGetElapsedTimef());
    
    //    to make it move alittle bit
    //    transparency.draw(500 + (wave * 100), 20);
    //    ofMap(sin(ofGetElapsedTimef() * 3.3), -1, 1, 0, h)
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    
//    singleGif.pages[singleIndex].draw( w-200, h-300); // position for spinning hand
    
    //    for (int i = 0; i< gifsLoader.size(); i++){
    //         gifsLoader[i].pages[pageIndexes[i]].draw(100 * i, 100);
    //    }
    
    ofDisableAlphaBlending();

    
    

    
    
    
//    self rotate in center
    
//    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
//
//    float l = img.getWidth();
//    img.draw(-img.getWidth() / 2, -img.getWidth() / 2);
//
//    for (int i = 1; i < countLevels; i++) {
//        float h = sqrt(2 * pow(l / 2, 2));
//        ofPushMatrix();
//        ofRotate(i * 45);
//        ofScale(h / img.getWidth(), h / img.getWidth());
//        img.draw(-img.getWidth() / 2, -img.getWidth() / 2);
//        ofPopMatrix();
//        l = h;
//    }
    

}


void qImage:: animateScale(int value){
    
}

void qImage:: animateRotate(int value){
    
}

void qImage:: animateSpiral(int value){
    
}

void qImage:: distort(int value){
    
}

void qImage:: filter(int value){
    
}
