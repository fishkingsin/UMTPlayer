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
    if(player.isLoaded() && player.isPlaying()){
        player.stop();
        player.close();
    }
    player.load(files[ofRandom(files.size())].getAbsolutePath());
    player.play();
    
    player.setLoopState(OF_LOOP_NONE);
    duration = player.getDuration();
    
    startPoint = ofRandom(duration-60)/duration;
    
    drawRect.set(0,0,1920,1080);
    offSetX = ((ofRandomf()*720)-720)*scale;
    offSetY = ((ofRandomf()*540)-540)*scale;
    ofLogVerbose() << "duration " <<  duration;
    ofLogVerbose() << "startPoint " <<  startPoint;
    isSetPosition = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(player.isLoaded()){
        if(!isSetPosition && player.getPosition()>0){
            isSetPosition = true;
            player.setPosition(startPoint);
            ofLogVerbose() << "position " <<  player.getPosition();
        }
        player.update();
        float diff = (player.getPosition()-startPoint)*duration;
        
        if(diff >60){
            player.stop();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    if(player.isPlaying()){
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
