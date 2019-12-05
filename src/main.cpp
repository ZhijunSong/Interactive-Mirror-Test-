#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include "Face.h"
//========================================================================
int main( ){
/*	ofSetupOpenGL(242,766,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp()); */
	ofGLFWWindowSettings settings;


	
	settings.setSize(640,480);
	settings.setPosition(ofVec2f(200, 200));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> facetracker = ofCreateWindow(settings);

	settings.setSize(242, 766);
	settings.setPosition(ofVec2f(840, 200));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<Face> faceApp(new Face);

	mainApp->facedata =faceApp;///////

	ofRunApp(facetracker,faceApp);
	ofRunApp(mainWindow,mainApp);
	ofRunMainLoop();


}
