#include <SPI.h>
#include <Arduino.h>

#include "PMU.h"
#include "Display.h"
#include "board_config.h"

PMU *pmu;
Display *display;

void setup() {
    pinMode( MIC_CTRL_PIN, OUTPUT );
    digitalWrite( MIC_CTRL_PIN, LOW );

    // Initialize Serial communication
    Serial.begin( 115200 );
    delay( 1000 ); // Give the serial monitor some time to start
    Serial.println( "Bootoing up." );

    // Initialize the power management unit
    pmu = new PMU();
    if( ! pmu->init() ){
        Serial.println( "Failed to initialize PMU." );
        while( true );
    }

    // Initialize the display
    display = new Display();
    display->homeScreen();
    Serial.println( "Boot complete." );
}

void loop() {

}