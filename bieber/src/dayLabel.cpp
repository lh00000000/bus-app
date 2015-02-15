#include "dayLabel.h"

#define MARGIN_FROM_TOP 45
#define MARGIN_FROM_BOTTOM 20

void dayLabel::setup(int dayi, int heightOfDay, fontRepo* allFonts) {
    dayLabelFont = allFonts->dayLabelFont;
    dayIndex = dayi;

    topOfBox = heightOfDay*dayi;
    bottomOfBox = topOfBox + heightOfDay;
    labelY = topOfBox;

    switch (dayIndex) {
        case MONDAY:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("monday") - 16;
            dayString = "monday";
            break;
        case TUESDAY:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("tuesday") - 16;
            dayString = "tuesday";
            break;
        case WEDNESDAY:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("wednesday") - 16;
            dayString = "wednesday";
            break;
        case THURSDAY:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("thursday") - 16;
            dayString = "thursday";
            break;
        case FRIDAY:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("friday") - 16;
            dayString = "friday";
            break;
        case SATURDAY:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("saturday") - 16;
            dayString = "saturday";
            break;
        case SUNDAY:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("sunday") - 16;
            dayString = "sunday";
            break;
        case -1:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("sunday") - 16;
            dayString = "sunday";
            break;
        case 7:
            labelX = ofGetWidth() - dayLabelFont.stringWidth("monday") - 16;
            dayString = "monday";
            break;

    }
}

void dayLabel::draw(int topOfViewPort) {
    labelY = bottomOfBox - MARGIN_FROM_BOTTOM;
    if (topOfViewPort + MARGIN_FROM_TOP < labelY) {
        labelY = topOfViewPort + MARGIN_FROM_TOP;
    }
    if (labelY < topOfBox + MARGIN_FROM_TOP - 10) {
        labelY = topOfBox + MARGIN_FROM_TOP - 10;
    }
    //}

    dayLabelFont.drawString(dayString, labelX, labelY);
}

