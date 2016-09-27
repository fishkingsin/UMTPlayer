#pragma once

#include "ofMain.h"
#define SETTING_PATH "settings.xml"
#include "MyVideoPlayer.h"
class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	MyVideoPlayer player;
	ofDirectory dir;
	vector<ofFile> files;
	ofRectangle drawRect;
	float scale ,offSetX,offSetY;

	float startPoint,duration,max_scale;
	bool isSetPosition;

	void setupVideo();
    string path, fileToPlay;
    bool isFullScreen;
    bool isDebug;
    float speed;
    
};
