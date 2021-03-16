
/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#include <Arduino.h>
#include "DiySensor.h"


void DiySensor::initBlockSensors(int totalSensor) {
  if (totalSensor > 0) {
    if (totalSensor > 0)
      _totalSensor = totalSensor;
    this->_ctSensorBlocks = new CtSensor[_totalSensor];
    for (int i = 0; i < _totalSensor; i++) {
      this->_ctSensorBlocks[i].setBlockSensorPin(0);
    }
  } else {
    Serial.println("Invalid Sensor Count");
  }
}

void DiySensor::setDiyOccupancyThreshhold(int blockNo, int occupancyThreshold) {
  this->_ctSensorBlocks[blockNo].setOccupancyThreshhold(occupancyThreshold);
}

void DiySensor::setDiyOccupancySamples(int blockNo, int unOccupancySamples) {
  this->_ctSensorBlocks[blockNo].setOccupancySamples(unOccupancySamples);
}

void DiySensor::setBlockSensorPins(int blockNo, uint8_t ctSensorPin) {
  if (blockNo > -1 && blockNo <= _totalSensor ) {
    _ctSensorBlocks[blockNo - 1].setBlockSensorPin(ctSensorPin);
  } else {
    Serial.println("Invalid Block Sensor Input No.");
  }
}

bool DiySensor::isSensorBlockOccupied(int blockNo) {
  if (blockNo > -1 && blockNo <= _totalSensor) {
    return _ctSensorBlocks[blockNo - 1].isBlockOccupied();
  } else {
    Serial.println("Invalid Block Sensor No");
    return false;
  }
}
