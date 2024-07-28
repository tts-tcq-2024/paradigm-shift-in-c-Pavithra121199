#include <stdio.h>
#include "EarlyWarning.h"

void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning) {
    if (value >= min && value < min + tolerance) {
        printf("%s\n", lowWarning);
    } else if (value > max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}
