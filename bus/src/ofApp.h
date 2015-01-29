#pragma once

#include "ofMain.h"
#define BIEBERTRIPS 20

enum day {
    monday, tuesday, wednesday, thursday, friday
};



struct trip {
    int fromTime;
    int toTime;
    //string agency;
};


class ofApp : public ofBaseApp{
    trip bieberWeekday[BIEBERTRIPS] = {{425, 600},{445, 635},{505, 655},{540, 740},{600, 805},{620, 810},{650, 840},{720, 910},{750, 940},{820, 1010},{920, 1110},{935, 1125},{1020, 1210},{1220, 1415},{1320, 1515},{1450, 1640},{1720, 1900},{1850, 2030},{2050, 2230}};


	public:

    int ySpacing = 256;
    int xSpacing = 128;
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

		void drawBieber(int dayOffset, int xSpacing, int ySpacing);

		ofVec2f viewPos;
		ofVec2f beginMouseDrag;
		ofVec2f translateBeginMouseDrag;


        inline int timeToPixels(int time, int spacing) {
            int minute = time%100;
            int hour = (time-minute)/100;
            return ((hour*spacing) + (minute/60.0)*spacing);
        }

        inline string timeToString(int time) {
            int minute;
            int hour;
            string m = "am";

            minute = time%100;
            hour = (time-minute)/100;
            if (hour > 12) {
                m = "pm";
            }

            hour = (hour%24)%12;

            if (hour == 0) {
                hour = 12;
            }
            return ofToString(hour) +":"+ofToString((float)minute,0,2,'0')+m;
        }

};
