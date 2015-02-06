
struct busTime {
    int secondsFromSunday;
    int secondsFromClosestMidnight;
    int hoursIntoDay;
    int minutesIntoHour;
    busTime(int time) {
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

    string ampm() {
        if (hour() > 11) return "pm";
        else return "am";
    }
    string timeStr() {
        if (hour() == 0 && minute() == 0) {
            return "midnight";
        } else if (hour() == 24 && minute() == 0) {
            return "midnight";
        } else if (hour() == 12 && minute() == 0) {
            return "noon";
        } else {
            if (hour()%12 == 0)
                return ofToString(hour(),0,2,' ') + ":" + ofToString(minute(),0,2,'0');
            else
                return ofToString(hour()%12,0,2,' ') + ":" + ofToString(minute(),0,2,'0');
        }

    }
};

struct tripTime {
    busTime startTime;
    busTime endTime;
};
