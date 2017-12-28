//
//  rainforestScene.cpp
//  consonantKaroake
//
//  Created by Qiao Lin on 11/12/17.
//

#include "rainforestScene.h"
#include "ofApp.h"


void rainforestScene::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    
    myVideo.setup("clips/rainforest.mp4");
    myLyric.setup("lyrics/song_02.txt");
    mySound.setup("tracks/piano_r&b.mp3");
    
    // Bunch of pills
    flowerDir.listDir("gifs/scene_rainforest/flowers/");
    
    for (int i = 0; i < flowerDir.size(); i++){
        string path = flowerDir.getPath(i);
        ofxGIF::fiGifLoader gif;
        gif.load(path);
        flowerLoader.push_back(gif);
        flowerIndexes.push_back(0);
    }
    
    
    
    
    // beautiful pineapple
    monkeyIndex = 0;
    monkeyGif.load("gifs/scene_rainforest/monkey.gif");
    manIndex = 0;
    manGif.load("gifs/scene_rainforest/manWalking.gif");
    
    
    
    
    

}

void rainforestScene::update(){
    
    duration = ofGetElapsedTimef() - startTime;
    durationMillis = ofGetElapsedTimeMillis() - startTimeMillis;
    
    myVideo.update();
    mySound.update();
//
//    if (durationMillis % 3){
//        wowFighterIndex++;
//        if (wowFighterIndex > wowFighterGif.pages.size()-1) wowFighterIndex = 0;
//    }

    
    
    // loop thru gif pages of each flower
    for (int i = 0; i< flowerLoader.size(); i++){
        if (durationMillis % 2){
            flowerIndexes[i]++;
            if (flowerIndexes[i] > flowerLoader[i].pages.size()-1) flowerIndexes[i] = 0;
        }
    }

    
    
    if (durationMillis % 3){
        monkeyIndex++;
        if (monkeyIndex > monkeyGif.pages.size()-1) monkeyIndex = 0;
    }
    
    
    
    if (durationMillis % 3){
        manIndex++;
        if (manIndex > manGif.pages.size()-1) manIndex = 0;
    }
    
    if(duration > 60 * 3.5){
        ((ofApp*)ofGetAppPtr())->nextScene();
    }
    
    

    
}


void rainforestScene::draw(){
    
    duration = ofGetElapsedTimef() - startTime;
    
    myVideo.draw();
    myLyric.draw(myVideo.startHeight, 85, 20+startTime);//seconds_per_bar); // second param should be adjusted to bpm
    
    
    
    
    if(int(floor(duration/35.0)) % 2 == 0){ // TODO : change to 30 seconds
        monkeyHair(duration);

    }else{
        bloomingAnimation(duration);

    }
    
}

void rainforestScene::bloomingAnimation(float duration){
    ofTranslate(0, -ofGetHeight()/3);
    for (int i = 0; i < 20; i++){
        ofPushMatrix();
        ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
        ofRotate( i * 15 );
        ofTranslate(i * 10, 0 );
        float scl = 1.0 - i * 0.9 / 20.0;
        ofScale( scl, scl );
        
        for (int j = 0; j< flowerLoader.size(); j++){
            ofEnableBlendMode(OF_BLENDMODE_ALPHA);

            flowerLoader[j].pages[flowerIndexes[j]].draw(0,0);
            ofDisableBlendMode();
        }
        ofPopMatrix();
    }
}

void rainforestScene::monkeyHair(float duration){
    
    
    ofPushMatrix();
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    for(int i = 0; i<manGif.pages.size(); i++){ // overlapping trick for visibility
        manGif.pages[manIndex].draw(0, 0); // position for spinning hand

    }
//    ofDisableBlendMode();
    ofPopMatrix();
    
    for(int i = 0; i<monkeyGif.pages.size(); i++){ // overlapping trick for visibility
//        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        int ww = monkeyGif.pages[monkeyIndex].getWidth();
        int hh = monkeyGif.pages[monkeyIndex].getHeight();
        monkeyGif.pages[monkeyIndex].draw(ofGetWidth()- ww, ofGetHeight()-(hh+100)); // position for spinning hand
//        ofDisableBlendMode();
    }
    ofPopMatrix();


}

