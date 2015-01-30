#include "ofApp.h"
#define WINDOWHOURS 8
//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    ball.update();
    beginningSecond = ofMap(ball.pos.y, ofGetHeight(),0, 0, 86400*7);
    endingSecond = beginningSecond + WINDOWHOURS*60*60;
}

//--------------------------------------------------------------
void ofApp::draw(){


    ofSetColor(255);
    //ofCircle(ball.pos, 50);
    //ofCircle(ball.pos.x, ball.pos.y - ofGetHeight(), 50);
    //ofCircle(ball.pos.x, ball.pos.y + ofGetHeight(), 50);

    ofDrawBitmapString("begin hour: " + ofToString(beginningSecond), 20, 20);
    ofDrawBitmapString("ending hour: " + ofToString(endingSecond), 20, ofGetHeight() - 25);

    ofPushMatrix();
    ofTranslate(0,-beginningSecond);
    for (int i = 0; i < NUMTRIPS; i++) {
        if (weekSchedule[i].endSec > beginningSecond && weekSchedule[i].startSec < endingSecond) {
            ofRect(i * 2, weekSchedule[i].startSec, 10, weekSchedule[i].endSec - weekSchedule[i].startSec);
        }
    }
    ofPopMatrix();
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
    toss.update(x,y);
    ball.vel.y = toss.getVel().y/150;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    toss.prevPos = ofVec2f(x,y);
    toss.currentPos = ofVec2f(x,y);
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
