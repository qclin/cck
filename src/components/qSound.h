//
//  fftSound.hpp
//  textAtIntervals
//
//  Created by Qiao Lin on 11/4/17.
//

#ifndef Sound_h
#define Sound_h

#include <stdio.h>
#include "ofMain.h"
#include "fft.h"
#include "fftOctaveAnalyzer.h"
#include "ofxAubio.h"


#define BUFFER_SIZE_FFT 512


class qSound : public ofBaseApp{
    public:
        void setup(string path);
        void update();
    
        ofSoundPlayer track;
        float * fftSmooth;
        int bands;

        void audioIn(float * input, int bufferSize, int nChannels);
        ofSoundStream soundStream;
    
        FFTOctaveAnalyzer FFTanalyzer;
        fft        myfft;
        float magnitude    [BUFFER_SIZE_FFT];
        float phase        [BUFFER_SIZE_FFT];
        float power        [BUFFER_SIZE_FFT];
        float freq        [BUFFER_SIZE_FFT];
        float avg_power = 0.0f;
    
    
        void onsetEvent(float & time);
        void beatEvent(float & time);
    
        float bpm;
        float midiPitch;
        float pitchConfidence;
    
        float onsetThreshold;
        float onsetNovelty;
        float onsetThresholdedNovelty;
    
        ofxAubioOnset onset;
        ofxAubioPitch pitch;
        ofxAubioBeat beat;
    
        bool gotBeat;
        bool gotOnset;

    private:

};

#endif /* Sound_h */
