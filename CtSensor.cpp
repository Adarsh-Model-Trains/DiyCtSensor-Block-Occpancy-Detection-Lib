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
  _unOccupancySamples = 50;
}

void CtSensor::setName(String blockName) {
  _blockName = blockName;
}

void CtSensor::setOccupancyThreshhold(int occupancyThreshold) {
  _occupancyThreshold = occupancyThreshold;
}

void CtSensor::setUnOccupancySamples(int unOccupancySamples) {
  _unOccupancySamples = unOccupancySamples;
}

void CtSensor::setBlockSensorPin(uint8_t blockSensorPin) {
  _blockSensorPin = blockSensorPin;
}

void CtSensor::unOccupiedBlock() {
  _unOccupancyCount = 0;
  if (_sensorAverageReading < _occupancyThreshold) {
    _stateCurrent = OCCUPIED;
    _sensorAverageReading = 0;
  }
}

void CtSensor::occupiedBlock() {
  if (_sensorAverageReading > _unOccupancySamples && _unOccupancyCount < _unOccupancySamples) {
    _unOccupancyCount ++;
  }
  if (_sensorAverageReading < _unOccupancySamples && _unOccupancyCount < _unOccupancySamples) {
    _unOccupancyCount = 0;
  }
  if (_sensorAverageReading > _unOccupancySamples && _unOccupancyCount > _unOccupancySamples - 1) {
    _stateCurrent = UNOCCUPIED;
    _sensorAverageReading = 0;
  }
}

void CtSensor::calculateBlockOccupancy() {
  _sensorReadingTempVal = 0;
  _sensorTotalReading = 0;

  Serial.println(_blockName);
  for (_index = 0; _index < _sensorSamplesCount; _index++ ) {
    _sensorReadingTempVal = analogRead(_blockSensorPin);
    Serial.print(" SENSOR READING ");
    Serial.println(_sensorReadingTempVal);
    _sensorTotalReading += _sensorReadingTempVal;
  }
  _sensorAverageReading = _sensorTotalReading / _sensorSamplesCount;
  Serial.print(" SENSOR AVERAGE READING ");
  Serial.println(_sensorAverageReading);

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
