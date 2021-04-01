
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>



Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup(void) {
  Serial.begin(9600);

   
  if (! mma.begin()) {
    Serial.println("Accelerometer Not working");
  }
  mma.setRange(MMA8451_RANGE_8_G);

  
  
}

void loop() {
 
  // read values from the accelerometer
  mma.read();
  sensors_event_t event; 
  mma.getEvent(&event);


  // find the current time and convert it into a string
  String time =  String(millis());

  
   // Temperature 
   printValue("0", "0", analogRead(2), time, true);

   // Strain gauge
   printValue("1", "0", analogRead(0), time, true);
   printValue("1", "0", analogRead(1), time, true);
  
   // Accelerometer
   printValue("2", "0", event.acceleration.x, time, true);
   printValue("2", "1", event.acceleration.y, time, true);
   printValue("2", "2", event.acceleration.z, time, false);
  

  Serial.println();

  delay(500);

  
}

void printValue(String plot, String layer, float value, String time, boolean coma){
  Serial.print(plot + "," + layer + ","  + String(value) + "," + String(time) + ((coma == true) ? "," : ""));
}
