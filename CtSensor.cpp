/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#include <Arduino.h>
#include "CtSensor.h"


void CtSensor::init() {
  _sensorAverageReading = 0;
  _sensorSamplesCount = 10;
  _occupancyThreshold = 550;
  _unOccupancyThreshold = 100;
}

void CtSensor::setBlockSensorPin(int blockSensorPin) {
  _blockSensorPin = blockSensorPin;
}

void CtSensor::occupiedBlock() {
  _unOccupancyCount = 0;
  if (_sensorAverageReading < _occupancyThreshold) {
    _stateCurrent = OCCUPIED;
  }
}

void CtSensor::unOccupiedBlock() {
  if (_sensorAverageReading > _occupancyThreshold && _unOccupancyCount < _unOccupancyThreshold) {
    _unOccupancyCount ++;
  }
  if (_sensorAverageReading < _occupancyThreshold && _unOccupancyCount < _unOccupancyThreshold) {
    _unOccupancyCount = 0;
  }
  if (_sensorAverageReading > _occupancyThreshold && _unOccupancyCount > _unOccupancyThreshold - 1) {
    _stateCurrent = UNOCCUPIED;
  }
}

void CtSensor::calculateBlockOccupancy() {
  _sensorTotalReadingTemp = 0;
  for (_index = 0; _index < _sensorSamplesCount; _index++ ) {
    _sensorTotalReadingTemp += analogRead(_blockSensorPin);
    _sensorAverageReading = _sensorTotalReadingTemp / _index;
  }
  delay(10);
  switch (_stateCurrent) {
    case OCCUPIED:
      occupiedBlock();
      break;
    case UNOCCUPIED:
      unOccupiedBlock();
      break;
  }
}

bool CtSensor::isBlockOccupied() {
  calculateBlockOccupancy();
  if (_stateCurrent == OCCUPIED) {
    return true;
  } else {
    return false;
  }
}
