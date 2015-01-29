#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    viewPos.set(0,0);
}

//--------------------------------------------------------------
void ofApp::update() {

}



//--------------------------------------------------------------
void ofApp::draw() {
    int ySpacing = 256;
    int xSpacing = 128;

    //need bieber/trans/drive
    //viewPos.x = viewPos.y;
    ofTranslate(viewPos);
    //guidelines
    ofSetColor(255);

    ofPushStyle();
    ofSetColor(255,255,255,16);
    ofFill();
    for (int x = 0; x < 200; x += 2) {
        ofRect(x*xSpacing, -viewPos.y, xSpacing, ofGetHeight());
        //ofLine(x*xSpacing, -viewPos.y, x*xSpacing, -viewPos.y + ofGetHeight());
    }
    ofPopStyle();

    for (int y = 0; y < 200; y ++) {
        ofLine(-viewPos.x , y*ySpacing, -viewPos.x+ofGetWidth(), y*ySpacing);
    }

    //time labels
    for (int dayy = 0; dayy < 8; dayy ++) {
        int heightofday = ySpacing*24;
        for (int y = 0; y < 24; y ++) {
            ofLine(-viewPos.x , y*ySpacing, -viewPos.x+ofGetWidth(), y*ySpacing);
            string time;
            if (y == 0) {
                time = "midnight";
            }
            else if (y < 13) {
                time = ofToString(y) + " am";
            } else {
                time = ofToString(y-12) + " pm";
            }
            ofDrawBitmapString(time, -viewPos.x + 2, dayy*heightofday + y*ySpacing -2 );
        }
    }

    // day string
    // todo: replace with pushing (like months in ical)
    int dayInt = int((-viewPos.y+ySpacing)/(24*ySpacing))%7;
    string dayString;
    switch (dayInt) {
    case monday:
        dayString = "monday";
        break;
    case tuesday:
        dayString = "tuesday";
        break;
    case wednesday:
        dayString = "wednesday";
        break;
    case thursday:
        dayString = "thursday";
        break;
    case friday:
        dayString = "friday";
        break;
    default:
        dayString = "idk";
        break;
    }
    ofDrawBitmapString(dayString, -viewPos.x + 4, -viewPos.y +12);


    //bieber
    ofColor bieberGold = ofColor(216,151,9);

    ofColor agencyColor = bieberGold;
    int barWidth = 10;
    int yySpacing = ySpacing;
    int xxSpacing = xSpacing;
    string fromStopName = "hellertown";
    string toStopName = "PABT";

    ofPushStyle();
    ofSetColor(agencyColor);
    ofFill();
    ofSetLineWidth(2);
    for (int t = 0; t < BIEBERTRIPS; t ++) {
        int left = (1.5*xSpacing) + t*xSpacing - barWidth/2;
        int top = bieberWeekday[t].fromTimeToPixels(yySpacing);
        int barheight = bieberWeekday[t].durationToPixels(yySpacing);
        ofRect(left, top,
               barWidth, barheight);

        string fromInfo = fromStopName + "\n" + bieberWeekday[t].fromTimeToString();
        ofDrawBitmapString(fromInfo, left + barWidth + 2, top + 10);

        string toInfo = bieberWeekday[t].fromTimeToString() + "\n" + toStopName ;
        ofDrawBitmapString(toInfo, left +  barWidth + 2, top + barheight - 14);
    }
    ofPopStyle();



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
    ofVec2f drag(x,y);
    ofVec2f dragChange = drag - beginMouseDrag;
    viewPos = translateBeginMouseDrag + dragChange;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    beginMouseDrag = ofVec2f(x,y);
    translateBeginMouseDrag = viewPos;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}
