#ifndef TWR_APRS_RADIO_H
#define TWR_APRS_RADIO_H

#include "modules/SA868.h"

class Radio {
public:
    enum Power { Low, High };

    Radio();
    void begin();
    void setVolume( uint8_t volume );
    void setPower( Power power );
    void transmit();
    void receive();
    void frequency( uint32_t frequency );
    bool apply();

private:
    SA868 radio;
    Power m_power;
    bool m_bandwidth;
    uint32_t m_frequency;
    uint8_t m_rx_cxcss;
    uint8_t m_tx_cxcss;
    uint8_t m_sq_level;
};


#endif //TWR_APRS_RADIO_H
