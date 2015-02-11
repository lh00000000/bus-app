#include "weekTrips.h"
void weekTrips::setup(int _heightOfWeek) {
    heightOfWeek = _heightOfWeek;

    fromLocationFont.loadFont("./data/FreeSans.otf",10);
    fromTimeFont.loadFont("./data/FreeSansBold.otf",24);
    fromTimeAMPMFont.loadFont("./data/FreeSansBold.otf",12);

    toLocationFont.loadFont("./data/FreeSans.otf",14);
    toTimeFont.loadFont("./data/FreeSansBold.otf",22);
    toTimeAMPMFont.loadFont("./data/FreeSans.otf",10);
}

void weekTrips::draw(int topOfViewPort, int bottomOfViewPort) {
    drawHellertownToPABT(topOfViewPort, bottomOfViewPort);
    ofPushMatrix();
    ofTranslate(ofGetWidth(),0);
    drawPABTtoHellertown(topOfViewPort, bottomOfViewPort);
    ofPopMatrix();
}


void weekTrips::drawPABTtoHellertown(int topOfViewPort, int bottomOfViewPort) {
    ///////trips///////
    ofPushStyle();
    ofSetColor(255);
    for (int i = 0; i < NUM_ROUTES; i++) {
        int leaveTimeX = ofGetWidth()/3;
        int leaveTimeY = ofMap(data.toHellertown[i].startTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);
        int arriveTimeX = ofGetWidth()*2/3;
        int arriveTimeY = ofMap(data.toHellertown[i].endTime.secondsFromSunday, 0, 24*60*60*7, 0, heightOfWeek);

        if (arriveTimeY < topOfViewPort) continue;
        if (leaveTimeY > bottomOfViewPort) break;


        if (data.toHellertown[i].endTime.hour() == 8 &&
            data.toHellertown[i].endTime.minute() == 10) {
            arriveTimeY = arriveTimeY + 15;
        }

        int leaveOpacity = ofClamp((leaveTimeY+FADEOFFSET)-(topOfViewPort), 30,255);
        int arriveOpacity = ofClamp((arriveTimeY+FADEOFFSET)-(topOfViewPort), 20,255);
        int lineOpacity = (leaveOpacity + arriveOpacity)/2;

        ofPushStyle();
        ofSetColor(255,leaveOpacity);
        ofSetLineWidth(.5);
        ofLine(0,leaveTimeY, leaveTimeX,leaveTimeY);
        ofCircle(leaveTimeX,leaveTimeY,3);
        toLocationFont.drawString("   PABT:", 0, leaveTimeY-2);
        fromTimeFont.drawString(data.toHellertown[i].startTime.timeStr(), 87, leaveTimeY-2);
        fromTimeAMPMFont.drawString(data.toHellertown[i].startTime.ampm(), leaveTimeX-33, leaveTimeY-2);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,lineOpacity);
        //line from leave to arrive
        ofSetLineWidth(2);
        ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,(arriveTimeY)-topOfViewPort);

        ofSetLineWidth(.5);
        ofLine(arriveTimeX, arriveTimeY, ofGetWidth(), arriveTimeY);
        ofCircle(arriveTimeX,arriveTimeY,3);
        toTimeFont.drawString(data.toHellertown[i].endTime.timeStr(), arriveTimeX+4, arriveTimeY-2);
        toTimeAMPMFont.drawString(data.toHellertown[i].endTime.ampm(), arriveTimeX+90, arriveTimeY-2);
        fromLocationFont.drawString(" hellertown", arriveTimeX + 120, arriveTimeY-2);
        ofPopStyle();

    }
    ofPopStyle();
}
void weekTrips::drawHellertownToPABT(int topOfViewPort, int bottomOfViewPort) {

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

        int leaveOpacity = ofClamp((leaveTimeY+FADEOFFSET)-topOfViewPort, 30,255);
        int arriveOpacity = ofClamp((arriveTimeY+FADEOFFSET)-topOfViewPort, 20,255);
        int lineOpacity = (leaveOpacity + arriveOpacity)/2;

        ofSetColor(255,leaveOpacity);
        //line under fromLocation
        ofSetLineWidth(.5);
        ofLine(0,leaveTimeY, leaveTimeX,leaveTimeY);
        ofCircle(leaveTimeX,leaveTimeY,3);
        fromLocationFont.drawString("  hellertown:", 0, leaveTimeY-2);
        fromTimeFont.drawString(data.toPABT[i].startTime.timeStr(), 87, leaveTimeY-2);
        fromTimeAMPMFont.drawString(data.toPABT[i].startTime.ampm(), leaveTimeX-33, leaveTimeY-2);
        ofPopStyle();


        ofPushStyle();
        ofSetColor(255, lineOpacity);
        //line from leave to arrive
        ofSetLineWidth(2);
        ofLine(leaveTimeX, leaveTimeY, arriveTimeX, arriveTimeY);
        ofPopStyle();

        ofPushStyle();
        ofSetColor(255,arriveOpacity);
        ofSetLineWidth(.5);
        ofLine(arriveTimeX, arriveTimeY, ofGetWidth(), arriveTimeY);
        ofCircle(arriveTimeX,arriveTimeY,3);


        toTimeFont.drawString(data.toPABT[i].endTime.timeStr(), arriveTimeX+4, arriveTimeY-2);
        toTimeAMPMFont.drawString(data.toPABT[i].endTime.ampm(), arriveTimeX+90, arriveTimeY-2);
        toLocationFont.drawString(" PABT", arriveTimeX + 110, arriveTimeY-2);
        ofPopStyle();

    }
    ofPopStyle();
}
