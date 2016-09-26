//
//  MyVideoPlayer.hpp
//  UMTPlayer
//
//  Created by James Kong on 26/9/2016.
//
//

#ifndef MyVideoPlayer_hpp
#define MyVideoPlayer_hpp

#include <stdio.h>
#include "ofMain.h"
#ifdef TARGET_LINUX_ARM
#includde "ofxOMXPlayer.h"
#endif
class MyVideoPlayer : public ofBaseVideoPlayer{
public:
    
    //needs implementing
    bool				load(string name) {return false;};
    void				loadAsync(string name){};
    
    void				play(){};
    void				stop(){};
    ofTexture *			getTexturePtr(){return NULL;};
    
    float 				getWidth(){return 0;};
    float 				getHeight(){return 0;};
    
    bool				isPaused(){return false;};
    bool				isLoaded(){return false;};
    bool				isPlaying(){return false;};
    bool				isInitialized(){return false;};
    
    //should implement!
    float 				getPosition(){return 0;};
    float 				getSpeed(){return 0;};
    float 				getDuration(){return 0;};
    bool				getIsMovieDone(){return 0;};
    
    void 				setLoopState(ofLoopType state){};
    void   				setSpeed(float speed){};
    
    
    void				setFrame(int frame){};  // frame 0 = first frame...
    
    int					getCurrentFrame(){return 0;};
    int					getTotalNumFrames(){return 0;};
    ofLoopType			getLoopState(){return OF_LOOP_NONE;};
    
    void				firstFrame(){};
    void				nextFrame(){};
    void				previousFrame(){};
    
    bool isFrameNew(){return 0;};
    void close(){};
    
    bool setPixelFormat(ofPixelFormat pixelFormat){return false;};

    ofPixelFormat getPixelFormat(){return OF_PIXELS_RGB;};
#ifdef TARGET_LINUX_ARM
    ofxOMXPlayer player;
#else
    ofVideoPlayer player;
#endif
    
};

#endif /* MyVideoPlayer_hpp */
