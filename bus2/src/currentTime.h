
class currentTime {
    struct tm * now;
    int secIntoWeek;
	time_t timeNow;
public:
	inline void update() {
        time_t t = time(0);
        now = localtime( & t );

        int fromSundayToMidnight = (((now->tm_wday-1)+7)%7)*24*60*60;
        int fromMidnightToHour = now->tm_hour*60*60;
        int fromHourToMinute = now->tm_min*60;
        int fromMinuteToSecond = now->tm_sec;

        secIntoWeek = fromSundayToMidnight + fromMidnightToHour  + fromHourToMinute + fromMinuteToSecond;
	}

     inline string ampm() {
        if (now->tm_hour > 11) {
            return "pm";
        } else {
            return "am";
        }
    }

    inline string timeStr() {
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
    inline int getSecondsFromWeek() {
        return secIntoWeek;
    }
};
