//
//  fontRepo.cpp
//  bieber
//
//  Created by Luming Hao on 2/14/15.
//
//

#include "fontRepo.h"
#include <stdio.h>

fontRepo::fontRepo() {
    dayLabelFont.loadFont("helveticaneue.ttf", 30);
    littleTimeFont.loadFont("helveticaneue.ttf",8);;
    routeLabelFont.loadFont("helveticaneue.ttf",26);
    
    locationAFont.loadFont("helveticaneue.ttf",10);
    timeAFont.loadFont("helveticaneue.ttf",24);
    ampmAFont.loadFont("helveticaneue.ttf",10);
    
    locationBFont.loadFont("helveticaneue.ttf",14);
    timeBFont.loadFont("helveticaneue.ttf",22);
    ampmBFont = ampmAFont;
}