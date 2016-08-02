#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#include <Wire.h>
int val1;
int val2;
int val3;

float angles[3]; // yaw pitch roll

// Set the FreeSixIMU object
FreeSixIMU sixDOF = FreeSixIMU();

void setup() { 
  Serial.begin(9600);
  Wire.begin();
  
  delay(5);
  sixDOF.init(); //begin the IMU
  delay(5);
}

void loop() { 
  
  sixDOF.getEuler(angles);
  val1 = map(angles[0], -180, 180, 0, 85);
  val2 = map(angles[1], -180, 180, 86, 170);
  val3 = map(angles[2], -180, 180, 171, 256);
  Serial.write(val1); //.write works with pd - change to Serial.print to see in console
  Serial.write(val2);
  Serial.write(val3);
  delay(100); 
}

