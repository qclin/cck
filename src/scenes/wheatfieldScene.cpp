//
//  wheatfieldScene.cpp
//  consonantKaroake
//
//  Created by Qiao Lin on 11/12/17.
//

#include "wheatfieldScene.h"
#include "ofApp.h"


void wheatfieldScene::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    
    myVideo.setup("clips/wheat_in_wind.mp4");
    myLyric.setup("lyrics/song_07.txt");
    mySound.setup("tracks/bbkingblues.mp3");
    
    
}

void wheatfieldScene::update(){
    
    duration = ofGetElapsedTimef() - startTime;
    durationMillis = ofGetElapsedTimeMillis() - startTimeMillis;
    
    myVideo.update();
    mySound.update();
    //
    //    if (durationMillis % 3){
    //        wowFighterIndex++;
    //        if (wowFighterIndex > wowFighterGif.pages.size()-1) wowFighterIndex = 0;
    //    }
    
    if(duration > 60 * 3.5){
        ((ofApp*)ofGetAppPtr())->nextScene();
    }
    
}


void wheatfieldScene::draw(){
    
    duration = ofGetElapsedTimef() - startTime;
    
    myVideo.draw();
    myLyric.draw(myVideo.startHeight, 105, 20+startTime);//seconds_per_bar); // second param should be adjusted to bpm
    
    
}

