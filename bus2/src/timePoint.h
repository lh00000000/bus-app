#include <string>
#include "ofMain.h"
struct timePoint {
    int secondsFromSunday;
    int secondsFromClosestMidnight;
    int hoursIntoDay;
    int minutesIntoHour;
    timePoint(int time) {
        int secsInADay = 24*60*60;
        secondsFromSunday = time;
        secondsFromClosestMidnight = time % secsInADay;
        hoursIntoDay = secondsFromClosestMidnight / (60*60);
        minutesIntoHour = (secondsFromClosestMidnight % (60*60))/60;
    }

    int hour() {
        return hoursIntoDay;
    }

    int minute() {
        return minutesIntoHour;
    }

    std::string ampm() {
        if (hour() > 11) return "pm";
        else return "am";
    }

    std::string timeStr() {
        if (hour() == 0 && minute() == 0) {
            return "midnight";
        } else if (hour() == 24 && minute() == 0) {
            return "midnight";
        } else if (hour() == 12 && minute() == 0) {
            return "noon";
        } else {
            if (hour()%12 == 0)
                return ofToString(12,0,2,' ') + ":" + ofToString(minute(),0,2,'0');
            else
                return ofToString(hour()%12,0,2,' ') + ":" + ofToString(minute(),0,2,'0');
        }

    }
};
