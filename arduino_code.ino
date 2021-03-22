
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup(void) {
  Serial.begin(9600);
  
}

void loop() {
  
  if (! mma.begin()) {
  
  }
  
  mma.setRange(MMA8451_RANGE_8_G);
  mma.read();
  
  sensors_event_t event; 
  mma.getEvent(&event);
  
  Serial.print("0,0," + String(analogRead(0)));
  Serial.print(",2,0," + String(event.acceleration.x)); 
  Serial.print(",2,1," + String(event.acceleration.y)); 
  Serial.println(",2,2," +String(event.acceleration.z)); 

  delay(1000);
  
}
