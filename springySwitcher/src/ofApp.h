#pragma once

#include "ofMain.h"

struct attractor {
	ofVec2f pos;
	float mass=100;
	float maxForce=10000;
	float minDistance=60;
	ofVec2f getForce(ofVec2f point) {
		ofVec2f force = pos - point;
		force.normalize();

		force.scale(mass/(point.distance(pos)));
		if (force.length() > maxForce) {
			force.normalize();
			force.scale(maxForce);
		}
		if (point.distance(pos)<minDistance) {
			force.scale(0);
		}
		return force;
	}
	void draw() {
		ofRect(pos, 10, 10);
	}
};

struct particle {
    ofVec2f pos = ofVec2f(0,0);
    ofVec2f target = ofVec2f(0,0);
    ofVec2f vel = ofVec2f(0,0);
    ofVec2f accel = ofVec2f(0,0);
    float mass = 10;
    float drag = .7;
    float maxspeed = 10;
    float radius = 50;

    void update() {
        if (vel.length() > 30000) {
            vel.normalize();
            vel.scale(maxspeed);
        }

/*	        if (target.x < 0) target.x = ofGetWidth();
        if (target.x > ofGetWidth()) target.x = 0;
        if (target.y < 0) target.y = ofGetHeight();
        if (target.y > ofGetHeight()) target.y = 0;*/

        vel += accel;
        target += vel;
        vel *= drag;
        pos.interpolate(target, 0.5);
        accel.scale(0);

/*	        if (pos.x < 0) pos.x = ofGetWidth();
        if (pos.x > ofGetWidth()) pos.x = 0;
        if (pos.y < 0) pos.y = ofGetHeight();
        if (pos.y > ofGetHeight()) pos.y = 0;*/
    }

    void applyForce(ofVec2f f) {
    	accel += f;
    }

    void moveTo(ofVec2f p) {
    	ofVec2f prevVel = vel;
    	vel = p - pos;
    	accel = vel - prevVel;
    	pos = p;
    }

    void draw() {
    	ofCircle(pos.x, pos.y, radius);
    }

    bool isHit(ofVec2f point) {
    	if (point.distance(pos) <= radius)
    		return true;
    	else
    		return false;
    }
};


class ofApp : public ofBaseApp{
	/*struct particle ball;
	struct attractor rightAttractor;
	struct attractor leftAttractor;
*/
	//struct particle mouseParticle;


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

};
