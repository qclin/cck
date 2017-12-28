//
//  fftSound.cpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#include "qSound.h"
#include "fft.h"
#include "fftOctaveAnalyzer.h"

void qSound::setup(string path){
    
    track.load(path);
    track.setVolume(1.0f);
    track.setMultiPlay(true);
  //  track.play();
    
    soundStream.setup(this, 0, 1, 44100, 512, 4);
    FFTanalyzer.linearEQIntercept = 0.8f; // reduced gain at lowest frequency
    FFTanalyzer.linearEQSlope = 0.09f; // increasing gain at higher frequencies
    FFTanalyzer.setup(44100, 512, 3); // increase number of bins for more inputs
    
    onset.setup();
    ofAddListener(onset.gotOnset, this, &qSound::onsetEvent);
    beat.setup();
    pitch.setup();
    ofAddListener(beat.gotBeat, this, &qSound::beatEvent);
    
}

void qSound::update(){
    
    FFTanalyzer.calculate(magnitude);
    FFTanalyzer.nAverages;
    FFTanalyzer.averages;
    ofSoundUpdate();
    
    onset.setThreshold(onsetThreshold);
    
    // update beat info
    if (gotBeat) {
        gotBeat = false;
    }
    
    // update onset info
    if (gotOnset) {

        gotOnset = false;
    }
    onsetNovelty = onset.novelty;
    onsetThresholdedNovelty = onset.thresholdedNovelty;
    
    // update pitch info
    pitchConfidence = pitch.pitchConfidence;
    if (pitch.latestPitch) midiPitch = pitch.latestPitch;
    bpm = beat.bpm;
    
//    cout << "qSound bpm ::: " << bpm << endl;
}

//--------------------------------------------------------------
void qSound::audioIn(float * input, int bufferSize, int nChannels){
    // compute onset detection
    onset.audioIn(input, bufferSize, nChannels);
    // compute pitch detection
    pitch.audioIn(input, bufferSize, nChannels);
    // compute beat location
    beat.audioIn(input, bufferSize, nChannels);
    
    myfft.powerSpectrum(0,bufferSize/2, input, bufferSize, &magnitude[0], &phase[0], &power[0], &avg_power);
}


//----
void qSound::onsetEvent(float & time) {
//    ofLog() << "got onset at " << time << " s";
    gotOnset = true;
}

//----
void qSound::beatEvent(float & time) {
//    ofLog() << "got beat at " << time << " s";
    gotBeat = true;
}
