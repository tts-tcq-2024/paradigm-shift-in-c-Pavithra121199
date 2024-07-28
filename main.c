#include <assert.h>
#include "Battery_Monitor.h"

int main() {
    
    // Invalid temperature cases
    assert(!batteryIsOk(-1, 75, 0.6));  // Temperature below lower limit
    assert(!batteryIsOk(46, 75, 0.6));  // Temperature above upper limit
    
    // Invalid soc cases
    assert(!batteryIsOk(30, 19, 0.6));  // soc below lower limit
    assert(!batteryIsOk(30, 81, 0.6));  // soc above upper limit
    
    // Invalid chargeRate case
    assert(!batteryIsOk(30, 75, 0.9));  // chargeRate above upper limit

    //Early warnings
    assert(batteryIsOk(2.25, 75, 0.8));  // Approaching lower temperature limit
    assert(batteryIsOk(42.75, 75, 0.8));  // Approaching higher temperature limit
    assert(batteryIsOk(30, 24, 0.8));  // Approaching discharge
    assert(batteryIsOk(30, 76, 0.8));  // Approaching charge-peak
    assert(batteryIsOk(30, 60, 0.76));  // Approaching maximum charge rate
    return 0;
}
