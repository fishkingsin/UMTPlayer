//
//  MyVideoPlayer.cpp
//  UMTPlayer
//
//  Created by James Kong on 26/9/2016.
//
//

#include "MyVideoPlayer.hpp"
//needs implementing
bool MyVideoPlayer::load(string name) {
#ifdef TARGET_LINUX_ARM
    isVideoEnd = false;
    ofxOMXPlayerSettings settings;
    settings.videoPath = name;
    settings.useHDMIForAudio	= true;		//default true
    settings.enableTexture		= true;		//default true
    settings.enableLooping		= true;		//default true
    settings.enableAudio		= true;		//default true, save resources by disabling
    //settings.doFlipTexture = true;		//default false
    settings.listener = this;
    
    //so either pass in the settings
    omxPlayer.setup(settings);
#else
    player.load(name);
#endif
};
void MyVideoPlayer::loadAsync(string name){
#ifdef TARGET_LINUX_ARM
#else
    player.loadAsync(name);
#endif
};

void MyVideoPlayer::play(){
#ifdef TARGET_LINUX_ARM
#else
    player.play();
#endif
};
void MyVideoPlayer::stop(){
#ifdef TARGET_LINUX_ARM
#else
    player.stop();
#endif
};

bool MyVideoPlayer::isPaused(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.isPaused();
#else
    return player.isPaused();
#endif
};
bool MyVideoPlayer::isLoaded(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.isLoad();
#else
    return player.isLoaded();
#endif
};
bool MyVideoPlayer::isPlaying(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.isPlaying();
#else
    return player.isPlaying();
#endif
};


//should implement!
float MyVideoPlayer::getPosition(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.getMediaTime();
#else
    return player.getPosition();
#endif
};

float MyVideoPlayer::getDuration(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.getDurationInSeconds();
#else
    return player.getDuration();
#endif
};
bool MyVideoPlayer::getIsMovieDone(){
#ifdef TARGET_LINUX_ARM
    return isVideoEnd;
#else
    return player.getIsMovieDone();
#endif
};

void MyVideoPlayer::setLoopState(ofLoopType state){
#ifdef TARGET_LINUX_ARM
#else
    player.setLoopState(state);
#endif
};
void MyVideoPlayer::setSpeed(float speed){
#ifdef TARGET_LINUX_ARM
#else
    player.setSpeed(speed);
#endif
};

float MyVideoPlayer::getWidth(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.getWidth();
#else
    return player.getWidth();
#endif
};

float MyVideoPlayer::getHeight(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.getHeight();
#else
    return player.getHeight();
#endif
};

bool MyVideoPlayer::isFrameNew(){
#ifdef TARGET_LINUX_ARM
    return omxPlayer.isFrameNew();
#else
    return player.isFrameNew();
#endif
};
void MyVideoPlayer::close(){
#ifdef TARGET_LINUX_ARM
    omxPlayer.close();
#else
    player.close();
#endif
};

void MyVideoPlayer::draw(ofRectangle rect){
#ifdef TARGET_LINUX_ARM
#else
    player.draw(rect);
#endif
};


void MyVideoPlayer::update(){
#ifdef TARGET_LINUX_ARM
#else
    player.update();
#endif
};
