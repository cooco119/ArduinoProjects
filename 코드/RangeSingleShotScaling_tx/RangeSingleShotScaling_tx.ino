/* This example shows how to change the range scaling factor
of the VL6180X. The sensor uses 1x scaling by default,
giving range measurements in units of mm. Increasing the
scaling to 2x or 3x makes it give raw values in units of 2
mm or 3 mm instead. In other words, a bigger scaling factor
increases the sensor's potential maximum range but reduces
its resolution. */

#include <Wire.h>
#include <VL6180X.h>

// To try different scaling factors, change the following define.
// Valid scaling factors are 1, 2, or 3.
#define SCALING 2

VL6180X sensor;
char range = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("UART");
  Wire.begin();

  sensor.init();
  sensor.configureDefault();
  sensor.setScaling(2);
  sensor.setTimeout(500);
}

void loop()
{
  range = sensor.readRangeSingleMillimeters();
  Serial.print(range);
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
