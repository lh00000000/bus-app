#pragma once

#include "ofMain.h"

#define NUMTRIPS 111

//TODO
// display day
// scroll away day
// day menu
// time of day slider (top left)
// trips back
// swipe to see back trips
// go to current time

enum day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, NUM_DAYS
};

struct busTime {
    int secondsFromSunday;
    int secondsFromClosestMidnight;
    int hoursIntoDay;
    int minutesIntoHour;
    busTime(int time) {
        int secsInADay = 24*60*60;
        secondsFromSunday = time;
        secondsFromClosestMidnight = time % secsInADay;
        hoursIntoDay = secondsFromClosestMidnight / (60*60);
        minutesIntoHour = (secondsFromClosestMidnight % (60*60))/60;
    }

    int hour() {
        return hoursIntoDay;
    }

    int minute() {
        return minutesIntoHour;
    }

    string ampm() {
        if (hour() > 11) return "pm";
        else return "am";
    }
    string timeStr() {
        if (hour() == 0 && minute() == 0) {
            return "midnight";
        } else if (hour() == 24 && minute() == 0) {
            return "midnight";
        } else if (hour() == 12 && minute() == 0) {
            return "noon";
        } else {
            if (hour()%12 == 0)
                return ofToString(hour(),0,2,' ') + ":" + ofToString(minute(),0,2,'0');
            else
                return ofToString(hour()%12,0,2,' ') + ":" + ofToString(minute(),0,2,'0');
        }

    }
};

struct tripTime {
    busTime startTime;
    busTime endTime;
};


struct dayLabel {
    int dayIndex;
    int topOfBox;
    int bottomOfBox;
    int labelX;
    int labelY;
    int buf = 36;
    dayLabel(int dayi, int heightOfDay) {
        dayIndex = dayi;
        int heightOfHour = heightOfDay/24;
        topOfBox = heightOfDay*dayi;
        bottomOfBox = topOfBox + heightOfDay - heightOfHour;
        labelY = topOfBox;

        switch (dayIndex) {
            case MONDAY:
                labelX = ofGetWidth() - 220;
                break;
            case TUESDAY:
                labelX = ofGetWidth() - 220;
                break;
            case WEDNESDAY:
                labelX = ofGetWidth() - 280;
                break;
            case THURSDAY:
                labelX = ofGetWidth() - 225;
                break;
            case FRIDAY:
                labelX = ofGetWidth() - 180;
                break;
            case SATURDAY:
                labelX = ofGetWidth() - 220;
                break;
            case SUNDAY:
                labelX = ofGetWidth() - 200;
                break;

        } 

    }
    void update(int camYPos) {
        int marginFromTopOfWindow=30;
        int marginFromTopOfDay = 48;
        if (camYPos + marginFromTopOfWindow < topOfBox) {
            labelY = topOfBox + marginFromTopOfDay;
            cout << "cond1" << endl;
        } else if (camYPos + marginFromTopOfWindow > topOfBox && camYPos + marginFromTopOfWindow < bottomOfBox) {
            labelY = camYPos + marginFromTopOfWindow + marginFromTopOfDay;
            cout << "cond2" << endl;
        } else {
          /*  labelY = bottomOfBox + 36;
            cout << "cond3" << endl;*/
        }
    }


};

class ofApp : public ofBaseApp {

    struct centerOfView {
        ofVec2f pos = ofVec2f(0,0);
        ofVec2f vel = ofVec2f(0,0);
        float mass = 30;
        float drag = .7;


        void update() {
            pos += vel;
            vel *= drag;
            if (pos.x < 0) pos.x = ofGetWidth();
            if (pos.x > ofGetWidth()) pos.x = 0;
            if (pos.y < 0) pos.y = ofGetHeight();
            if (pos.y > ofGetHeight()) pos.y = 0;
        
        }
    } ball;

    struct mouseToss {
        ofVec2f prevPos;
        ofVec2f currentPos;

        void update(int x, int y) {
            prevPos = currentPos;
            currentPos = ofVec2f(x,y);
        }
        ofVec2f getVel() {
            return currentPos - prevPos;
        }

    } toss;

public:

    int heightOfWeek = ofGetHeight()*32;
    int heightOfDay = heightOfWeek/7;
    int beginningSecond;
    int endingSecond;

    int viewTranslateY;
    ofTrueTypeFont hourLabelFont;
    ofTrueTypeFont fromLocationFont;
    ofTrueTypeFont fromTimeFont;
    ofTrueTypeFont fromTimeAMPMFont;

    ofTrueTypeFont toLocationFont;
    ofTrueTypeFont toTimeFont;
    ofTrueTypeFont toTimeAMPMFont;

    ofTrueTypeFont dayLabelFont;

    struct dayLabel mondayLabel = dayLabel(0, heightOfDay);
    struct dayLabel tuesdayLabel = dayLabel(1, heightOfDay);
    struct dayLabel wednesdayLabel = dayLabel(2, heightOfDay);
    struct dayLabel thursdayLabel = dayLabel(3, heightOfDay);
    struct dayLabel fridayLabel = dayLabel(4, heightOfDay);
    struct dayLabel saturdayLabel = dayLabel(5, heightOfDay);
    struct dayLabel sundayLabel = dayLabel(6, heightOfDay);


