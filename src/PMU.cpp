#include "PMU.h"

#include <Arduino.h>
#include <Wire.h>

#include "board_config.h" // It overrides I2C_SDA, I2C_SCL set from incorrect board config

bool PMU::init()
{
    return pmu.begin( Wire, AXP2101_SLAVE_ADDRESS, I2C_SDA, I2C_SCL );
}

bool PMU::startRadio() {
    return pmu.setDC3Voltage( 3400 ) && pmu.enableDC3();
}

bool PMU::startMic() {
    return pmu.setBLDO1Voltage( 3300 ) && pmu.enableBLDO1();
}

bool PMU::startMicroSD() {
    return pmu.setALDO2Voltage( 3300 ) && pmu.enableALDO2();
}

bool PMU::startGNSS() {
    return pmu.setALDO4Voltage( 3300 ) && pmu.enableALDO4();
}
