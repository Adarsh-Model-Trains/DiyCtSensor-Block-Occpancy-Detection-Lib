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
    int _blockSensorPin;
    int _sensorAverageReading;//value
    int _sensorSamplesCount; //numSamples
    int _occupancyThreshold;  //threshold
    int _unOccupancyThreshold; // clearsample
    int _unOccupancyCount; // clearcount
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

    void setBlockSensorPin(int blockSensorPin);
    bool isBlockOccupied();

    ~CtSensor() {

    }
};

#endif
