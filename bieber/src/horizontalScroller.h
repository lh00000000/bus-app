#include "ofMain.h"
class horizontalScroller {
private:
    bool isLeftPosition;
    float x;
    float targetx;
public:
    void setup();
    void update();
    void draw();
    float getX();
    void toggle();

};