    void setup();
    void update();
    void draw();

    void drawDayGrid(int r, int g, int b, int brightnessDiff);
    void drawHellertownToPABT();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    tripTime toPABT[NUMTRIPS] = {
        {busTime(15900),busTime(21600)},
        {busTime(17100),busTime(23700)},
        {busTime(18300),busTime(24900)},
        {busTime(20400),busTime(27600)},
        {busTime(21600),busTime(29100)},
        {busTime(22800),busTime(29400)},
        {busTime(24600),busTime(31200)},
        {busTime(26400),busTime(33000)},
        {busTime(28200),busTime(34800)},
        {busTime(30000),busTime(36600)},
        {busTime(33600),busTime(40200)},
        {busTime(34500),busTime(41100)},
        {busTime(37200),busTime(43800)},
        {busTime(44400),busTime(51300)},
        {busTime(48000),busTime(54900)},
        {busTime(53400),busTime(60000)},
        {busTime(62400),busTime(68400)},
        {busTime(67800),busTime(73800)},
        {busTime(75000),busTime(81000)},
        {busTime(102300),busTime(108000)},
        {busTime(103500),busTime(110100)},
        {busTime(104700),busTime(111300)},
        {busTime(106800),busTime(114000)},
        {busTime(108000),busTime(115500)},
        {busTime(109200),busTime(115800)},
        {busTime(111000),busTime(117600)},
        {busTime(112800),busTime(119400)},
        {busTime(114600),busTime(121200)},
        {busTime(116400),busTime(123000)},
        {busTime(120000),busTime(126600)},
        {busTime(120900),busTime(127500)},
        {busTime(123600),busTime(130200)},
        {busTime(130800),busTime(137700)},
        {busTime(134400),busTime(141300)},
        {busTime(139800),busTime(146400)},
        {busTime(148800),busTime(154800)},
        {busTime(154200),busTime(160200)},
        {busTime(161400),busTime(167400)},
        {busTime(188700),busTime(194400)},
        {busTime(189900),busTime(196500)},
        {busTime(191100),busTime(197700)},
        {busTime(193200),busTime(200400)},
        {busTime(194400),busTime(201900)},
        {busTime(195600),busTime(202200)},
        {busTime(197400),busTime(204000)},
        {busTime(199200),busTime(205800)},
        {busTime(201000),busTime(207600)},
        {busTime(202800),busTime(209400)},
        {busTime(206400),busTime(213000)},
        {busTime(207300),busTime(213900)},
        {busTime(210000),busTime(216600)},
        {busTime(217200),busTime(224100)},
        {busTime(220800),busTime(227700)},
        {busTime(226200),busTime(232800)},
        {busTime(235200),busTime(241200)},
        {busTime(240600),busTime(246600)},
        {busTime(247800),busTime(253800)},
        {busTime(275100),busTime(280800)},
        {busTime(276300),busTime(282900)},
        {busTime(277500),busTime(284100)},
        {busTime(279600),busTime(286800)},
        {busTime(280800),busTime(288300)},
        {busTime(282000),busTime(288600)},
        {busTime(283800),busTime(290400)},
        {busTime(285600),busTime(292200)},
        {busTime(287400),busTime(294000)},
        {busTime(289200),busTime(295800)},
        {busTime(292800),busTime(299400)},
        {busTime(293700),busTime(300300)},
        {busTime(296400),busTime(303000)},
        {busTime(303600),busTime(310500)},
        {busTime(307200),busTime(314100)},
        {busTime(312600),busTime(319200)},
        {busTime(321600),busTime(327600)},
        {busTime(327000),busTime(333000)},
        {busTime(334200),busTime(340200)},
        {busTime(361500),busTime(367200)},
        {busTime(362700),busTime(369300)},
        {busTime(363900),busTime(370500)},
        {busTime(366000),busTime(373200)},
        {busTime(367200),busTime(374700)},
        {busTime(368400),busTime(375000)},
        {busTime(370200),busTime(376800)},
        {busTime(372000),busTime(378600)},
        {busTime(373800),busTime(380400)},
        {busTime(375600),busTime(382200)},
        {busTime(379200),busTime(385800)},
        {busTime(380100),busTime(386700)},
        {busTime(382800),busTime(389400)},
        {busTime(390000),busTime(396900)},
        {busTime(393600),busTime(400500)},
        {busTime(399000),busTime(405600)},
        {busTime(408000),busTime(414000)},
        {busTime(413400),busTime(419400)},
        {busTime(420600),busTime(426600)},
        {busTime(454500),busTime(460800)},
        {busTime(461700),busTime(468000)},
        {busTime(468900),busTime(475260)},
        {busTime(476100),busTime(482400)},
        {busTime(483300),busTime(489600)},
        {busTime(490500),busTime(496800)},
        {busTime(497700),busTime(504000)},
        {busTime(504900),busTime(511200)},
        {busTime(540900),busTime(547200)},
        {busTime(548100),busTime(554400)},
        {busTime(555300),busTime(561660)},
        {busTime(562500),busTime(568800)},
        {busTime(569700),busTime(576000)},
        {busTime(576900),busTime(583200)},
        {busTime(584100),busTime(590400)},
        {busTime(591300),busTime(597600)}
    };

};
