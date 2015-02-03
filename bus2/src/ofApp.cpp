#include "ofApp.h"
#define WINDOWHOURS 80

//--------------------------------------------------------------
void ofApp::setup() {
    //type.loadFont("./data/Inconsolata.otf",32);
    hourLabelFont.loadFont("./data/FreeSans.otf",8);

    fromLocationFont.loadFont("./data/FreeSans.otf",10);
    fromTimeFont.loadFont("./data/FreeSansBold.otf",24);
    fromTimeAMPMFont.loadFont("./data/FreeSansBold.otf",12);

    toLocationFont.loadFont("./data/FreeSans.otf",14);
    toTimeFont.loadFont("./data/FreeSansBold.otf",22);
    toTimeAMPMFont.loadFont("./data/FreeSans.otf",10);


    ofEnableSmoothing();
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update() {
    ball.update();
    beginningSecond = ofMap(ball.pos.y, ofGetHeight(),0, 0, 86400*7);
    endingSecond = beginningSecond + WINDOWHOURS*60*60;
}


void ofApp::drawDayGrid(int r, int g, int b, int brightnessDiff) {
    ofColor darker = ofColor(r,g,b);
    ofColor lighter = ofColor(r+brightnessDiff, g+brightnessDiff, b+brightnessDiff);
    for (int hourInDay = 0; hourInDay < 24; hourInDay ++) {

        ofPushStyle();
        if (hourInDay%2 == 0) {
            ofSetColor(darker);

            ofFill();
            ofRect(0, hourInDay*heightOfDay/24, ofGetWidth(), heightOfDay/24);
            ofNoFill();
            ofRect(0, hourInDay*heightOfDay/24, ofGetWidth(), heightOfDay/24);

            ofFill();
            ofRectangle hourLabelBg = ofRectangle(0, hourInDay*heightOfDay/24-13, 55, 13);
            ofRectRounded(hourLabelBg,0,3,0,0);


            ofSetColor(lighter);
            string hourString;
            if (hourInDay == 12) {
                hourString = "   noon";
            } else if (hourInDay == 0) {
                hourString = "midnight";
            } else {
                hourString = ofToString(hourInDay%12,0,2,' ') + ":00";
                if (hourInDay > 11) hourString += "pm";
                else hourString += "am";

            }
            hourLabelFont.drawString(hourString, 2, hourInDay*heightOfDay/24);

        } else {
            ofSetColor(lighter);

            ofFill();
            ofRect(0, hourInDay*heightOfDay/24, ofGetWidth(), heightOfDay/24+ 10);
            ofNoFill();
            ofRect(0, hourInDay*heightOfDay/24, ofGetWidth(), heightOfDay/24);

            ofFill();
            ofRectangle hourLabelBg = ofRectangle(0, hourInDay*heightOfDay/24-13, 55, 13);
            ofRectRounded(hourLabelBg,0,3,0,0);

            ofSetColor(darker);
            string hourString;
            hourString = ofToString(hourInDay%12,0,2,' ') + ":00";
            if (hourInDay > 11) hourString += "pm";
            else hourString += "am";

            hourLabelFont.drawString(hourString, 2, hourInDay*heightOfDay/24);

        }

        ofPopStyle();

    }
}
//--------------------------------------------------------------
void ofApp::draw() {

    ofSetColor(255);
    //ofCircle(ball.pos, 50);
    //ofCircle(ball.pos.x, ball.pos.y - ofGetHeight(), 50);
    //ofCircle(ball.pos.x, ball.pos.y + ofGetHeight(), 50);


    ofPushMatrix();
    ofTranslate(0, -ofMap(beginningSecond, 0, 24*60*60*7, 0, heightOfWeek));



    for (int tile = -1; tile < 2; tile ++) {
        ofPushMatrix();
        ofTranslate(0, heightOfWeek*tile);

        /////grid/////
        for (int dayi = 0; dayi < NUM_DAYS; dayi++) {
            //alt color per day
            if (dayi == MONDAY) {
                ofPushMatrix();
                ofTranslate(0,dayi*heightOfDay);
                drawDayGrid(136,168,37,32);
                ofPopMatrix();
            }
            if (dayi == TUESDAY) {
                ofPushMatrix();
                ofTranslate(0,dayi*heightOfDay);
                drawDayGrid(53+100,32+100,59+100,32);
                ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
                ofPopMatrix();
            }
            if (dayi == WEDNESDAY) {
                ofPushMatrix();
                ofTranslate(0,dayi*heightOfDay);
                drawDayGrid(145,17,70,32);
                ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
                ofPopMatrix();
            }
            if (dayi == THURSDAY) {
                ofPushMatrix();
                ofTranslate(0,dayi*heightOfDay);
                drawDayGrid(207,74,48,32);
                ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
                ofPopMatrix();
            }
            if (dayi == FRIDAY) {
                ofPushMatrix();
                ofTranslate(0,dayi*heightOfDay);
                drawDayGrid(237,140,43,255-237);
                ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
                ofPopMatrix();
            }
            if (dayi == SATURDAY) {
                ofPushMatrix();
                ofTranslate(0,dayi*heightOfDay);
                drawDayGrid(89,82,65,32);
                ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
                ofPopMatrix();
            }
            if (dayi == SUNDAY) {
                ofPushMatrix();
                ofTranslate(0,dayi*heightOfDay);
                drawDayGrid(184,174,156,32);
                ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
                ofPopMatrix();
            }

        }

        ///////trips///////
        ofPushStyle();
        ofSetColor(255);
        for (int i = 0; i < NUMTRIPS; i++) {

            int leaveTimeX = ofGetWidth()/3;
            int leaveTimeY = ofMap(toPABT[i].startTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);
            int arriveTimeX = ofGetWidth()*2/3;
            int arriveTimeY = ofMap(toPABT[i].endTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);

            ofSetLineWidth(.5);
            ofLine(0,leaveTimeY, leaveTimeX,leaveTimeY);
            ofLine(arriveTimeX, arriveTimeY, ofGetWidth(), arriveTimeY);

            ofSetLineWidth(2);
            ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);


            ofCircle(leaveTimeX,leaveTimeY,3);
            ofCircle(arriveTimeX,arriveTimeY,3);

            //ofPushStyle();
            //if leaveTimeY - ballPos < Thres, ofMap val to opacity (fade out near top)
            ofSetColor(255)
            fromLocationFont.drawString("  hellertown:", 0, leaveTimeY-2);
            fromTimeFont.drawString(toPABT[i].startTime.timeStr(), 87, leaveTimeY-2);
            fromTimeAMPMFont.drawString(toPABT[i].startTime.ampm(), leaveTimeX-33, leaveTimeY-2);

            toTimeFont.drawString(toPABT[i].endTime.timeStr(), arriveTimeX+4, arriveTimeY-2);
            toTimeAMPMFont.drawString(toPABT[i].endTime.ampm(), arriveTimeX+90, arriveTimeY-2);
            toLocationFont.drawString(" PABT", arriveTimeX + 110, arriveTimeY-2);

        }
        ofPopStyle();


        ofPopMatrix(); //for tiling
    }
    ofPopMatrix(); // for scrolling
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
    toss.update(x,y);
    ball.vel.y = toss.getVel().y/2;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    toss.prevPos = ofVec2f(x,y);
    toss.currentPos = ofVec2f(x,y);
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
