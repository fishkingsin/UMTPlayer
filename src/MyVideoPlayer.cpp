//
//  MyVideoPlayer.cpp
//  UMTPlayer
//
//  Created by James Kong on 26/9/2016.
//
//

#include "MyVideoPlayer.h"
//needs implementing
bool MyVideoPlayer::load(string name) {
    player.load(name);
}
void MyVideoPlayer::loadAsync(string name){
    player.loadAsync(name);
}

void MyVideoPlayer::play(){
    player.play();
}
void MyVideoPlayer::stop(){
    player.stop();
}

bool MyVideoPlayer::isPaused(){
    return player.isPaused();
}
bool MyVideoPlayer::isLoaded(){
    return player.isLoaded();
}
bool MyVideoPlayer::isPlaying(){
    return player.isPlaying();
}
//should implement!
float MyVideoPlayer::getPosition(){
    return player.getPosition();
}

float MyVideoPlayer::getDuration(){
    return player.getDuration();
}
bool MyVideoPlayer::getIsMovieDone(){
    return player.getIsMovieDone();
}

void MyVideoPlayer::setLoopState(ofLoopType state){
    player.setLoopState(state);
}
void MyVideoPlayer::setSpeed(float speed){
    player.setSpeed(speed);
}

float MyVideoPlayer::getWidth(){
    return player.getWidth();
}

float MyVideoPlayer::getHeight(){
    return player.getHeight();
}

bool MyVideoPlayer::isFrameNew(){
    return player.isFrameNew();
}
void MyVideoPlayer::close(){
    player.close();
}

void MyVideoPlayer::draw(ofRectangle rect){
    player.draw(rect.x, rect.y, rect.width, rect.height);
}


void MyVideoPlayer::update(){
    player.update();
}
