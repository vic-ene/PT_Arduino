
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

int pinSD = 53;

int DELAY = 500;

String VAL = "VAL";


Adafruit_MMA8451 mma = Adafruit_MMA8451();

String filename = "file.txt";
File file;

void setup(void) {
  Serial.begin(9600);
  SD.begin(pinSD);
  mma.setRange(MMA8451_RANGE_8_G);

  if(mma.begin()){
   
  }
  pinMode(pinSD, OUTPUT);

 }

void loop() {
 
  // read values from the accelerometer
  mma.read();
  sensors_event_t event; 
  mma.getEvent(&event);


   // find the current time and convert it into a string
   String time =  String(millis());

   String newLine ="";

   newLine += addValue("0", "0", analogRead(2), time, true);
   
   newLine += addValue("1", "0", analogRead(0), time, true);
   newLine += addValue("1", "1", analogRead(1), time, true);

   newLine += addValue("2", "0", event.acceleration.x, time, true);
   newLine += addValue("2", "1", event.acceleration.y, time, true);
   newLine += addValue("2", "2", event.acceleration.z, time, false);

   //writes to SD cards
   writeToSdCard(newLine);

   // Sends the values to processing
   Serial.println(newLine);
    
   delay(100);
}

void writeToSdCard(String newLine){
    //SD.begin(pinSD);
    file = SD.open(filename, FILE_WRITE);
    if(file){
      file.println(newLine);
      Serial.println("Written");
      file.close();
   }
}



 String addValue(String plot, String layer, float value, String time, boolean coma){
   return plot + "," + layer + ","  + String(value) + "," + String(time) + ((coma == true) ? "," : "");
}
