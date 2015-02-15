#include "ofMain.h"
#include "dayEnum.h"
#include "fontRepo.h"
class weekGrid {
private:
    int heightOfWeek;
    int heightOfDay;

    ofTrueTypeFont hourLabelFont;
    void drawOneDay(int r, int g, int b, int brightnessDiff);
    void drawOneWeek(int topOfViewPort, int bottomOfViewPort);
public:
    void setup(int _heightOfWeek, fontRepo *allFonts);
    void update();
    void draw(int topOfViewPort, int bottomOfViewPort);
};
