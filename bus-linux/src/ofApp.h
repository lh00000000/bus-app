#pragma once

#include "ofMain.h"
#define BIEBERTRIPS 20

enum day {
    monday, tuesday, wednesday, thursday, friday
};

struct trip {
    int fromTime;
    int toTime;
    string agency;
    int fromTimeToPixels(int spacing) {
        int minute = fromTime%100;
        int hour = (fromTime-minute)/100;
        return hour*spacing + minute*spacing/60;
    }
    int toTimeToPixels(int spacing) {
        int minute = toTime%100;
        int hour = (toTime-minute)/100;
        return hour*spacing + minute*spacing/60;
    }

    int durationToPixels(int spacing) {
        int from = fromTimeToPixels(spacing);
        int to = toTimeToPixels(spacing);
        return to-from;
    }

    string timeToString(int time) {
        int minute;
        int hour;
        string m = "am";
        if (time > 1300) {
            time -= 1200;
            m = "pm";
        }
        minute = time%100;
        hour = (time-minute)/100;

        return ofToString(hour) +":"+ofToString((float)minute,0,2,'0')+m;
    }

    string fromTimeToString() {
        return timeToString(fromTime);
    }

    string toTimeToString() {
        return timeToString(toTime);
    }

};


class ofApp : public ofBaseApp{
    trip bieberWeekday[BIEBERTRIPS] = {{425, 600},{445, 635},{505, 655},{540, 740},{600, 805},{620, 810},{650, 840},{720, 910},{750, 940},{820, 1010},{920, 1110},{935, 1125},{1020, 1210},{1220, 1415},{1320, 1515},{1450, 1640},{1720, 1900},{1850, 2030},{2050, 2230}};

	public:
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

		ofVec2f viewPos;
		ofVec2f beginMouseDrag;
		ofVec2f translateBeginMouseDrag;

};
