#include "horizontalScroller.h"
void horizontalScroller::setup() {
    isLeftPosition = true;
    update();
}

void horizontalScroller::update() {
    if (isLeftPosition) targetx = 0;
    else targetx = ofGetWidth();
    x = ofLerp(x, targetx, 0.5);
}


void horizontalScroller::toggle() {
    isLeftPosition = !isLeftPosition;
}

float horizontalScroller::getX() {
    return x;
}
