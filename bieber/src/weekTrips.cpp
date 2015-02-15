#include "weekTrips.h"
#define PRELOAD_BUFFER 50
#define HEIGHT 568
void weekTrips::setup(int _heightOfWeek, fontRepo *allFonts) {
    heightOfWeek = _heightOfWeek;

    fromLocationFont = allFonts->locationAFont;
    fromTimeFont = allFonts->timeAFont;
    fromTimeAMPMFont = allFonts->ampmAFont;

    toLocationFont = allFonts->locationBFont;
    toTimeFont = allFonts->timeBFont;
    toTimeAMPMFont = allFonts->ampmBFont;
}

void weekTrips::draw(int topOfViewPort, int bottomOfViewPort) {
    drawHellertownToPABT(topOfViewPort, bottomOfViewPort);
    drawPABTtoHellertown(topOfViewPort, bottomOfViewPort);
}

int fadeNearEdges(int y, int topOfViewport) {
    return ofMap(abs(y - (topOfViewport+HEIGHT/2)), (HEIGHT/2)-100, HEIGHT/2, 255, 20,true);
}

void weekTrips::drawPABTtoHellertown(int topOfViewPort, int bottomOfViewPort) {
    ///////trips///////
    bottomOfViewPort += PRELOAD_BUFFER;
    ofPushStyle();
    ofSetColor(255);
    for (int i = 0; i < NUM_ROUTES; i++) {
        int leaveTimeX = ofGetWidth()/3 + ofGetWidth();
        int leaveTimeY = ofMap(data.toHellertown[i].startTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);
        int arriveTimeX = ofGetWidth()*2/3 + ofGetWidth();
        int arriveTimeY = ofMap(data.toHellertown[i].endTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);
        
        if (arriveTimeY < topOfViewPort) continue;
        if (leaveTimeY > bottomOfViewPort) break;


        if (data.toHellertown[i].endTime.hour() == 8 &&
            data.toHellertown[i].endTime.minute() == 10) {
            arriveTimeY = arriveTimeY + 15;
        }

        int leaveOpacity = fadeNearEdges(leaveTimeY, topOfViewPort);
        int arriveOpacity = fadeNearEdges(arriveTimeY, topOfViewPort);
        int lineOpacity = (leaveOpacity + arriveOpacity)/2;

        ofPushStyle();
        ofSetColor(255,leaveOpacity);
        ofSetLineWidth(1);
        ofLine(ofGetWidth(),leaveTimeY, leaveTimeX,leaveTimeY);
        ofCircle(leaveTimeX,leaveTimeY,2);
        /*toLocationFont.drawString("   PABT:", 0, leaveTimeY-2);
        fromTimeFont.drawString(data.toHellertown[i].startTime.timeStr(), 87, leaveTimeY-2);
        fromTimeAMPMFont.drawString(data.toHellertown[i].startTime.ampm(), leaveTimeX-33, leaveTimeY-2);*/
        fromTimeFont.drawString(data.toHellertown[i].startTime.timeStr(), ofGetWidth() + 2, leaveTimeY-2);
        fromTimeAMPMFont.drawString(data.toHellertown[i].startTime.ampm(), leaveTimeX-21, leaveTimeY-2);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,lineOpacity);
        //line from leave to arrive
        ofSetLineWidth(2);
        ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,arriveOpacity);

        ofSetLineWidth(1);
        ofLine(arriveTimeX, arriveTimeY, ofGetWidth()*2, arriveTimeY);
        ofCircle(arriveTimeX,arriveTimeY,2);
        //toTimeFont.drawString(data.toHellertown[i].endTime.timeStr(), arriveTimeX+4, arriveTimeY-2);
        //toTimeAMPMFont.drawString(data.toHellertown[i].endTime.ampm(), arriveTimeX+90, arriveTimeY-2);
        
        toTimeFont.drawString(data.toHellertown[i].endTime.timeStr(), arriveTimeX+2, arriveTimeY-2);
        toTimeAMPMFont.drawString(data.toHellertown[i].endTime.ampm(), arriveTimeX + toTimeFont.stringWidth("AAAA"), arriveTimeY-2);
        //fromLocationFont.drawString(" hellertown", arriveTimeX + 120, arriveTimeY-2);
        ofPopStyle();

    }
    ofPopStyle();
}
void weekTrips::drawHellertownToPABT(int topOfViewPort, int bottomOfViewPort) {
        bottomOfViewPort += PRELOAD_BUFFER;
    ///////trips///////
    ofPushStyle();
    ofSetColor(255);
    for (int i = 0; i < NUM_ROUTES; i++) {
        int leaveTimeX = ofGetWidth()/3;
        int leaveTimeY = ofMap(data.toPABT[i].startTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);
        int arriveTimeX = ofGetWidth()*2/3;
        int arriveTimeY = ofMap(data.toPABT[i].endTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);

        if (arriveTimeY < topOfViewPort) continue;
        if (leaveTimeY > bottomOfViewPort) break;


        if (data.toPABT[i].endTime.hour() == 8 &&
            data.toPABT[i].endTime.minute() == 10) {
            arriveTimeY = arriveTimeY + 15;
        }
        ofPushStyle();
        
        //int leaveOpacity = ofClamp((leaveTimeY+FADEOFFSET)-topOfViewPort, 30,255);
        int leaveOpacity = fadeNearEdges(leaveTimeY, topOfViewPort);
        int arriveOpacity = fadeNearEdges(arriveTimeY, topOfViewPort);
        int lineOpacity = (leaveOpacity + arriveOpacity)/2;

        ofSetColor(255,leaveOpacity);
        //line under fromLocation
        ofSetLineWidth(1);
        ofLine(0,leaveTimeY, leaveTimeX,leaveTimeY);
        ofCircle(leaveTimeX,leaveTimeY,2);
        //fromLocationFont.drawString("hellertown:", 0, leaveTimeY-2);
        fromTimeFont.drawString(data.toPABT[i].startTime.timeStr(), 2, leaveTimeY-2);
        fromTimeAMPMFont.drawString(data.toPABT[i].startTime.ampm(), leaveTimeX-21, leaveTimeY-2);
        ofPopStyle();


        ofPushStyle();
        ofSetColor(255, lineOpacity);
        //line from leave to arrive
        ofSetLineWidth(2);
        ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,arriveOpacity);
        ofSetLineWidth(1);
        ofLine(arriveTimeX, arriveTimeY, ofGetWidth(), arriveTimeY);
        ofCircle(arriveTimeX,arriveTimeY,2);


        toTimeFont.drawString(data.toPABT[i].endTime.timeStr(), arriveTimeX+2, arriveTimeY-2);
        toTimeAMPMFont.drawString(data.toPABT[i].endTime.ampm(), arriveTimeX + toTimeFont.stringWidth("AAAA"), arriveTimeY-2);
        //toLocationFont.drawString(" PABT", arriveTimeX + 110, arriveTimeY-2);
        ofPopStyle();

    }
    ofPopStyle();
}
