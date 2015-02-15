#include "weekGrid.h"
#define RECTROUND 8
void weekGrid::setup(int _heightOfWeek, fontRepo *allFonts) {
    heightOfWeek = _heightOfWeek;
    heightOfDay = heightOfWeek/7;
    hourLabelFont = allFonts->littleTimeFont;
}

void weekGrid::update() {
}

void weekGrid::drawOneDay(int r, int g, int b, int brightnessDiff) {

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
            ofRectRounded(hourLabelBg,0,RECTROUND,0,0);

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
            ofRectRounded(hourLabelBg,0,RECTROUND,0,0);

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

void weekGrid::drawOneWeek(int topOfViewPort, int bottomOfViewPort) {
    //extraSunday
    ofPushMatrix();
    ofTranslate(0,-heightOfDay);
    drawOneDay(119,79,56,32);
    ofPopMatrix();
      /////grid/////
    for (int dayi = 0; dayi < NUM_DAYS; dayi++) {
        //alt color per day
        if (dayi*heightOfDay + heightOfDay < topOfViewPort) continue;
        if (dayi*heightOfDay > bottomOfViewPort) break;

        if (dayi == MONDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawOneDay(136,168,37,32);
            ofPopMatrix();
        }
        if (dayi == TUESDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawOneDay(53+100,32+100,59+100,32);
            ofPopMatrix();
        }
        if (dayi == WEDNESDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawOneDay(145,17,70,32);
            ofPopMatrix();
        }
        if (dayi == THURSDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawOneDay(207,74,48,32);
            ofPopMatrix();
        }
        if (dayi == FRIDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawOneDay(237,140,43,255-237);
            ofPopMatrix();
        }
        if (dayi == SATURDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawOneDay(18,122,191,32);
            ofPopMatrix();
        }
        if (dayi == SUNDAY) {
            ofPushMatrix();
            ofTranslate(0,dayi*heightOfDay);
            drawOneDay(119,79,56,32);
            ofPopMatrix();
        }
    }

    //drawExtraDays

    //extraMonday
    ofPushMatrix();
    ofTranslate(0,7*heightOfDay);
    drawOneDay(136,168,37,32);
    ofPopMatrix();
}

void weekGrid::draw(int topOfViewPort, int bottomOfViewPort) {
    drawOneWeek(topOfViewPort, bottomOfViewPort);
    ofPushMatrix();
    ofTranslate(ofGetWidth(), 0);
    drawOneWeek(topOfViewPort, bottomOfViewPort);
    ofPopMatrix();

}
