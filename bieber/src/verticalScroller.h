#include "ofMain.h"
class verticalScroller {

    struct mouseToss {
        ofVec2f initialPos;
        ofVec2f prevPos;
        ofVec2f currentPos;
        float mass = 16.0;

        void update(int x, int y) {
            prevPos = currentPos;
            currentPos = ofVec2f(x,y);
        }
        ofVec2f getVel() {
            return currentPos - prevPos;
        }
        ofVec2f getDelta() {
            return currentPos - initialPos;
        }

    } mouse;

    float y;
    float target;
    float vel;

    float mass = 60;
    float drag = .92;
    float maxspeed = 100;

    int heightOfWeek;
public:
    void setup(int heightOfWeek);
    void update();
    void draw();

    void mousePress(int x, int y);
    void mouseUpdate(int x,int y); //toss.update(x,y);
    void mouseRelease();

    void snap(float where);

    float getY();
    void killVel();
};
