//
//  qVideo.cpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#include "qVideo.h"
#include "ofApp.h" /// for calling main file next scene

void qVideo::setup(string path){
    
    w = ofGetWidth();
    h = ofGetHeight();
    videoClip.load(path);
    videoClip.setVolume(0);

    
    // -------------- video manipulation
    //Fill the table by random values from 0 to 255
    for ( int i=0; i<16; i++ ) {
        table[i] = ofRandom( 0, 255 );
    }

    //for better seeing slit-scan effect
    //    videoClip.setSpeed( 0.25 );
    //    bufferN = 150;
    videoClip.setLoopState(OF_LOOP_NORMAL);
  //  videoClip.play();
}

void qVideo::update(){
    videoClip.update();

    
    
    // ---------------- -- SLIT SCAN --------------
    if(videoClip.isFrameNew()) {
        frames.push_front(videoClip.getPixelsRef());
        if(frames.size() > bufferN){
            // pop oldest frame when size exceeds
            frames.pop_back();
        }
    }
    
    // possible that video player didn't finished decoding the first frame
    //    if(!frames.empty()){
    //        if(!slitImagePixels.isAllocated()){
    //            slitImagePixels = frames[0]
    //        }
    //
    //        int frameW = frames[0].getWidth();
    //        int frameH = frames[0].getHeight();
    //
    //        /// scan all pixels
    //        for(int y =0; y < frameH; y++){
    //            for(int x = 0; x<w; x++){
    //                // get slit pixel color
    //                ofColor color = getSlitPixelColor(x, y);
    //                // set pixel to image pixels
    //
    //                slitImagePixels.setColor(x, y, color);
    //
    //            }
    //        }
    //        // set new pixels values to the image
    ////        slitImagePixels.setFromPixels(slitImagePixels);
    //
    //    }
    
    //use ofGetMousePressed() for testing
    //// get to next scene with certain parameters
//    if (videoClip.getIsMovieDone()){ // not sure if this should live in scenes
//        ((ofApp*)ofGetAppPtr())->nextScene(); // pointer to call parent function
//    }
    
}
void qVideo::getPixels(){
    
    /// call in .update
    //    //Do computing only if a new frame was obtained
    //    if ( videoClip.isFrameNew() ) {
    //        //Getting pixels
    //        ofPixels pixels = videoClip.getPixelsRef();
    //
    //        //Scan all the pixels
    //        for (int y=0; y<pixels.getHeight(); y++) {
    //            for (int x=0; x<pixels.getWidth(); x++) {
    //                //Getting pixel (x,y) color
    //                ofColor col = pixels.getColor( x, y );
    //
    //                //Change color components of col
    //                //using table
    //                col.r = table[ col.r/16 ];
    //                col.g = table[ col.g/16 ];
    //                col.b = table[ col.b/16 ];
    //
    //                //Set the color back to the pixel (x,y)
    //                pixels.setColor( x, y, col );
    //            }
    //        }
    //
    //        //Set pixel array to the image
    //        videoImage.setFromPixels( pixels );
    //    }
}


//--------------------------------------------------------------

ofColor qVideo::getSlitPixelColor(int x, int y){
    // calculate the distance from (x, y) to the current
    //    mouse position
}

void qVideo::draw(){

    
    // ---------- ### TODO : if(volume threshold)
    //    ofSetColor( 255, 255, 255 );
    //    videoImage.draw(0,videoStartHeight, screenW, videoHeight);
    
    ofRectangle screenRect(0,0,ofGetWidth(), ofGetHeight());
    ofRectangle vidRectangle(0,0,videoClip.getWidth(),videoClip.getHeight());
    
    vidRectangle.scaleTo(screenRect);
    
    vidWidth = videoClip.getWidth();
    scaleVidRatio = ofGetWidth()/vidWidth;
    videoHeight = videoClip.getHeight() * scaleVidRatio;
    startHeight = (ofGetHeight() - videoHeight)/2;
    
    videoClip.draw(vidRectangle);// 0,startHeight, ofGetWidth(), videoHeight);
    
//    slitImage.draw(0,0);
    
}



void qVideo::keyPressed(int key){
    
    int currentFrame = videoClip.getCurrentFrame();
    
    switch(key){
        case OF_KEY_LEFT:
            videoClip.setFrame(currentFrame -120);
        case OF_KEY_RIGHT:
            videoClip.setFrame(currentFrame + 120);
        case OF_KEY_BACKSPACE:
            videoClip.setPaused(true); /// DOESN"T WORK
        case ' ':
            videoClip.setPaused(false); /// DOESN"T WORK
            break;
        default:
            break;
    }
}
