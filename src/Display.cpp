#include "Display.h"
#include "config.h"

Display::Display() : u8g2( U8G2_R0, U8X8_PIN_NONE )
{
    Wire.begin( I2C_SDA, I2C_SCL );
    u8g2.begin();
    u8g2.setFontRefHeightExtendedText();
    u8g2.setDrawColor( 1 );
    u8g2.setFontPosTop();
    u8g2.setFontDirection( 0 );
}

void Display::homeScreen()
{
    u8g2.clearBuffer();
    u8g2.setFont( u8g2_font_unifont_tf );
    u8g2.drawStr( 0, 13*0, CALLSIGN " (LoRa)" );
    u8g2.drawStr( 0, 13*1, "APRS Tracker" );
    u8g2.drawStr( 0, 13*2, (String(FREQUENCY / 1E6, 3) + "MHz").c_str() );
    u8g2.sendBuffer();
}
