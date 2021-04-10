/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

#include <Arduino.h>
<<<<<<< HEAD:DiyCtSensor.cpp
#include "DiyCtSensor.h"


void DiyCtSensor::init() {
=======
#include "CustomCtSensor.h"


void CustomCtSensor::init() {
>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256:CustomCtSensor.cpp
  _sensorAverageReading = 0;
  _sensorSamplesCount = 10;
  _occupancyThreshold = 550;
  _unOccupancySamples = 50;
}

<<<<<<< HEAD:DiyCtSensor.cpp
void DiyCtSensor::setName(String blockName) {
  _blockName = blockName;
}

void DiyCtSensor::setOccupancyThreshhold(int occupancyThreshold) {
  _occupancyThreshold = occupancyThreshold;
}

void DiyCtSensor::setUnOccupancySamples(int unOccupancySamples) {
  _unOccupancySamples = unOccupancySamples;
}

void DiyCtSensor::setBlockSensorPin(uint8_t blockSensorPin) {
  _blockSensorPin = blockSensorPin;
}

void DiyCtSensor::unOccupiedBlock() {
=======
void CustomCtSensor::setName(String blockName) {
  _blockName = blockName;
}

void CustomCtSensor::setOccupancyThreshhold(int occupancyThreshold) {
  _occupancyThreshold = occupancyThreshold;
}

void CustomCtSensor::setUnOccupancySamples(int unOccupancySamples) {
  _unOccupancySamples = unOccupancySamples;
}

void CustomCtSensor::setBlockSensorPin(uint8_t blockSensorPin) {
  _blockSensorPin = blockSensorPin;
}

void CustomCtSensor::unOccupiedBlock() {
>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256:CustomCtSensor.cpp
  _unOccupancyCount = 0;
  if (_sensorAverageReading < _occupancyThreshold) {
    _stateCurrent = OCCUPIED;
    _sensorAverageReading = 0;
  }
}

<<<<<<< HEAD:DiyCtSensor.cpp
void DiyCtSensor::occupiedBlock() {
=======
void CustomCtSensor::occupiedBlock() {
>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256:CustomCtSensor.cpp
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

<<<<<<< HEAD:DiyCtSensor.cpp
void DiyCtSensor::calculateBlockOccupancy() {
=======
void CustomCtSensor::calculateBlockOccupancy() {
>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256:CustomCtSensor.cpp
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

<<<<<<< HEAD:DiyCtSensor.cpp
bool DiyCtSensor::isBlockOccupied() {
=======
bool CustomCtSensor::isBlockOccupied() {
>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256:CustomCtSensor.cpp
  calculateBlockOccupancy();
  if (_stateCurrent == OCCUPIED) {
    return true;
  } else {
    return false;
  }
}
