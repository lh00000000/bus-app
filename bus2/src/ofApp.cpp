#include "ofApp.h"
#define WINDOWHOURS 80
#define FADEOFFSET 20

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

    dayLabelFont.loadFont("./data/FreeSansBold.otf",36);

    ofEnableSmoothing();
    ofBackground(0);
    ofSetFrameRate(60);

    nowCursor.update();
    snapToCurrentTime(true);
}


//--------------------------------------------------------------
void ofApp::update() {
    if (drawReturn){
        translateXtarget = -ofGetWidth();
    } else {
        translateXtarget = 0;
    }
    translateX = ofLerp(translateX, translateXtarget, 0.2);
    ball.update();
    beginningSecond = ofMap(ball.pos.y, ofGetHeight(),0, 0, 86400*7);
    endingSecond = beginningSecond + WINDOWHOURS*60*60;

    viewTranslateY = -ofMap(beginningSecond, 0, secondsInAWeek, 0, heightOfWeek);
    //cout << -viewTranslateY << endl;
    if (viewTranslateY < -heightOfWeek/2) {
        mondayLabel.update(-(viewTranslateY+heightOfWeek));
    } else {
        mondayLabel.update(-viewTranslateY);
    }
    tuesdayLabel.update(-viewTranslateY);
    wednesdayLabel.update(-viewTranslateY);
    thursdayLabel.update(-viewTranslateY);
    fridayLabel.update(-viewTranslateY);
    saturdayLabel.update(-viewTranslateY);
    sundayLabel.update(-viewTranslateY);

    nowCursor.update();
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

void ofApp::drawHellertownToPABT(int topOfViewPort, int bottomOfViewPoint) {

    ///////trips///////
    ofPushStyle();
    ofSetColor(255);
    for (int i = 0; i < NUM_ROUTES; i++) {
        int leaveTimeX = ofGetWidth()/3;
        int leaveTimeY = ofMap(toPABT[i].startTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);
        int arriveTimeX = ofGetWidth()*2/3;
        int arriveTimeY = ofMap(toPABT[i].endTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);

        if (arriveTimeY < topOfViewPort) continue;
        if (leaveTimeY > bottomOfViewPoint) break;


        if (toPABT[i].endTime.hour() == 8 &&
            toPABT[i].endTime.minute() == 10) {
            arriveTimeY = arriveTimeY + 15;
        }
        ofPushStyle();

        int leaveOpacity = ofClamp((leaveTimeY+FADEOFFSET)-(-viewTranslateY), 30,255);
        int arriveOpacity = ofClamp((arriveTimeY+FADEOFFSET)-(-viewTranslateY), 20,255);
        int lineOpacity = (leaveOpacity + arriveOpacity)/2;

        ofSetColor(255,leaveOpacity);
        //line under fromLocation
        ofSetLineWidth(.5);
        ofLine(0,leaveTimeY, leaveTimeX,leaveTimeY);
        ofCircle(leaveTimeX,leaveTimeY,3);
        fromLocationFont.drawString("  hellertown:", 0, leaveTimeY-2);
        fromTimeFont.drawString(toPABT[i].startTime.timeStr(), 87, leaveTimeY-2);
        fromTimeAMPMFont.drawString(toPABT[i].startTime.ampm(), leaveTimeX-33, leaveTimeY-2);
        ofPopStyle();


        ofPushStyle();
        ofSetColor(255, lineOpacity);
        //line from leave to arrive
        ofSetLineWidth(2);
        ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,arriveOpacity);
        ofSetLineWidth(.5);
        ofLine(arriveTimeX, arriveTimeY, ofGetWidth(), arriveTimeY);
        ofCircle(arriveTimeX,arriveTimeY,3);


        toTimeFont.drawString(toPABT[i].endTime.timeStr(), arriveTimeX+4, arriveTimeY-2);
        toTimeAMPMFont.drawString(toPABT[i].endTime.ampm(), arriveTimeX+90, arriveTimeY-2);
        toLocationFont.drawString(" PABT", arriveTimeX + 110, arriveTimeY-2);
        ofPopStyle();

    }
    ofPopStyle();
}

