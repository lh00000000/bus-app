#pragma once

#include "ofMain.h"
#include "horizontalScroller.h"
#include "verticalScroller.h"
#include "weekGrid.h"
#include "weekTrips.h"
#include "weekLabels.h"
#include "routeLabels.h"
#include "doubleClick.h"
#include "timeCursor.h"

//TODO
// display day
// scroll away day
// day menu
// time of day slider (top left)
// trips back
// swipe to see back trips
// go to current time
//i know this is awful...

class ofApp : public ofBaseApp {

    horizontalScroller horizontalScroll;
    verticalScroller verticalScroll;
    weekGrid weekgrid;
    weekTrips weektrips;
    weekLabels weeklabels;
    routeLabels routelabels;
    timeCursor currentTimeCursor;

    doubleClick goToCurrentTimeDoubleClick;
    doubleClick switchTripDirectionDoubleClick;

    int topOfViewPort;
    int bottomOfViewPort;

public:
    int heightOfWeek = ofGetHeight()*32;

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

};
