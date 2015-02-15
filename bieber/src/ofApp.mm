#include "ofApp.h"
#define WINDOWHOURS 80
#define HEIGHT 568

//--------------------------------------------------------------
void ofApp::setup(){
    allFonts = fontRepo();
    weekgrid.setup(heightOfWeek, &allFonts);
    verticalScroll.setup(heightOfWeek);
    horizontalScroll.setup();
    weeklabels.setup(heightOfWeek,&allFonts);
    routelabels.setup(&allFonts);
    weektrips.setup(heightOfWeek,&allFonts);
    currentTimeCursor.setup(heightOfWeek,&allFonts);
    
    verticalScroll.snap(currentTimeCursor.getY() - 240);
    ofEnableAntiAliasing();
}

//--------------------------------------------------------------
void ofApp::update(){
    verticalScroll.update();
    horizontalScroll.update();
    currentTimeCursor.update();
    
    topOfViewPort = verticalScroll.getY();
    bottomOfViewPort = topOfViewPort + HEIGHT;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(-horizontalScroll.getX(), -topOfViewPort);
    weekgrid.draw(topOfViewPort, bottomOfViewPort);
    currentTimeCursor.draw();
    weektrips.draw(topOfViewPort, bottomOfViewPort);
    
    
    weeklabels.draw(topOfViewPort);
    routelabels.draw(bottomOfViewPort);
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
        verticalScroll.mousePress(touch.x,touch.y);
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    verticalScroll.mouseUpdate(touch.x, touch.y);//toss.update(x,y);

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    verticalScroll.mouseRelease();
    

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){
    if (touch.y < 80) {
        verticalScroll.snap(currentTimeCursor.getY() - 240);
        
    }
    
    if (touch.y > HEIGHT - 80) {
        horizontalScroll.toggle();
        verticalScroll.killVel();
    }
    
}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
