#ifndef DisplayManager_h
#define DisplayManager_h
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_ADDRESS 0x3C 
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
#include <Arduino.h>

class DisplayManager {
  private:
    Adafruit_SSD1306 display;
    int initDelay = 2000;
  
  public:
    DisplayManager();
    void initializeDisplay();
    void screenWipe();
    void showReadings();
};

#endif
