#include "weekLabels.h"

void weekLabels::setup(int _heightOfWeek, fontRepo* allFonts) {
    heightOfWeek = _heightOfWeek;
    int heightOfDay = heightOfWeek/7;

    ghostSundayLabel.setup(-1, heightOfDay, allFonts);
    mondayLabel.setup(0, heightOfDay, allFonts);
    tuesdayLabel.setup(1, heightOfDay, allFonts);
    wednesdayLabel.setup(2, heightOfDay, allFonts);
    thursdayLabel.setup(3, heightOfDay, allFonts);
    fridayLabel.setup(4, heightOfDay, allFonts);
    saturdayLabel.setup(5, heightOfDay, allFonts);
    sundayLabel.setup(6, heightOfDay, allFonts);
    ghostMondayLabel.setup(7, heightOfDay, allFonts);
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
