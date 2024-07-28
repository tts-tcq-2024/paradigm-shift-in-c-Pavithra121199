#include <assert.h>
#include "Battery_Monitor.h"

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
    
    // Early warnings
    assert(batteryIsOk(2.25, 75, 0.6));  
    assert(batteryIsOk(42.75, 75, 0.6));
    assert(batteryIsOk(20, 21, 0.6));  
    assert(batteryIsOk(20, 79, 0.6));  
    assert(batteryIsOk(20, 40, 0.76));
    

    return 0;
}
