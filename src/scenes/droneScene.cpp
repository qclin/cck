#include "droneScene.h"
#include "ofApp.h"
//#include "ofApp.h"  // only do this in the cpp file, otherwise will cause recursion conflict since  triangel.h is included in the main.h


//void droneScene::start(){
//    startTime = ofGetElapsedTimef();
//    startTimeMillis = ofGetElapsedTimeMillis(); 
//}
void droneScene::setup(){
    
    w = ofGetWidth();
    h = ofGetHeight();
    
    myVideo.setup("clips/slomo_drone_beach.mp4");
    myLyric.setup("lyrics/song_03.txt");
    mySound.setup("tracks/loveGalore.mp3");

    // GUNDAM running
    gundamIndex = 0;
    gundamGif.load("gifs/scene_beach/haloman.gif");
    
    
    // Bunch of pills
    pillsDir.listDir("gifs/scene_beach/drugs/");
    
    for (int i = 0; i < pillsDir.size(); i++){
        string path = pillsDir.getPath(i);
        ofxGIF::fiGifLoader gif;
        gif.load(path);
        pillLoader.push_back(gif);
        pillIndexes.push_back(0);
    }
    
}

void droneScene::update(){
    duration = ofGetElapsedTimef() - startTime;
    durationMillis = ofGetElapsedTimeMillis() - startTimeMillis;
    myVideo.update();
    mySound.update();

    // loop thru gif pages of each pill
    for (int i = 0; i< pillLoader.size(); i++){
        if (durationMillis % 3){
            pillIndexes[i]++;
            if (pillIndexes[i] > pillLoader[i].pages.size()-1) pillIndexes[i] = 0;
        }
    }
    
    
    // loop thru single gif pages
    if (durationMillis % 3){
        gundamIndex++;
        if (gundamIndex > gundamGif.pages.size()-1) gundamIndex = 0;
    }
    
    if(duration >  60 * 3.5){
        ((ofApp*)ofGetAppPtr())->nextScene();
    }

    
}
void droneScene::draw(){
    
    duration = ofGetElapsedTimef() - startTime;
    
    myVideo.draw();
    
    float seconds_per_bar = 60/(167/4);
//    60 seconds/ ( Beats per minute/ 4 bars)
    
    
    myLyric.draw(myVideo.startHeight, 85, 21 + startTime);//seconds_per_bar); // second param should be adjusted to bpm
    rainingPills(duration);
    runningManPerspective(duration);
    
}


void droneScene:: rainingPills(float timeElapsed){

    //RAINING PILL with random start position
    //ADD gravity and descrease size as they fall
    ofEnableAlphaBlending();
    for (int i = 0; i < 20; i++){
        ofPushMatrix();
        //        float scl = 1.0 - i * 0.8 / 20.0; // makes everything spiral
        for (int j = 0; j< pillLoader.size(); j++){
            // float yPos =  ofGetHeight()/2 + ofGetElapsedTimef() * 30;
            // pillLoader[j].pages[(pillIndexes[j] + i) % 59].draw( 100 * i, yPos);  // start animation at different frames
            float yPos =  -500 * ofNoise(i, j) + ofMap(ofNoise(i+100,j+100), 0,1,0, 100) * timeElapsed;
            float scale =ofMap(yPos, 0, h, .8, .2);
            ofTranslate( 100 * i, yPos);
            ofScale(scale, scale);
            
            pillLoader[j].pages[pillIndexes[j]].draw(0,0);
        }
        ofPopMatrix();
    }
    ofDisableAlphaBlending();
}
void droneScene:: runningManPerspective(float timeElapsed){

    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofPushMatrix();
    
    ofTranslate( 0.5 * w + 100 * cos(timeElapsed) , 0.5*h + timeElapsed * 0.1); /// now he's scaling from the center
    //        1 - translate
    //        2 - draw at origin 0,0
    //        3 - scale in relative to time power at exponential rate
    ofScale(.5 + 0.01 *  pow(timeElapsed,2), .5 + 0.01 * pow(timeElapsed,2));
    //start from the back and move forward
    for(int i = 0; i<2; i++){ // overlapping trick for visibility
        gundamGif.pages[gundamIndex].draw(0, 0); // position for spinning hand
    }
    ofPopMatrix();
    ofDisableBlendMode();
}
