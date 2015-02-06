

enum day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, NUM_DAYS
};



struct currentTimeCursor {
    struct tm * now;
    int secIntoWeek;

	time_t timeNow;
	void update() {
        time_t t = time(0);   // get time now
        now = localtime( & t );

        int fromSundayToMidnight = (((now->tm_wday-1)+7)%7)*24*60*60;
        int fromMidnightToHour = now->tm_hour*60*60;
        int fromHourToMinute = now->tm_min*60;
        int fromMinuteToSecond = now->tm_sec;

        secIntoWeek = fromSundayToMidnight + fromMidnightToHour  + fromHourToMinute + fromMinuteToSecond;
	}

    string ampm() {
        if (now->tm_hour > 11) {
            return "pm";
        } else {
            return "am";
        }
    }

    string timeStr() {
        if (now->tm_min == 0) {
            if (now->tm_hour == 0)
                return "midnight";
            else if (now->tm_hour == 12)
                return "noon";
        } else {
            if (now->tm_hour%12 == 0)

                return ofToString(now->tm_hour,0,2,' ') + ":" + ofToString(now->tm_min,0,2,'0') + ampm();
            else
                return ofToString(now->tm_hour%12,0,2,' ') + ":" + ofToString(now->tm_min,0,2,'0') + ampm();
        }
    }
};


struct dayLabel {
    int dayIndex;
    int topOfBox;
    int bottomOfBox;
    int labelX;
    int labelY;
    int buf = 36;
    int dayString;
    dayLabel(int dayi, int heightOfDay) {
        dayIndex = dayi;
        int heightOfHour = heightOfDay/24;
        topOfBox = heightOfDay*dayi;
        bottomOfBox = topOfBox + heightOfDay - 54;
        labelY = topOfBox;

        switch (dayIndex) {
            case MONDAY:
                labelX = ofGetWidth() - 220;
                break;
            case TUESDAY:
                labelX = ofGetWidth() - 220;
                break;
            case WEDNESDAY:
                labelX = ofGetWidth() - 280;
                break;
            case THURSDAY:
                labelX = ofGetWidth() - 225;
                break;
            case FRIDAY:
                labelX = ofGetWidth() - 180;
                break;
            case SATURDAY:
                labelX = ofGetWidth() - 220;
                break;
            case SUNDAY:
                labelX = ofGetWidth() - 200;
                break;

        }

    }
    void update(int camYPos) {
        int marginFromTopOfWindow=30;
        int marginFromTopOfDay = 48;
        if (camYPos + marginFromTopOfWindow < topOfBox) {
            labelY = topOfBox + marginFromTopOfDay;
        } else if (camYPos + marginFromTopOfWindow > topOfBox && camYPos + marginFromTopOfWindow < bottomOfBox) {
            labelY = camYPos + marginFromTopOfWindow + marginFromTopOfDay;
        }
    }

    void draw() {
    }

};
