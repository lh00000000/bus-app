#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    viewPos.set(0,0);

    for (int t = 0; t < WEEKENDRUNS; t ++) {
        int y = timeToPixels(bieberWeekday[t].fromTime, ySpacing);
        int x = xSpacing*t + 1.5*xSpacing;
        line.curveTo(ofVec2f(x,y- ));
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    int indexOfClosestPath;
    int minDistance = 9999999999;
    viewPos.y = ((int)viewPos.y)%(24*7*ySpacing);
    viewPos.x = ((int)viewPos.x)%((WEEKENDRUNS+WEEKDAYRUNS)*ySpacing);

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
    for (int x = 0; x < ofGetWidth()/xSpacing +2 ; x += 2) {
        int xoffset = viewPos.x - (((int)viewPos.x)%(xSpacing*2));
        ofRect(x*xSpacing - xoffset, -viewPos.y, xSpacing, ofGetHeight());
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


    drawBieber(monday, bieberWeekday, WEEKDAYRUNS);
    drawBieber(tuesday,bieberWeekday, WEEKDAYRUNS);
    drawBieber(wednesday,bieberWeekday, WEEKDAYRUNS);
    drawBieber(thursday, bieberWeekday, WEEKDAYRUNS);
    drawBieber(friday, bieberWeekday, WEEKDAYRUNS);
    drawBieber(saturday, bieberWeekend, WEEKENDRUNS);
    drawBieber(sunday, bieberWeekend, WEEKENDRUNS);



    //box behind time labels
    ofPushStyle();
    ofSetColor(0,0,0,48);
    ofRect(-viewPos.x, -viewPos.y, 48, ofGetHeight());
    ofPopStyle();

    //time labels
    int heightofday = ySpacing*24;
    for (int dayoffset = -heightofday; dayoffset < heightofday*2 + 1; dayoffset+=heightofday) {
        for (int y = 0; y < 24; y ++) {
            int yoffset = viewPos.y - (((int)viewPos.y)%(ySpacing*24));
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
            ofDrawBitmapString(time, -viewPos.x + 2, y*ySpacing - yoffset- 2 + dayoffset);
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
    case saturday:
        dayString = "saturday";
        break;
    case sunday:
        dayString = "sunday";
        break;
    default:
        dayString = "idk";
        break;
    }
    ofDrawBitmapString(dayString, -viewPos.x + 4, -viewPos.y +12);

    ofPopMatrix();

}

void ofApp::drawBieber(int dayOffset, trip* bieberday, int numruns) {
    //bieber
    ofColor bieberGold = ofColor(216,151,9);
    ofColor agencyColor = bieberGold;
    int barWidth = 10;
    string fromStopName = "hellertown";
    string toStopName = "PABT";

    ofPushMatrix();
    ofTranslate(xSpacing*numruns*(dayOffset), 24*ySpacing*dayOffset);

    ofPushStyle();
    ofSetColor(agencyColor);
    ofFill();
    ofSetLineWidth(2);

    for (int t = 0; t < numruns; t ++) {

        int left = (1.5*xSpacing) + t*xSpacing - barWidth/2;
        int top = timeToPixels(bieberday[t].fromTime, ySpacing);
        int barheight = timeToPixels(bieberday[t].toTime,ySpacing) - timeToPixels(bieberday[t].fromTime, ySpacing);

        ofRect(left, top, barWidth, barheight);

        string fromInfo = fromStopName + "\n" + timeToString(bieberday[t].fromTime);
        ofDrawBitmapString(fromInfo, left + barWidth + 2, top + 10);

        string toInfo = timeToString(bieberday[t].toTime) + "\n" + toStopName ;
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

