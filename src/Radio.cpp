#include "Radio.h"

#include <Arduino.h>
#include "board_config.h"

Radio::Radio() : radio( Serial1, SA868_PTT_PIN, SA868_PD_PIN, SA868_RF_PIN )
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

void Radio::setPower( uint8_t power )
{
    switch( power ){
        case 1:
           radio.lowPower();
        case 2:
           radio.highPower();
    }
}

void Radio::transmit()
{
    radio.transmit();
}

void Radio::receive()
{
    radio.receive();
}