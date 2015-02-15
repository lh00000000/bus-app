#include "verticalScroller.h"
void verticalScroller::setup(int _heightOfWeek)
{
    heightOfWeek = _heightOfWeek;
}

void verticalScroller::update()
{
    if (vel > 150) vel = maxspeed;

    target += vel;
    vel *= drag;
    y = ofLerp(y, target, 0.8);

    if (target < 0 && y < 0)
    {
        target += heightOfWeek;
        y += heightOfWeek;
    }
    if (target > heightOfWeek && y > heightOfWeek)
    {
        target -= heightOfWeek;
        y -= heightOfWeek;
    }

}

void verticalScroller::mouseUpdate(int x,int y)
{
    mouse.update(x,y);
    target+= -mouse.getVel().y;
}

void verticalScroller::mouseRelease()
{
    drag =  0.97;
    vel = -mouse.getVel().y;
    
}

void verticalScroller::mousePress(int x, int y)
{
    mouse.initialPos = ofVec2f(x,y);
    mouse.prevPos = ofVec2f(x,y);
    mouse.currentPos = ofVec2f(x,y);
    drag =  0.1;
}

void verticalScroller::snap(float where)
{
    float distanceGoingUp;
    float distanceGoingDown;
    if (y > where) {
        distanceGoingUp = y - where;
        distanceGoingDown = (heightOfWeek-y) + where;
        if (distanceGoingUp < distanceGoingDown) {
            target = where;
        } else {
            target = where + heightOfWeek;
        }
    } else {
        // y < where
        distanceGoingUp = y + (heightOfWeek-where);
        distanceGoingDown = where - y;
        if (distanceGoingUp < distanceGoingDown) {
            target = where - heightOfWeek;
        } else {
            target = where;
        }
    }
    vel = 0;
    drag = 0;
}

float verticalScroller::getY()
{
    return y;
}

void verticalScroller::killVel() {
    vel = 0;
}

