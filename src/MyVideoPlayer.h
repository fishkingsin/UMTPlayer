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
#include "ofRPIVideoPlayer.h"
#endif
class MyVideoPlayer {

public:
    
    
    bool load(string name);
    
    void loadAsync(string name);
    
    void play();
    
    void stop();
    
    bool isPaused();
    
    bool	 isLoaded();
    
    bool	 isPlaying();
    
    float getPosition();
    
    float getDuration();
    
    bool getIsMovieDone();
    
    void setLoopState(ofLoopType state);
    
    void setSpeed(float speed);
    
    float getWidth();
    
    float getHeight();
    
    bool isFrameNew();
    
    void close();
    
    void draw(ofRectangle rect);
    
    void update();
    
    
#ifdef TARGET_LINUX_ARM
    ofRPIVideoPlayer player;
#else
    ofVideoPlayer player;
#endif
    
};

#endif /* MyVideoPlayer_hpp */
