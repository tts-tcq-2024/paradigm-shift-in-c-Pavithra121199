#include <stdio.h>
#include "EarlyWarning.h"

void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning) {
    if (value > max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}
