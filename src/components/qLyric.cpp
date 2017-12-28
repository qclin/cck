//
//  qLyric.cpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#include "qLyric.h"

void qLyric::setup(string path){
    w = ofGetWidth();
    h = ofGetHeight();
    currentIndex = 0; 
    myFont.load("fonts/AmericanTypewriter.ttc", 50, true, true, true); // font with point size
    ABZ.loadFont("fonts/AmericanTypewriter.ttc");

    ifstream fileStream;
    fileStream.open(ofToDataPath(path).c_str());
    
    while(!fileStream.eof()) {
        string tempStr;
        getline(fileStream, tempStr);
        txtFileStrs.push_back(tempStr);
    }
    
    
//    dir.listDir("lyrics/");
//
//    for (int i = 0; i < dir.size(); i++){
//        string path = dir.getPath(i);
//        cout << "lyrics pathss ::: "<< path << endl;
//        lyricPaths.push_back(path);
//    }
}

void qLyric::update(){
    
}

void qLyric::draw(int startHeight, float bpm, float startTime){
//    cout<< "drawLyrics ::: "<< bpm << " :: "<< startTime << endl;
    if(bpm < 1 ){
        bpm = 100;
    }
    
    float secsPerBeat = 1/(bpm/60);
    auto t = ofGetElapsedTimef();
    float sequence = t - startTime; //* 1.0/4.0;  // second number is how many seconds to display text
    //*
    if(sequence >= 0.0){
        float currentBeat = sequence/secsPerBeat;
        
        string lyric = txtFileStrs[currentLyric];//currentBeat%txtFileStrs.size()];
        
        int lyricSize;
        if(lyric.empty()){
            lyricSize = 1;
        }else{
            lyricSize= ofSplitString(lyric, " ", true, true).size();
        }

        if(lyricSize == 0){lyricSize =1;}
        
        float pctSequence = fmod((currentBeat - accumSize)/(float)lyricSize, 1.0f);
        
        if((int)floor((currentBeat - accumSize)/(float)lyricSize)>0){
            currentLyric++;
            currentLyric %= txtFileStrs.size();
            accumSize += lyricSize;
        }
        
        
        
        ofPushMatrix();
        ofRectangle fontRect = myFont.getStringBoundingBox(lyric, 0, 0);
        ofTranslate((ofGetWidth() - fontRect.width)/2, ofGetHeight() - fontRect.height);
        
        myFont.drawString(lyric, 0, 0);
        
        ofPushStyle();
        ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        ofSetColor(255,24,0);
        ofDrawRectangle(0, -fontRect.height, fontRect.width*pctSequence, fontRect.height);
        ofDisableBlendMode();
        ofPopStyle();
        ofPopMatrix();
    }
}

void qLyric::loadSong(){
    
}

/// NOT USE
void qLyric::keyPressed(int key){
    
}

