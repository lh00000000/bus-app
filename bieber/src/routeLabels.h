#include "ofMain.h"
#include "fontRepo.h"
#define LABELFROMBOTTOM 20
class routeLabels {
private:
    ofTrueTypeFont routeLabelFont;
public:
    void setup(fontRepo* allFonts);
    void draw(int bottomOfViewPort);
};
