#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofDisableAntiAliasing();
	//ofSetFrameRate(120);
	//finder.setPreset(ObjectFinder::Fast);
	//cam.setup(640,480);
	ofDirectory dir;
	ofDisableArbTex();
	int n = dir.listDir("textures");
	for (int i = 0;i < n;i++) {
		auto tex = make_shared<ofTexture>();
		ofLoadImage(*tex,dir.getPath(i));

		tex->setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
		tex->setTextureWrap(GL_REPEAT, GL_REPEAT);

		textures.push_back(tex);
	}
	printf("%i Textures Loaded\n", (int)textures.size());


	box2d.init();
	box2d.setGravity(0,20);
	box2d.createGround();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();

	/*for (int i = 0; i < 3; i++) {
		auto circle = make_shared<ofxBox2dCircle>();
		circle->setPhysics(3.0, 0.53, 0.1);
		
		circle->setup(box2d.getWorld(), ofGetWidth() / 2, 100 + (i * 20), ofRandom(10,20));
		
		circles.push_back(circle);
	} */

}

//--------------------------------------------------------------
void ofApp::update(){
/*	cam.update();
	if (cam.isFrameNew) {
		finder.update(cam);
	}
	*/
	if ((int)ofRandom(0, 10) == 0) {

		auto tex = textures[(int)ofRandom(textures.size())];
		float x = (ofGetWidth() / 2) + ofRandom(-20, 20);
		float y = -20;
		float r = ofRandom(10,20);

		shapes.push_back(make_shared<TextureShape>(box2d.getWorld(), tex, x, y, r));

	}
	box2d.update();


}

//--------------------------------------------------------------
void ofApp::draw(){	

	/*cam.draw(0, 0);
	finder.draw();
	for (int i = 0;i < finder.size();i++) {
		float x = finder.getObject(i).getX()+finder.getObject(i).getWidth()/2;
		float y = finder.getObject(i).getY()+ finder.getObject(i).getHeight() / 2;
		cout << x << "," << y << endl;
	}
	ofDrawBitmapStringHighlight(ofToString(finder.size()), 10, 20);
   */
	ofSetHexColor(0xf2ab01);
	for (auto &circle : circles) {
		ofFill();
		ofSetHexColor(0x01b1f2);
		circle->draw();

	}
	for (auto &shape : shapes) {
		shape->draw();
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'n') {

		// add a new circle
		auto circle = make_shared<ofxBox2dCircle>();
		circle->setPhysics(3.0, 0.53, 0.1);
		circle->setup(box2d.getWorld(),facedata->newX ,facedata->newY, ofRandom(10, 20));
		circles.push_back(circle);
	
	}
	if (key == 'c') {
	//	auto circle = make_shared<ofxBox2dCircle>();
		circles.clear();
		
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
