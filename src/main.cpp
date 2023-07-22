#include <SPI.h>
#include <Arduino.h>

#include "PMU.h"
#include "Display.h"
#include "Radio.h"
#include "board_config.h"

PMU pmu;
Display display;
Radio radio;

void setup() {
    pinMode( MIC_CTRL_PIN, OUTPUT );
    digitalWrite( MIC_CTRL_PIN, LOW );

    // Initialize Serial communication
    Serial.begin( 115200 );
    delay( 1000 ); // Give the serial monitor some time to start
    Serial.println( "Bootoing up." );

    // Initialize the power management unit
    pmu = PMU();
    if( ! pmu.init() ){
        Serial.println( "Failed to initialize PMU." );
        while( true );
    }

    pmu.startRadio();
    pmu.startMic();

    radio.begin();
    radio.setVolume( 5 );
    radio.setPower( 1 ); // Low power

    // Initialize the display
    display = Display();
    display.homeScreen();
    Serial.println( "Boot complete." );
}

void loop() {

}