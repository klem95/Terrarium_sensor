#ifndef SampleTracker_h
#define SampleTracker_h

#include <Arduino.h>
#include "EnvironmentSample.h"

class SampleTracker {
  public:
    static const byte sampleBufferLength = 10;
    SampleTracker();
    void recordSample(float c, float h);
    EnvironmentSample latestSample();
    float * getCelsiusReadings();
    float * getHumidityReadings();
    EnvironmentSample * avgReadings(); // MISSING 

    private:
      EnvironmentSample * envSamplespntr [sampleBufferLength];
  };

#endif
