#include "ofMain.h"
#define DOUBLE_CLICK_MAX_TIME 600
class doubleClick {
private:
    long lastClickTime;
public:
    bool click();
};
