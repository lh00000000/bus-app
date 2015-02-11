#include "ofMain.h"
#include "currentTime.h"

class timeCursor {
private:
    ofTrueTypeFont timeCursorFont;
    currentTime currenttime;
    float y;
    int heightOfWeek;

public:
    void setup(int _heightOfWeek);
    void update();
    void draw();

    float getY();
};
