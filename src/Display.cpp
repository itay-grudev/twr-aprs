#include "Display.h"
#include "config.h"

#include <string>
#include <sstream> // std::stringstream
#include <iomanip> // std::setprecision

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
    u8g2.drawStr( 0, 13*0, CALLSIGN );
    std::stringstream frequency; // Convert to float with precision
    frequency << std::fixed << std::setprecision( 3 ) << FREQUENCY / 1E6;
    u8g2.drawStr( 0, 13*1, (std::string("APRS ") + frequency.str() + "MHz").c_str() );
    u8g2.sendBuffer();
}
