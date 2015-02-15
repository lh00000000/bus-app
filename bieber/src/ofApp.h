#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "ofMain.h"
#include "horizontalScroller.h"
#include "verticalScroller.h"
#include "weekGrid.h"
#include "weekTrips.h"
#include "weekLabels.h"
#include "routeLabels.h"
#include "doubleClick.h"
#include "timeCursor.h"
#include "fontRepo.h"

class ofApp : public ofxiOSApp {
	
    public:
        fontRepo allFonts;
    
        horizontalScroller horizontalScroll;
        verticalScroller verticalScroll;
        weekGrid weekgrid;
        weekTrips weektrips;
        weekLabels weeklabels;
        routeLabels routelabels;
        timeCursor currentTimeCursor;
        
        doubleClick goToCurrentTimeDoubleClick;
        doubleClick switchTripDirectionDoubleClick;
    
        int phoneHeight = 1024;
        int phoneWidth = 768;
    
        int topOfViewPort;
        int bottomOfViewPort;
        int heightOfWeek = phoneHeight*18;

    
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);

};


