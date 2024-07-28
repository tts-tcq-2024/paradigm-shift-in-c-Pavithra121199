#include <stdio.h>
#include "EarlyWarning.h"
#include "EarlyWarningMessage_printer.c"

void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning) {
    printLowWarning(value, min, tolerance, lowWarning);
    printHighWarning(value, max, tolerance, highWarning);
}

void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning) {
    if (value > max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}



