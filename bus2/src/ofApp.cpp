#include "ofApp.h"
#define WINDOWHOURS 80

struct busTime {
    private int secondsFromSunday;
    private int secondsFromClosestMidnight;
    private int hoursIntoDay;
    private int minutesIntoHour;
    busTime(int time) {
        int secsInADay = 24*60*60;
        secondsFromSunday = time;
        secondsFromClosestMidnight = time % secsInADay;
        hoursIntoDay = secsIntoTheDay / (60*60);
        minutesIntoHour = (secsIntoTheDay % (60*60))/60;
    }

};


string timeToString(int time) {
    int secsInADay = 24*60*60;
    int secsIntoTheDay = time % secsInADay;
    int hoursIntoDay = secsIntoTheDay / (60*60);
    int minutesIntoHour = (secsIntoTheDay % (60*60))/60;
    return ofToString(minutesIntoHour);

}
//--------------------------------------------------------------
void ofApp::setup(){
    type.loadFont("./data/Inconsolata.otf",10);

    for (int i = 0; i < 50; i++) {
        cout << timeToString(toPABT[i].startSec) << endl;

    }
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

    type.drawString("begin hour: " + ofToString(beginningSecond), 20, 20);
    type.drawString("ending hour: " + ofToString(endingSecond), 20, ofGetHeight() - 25);


    int heightOfWeek = ofGetHeight()*42;
    ofPushMatrix();
    ofTranslate(0, -ofMap(beginningSecond, 0, 24*60*60*7, 0, heightOfWeek));
    for (int tile = -1; tile < 2; tile ++) {
        ofPushMatrix();
        ofTranslate(0, heightOfWeek*tile);
        for (int i = 0; i < NUMTRIPS; i++) {

            int leaveTimeX = 100;
            int leaveTimeY = ofMap(toPABT[i].startSec, 0, 24*60*60*7, 0, heightOfWeek);
            int arriveTimeX = ofGetWidth()-100;
            int arriveTimeY = ofMap(toPABT[i].endSec, 0, 24*60*60*7, 0, heightOfWeek);

            ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);
            type.drawString(timeToString(toPABT[i].startSec), leaveTimeX, leaveTimeY);
        }
        ofPopMatrix();
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
    ball.vel.y = toss.getVel().y/5;
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
