#include "ofApp.h"

#include "droneScene.h"
#include "oceanScene.h"
#include "rainforestScene.h"
#include "wheatfieldScene.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    screenW = ofGetWidth();
    screenH = ofGetHeight();
    ofBackground(0);
    
    currentScene = 0;
    scenes.push_back(new rainforestScene());
    scenes.push_back(new oceanScene());
    scenes.push_back(new droneScene());
    scenes.push_back(new wheatfieldScene());
    
    
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
    scenes[currentScene]->start();
}


//--------------------------------------------------------------
void ofApp::update(){
    
//    myImage.update();

    
    //    myAnim.update(mySound.ffTanalyzer.bins);
    
    scenes[currentScene]->update();

}

//--------------------------------------------------------------
void ofApp::draw(){
//    myImage.draw();
    
    scenes[currentScene]->draw();

}




//--------------------------------------------------------------


void ofApp::nextScene(){
    scenes[currentScene]->stop();
    currentScene ++;
    currentScene %= scenes.size();
    scenes[currentScene]->start();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    switch(key){
            
        case  OF_KEY_DOWN:
            scenes[currentScene]->stop();
            currentScene ++;
            currentScene %= scenes.size();
            scenes[currentScene]->start();
        case 'f':
            ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
