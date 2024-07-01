#include <stdio.h>
#include <assert.h>

void printMessage(const char* Message) {
    printf("%s\n", Message);
}

int isTemperatureOk(float temperature) {
    if (temperature < 0 || temperature > 45) {
        printMessage("Temperature out of range!");
        return 0;
    }
    return 1;
}

int isSocOk(float soc) {
    if (soc < 20 || soc > 80) {
        printMessage("State of Charge out of range!");
        return 0;
    }
    return 1;
}

int isChargeRateOk(float chargeRate) {
    if (chargeRate > 0.8) {
        printMessage("Charge Rate out of range!");
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
