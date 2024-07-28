#include "Battery_Monitor.h"
#include "Temperature_Rangechecker.h"
#include "SOC_Rangechecker"
#include "ChargeRate_Rangechecker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
