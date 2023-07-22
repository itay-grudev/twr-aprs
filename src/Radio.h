#ifndef TWR_APRS_RADIO_H
#define TWR_APRS_RADIO_H

#include "modules/SA868.h"

class Radio {
public:
    Radio();
    void begin();
    void setVolume( uint8_t volume );
    void setPower( uint8_t power );
    void transmit();
    void receive();

private:
    SA868 radio;
};


#endif //TWR_APRS_RADIO_H
