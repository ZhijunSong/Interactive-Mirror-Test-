#pragma once
#include <iostream>
#include"ofMain.h"
#include "ofxCv.h"
#include "ofxOpencv.h"
class Face: public ofBaseApp {
public:
		void setup();
		void update();
		void draw();
			
		ofxCv::ObjectFinder finder;
		ofVideoGrabber	 cam;
		float x=0;
		float y=0;
		float newX=0;
		float newY=0;
};



