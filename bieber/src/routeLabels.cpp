#include "routeLabels.h"
void routeLabels::setup(fontRepo* allFonts) {
    routeLabelFont.loadFont("helveticaneue.ttf",22);
    routeLabelFont = allFonts->routeLabelFont;
}

void drawArrow(int x1, int y1, int x2, int y2) {
    ofLine(x1, y1, x2, y2);
    ofFill();
    ofBeginShape();
    ofVertex(x2, y2);
    ofVertex(x2-3, y2-4);
    ofVertex(x2-3, y2+3);
    ofEndShape();
    
}

void routeLabels::draw(int bottomOfViewPort) {

    routeLabelFont.drawString("hellertown PABT", ofGetWidth()/2 - (136), bottomOfViewPort-LABELFROMBOTTOM);
    drawArrow(189, bottomOfViewPort - 28, 204, bottomOfViewPort - 28);
    routeLabelFont.drawString("PABT hellertown", ofGetWidth() + ofGetWidth()/2 - (136), bottomOfViewPort-LABELFROMBOTTOM);
    drawArrow(ofGetWidth() + 116 , bottomOfViewPort - 28, ofGetWidth() + 131 , bottomOfViewPort - 28);
}
