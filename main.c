#include <assert.h>
#include "batteryIsOk.h"

int main() {
    // Valid cases
    assert(batteryIsOk(30, 75, 0.6));  // Valid case - random input
    assert(batteryIsOk(0, 20, 0.8));  // Valid case checking the lower limit of temperature, soc and chargeRate
    assert(batteryIsOk(45, 80, 0.8));  // Valid case checking the upper limit of temperature and soc
    
    // Invalid temperature cases
    assert(!batteryIsOk(-1, 75, 0.6));  // Temperature below lower limit
    assert(!batteryIsOk(46, 75, 0.6));  // Temperature above upper limit
    
    // Invalid soc cases
    assert(!batteryIsOk(30, 19, 0.6));  // soc below lower limit
    assert(!batteryIsOk(30, 81, 0.6));  // soc above upper limit
    
    // Invalid chargeRate case
    assert(!batteryIsOk(30, 75, 0.9));  // chargeRate above upper limit
    
    // Combination of invalid cases
    assert(!batteryIsOk(-1, 19, 0.7));  // temperature and soc out of range
    assert(!batteryIsOk(30, 19, 0.9));  // soc and chargeRate out of range
    assert(!batteryIsOk(-1, 75, 0.9));  // temperature and chargeRate out of range
    assert(!batteryIsOk(-1, 19, 0.9));  // All parameters out of range

    return 0;
}
