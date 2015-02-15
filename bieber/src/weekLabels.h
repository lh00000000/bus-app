#include "dayLabel.h"
#include "fontRepo.h"
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
     void setup(int heightOfWeek, fontRepo* allFonts);
     void draw(int topOfViewPort);
};
