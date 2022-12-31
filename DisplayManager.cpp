#include "DisplayManager.h"

DisplayManager::DisplayManager() {
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
}


void DisplayManager::initializeDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.display();
  delay(initDelay);
  
}

void DisplayManager::screenWipe() {
  display.clearDisplay();
  display.fillScreen(0x001F);
  display.display();
}

void DisplayManager::showReadings(float celsius, float humidity) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 5);
  display.print("Temperature: " + String(celsius));
  display.cp437(true);
  display.write(ASCII_DEGREE);
  display.println(" ");
  display.print("Humidity: " + String(humidity));
  display.write(ASCII_PERCENT);
  display.display();    
}

void DisplayManager::playLoadingAni(){
  for(int i = 0; i < bitmap_frame_count; i ++) {
  display.clearDisplay();
    display.drawBitmap(
      (display.width()  - bitmap_height ) / 2,
      (display.height() - bitmap_width) / 2,
      akatsukiAnimation[i], bitmap_height, bitmap_width, WHITE);
    display.display();
    delay(loadingAnimDelay);
  }
}
