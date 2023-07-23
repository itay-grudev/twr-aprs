#include "Radio.h"

#include <Arduino.h>
#include "board_config.h"

Radio::Radio()
    : radio( Serial1, SA868_PTT_PIN, SA868_PD_PIN, SA868_RF_PIN ), m_bandwidth( 1 ), m_frequency( 144e6 ), m_rx_cxcss( 0 ), m_tx_cxcss( 0 ), m_sq_level( 2 )
{
}

void Radio::begin()
{
    radio.begin();
}

void Radio::setVolume( uint8_t volume )
{
    radio.setVolume( volume );
}

void Radio::setPower( Power power )
{
    m_power = power;
    switch( power ){
        case Power::Low:
           radio.lowPower();
           break;
        case Power::High:
           radio.highPower();
           break;
    }
}

void Radio::frequency( uint32_t frequency )
{
    m_frequency = frequency;
}

bool Radio::apply()
{
    // Setting bandwidth to 0 for some reason crashes the device.
    // Is the protocol incorrectly documented?
    return radio.setGroup( m_bandwidth, m_frequency, m_frequency, (teCXCSS)m_tx_cxcss, m_sq_level, (teCXCSS)m_rx_cxcss );
}

void Radio::transmit()
{
    radio.transmit();
}

void Radio::receive()
{
    radio.receive();
}