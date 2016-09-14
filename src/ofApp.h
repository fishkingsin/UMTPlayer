#pragma once

#include "ofMain.h"
#ifdef TARGET_LINUX_ARM
#include "ofxOMXPlayer.h"
#endif
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
#ifdef TARGET_LINUX_ARM
	ofxOMXPlayer player;
#else
	ofVideoPlayer player;
#endif
	ofDirectory dir;
	vector<ofFile> files;
	ofRectangle drawRect;
	float scale ,offSetX,offSetY;

	float startPoint,duration;
	bool isSetPosition;

	void setupVideo();

};
