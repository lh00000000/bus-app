#include "routeLabels.h"
void routeLabels::setup() {
    routeLabelFont.loadFont("./data/FreeSansBold.otf",22);
}

void routeLabels::draw(int topOfViewPort) {
    routeLabelFont.drawString("hellertown>PABT", 20, topOfViewPort+LABELFROMTOP);
    routeLabelFont.drawString("PABT>hellertown", 20 + ofGetWidth(), topOfViewPort+LABELFROMTOP);
}
