#include "doubleClick.h"

bool doubleClick::click() {
    bool isDoubleClick;
    int currentClickTime = ofGetElapsedTimeMillis();

    if (currentClickTime - lastClickTime < DOUBLE_CLICK_MAX_TIME) isDoubleClick = true;
    else isDoubleClick = false;

    lastClickTime = currentClickTime;
    return isDoubleClick;
}
