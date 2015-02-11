#include "ofApp.h"
#define WINDOWHOURS 80


//--------------------------------------------------------------
void ofApp::setup()
{

    ofEnableSmoothing();
    ofBackground(0);
    ofSetFrameRate(60);

    /*
    snapToCurrentTime(true);*/
    weekgrid.setup(heightOfWeek);
    verticalScroll.setup(heightOfWeek);
    horizontalScroll.setup();
    weeklabels.setup(heightOfWeek);
    routelabels.setup();
    weektrips.setup(heightOfWeek);
    currentTimeCursor.setup(heightOfWeek);

    verticalScroll.snap(currentTimeCursor.getY() - 240);
}


//--------------------------
void ofApp::update()
{
    verticalScroll.update();
    horizontalScroll.update();
    currentTimeCursor.update();

    topOfViewPort = verticalScroll.getY();
    bottomOfViewPort = topOfViewPort + ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(-horizontalScroll.getX(), -topOfViewPort);
    weekgrid.draw(topOfViewPort, bottomOfViewPort);
    weektrips.draw(topOfViewPort, bottomOfViewPort);

    currentTimeCursor.draw();
    weeklabels.draw(topOfViewPort);
    routelabels.draw(topOfViewPort);

    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    verticalScroll.mouseUpdate(x,y); //toss.update(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    verticalScroll.mousePress(x,y);

    if (x > ofGetWidth() - 300 && y < 80 && goToCurrentTimeDoubleClick.click())
        verticalScroll.snap(currentTimeCursor.getY() - 240);

    if (x < 300 && y < 80 && switchTripDirectionDoubleClick.click())
        horizontalScroll.toggle();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    verticalScroll.mouseRelease();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
