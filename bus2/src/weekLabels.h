#include "dayLabel.h"

class weekLabels {
    dayLabel ghostSundayLabel;
    dayLabel mondayLabel;
    dayLabel tuesdayLabel;
    dayLabel wednesdayLabel;
    dayLabel thursdayLabel;
    dayLabel fridayLabel;
    dayLabel saturdayLabel;
    dayLabel sundayLabel;
    dayLabel ghostMondayLabel;

    int heightOfWeek;
 public:
     void setup(int heightOfWeek);
     void draw(int topOfViewPort);
};
