/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/


#ifndef DiyCtSensor_h
#define DiyCtSensor_h

enum BLOCK_STATE {
  OCCUPIED,
  UNOCCUPIED,
};

class DiyCtSensor {

  private:
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

#endif
