#include "tripData.h"
#define FADEOFFSET 20
class weekTrips {
private:
    int heightOfWeek;
    tripData data;

    ofTrueTypeFont fromLocationFont;
    ofTrueTypeFont fromTimeFont;
    ofTrueTypeFont fromTimeAMPMFont;

    ofTrueTypeFont toLocationFont;
    ofTrueTypeFont toTimeFont;
    ofTrueTypeFont toTimeAMPMFont;

    void drawPABTtoHellertown(int topOfViewPort, int bottomOfViewPort);
    void drawHellertownToPABT(int topOfViewPort, int bottomOfViewPort);


public:
    void setup(int _heightOfWeek);
    void draw(int topOfViewPort, int bottomOfViewPort);
};
