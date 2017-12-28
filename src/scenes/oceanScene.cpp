
#include "oceanScene.h"
#include "ofApp.h"
//void oceanScene::start(){
//    startTime = ofGetElapsedTimef();
//    startTimeMillis = ofGetElapsedTimeMillis(); 
//}

void oceanScene::setup(){
    w = ofGetWidth();
    h = ofGetHeight();
    
    myVideo.setup("clips/underwater.mp4");
    myLyric.setup("lyrics/song_01.txt");
    mySound.setup("tracks/rosegold.mp3");

    // ghosting setup
    wowFighterIndex = 0;
    wowFighterGif.load("gifs/scene_ocean/ghosting/wow-fighter.gif");
    unicornIndex = 0;
    unicornGif.load("gifs/scene_ocean/ghosting/unicorn.gif");
    dude.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, ofRandom(-5, 5), ofRandom(-5, 5));
    for (int i = 0; i < 7; i++){
        particle catcher;
        catcher.setInitialCondition(ofRandom(0,w),ofRandom(0,h),0,0);
        catcher.damping = ofRandom(0.01, 0.05);
        dude_catchers.push_back(catcher);
    }
    
    
    // beautiful pineapple
    flipPhoneIndex = 0;
    flipPhoneGif.load("gifs/scene_ocean/beautiful-pineapple/flipPhone.gif");
    sphereIndex = 0;
    sphereGif.load("gifs/scene_ocean/beautiful-pineapple/cellSphere.gif");
    

}

void oceanScene::update(){
    
    duration = ofGetElapsedTimef() - startTime;
    durationMillis = ofGetElapsedTimeMillis() - startTimeMillis;
    
    myVideo.update();
    mySound.update();

    if (durationMillis % 3){
        wowFighterIndex++;
        if (wowFighterIndex > wowFighterGif.pages.size()-1) wowFighterIndex = 0;
    }
    
    if (durationMillis % 3){
        unicornIndex++;
        if (unicornIndex > unicornGif.pages.size()-1) unicornIndex = 0;
    }
    
    
    
    if (durationMillis % 2){
        flipPhoneIndex++;
        if (flipPhoneIndex > flipPhoneGif.pages.size()-1) flipPhoneIndex = 0;
    }
    
    if (durationMillis % 3){
        sphereIndex++;
        if (sphereIndex > sphereGif.pages.size() -1) sphereIndex = 0;
    }
    
    updateParticles(duration);
    
    
    if(duration > 60 * 3.5){
        ((ofApp*)ofGetAppPtr())->nextScene();
    }
    
}


void oceanScene::draw(){
    
    duration = ofGetElapsedTimef() - startTime;
    
    myVideo.draw();
    
    /// cheating here 167 is the BPM of RoseGold
    float seconds_per_bar = 60.0/(167.0/4.0);
    //    60 seconds/ ( Beats per minute/ 4 bars)
    
//    cout << "seconds_per_bar :::: " << seconds_per_bar << endl;
    myLyric.draw(myVideo.startHeight, 127, 15+startTime);//seconds_per_bar); // second param should be adjusted to bpm
    
    
    // position for lisajoux figure
    float posX = 200 * cos(ofGetElapsedTimef()*3.7);
    float posY = 200 * sin(ofGetElapsedTimef()*2.1);

    
    if(int(floor(duration/35.0)) % 2 == 0){ // TODO : change to 30 seconds
        drawGhostingAnimation(duration);
    }else{
        beautifulPinaepple(duration);
    }
    
    


}

void oceanScene::beautifulPinaepple(float duration){

    for (int j = 0; j < 10; j++){
        ofPushMatrix();
        
        for (int i = 0; i < 10; i++){
            float offset = i * sin(ofGetElapsedTimef()*0.1)*0.1;
            float x = 400 + 300 * cos((duration + offset + j * (PI*2/3.0))* 1.7);
            float y = 400 + 300 * sin((duration + offset+ j * (PI*2/3.0)) *0.7);
            ofTranslate(x, y);
            ofScale(.4, .4);
            int sphW = sphereGif.pages[sphereIndex].getWidth();
            int sphH = sphereGif.pages[sphereIndex].getHeight();
            ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
            sphereGif.pages[sphereIndex].draw(-sphW/2, -sphH/2);
            ofDisableBlendMode();
        }
        ofPopMatrix();
    }
    
    ofPushMatrix();
    int flipW = flipPhoneGif.pages[sphereIndex].getWidth();
    int flipH = flipPhoneGif.pages[sphereIndex].getHeight();
    ofTranslate(ofGetWidth()/8, ofGetHeight() - 200);
    ofScale(.65,.65);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    flipPhoneGif.pages[flipPhoneIndex].draw(0, 0);
    ofDisableBlendMode();
    ofPopMatrix();
}

void oceanScene::updateParticles(float duration){
    //    dude.resetForce();
    dude.bounceOffWalls();
    dude.update();
    for (int i = 0; i < dude_catchers.size(); i++){
        dude_catchers[i].resetForce();
        //        cout<< dude.pos.x <<  dude.pos.y << endl;
        //        dude_catchers[i].addAttractionForce(dude.pos.x, dude.pos.y, 100, 0.1);
        dude_catchers[i].addRepulsionForce(dude.pos.x, dude.pos.y, 60, 0.3);
        
        dude_catchers[i].update();
        
        float loopSinVal = sin(duration + i*0.4);
        float loopCosVal = cos(duration + i*0.4);
        
        dude_catchers[i].pos = 0.99 * dude_catchers[i].pos + 0.01 * dude.pos;
        dude_catchers[i].pos.x += loopCosVal * i;
        dude_catchers[i].pos.y += loopSinVal * i;
    }
}
void oceanScene::drawGhostingAnimation(float duration){
    ofPushMatrix();
    float posXX = dude.pos.x;
    float posYY = dude.pos.y;
    ofTranslate(posXX, posYY);
    int ww = wowFighterGif.pages[wowFighterIndex].getWidth();
    int hh = wowFighterGif.pages[wowFighterIndex].getHeight();
    ofScale(.7, .7);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    wowFighterGif.pages[wowFighterIndex].draw(-ww/2, -hh/2);
    ofDisableBlendMode();
    
    ofDrawCircle(0, 0, 10, 10);
    ofPopMatrix();
    
    for(int i = 0; i < 7; i++){
        ofPushMatrix();
        float posX = dude_catchers[i].pos.x;
        float posY = dude_catchers[i].pos.y;
        ofTranslate(posX, posY);
        int imgW = unicornGif.pages[unicornIndex].getWidth();
        int imgH = unicornGif.pages[unicornIndex].getHeight();
        ofScale(.4, .4);
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        unicornGif.pages[unicornIndex].draw(-imgW/2, -imgH/2);
        ofDisableBlendMode();
        
        ofPopMatrix();
    }
}
