#include <stdio.h>
#include <assert.h>

void printMessage(const char* Message) {
    printf("%s\n", Message);
}

int isValueInRange(float value, float min, float max, const char* Message) {
    if (value < min || value > max) {
        printMessage(Message);
        return 0;
    }
    return 1;
}

int isTemperatureOk(float temperature) {
    return isValueInRange(temperature, 0, 45, "Temperature out of range!");
}

int isSocOk(float soc) {
    return isValueInRange(soc, 20, 80, "State of Charge out of range!");
}

int isChargeRateOk(float chargeRate) {
    return isValueInRange(chargeRate, 0, 0.8, "Charge Rate out of range!");
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}

int main() {
    // Valid cases
    assert(batteryIsOk(25, 70, 0.7));
    assert(batteryIsOk(0, 20, 0.8));
    assert(batteryIsOk(45, 80, 0.0));
    
    // Invalid temperature cases
    assert(!batteryIsOk(-1, 70, 0.7));  // Temperature below lower limit
    assert(!batteryIsOk(46, 70, 0.7));  // Temperature above upper limit
    
    // Invalid SOC cases
    assert(!batteryIsOk(25, 19, 0.7));  // SOC below lower limit
    assert(!batteryIsOk(25, 81, 0.7));  // SOC above upper limit
    
    // Invalid charge rate cases
    assert(!batteryIsOk(25, 70, 0.9));  // Charge rate above upper limit
    
    // Combination of invalid parameters
    assert(!batteryIsOk(-1, 19, 0.9));  // All parameters out of range
    assert(!batteryIsOk(25, 19, 0.9));  // SOC and charge rate out of range
    assert(!batteryIsOk(-1, 70, 0.9));  // Temperature and charge rate out of range
    assert(!batteryIsOk(-1, 19, 0.7));  // Temperature and SOC out of range
    return 0;
}
