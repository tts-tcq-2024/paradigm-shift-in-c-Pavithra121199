#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  if(temperature >= 0 && temperature <= 45) {
    if(soc >=20 && soc <=80){
      if(chargeRate<=0.8){
        return 1;
      }
      printf("Charge Rate out of range!\n");
      return 0;
    }
    printf("State of Charge out of range!\n");
    return 0;
  }
  printf("Temperature out of range!\n");
  return 0;
} 
int main() {
  assert(!batteryIsOk(50, 85, 0));
}
