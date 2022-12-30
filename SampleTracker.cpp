#include "SampleTracker.h"

SampleTracker::SampleTracker() {
  
}

void SampleTracker::recordSample(float c, float h) {
    for (int i = sampleBufferLength; i >= 0; i--) {
      if (i == 0) {
        envSamplespntr[i] = new EnvironmentSample(c, h);
      } else {
        if(envSamplespntr[i - 1] != NULL) {
          envSamplespntr[i] = envSamplespntr[i - 1];
        } else {
          envSamplespntr[i] = new EnvironmentSample(0, 0);
        }
      }
    }
}

EnvironmentSample SampleTracker::latestSample() {
  return *envSamplespntr[0];
}

float * SampleTracker::getCelsiusReadings() {
  static float tempArray[sampleBufferLength];
  for(int i = 0; i < sampleBufferLength; i++) {
    tempArray[i] = envSamplespntr[i]->celsius;
  }
  return tempArray;
}

float * SampleTracker::getHumidityReadings() {
  static float tempArray[sampleBufferLength];
  for(int i = 0; i < sampleBufferLength; i++) {
    tempArray[i] = envSamplespntr[i]->humidity;
  }
  return tempArray;
}
