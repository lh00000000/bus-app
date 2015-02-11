#include "dayLabel.h"

#define MARGIN_FROM_TOP 58
#define MARGIN_FROM_BOTTOM 20

void dayLabel::setup(int dayi, int heightOfDay) {
    dayLabelFont.loadFont("./data/FreeSansBold.otf",36);
    dayIndex = dayi;

    topOfBox = heightOfDay*dayi;
    bottomOfBox = topOfBox + heightOfDay;
    labelY = topOfBox;

    switch (dayIndex) {
        case MONDAY:
            labelX = ofGetWidth() - 220;
            dayString = "monday";
            break;
        case TUESDAY:
            labelX = ofGetWidth() - 220;
            dayString = "tuesday";
            break;
        case WEDNESDAY:
            labelX = ofGetWidth() - 280;
            dayString = "wednesday";
            break;
        case THURSDAY:
            labelX = ofGetWidth() - 225;
            dayString = "thursday";
            break;
        case FRIDAY:
            labelX = ofGetWidth() - 180;
            dayString = "friday";
            break;
        case SATURDAY:
            labelX = ofGetWidth() - 220;
            dayString = "saturday";
            break;
        case SUNDAY:
            labelX = ofGetWidth() - 200;
            dayString = "sunday";
            break;
        case -1:
            labelX = ofGetWidth() - 200;
            dayString = "sunday";
            break;
        case 7:
            labelX = ofGetWidth() - 220;
            dayString = "monday";
            break;

    }
}

void dayLabel::draw(int topOfViewPort) {
    labelY = bottomOfBox - MARGIN_FROM_BOTTOM;
    if (topOfViewPort + MARGIN_FROM_TOP < labelY) {
        labelY = topOfViewPort + MARGIN_FROM_TOP;
    }
    if (labelY < topOfBox + MARGIN_FROM_TOP) {
        labelY = topOfBox + MARGIN_FROM_TOP;
    }
    //}

    dayLabelFont.drawString(dayString, labelX, labelY);
}

