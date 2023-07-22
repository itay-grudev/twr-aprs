#ifndef TWR_APRS_DISPLAY_H
#define TWR_APRS_DISPLAY_H

#include <Wire.h>
#include <U8g2lib.h>

#include "board_config.h"

class Display {
public:
    Display();

    void homeScreen();

private:
    DISPLAY_CLASS u8g2;
};


#endif //TWR_APRS_DISPLAY_H
