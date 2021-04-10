/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/

<<<<<<< HEAD

#ifndef DiyCtSensor_h
#define DiyCtSensor_h

enum BLOCK_STATE {
  OCCUPIED,
  UNOCCUPIED,
};
=======
#ifndef DiyCtSensor_h
#define DiyCtSensor_h

<<<<<<<< HEAD:DiySensor.h
#include "DiyCtSensor.h"
========
#include "CustomCtSensor.h"
>>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256:DiyCtSensor.h
>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256

class DiyCtSensor {

  private:
<<<<<<< HEAD
    String _blockName;
    uint8_t _blockSensorPin;
    long _sensorAverageReading;
    int _sensorSamplesCount;
    int _occupancyThreshold;
    int _unOccupancySamples;
    int _unOccupancyCount;
    int _sensorReadingTempVal;
    int _sensorTotalReading;
    int _index;

    BLOCK_STATE _stateCurrent = UNOCCUPIED;
    void init();

    void calculateBlockOccupancy();
    void occupiedBlock();
    void unOccupiedBlock();

  public:
    DiyCtSensor() {
      init();
    }
    void setName(String blockName);
    void setBlockSensorPin(uint8_t blockSensorPin);
    void setOccupancyThreshhold(int occupancyThreshold);
    void setUnOccupancySamples(int unOccupancySamples);
    bool isBlockOccupied();

    ~DiyCtSensor() {

    }
};

=======
    int _totalSensor;
<<<<<<<< HEAD:DiySensor.h
    DiyCtSensor * _ctSensorBlocks;
========
    CustomCtSensor * _ctSensorBlocks;
>>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256:DiyCtSensor.h

  public:
    DiyCtSensor() {
    }

    void initBlockSensors(int totalSensor);
    void setBlockSensorPins(int blockNo, uint8_t ctSensorPin);
    void setBlockSensorName(int blockNo, String blockName);
    void setDiyOccupancyThreshhold(int blockNo, int occupancyThreshold);
    void setDiyUnOccupancySamples(int blockNo, int unOccupancySamples);
    bool isSensorBlockOccupied(int blockNo);

    ~DiyCtSensor() {
      for (int i = 0; i < _totalSensor; i++) {
        delete &_ctSensorBlocks[i];
      }
      delete[] _ctSensorBlocks;
    }
};
>>>>>>> 7149c43ed238fafd32073550a773ccadb71d2256
#endif
