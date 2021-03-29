
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

  String time =  String(millis());


 // Serial.print("-1,");
  
  // Temperature 
  //Serial.print("0,0," + String(analogRead(2))  + time + ",");
  printValue("0", "0", analogRead(2), time, true);

  // Strain gauge
  //Serial.print("1,0," + String(analogRead(0)) + time + ",");
  //Serial.print("1,1," + String(analogRead(1)) + time + ",");
   printValue("1", "0", analogRead(0), time, true);
   printValue("1", "0", analogRead(1), time, true);
  

  // Accelerometer
  //Serial.print("2,0," + String(event.acceleration.x) + time + ","); 
  //Serial.print("2,1," + String(event.acceleration.y) + time + ","); 
  //Serial.print("2,2," +String(event.acceleration.z) + time); 
  printValue("2", "0", event.acceleration.x, time, true);
  printValue("2", "1", event.acceleration.y, time, true);
  printValue("2", "2", event.acceleration.z, time, false);
  

  
  Serial.println();

  delay(500);

  
}

void printValue(String plot, String layer, float value, String time, boolean coma){
  Serial.print(plot + "," + layer + ","  + String(value) + "," + String(time) + ((coma == true) ? "," : ""));
}
