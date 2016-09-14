#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    dir.allowExt("mp4");
    dir.allowExt("mov");
    int n = dir.listDir("");
    files = dir.getFiles();
    for(int i = 0 ; i < n ; i++ ){
        ofFile file = dir.getFiles()[i];
        
        ofLogVerbose() << file.getAbsolutePath();
        
    }
    
    setupVideo();
    
}

void ofApp::setupVideo(){
    scale = ofRandom(2)+1;
    if(player.isPlaying()){
        
        player.close();
    }
    ofxOMXPlayerSettings settings;
    settings.videoPath = files[ofRandom(files.size())].getAbsolutePath();
    settings.useHDMIForAudio = true;    //default true
    settings.enableTexture = true;      //default true
    settings.enableLooping = true;      //default true
    settings.enableAudio = true;        //default true, save resources by disabling
    //settings.doFlipTexture = true;        //default false
    
    
    //so either pass in the settings
    player.setup(settings);
    // player.loadMovie(files[ofRandom(files.size())].getAbsolutePath());
    // player.play();
    
    player.disableLooping();
    duration = player.getDurationInSeconds();
    
    startPoint = ofRandom(duration-60);
    
    drawRect.set(0,0,1920,1080);
    offSetX = ((ofRandomf()*720)-720)*scale;
    offSetY = ((ofRandomf()*540)-540)*scale;
    ofLogVerbose() << "duration " <<  duration;
    ofLogVerbose() << "startPoint " <<  startPoint;
    isSetPosition = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(player.getIsOpen()){

        if(!isSetPosition && player.getMediaTime()>0){
            isSetPosition = true;
            player.seekToTimeInSeconds(startPoint);
            ofLogVerbose() << "position " <<  player.getMediaTime();
        }
        // player.update();
        float diff = (player.getMediaTime()-startPoint)*duration;
        
        if(diff >60){
            player.close();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    if(player.getIsOpen()){
        ofPushMatrix();
        ofTranslate(offSetX,offSetY);
        ofScale(scale, scale);
        
        player.draw(drawRect);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case ' ':
            setupVideo();
            break;
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
