
#include "Face.h"
using namespace ofxCv;
using namespace cv;
using namespace std;
void Face::setup()
{
	ofBackground(0);
//	ofSetWindowShape(320,240);
	ofSetFrameRate(120);
	finder.setup("haarcascade_frontalface_default.xml");
	finder.setPreset(ObjectFinder::Fast);
	cam.setup(640,480);
   
}


void Face::update()
{	 	
	cam.update();
	if (cam.isFrameNew()) {
		finder.update(cam);
	}
	for (int i = 0;i < finder.size();i++) {
		float x = finder.getObject(i).getX() + finder.getObject(i).getWidth() / 2;
		float y = finder.getObject(i).getY() + finder.getObject(i).getHeight() / 2;
	    newX = ofMap(x, 0, 640, 0, 242);
		newY = ofMap(y, 0, 480, 0, 766);

			cout << newX << "," << newY << endl;
	}
}						   

void Face::draw()
{	  	
	cam.draw(0, 0);
	finder.draw();

	ofDrawBitmapStringHighlight(ofToString(finder.size()), 10, 20);
   
}



