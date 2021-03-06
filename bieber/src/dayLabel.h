#include <string>
#include "dayEnum.h"
#include "ofMain.h"
#include "fontRepo.h"

class dayLabel {
private:
    int dayIndex;
    std::string dayString;
    ofTrueTypeFont dayLabelFont;

    int topOfBox;
    int bottomOfBox;

    int labelX;
    int labelY;
    int buf = 36;

public:
    void setup(int dayi, int heightOfDay, fontRepo* allFonts);
    void draw(int topOfViewPort);
};
