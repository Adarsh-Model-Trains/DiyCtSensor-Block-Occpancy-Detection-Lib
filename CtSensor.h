/*
   Adarsh Model Trains
   Developed by Adarsh kumar
   Support adarshkumarsingh83@gmail.com
*/


#ifndef CtSensor_h
#define CtSensor_h

enum BLOCK_STATE {
  OCCUPIED,
  UNOCCUPIED,
};

class CtSensor {

  private:
    uint8_t _blockSensorPin;
    long _sensorAverageReading;//value
    int _sensorSamplesCount; //numSamples
    int _occupancyThreshold;  //threshold
    int _unOccupancySamples; // clearsample
    int _unOccupancyCount; // clearcount
    int _sensorReadingTemp;
    int _sensorTotalReadingTemp;
    int _index;
    BLOCK_STATE _stateCurrent = UNOCCUPIED;
    void init();

    void calculateBlockOccupancy();
    void occupiedBlock();
    void unOccupiedBlock();

  public:
    CtSensor() {
      init();
    }

    void setBlockSensorPin(uint8_t blockSensorPin);
    void setOccupancyThreshhold(int occupancyThreshold);
    void setOccupancySamples(int unOccupancySamples);
    bool isBlockOccupied();

    ~CtSensor() {

    }
};

#endif
