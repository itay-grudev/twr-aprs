#include "AFSK.h"
#include <Arduino.h>

#include "board_config.h"

union Byte {
    uint8_t _;
    bool bit[8];
};

void AFSK::send( std::string message  )
{
    // noInterrupts();
    for( uint8_t i = 0; i < message.length(); ++i ){
        Serial.print( message[i] );

        Byte byte = { message[i] };

        for( uint8_t i = 0; i < 8; ++i ){
            if( byte.bit[i] )
                ledcAttachPin( ESP2SA868_MIC, 0 );
            else
                ledcAttachPin( ESP2SA868_MIC, 1 );
            delay( 1 );
            ledcDetachPin( ESP2SA868_MIC );
        }
        
    }
    // interrupts();
}