void ofApp::drawPABTtoHellertown(int topOfViewPort, int bottomOfViewPoint) {

    ///////trips///////
    ofPushStyle();
    ofSetColor(255);
    for (int i = 0; i < NUM_ROUTES; i++) {
        int leaveTimeX = ofGetWidth()/3;
        int leaveTimeY = ofMap(toHellertown[i].startTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);
        int arriveTimeX = ofGetWidth()*2/3;
        int arriveTimeY = ofMap(toHellertown[i].endTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);

        if (arriveTimeY < topOfViewPort) continue;
        if (leaveTimeY > bottomOfViewPoint) break;


        if (toHellertown[i].endTime.hour() == 8 &&
            toHellertown[i].endTime.minute() == 10) {
            arriveTimeY = arriveTimeY + 15;
        }

        int leaveOpacity = ofClamp((leaveTimeY+FADEOFFSET)-(-viewTranslateY), 30,255);
        int arriveOpacity = ofClamp((arriveTimeY+FADEOFFSET)-(-viewTranslateY), 20,255);
        int lineOpacity = (leaveOpacity + arriveOpacity)/2;

        ofPushStyle();
        ofSetColor(255,leaveOpacity);
        ofSetLineWidth(.5);
        ofLine(0,leaveTimeY, leaveTimeX,leaveTimeY);
        ofCircle(leaveTimeX,leaveTimeY,3);
        toLocationFont.drawString("   PABT:", 0, leaveTimeY-2);
        fromTimeFont.drawString(toHellertown[i].startTime.timeStr(), 87, leaveTimeY-2);
        fromTimeAMPMFont.drawString(toHellertown[i].startTime.ampm(), leaveTimeX-33, leaveTimeY-2);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,lineOpacity);
        //line from leave to arrive
        ofSetLineWidth(2);
        ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,(arriveTimeY)-(-viewTranslateY));

        ofSetLineWidth(.5);
        ofLine(arriveTimeX, arriveTimeY, ofGetWidth(), arriveTimeY);
        ofCircle(arriveTimeX,arriveTimeY,3);
        toTimeFont.drawString(toHellertown[i].endTime.timeStr(), arriveTimeX+4, arriveTimeY-2);
        toTimeAMPMFont.drawString(toHellertown[i].endTime.ampm(), arriveTimeX+90, arriveTimeY-2);
        fromLocationFont.drawString(" hellertown", arriveTimeX + 120, arriveTimeY-2);
        ofPopStyle();

    }
    ofPopStyle();
}

void ofApp::drawWeekGrid(int topOfViewPort, int bottomOfViewPoint) {
    /////grid/////
    for (int dayi = 0; dayi < NUM_DAYS; dayi++) {
        //alt color per day
        if (dayi*heightOfDay + heightOfDay < topOfViewPort) continue;
        if (dayi*heightOfDay > bottomOfViewPoint) break;

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
            drawDayGrid(18,122,191,32);
            ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
            ofPopMatrix();
        }
        if (dayi == SUNDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawDayGrid(119,79,56,32);
            ofRect(0, dayi*heightOfDay, ofGetWidth(), heightOfDay);
            ofPopMatrix();
        }

    }
}

void ofApp::drawDayLabels(int topOfViewPort, int bottomOfViewPoint) {
    if (mondayLabel.labelY >= topOfViewPort && mondayLabel.labelY < bottomOfViewPoint+100)
        dayLabelFont.drawString("monday", mondayLabel.labelX, mondayLabel.labelY);
    if (tuesdayLabel.labelY >= topOfViewPort && tuesdayLabel.labelY < bottomOfViewPoint+100)
        dayLabelFont.drawString("tuesday", tuesdayLabel.labelX, tuesdayLabel.labelY);
    if (wednesdayLabel.labelY >= topOfViewPort && wednesdayLabel.labelY < bottomOfViewPoint+100)
        dayLabelFont.drawString("wednesday", wednesdayLabel.labelX, wednesdayLabel.labelY);
    if (thursdayLabel.labelY >= topOfViewPort && thursdayLabel.labelY < bottomOfViewPoint+100)
        dayLabelFont.drawString("thursday", thursdayLabel.labelX, thursdayLabel.labelY);
    if (fridayLabel.labelY >= topOfViewPort && fridayLabel.labelY < bottomOfViewPoint+100)
        dayLabelFont.drawString("friday", fridayLabel.labelX, fridayLabel.labelY);
    if (saturdayLabel.labelY >= topOfViewPort && saturdayLabel.labelY < bottomOfViewPoint+100)
        dayLabelFont.drawString("saturday", saturdayLabel.labelX, saturdayLabel.labelY);
    if (sundayLabel.labelY >= topOfViewPort && sundayLabel.labelY < bottomOfViewPoint+100)
        dayLabelFont.drawString("sunday", sundayLabel.labelX, sundayLabel.labelY);
}

