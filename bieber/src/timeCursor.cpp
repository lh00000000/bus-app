#include "timeCursor.h"

#define SECONDS_IN_A_WEEK 24*60*60*7
#define RECTROUND 8

void timeCursor::setup(int _heightOfWeek, fontRepo* allFonts) {
    heightOfWeek = _heightOfWeek;
    timeCursorFont = allFonts->littleTimeFont;
    update();

}
void timeCursor::update() {
    currenttime.update();
    y = ofMap(currenttime.getSecondsFromWeek(), 0, SECONDS_IN_A_WEEK, 0, heightOfWeek);

}
void timeCursor::draw() {
    //draw now line
    ofPushStyle();
    ofSetColor(105, 158, 249);
    ofLine(0, y, ofGetWidth()*2, y);
    ofRectangle hourLabelBg = ofRectangle(0, y, 55, -13);
    ofRectRounded(hourLabelBg,0,RECTROUND,0,0);
    ofRectangle hourLabelBgReturn = ofRectangle(ofGetWidth(), y, 55, -13);
    ofRectRounded(hourLabelBgReturn,0,RECTROUND,0,0);
    ofPopStyle();
    timeCursorFont.drawString(currenttime.timeStr(), 2, y-2);
    timeCursorFont.drawString(currenttime.timeStr(), ofGetWidth()+2, y-2);

}

float timeCursor::getY() {
    return y;
}
