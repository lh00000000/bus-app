#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    ts.update();
}


//--------------------------------------------------------------
void ofApp::draw(){
    int midX = ofGetWidth()/2;
    int midY = ofGetHeight()/2;

    ofLine(200, midY-20, 200, midY+20);
    ofLine(ofGetWidth()-200, midY-20, ofGetWidth()-200, midY+20);
    ofLine(200, midY, ofGetWidth()-200, midY);

    int togglePos = ofMap(ts.position(), 0,1,200,ofGetWidth()-200);
    ofCircle(togglePos, midY, 10);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button) {
    ts.mouseDragged(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    ts.mousePressed(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ts.mouseReleased(x,y);
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
