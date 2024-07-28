#include "ChargeRateRange_checker.h"
#include "WarningMessage_printer.h"

int isChargeRateInRange(float value, float max, const char* WarningMessage) {
    if (value > max) {
        printWarningMessage(WarningMessage);
        return 0;
    }
    return 1;
}
