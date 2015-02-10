#pragma once

#include "ofMain.h"
     struct paletteCheerUpEmoKid {
        ofColor mightySlate = ofColor(85,98,112);
        ofColor pacifica = ofColor(78,205,196);
        ofColor appleChic = ofColor(199,244,100);
        ofColor cheeryPink = ofColor(255,107.107);
        ofColor grandmasPillow = ofColor(196,77,88);
    };

     struct paletteLetThemEatCake {
        ofColor banquette = ofColor(119,79,56);
        ofColor strawBerrySugar = ofColor(224,142,121);
        ofColor cremeDeLaCreme = ofColor(241,212,175);
        ofColor powderpuff = ofColor(236,229,206);
        ofColor charlotte = ofColor(197,224,220);
    };

class ofApp : public ofBaseApp{

    struct leftColorPalette {
        ofColor monday = ofColor(85,98,112);
        ofColor tuesday = ofColor(78,205,196);
        ofColor wednesday = ofColor(199,244,100);
        ofColor thursday = ofColor(255,107.107);
        ofColor friday = ofColor(196,77,88);
        ofColor saturday = ofColor(224,142,121);
        ofColor sunday = ofColor(119,79,56);
    } leftColors;


    struct rightColorPalette {
        ofColor monday = ofColor(85,98,112);
        ofColor tuesday = ofColor(78,205,196);
        ofColor wednesday = ofColor(199,244,100);
        ofColor thursday = ofColor(255,107.107);
        ofColor friday = ofColor(196,77,88);
        ofColor saturday = ofColor(224,142,121);
        ofColor sunday = ofColor(119,79,56);
    } rightColors;





    enum day{
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, NUM_DAYS
    };


	public:
		void setup();
		void update();
		void draw();

		vector<ofRectangle> leftDays;
		vector<ofRectangle> rightDays;


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
