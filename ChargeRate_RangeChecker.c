#include "ChargeRate_RangeChecker.h"
#include "ChargeRateRange_checker.h"
#include "EarlyWarnings.h"

int isChargeRateOk(float chargeRate) {
    checkWarningChargeRate(chargeRate, 0.8, 0.04, "Warning: Approaching maximum charge rate");
    return isInRange(chargeRate, 0.8, "Charge Rate out of range!");
}
