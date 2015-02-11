#include "weekLabels.h"

void weekLabels::setup(int _heightOfWeek) {
    heightOfWeek = _heightOfWeek;
    int heightOfDay = heightOfWeek/7;

    ghostSundayLabel.setup(-1, heightOfDay);
    mondayLabel.setup(0, heightOfDay);
    tuesdayLabel.setup(1, heightOfDay);
    wednesdayLabel.setup(2, heightOfDay);
    thursdayLabel.setup(3, heightOfDay);
    fridayLabel.setup(4, heightOfDay);
    saturdayLabel.setup(5, heightOfDay);
    sundayLabel.setup(6, heightOfDay);
    ghostMondayLabel.setup(7, heightOfDay);
}

void weekLabels::draw(int topOfViewPort) {
    ghostSundayLabel.draw(topOfViewPort);
    mondayLabel.draw(topOfViewPort);
    tuesdayLabel.draw(topOfViewPort);
    wednesdayLabel.draw(topOfViewPort);
    thursdayLabel.draw(topOfViewPort);
    fridayLabel.draw(topOfViewPort);
    saturdayLabel.draw(topOfViewPort);
    sundayLabel.draw(topOfViewPort);
    ghostMondayLabel.draw(topOfViewPort);

    ofPushMatrix();
    ofTranslate(ofGetWidth(), 0);
    ghostSundayLabel.draw(topOfViewPort);
    mondayLabel.draw(topOfViewPort);
    tuesdayLabel.draw(topOfViewPort);
    wednesdayLabel.draw(topOfViewPort);
    thursdayLabel.draw(topOfViewPort);
    fridayLabel.draw(topOfViewPort);
    saturdayLabel.draw(topOfViewPort);
    sundayLabel.draw(topOfViewPort);
    ghostMondayLabel.draw(topOfViewPort);
    ofPopMatrix();
}
