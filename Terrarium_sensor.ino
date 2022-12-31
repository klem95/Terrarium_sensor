#include "DHT.h"
#include "SampleTracker.h"
#include "DisplayManager.h"

#define DHTTYPE DHT11 // DHT 11
#define DHTPIN 8  // Digital pin connected to the DHT sensor

DHT dht(DHTPIN, DHTTYPE);

SampleTracker sampleTracker;
DisplayManager displayMananger;

int stopper = -1; // Remove
int sampleDelay = 2000; // Find a good delay???
int logoDelay = 2000;

/* TO-DO
 * 1) Make function for avg readings (c and h)
 * 2) Make running avg??
  */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  dht.begin();
  
  stopper = sampleTracker.sampleBufferLength;

  displayMananger.initializeDisplay();
  //displayMananger.screenWipe();
  //displayMananger.showReadings(25.2, 64);


  /*
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.display();
  
  delay(logoDelay);
  */
  
  Serial.println("initialization over");

}
void loop() {
    displayMananger.playLoadingAni();

  /*
  delay(sampleDelay);

  // REMOVE!
  if(stopper > 0) {
    stopper -= 1;
  } else {
    while(true){
      
    }
  }
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

 if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  // Record sample
  sampleTracker.recordSample(hic, h);

  // Get historic readings from sensor 
  float * humidityRedings = sampleTracker.getHumidityReadings();
  float * celsiusRedings = sampleTracker.getCelsiusReadings();

  // REMOVE!
  if(humidityRedings != NULL && celsiusRedings != NULL ) {
   for (int i = 0; i < sampleTracker.sampleBufferLength; i++) {
      Serial.print("recorde data: ");
      Serial.print(humidityRedings[i]);
      Serial.print(" ");
      Serial.print(celsiusRedings[i]);

      Serial.println("");
   }
  Serial.println("___"); 
  }
  */
}
