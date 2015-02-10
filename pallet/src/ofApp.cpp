#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    for (int d = MONDAY; d < NUM_DAYS; d++) {
        leftDays.push_back(ofRectangle(0,(ofGetHeight()/7)*d,ofGetWidth()/2, ofGetHeight()/7));
        rightDays.push_back(ofRectangle(ofGetWidth()/2,(ofGetHeight()/7)*d,ofGetWidth()/2, ofGetHeight()/7));

    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

void drawAlt(ofColor base, ofRectangle rect, int n, int dim) {
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) ofSetColor(base);
        else ofSetColor(base, 255-dim);
        ofRect(rect.getX(),rect.getY() + (rect.getHeight()/n*i), rect.getWidth(), rect.getHeight()/n);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    drawAlt(leftColors.monday, leftDays.at(MONDAY), 4, 32);
    drawAlt(leftColors.tuesday, leftDays.at(TUESDAY), 4, 32);
    drawAlt(leftColors.wednesday, leftDays.at(WEDNESDAY), 4, 32);
    drawAlt(leftColors.thursday, leftDays.at(THURSDAY), 4, 32);
    drawAlt(leftColors.friday, leftDays.at(FRIDAY), 4, 32);
    drawAlt(leftColors.saturday, leftDays.at(SATURDAY), 4, 32);
    drawAlt(leftColors.sunday, leftDays.at(SUNDAY), 4, 32);

    drawAlt(rightColors.monday, rightDays.at(MONDAY), 4, 32);
    drawAlt(rightColors.tuesday, rightDays.at(TUESDAY), 4, 32);
    drawAlt(rightColors.wednesday, rightDays.at(WEDNESDAY), 4, 32);
    drawAlt(rightColors.thursday, rightDays.at(THURSDAY), 4, 32);
    drawAlt(rightColors.friday, rightDays.at(FRIDAY), 4, 32);
    drawAlt(rightColors.saturday, rightDays.at(SATURDAY), 4, 32);
    drawAlt(rightColors.sunday, rightDays.at(SUNDAY), 4, 32);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
