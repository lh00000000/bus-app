//
//  fonts.h
//  bieber
//
//  Created by Luming Hao on 2/14/15.
//
//
#include "ofMain.h"
#ifndef bieber_fonts_h
#define bieber_fonts_h

class fontRepo {
public:
    ofTrueTypeFont dayLabelFont;
    ofTrueTypeFont littleTimeFont;
    ofTrueTypeFont routeLabelFont;
    
    ofTrueTypeFont locationAFont;
    ofTrueTypeFont timeAFont;
    ofTrueTypeFont ampmAFont;
    ofTrueTypeFont locationBFont;
    ofTrueTypeFont timeBFont;
    ofTrueTypeFont ampmBFont;
    
    fontRepo();
    
};


#endif
