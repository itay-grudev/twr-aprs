#include <SPI.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h> 
#include "driver/sdm.h"

#include "Radio.h"
#include "PMU.h"
#include "Display.h"
#include "protocols/AFSK.h"
#include "board_config.h"
#include "config.h"

PMU *pmu;
Display *display;
Radio *radio;
AFSK *afsk;
Adafruit_NeoPixel strip(1, PIXELS_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
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

    pmu->startRadio();
    pmu->startMic();

    // Radio
    radio = new Radio();
    radio->begin();
    radio->frequency( FREQUENCY );
    radio->setVolume( 1 );
    radio->setPower( Radio::Power::High );
    radio->apply();

    afsk = new AFSK();

    // Initialize the display
    display = new Display();
    display->homeScreen();
    Serial.println( "Boot complete." );

    // Initialize the NeoPixel LED
    strip.begin();
    strip.setBrightness( 100 );

    digitalWrite( MIC_CTRL_PIN, HIGH ); // Switch the audio source to ESP32S3

    ledcSetup( 0, 2400, 10 );
    ledcWrite( 0, 512 );
    ledcSetup( 1, 4400, 10 );
    ledcWrite( 1, 512 );
    Serial.println( ledcRead(0) );

    sdm_channel_handle_t chan = NULL;
}

void loop(){

    std::string message = "UUUU<<<<UUUU<<<<UUUU<<<<UUUU<<<<UUUU<<<<UUUU<<<<UUUU<<<<UUUU<<<<UUUU<<<<";

    strip.setPixelColor( 0, strip.Color( 255, 0, 0) ); // Red
    strip.show();
    radio->transmit();
    afsk->send( message );
    radio->receive();
    strip.setPixelColor( 0, 0 ); // Black
    strip.show();

    delay( 5000 );
}
