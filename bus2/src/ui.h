

struct centerOfView {
    ofVec2f pos = ofVec2f(0,0);
    ofVec2f target = ofVec2f(0,0);
    ofVec2f vel = ofVec2f(0,0);
    float mass = 60;
    float drag = .92;
    float maxspeed = 10;


    void update() {
        if (vel.length() > 30) {
            vel.normalize();
            vel.scale(maxspeed);
        }

        target += vel;
        vel *= drag;
        pos.interpolate(target, 0.2);
        //pos = target;

        if (vel.length() < .0001) {
            if (target.x < 0) target.x = ofGetWidth();
            if (target.x > ofGetWidth()) target.x = 0;
            if (target.y < 0) target.y += ofGetHeight();
            if (target.y > ofGetHeight()) target.y -= ofGetHeight();


            if (pos.x < 0) pos.x = ofGetWidth();
            if (pos.x > ofGetWidth()) pos.x = 0;
            if (pos.y < 0) pos.y += ofGetHeight();
            if (pos.y > ofGetHeight()) pos.y -= ofGetHeight();
        }
    }
};

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

};
