#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    viewPos.set(0,0);

    for (int t = 0; t < BIEBERTRIPS; t ++) {
        int barheight = timeToPixels(bieberWeekday[t].toTime, ySpacing)-timeToPixels(bieberWeekday[t].fromTime, ySpacing);
        int y = timeToPixels(bieberWeekday[t].fromTime, ySpacing) + barheight/2;
        int x = xSpacing*t + 1.5*xSpacing;
        line.curveTo(ofVec2f(x,y));

    }




}

//--------------------------------------------------------------
void ofApp::update() {
    int indexOfClosestPath;
    int minDistance = 9999999999;
    cout << ofGetMouseX() << "," << ofGetMouseY() << endl;

}



//--------------------------------------------------------------
void ofApp::draw() {

    //need bieber/trans/drive

    ofPushMatrix();
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
    for (int dayy = 0; dayy < 8; dayy ++) {
        int heightofday = ySpacing*24;
        for (int y = 0; y < 24; y ++) {
            ofLine(-viewPos.x , y*ySpacing, -viewPos.x+ofGetWidth(), y*ySpacing);
        }
    }


    drawBieber(monday);
    /*
    drawBieber(tuesday);
    drawBieber(wednesday);
    drawBieber(thursday);
    drawBieber(friday);*/

    //time labels
    ofPushStyle();
    ofSetColor(0,0,0,48);
    ofRect(-viewPos.x, -viewPos.y, 48, ofGetHeight());
    ofPopStyle();
    for (int dayy = 0; dayy < 8; dayy ++) {
        int heightofday = ySpacing*24;
        for (int y = 0; y < 24; y ++) {
            string time;
            if (y == 0) {
                time = "midnight";
            }
            else if (y < 12) {
                time = ofToString(y) + "am";
            } else if (y == 12) {
                time = "noon";
            }else{
                time = ofToString(y-12) + "pm";
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

    ofPopMatrix();

}

void ofApp::drawBieber(int dayOffset) {
    //bieber
    dayOffset += 1;
    ofColor bieberGold = ofColor(216,151,9);
    ofColor agencyColor = bieberGold;
    int barWidth = 10;
    int yySpacing = ySpacing;
    int xxSpacing = xSpacing;
    string fromStopName = "hellertown";
    string toStopName = "PABT";

    ofPushMatrix();
    ofTranslate(xSpacing*BIEBERTRIPS*dayOffset, 24*yySpacing*dayOffset);

    ofPushStyle();
    ofSetColor(agencyColor);
    ofFill();
    ofSetLineWidth(2);

    for (int t = 0; t < BIEBERTRIPS; t ++) {

        int left = (1.5*xSpacing) + t*xSpacing - barWidth/2;
        int top = timeToPixels(bieberWeekday[t].fromTime, yySpacing);
        int barheight = timeToPixels(bieberWeekday[t].toTime,yySpacing) - timeToPixels(bieberWeekday[t].fromTime, yySpacing);

        ofRect(left, top, barWidth, barheight);

        string fromInfo = fromStopName + "\n" + timeToString(bieberWeekday[t].fromTime);
        ofDrawBitmapString(fromInfo, left + barWidth + 2, top + 10);

        string toInfo = timeToString(bieberWeekday[t].toTime) + "\n" + toStopName ;
        ofDrawBitmapString(toInfo, left +  barWidth + 2, top + barheight - 14);
    }
    ofPopStyle();
    ofPopMatrix();
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

