#ifndef TWR_APRS_PMU_H
#define TWR_APRS_PMU_H

#include "board_config.h"
#include <XPowersLib.h>

class PMU {
public:
    bool init();
    bool startRadio();
    bool startMic();
    bool startMicroSD();
    bool startGNSS();
private:
    XPowersPMU pmu;
};


#endif //TWR_APRS_PMU_H
