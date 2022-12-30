#ifndef EnvironmentSample_h
#define EnvironmentSample_h

#include <Arduino.h>

class EnvironmentSample {
  public:
    EnvironmentSample(float, float);
    float celsius;
    float humidity;
};

#endif
