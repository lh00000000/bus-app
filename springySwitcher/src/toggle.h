


struct springyToggle {
    float position=.5;
    float positionSmoothed = .5;
    float velocity=0;
    float acceleration=0;
    float mass=300;
    float drag = .9;
    float k = 0.4;
    float maxspeed = .1;
    void update() {
        acceleration *= 1.0/mass;
        velocity += acceleration;
        bound();
        position += velocity;
        bound();
        velocity *= drag;
        bound();
        positionSmoothed = ofLerp(positionSmoothed, position, 0.5);
    }

    void applySprings() {
        float leftSpring = -k*position;
        float rightSpring = -k*(position-1);
        acceleration += -leftSpring - rightSpring;
    }
    void bound() {
        if (position < 0) position = 0;
        if (position > 1) position = 1;
        if (velocity > maxspeed) velocity = maxspeed;
        if (velocity < -maxspeed) velocity = -maxspeed;
    }
    bool isOn() {
        if (position > .97) return true;
        if (position < .03) return false;
    }
    void push(float d) {
        position += d;
        bound();
    }
};

struct dragEvent {
    ofVec2f a;
    ofVec2f b;
    ofVec2f getVel() {
        ofVec2f del = b-a;
        a = b;
        return del;
    }
    ofVec2f getDel() {
        return b-a;
    }
};

struct toggleSystem {
    struct springyToggle tog;
    struct dragEvent drag;
    struct dragEvent fling;
    float mouseMass = 800;

    void update() {
        if (!ofGetMousePressed()) {
            tog.applySprings();
        }
        tog.update();
        cout << drag.getDel() << endl;
    }


    void mousePressed(int x, int y) {
        //cout << "mouse pressed" <<endl;
        drag.a = ofVec2f(x,y);
        drag.b = drag.a;
        fling.a = ofVec2f(x,y);
    }

    void mouseReleased(int x, int y) {
        tog.velocity = fling.getVel().x/mouseMass;
    }

    void mouseDragged( int x , int y ) {

        drag.b = ofVec2f(x,y);

        fling.b = ofVec2f(x,y);

        tog.push(ofMap(drag.getVel().x, -(ofGetWidth() - 400)/4, (ofGetWidth() - 400)/4, -.25, .25));

    }

    float position() {
        return tog.positionSmoothed;
    }
};