void ofApp::drawNowLine() {
    //draw now line
    ofPushStyle();
    ofSetColor(75, 128, 209);
    int nowTimeY = ofMap(nowCursor.secIntoWeek, 0, secondsInAWeek, 0, heightOfWeek);
    ofLine(0, nowTimeY, ofGetWidth(), nowTimeY);
    ofRectangle hourLabelBg = ofRectangle(0, nowTimeY, 55, -13);
    ofRectRounded(hourLabelBg,0,3,0,0);
    ofPopStyle();
    hourLabelFont.drawString(nowCursor.timeStr(), 2, nowTimeY-2);
}

//--------------------------------------------------------------
void ofApp::draw() {

    ofPushStyle();
    ofSetColor(255);

    ofPushMatrix();
    ofTranslate(translateX, viewTranslateY);

    //draw three times
    for (int tile = 0; tile < 3; tile ++) {
        int topOfViewPort;
        int bottomOfView;

        if (tile == 0) {
            topOfViewPort = heightOfWeek-(ofGetHeight()*2);
            bottomOfView = heightOfWeek;
        }
        if (tile == 1) {
            topOfViewPort = -viewTranslateY - ofGetHeight();

            bottomOfView = topOfViewPort + ofGetHeight()*3;

        }
        if (tile == 2) {
            topOfViewPort = 0;
            bottomOfView = ofGetHeight()*2;
        }

        ofPushMatrix();
        ofTranslate(0, heightOfWeek*(tile-1));

        //to NYC
        drawWeekGrid(topOfViewPort, bottomOfView);
        drawHellertownToPABT(topOfViewPort, bottomOfView);
        drawDayLabels(topOfViewPort, bottomOfView);
        drawNowLine();

        //from NYCx
        ofPushMatrix();
        ofTranslate(ofGetWidth(),0);
        drawWeekGrid(topOfViewPort, bottomOfView);
        drawPABTtoHellertown(topOfViewPort, bottomOfView);
        drawDayLabels(topOfViewPort, bottomOfView);
        drawNowLine();
        ofPopMatrix();

        ofPopMatrix(); //for tiling
    }

    toTimeFont.drawString("hellertown>PABT", 20, LABELFROMTOP-viewTranslateY);
    toTimeFont.drawString("PABT>hellertown", 20 + ofGetWidth(), LABELFROMTOP-viewTranslateY);
    ofPopMatrix(); // for scrolling
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
    toss.update(x,y);
    ball.vel.y = toss.getVel().y/16;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    toss.prevPos = ofVec2f(x,y);
    toss.currentPos = ofVec2f(x,y);

    if (x > ofGetWidth() - 300 && y < 80) {
	    int currentClickTime = ofGetElapsedTimeMillis();
		cout << ofGetElapsedTimeMillis();
		if (currentClickTime - lastClickTime < 600) {
			snapToCurrentTime(false);
		}
		lastClickTime = currentClickTime;
	}

	if (x < 300 && y < 80) {
	    int currentClickTime = ofGetElapsedTimeMillis();
		cout << ofGetElapsedTimeMillis();
		if (currentClickTime - lastClickTime < 600) {
			drawReturn = !drawReturn;
		}
		lastClickTime = currentClickTime;
	}
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
