
#include "DiyCtSensor.h"

#define CT_SENSOR_COUNT 1
#define X_BLOCK_LED 13

DiyCtSensor diySensor;
void setup() {
  Serial.begin(9600);
  diySensor.initBlockSensors(CT_SENSOR_COUNT);
  diySensor.setBlockSensorPins(1, A0);
  diySensor.setBlockSensorName(1, "BLOCK-A");
  diySensor.setDiyOccupancyThreshhold(1, 800);
  diySensor.setDiyUnOccupancySamples(1, 20);
  pinMode(X_BLOCK_LED, OUTPUT);
}

void loop() {
  bool xBlockState = diySensor.isSensorBlockOccupied(1);
  if (xBlockState) {
    digitalWrite(X_BLOCK_LED, HIGH);
  } else {
    digitalWrite(X_BLOCK_LED, LOW);
  }
}
