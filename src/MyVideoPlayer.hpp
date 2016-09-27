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
#include "ofxOMXPlayer.h"
#endif
class MyVideoPlayer {
public:
    
    //needs implementing
    bool				load(string name) {
#ifdef TARGET_LINUX_ARM
        ofxOMXPlayerSettings settings;
        settings.videoPath = name;
        settings.useHDMIForAudio	= true;		//default true
        settings.enableTexture		= true;		//default true
        settings.enableLooping		= true;		//default true
        settings.enableAudio		= true;		//default true, save resources by disabling
        //settings.doFlipTexture = true;		//default false
        
        if (!settings.enableTexture)
        {
            /*
             We have the option to pass in a rectangle
             to be used for a non-textured player to use (as opposed to the default full screen)
             */
            settings.displayRect.width = 400;
            settings.displayRect.height = 300;
            settings.displayRect.x = 440;
            settings.displayRect.y = 200;
        }
        
        
        //so either pass in the settings
        omxPlayer.setup(settings);
#else
        player.load(name);
#endif
    };
    void loadAsync(string name){
#ifdef TARGET_LINUX_ARM
#else
        player.loadAsync(name);
#endif
    };
    
    void play(){
#ifdef TARGET_LINUX_ARM
#else
        player.play();
#endif
    };
    void stop(){
#ifdef TARGET_LINUX_ARM
#else
        player.stop();
#endif
    };
    
    
    
    bool isPaused(){
#ifdef TARGET_LINUX_ARM
#else
        return player.isPaused();
#endif
    };
    bool				isLoaded(){
#ifdef TARGET_LINUX_ARM
#else
        return player.isLoaded();
#endif
    };
    bool				isPlaying(){
#ifdef TARGET_LINUX_ARM
        return omxPlayer.isPlaying();
#else
        return player.isPlaying();
#endif
    };
    
    
    //should implement!
    float 				getPosition(){
#ifdef TARGET_LINUX_ARM
        return omxPlayer.getMediaTime();
#else
        return player.getPosition();
#endif
    };
    
    float getDuration(){
#ifdef TARGET_LINUX_ARM
        return omxPlayer.getDurationInSeconds();
#else
        return player.getDuration();
#endif
    };
    bool				getIsMovieDone(){
#ifdef TARGET_LINUX_ARM
#else
        return player.getIsMovieDone();
#endif
    };
    
    void 				setLoopState(ofLoopType state){
#ifdef TARGET_LINUX_ARM
#else
        player.setLoopState(state);
#endif
    };
    void   				setSpeed(float speed){
#ifdef TARGET_LINUX_ARM
#else
        player.setSpeed(speed);
#endif
    };
    
    float getWidth(){
#ifdef TARGET_LINUX_ARM
        return omxPlayer.getWidth();
#else
        return player.getWidth();
#endif
    };
    
    float getHeight(){
#ifdef TARGET_LINUX_ARM
#else
        return player.getHeight();
#endif
    };
    
    bool isFrameNew(){
#ifdef TARGET_LINUX_ARM
        omxPlayer.isFrameNew();
#else
        return player.isFrameNew();
#endif
    };
    void close(){
#ifdef TARGET_LINUX_ARM
        omxPlayer.close();
#else
        player.close();
#endif
    };
    
    void draw(ofRectangle rect){
#ifdef TARGET_LINUX_ARM
#else
        player.draw(rect);
#endif
    };
    
    
    void update(){
#ifdef TARGET_LINUX_ARM
#else
        player.update();
#endif
    };
    
    
#ifdef TARGET_LINUX_ARM
    ofxOMXPlayer omxPlayer;
#else
    ofVideoPlayer player;
#endif
    
};

#endif /* MyVideoPlayer_hpp */
