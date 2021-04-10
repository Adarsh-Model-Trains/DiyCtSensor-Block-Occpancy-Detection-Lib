
#include "DiyCtSensor.h"

#define CT_SENSOR_COUNT 2
#define X_BLOCK_LED 13
#define Y_BLOCK_LED 12

DiyCtSensor diySensor;
void setup() {
  Serial.begin(9600);
  diySensor.initBlockSensors(CT_SENSOR_COUNT);
  diySensor.setBlockSensorPins(1, A0);
  diySensor.setBlockSensorName(1, "BLOCK-A");
  diySensor.setDiyOccupancyThreshhold(1, 800);
  diySensor.setDiyUnOccupancySamples(1, 20);


  diySensor.setBlockSensorPins(2, A1);
  diySensor.setBlockSensorName(2, "BLOCK-B");
  diySensor.setDiyOccupancyThreshhold(2, 800);
  diySensor.setDiyUnOccupancySamples(2, 20);


  pinMode(X_BLOCK_LED, OUTPUT);
  pinMode(Y_BLOCK_LED, OUTPUT);
}

void loop() {
  bool xBlockState = diySensor.isSensorBlockOccupied(1);
  if (xBlockState) {
    digitalWrite(X_BLOCK_LED, HIGH);
  } else {
    digitalWrite(X_BLOCK_LED, LOW);
  }

  bool yBlockState = diySensor.isSensorBlockOccupied(2);
  if (yBlockState) {
    digitalWrite(Y_BLOCK_LED, HIGH);
  } else {
    digitalWrite(Y_BLOCK_LED, LOW);
  }

}
