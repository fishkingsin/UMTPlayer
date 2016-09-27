#include "ofApp.h"
#include "ofxXmlSettings.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofxXmlSettings settings;
    settings.load(SETTING_PATH);
    path = settings.getValue("SETTINGS:PATH", "");
    isFullScreen = settings.getValue("SETTINGS:FULLSCREEN", false);
    isDebug = settings.getValue("SETTINGS:DEBUG", false);
    max_scale = settings.getValue("SETTINGS:MAX_SCALE", 2);
    dir.allowExt("mp4");
    dir.allowExt("mov");
    int n = dir.listDir(path);
    files = dir.getFiles();
    for(int i = 0 ; i < n ; i++ ){
        ofFile file = dir.getFiles()[i];
        
        ofLogVerbose() << file.getAbsolutePath();
        
    }
    
    setupVideo();
}

void ofApp::setupVideo(){
    if(files.size()==0){
        ofLogWarning() << " no more file to play";
        return;
    }
    ofLogVerbose() << "======================== begin setup ========================";
    scale = ofRandom(max_scale)+1;
    ofLogVerbose() << "scale " << scale;
    if(player.isPlaying()){
        
        player.close();
    }
    int index = ofRandom(files.size());
    fileToPlay = files[index].getAbsolutePath();
    player.load(fileToPlay);
    player.play();
    
    player.setLoopState(OF_LOOP_NONE);
    duration = player.getDuration();
    startPoint = 0;//ofRandom(duration-60)/duration;
    
    
    int newWidth = (int)player.getWidth()*scale;
    int newHeight = (int)player.getHeight()*scale;
    int offsetWidth = (int) (((newWidth*1.0f)-ofGetWidth()));
    int offsetHeight = (int) (((newHeight*1.0f)-ofGetHeight()));
    offSetX = ofRandom(-offsetWidth,0);
    offSetY = ofRandom(-offsetHeight,0);
    
    ofLogVerbose() << "offSetX " << offSetX << endl
    << "offSetY " << offSetY << endl
    << "newWidth " << newHeight << endl
    << "newHeight " << newHeight << endl;
    
    drawRect.set(offSetX, offSetY, newWidth, newHeight);
    ofLogVerbose() << "duration " <<  duration;
    ofLogVerbose() << "startPoint " <<  startPoint;
    speed = duration/120;
    ofLogVerbose() << "speed " <<  speed;
    player.setSpeed(speed);
    isSetPosition = false;
    
    files.erase(files.begin()+index);
    ofLogVerbose() << "======================== end setup ========================";
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(player.isLoaded()){
        
        player.update();
        if(player.getIsMovieDone()){
            setupVideo();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    if(player.isLoaded()){
        ofPushMatrix();
        player.draw(drawRect);
        ofPopMatrix();
    }
    
    if(isDebug){
        ofSetColor(0, 0, 0,100);
        ofDrawRectangle(0, 0, 200, 100);
        ofSetColor(255);
        ostringstream debugInfo;
        debugInfo << "poatiion "<<player.getPosition()*duration << endl;
        debugInfo << "duration " <<duration << endl;
        debugInfo << "speed " << speed << endl;
        debugInfo << "scale " << scale << endl;
        debugInfo << "draw rect " << drawRect << endl;
        ofDrawBitmapString(debugInfo.str(), 20, 20);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case ' ':
            setupVideo();
            break;
        case 's':{
            ofxXmlSettings settings;
            settings.load(SETTING_PATH);
            settings.setValue("SETTINGS:FULLSCREEN", isFullScreen);
            settings.setValue("SETTINGS:DEBUG", isDebug);
            settings.save(SETTING_PATH);
        }
            break;
        case OF_KEY_TAB:
            isDebug = !isDebug;
            break;
        case 'f':
            isFullScreen = !isFullScreen;
            ofSetFullscreen(isFullScreen);
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
    
    path = dragInfo.files.at(0);
    dir.allowExt("mp4");
    dir.allowExt("mov");
    int n = dir.listDir(path);
    files = dir.getFiles();
    for(int i = 0 ; i < n ; i++ ){
        ofFile file = dir.getFiles()[i];
        
        ofLogVerbose() << file.getAbsolutePath();
        
    }
    
    ofxXmlSettings settings;
    settings.load(SETTING_PATH);
    //    path = settings.getValue("SETTINGS:PATH", "");
    settings.setValue("SETTINGS:PATH", path);
    settings.save(SETTING_PATH);
    
    setupVideo();
    
}
