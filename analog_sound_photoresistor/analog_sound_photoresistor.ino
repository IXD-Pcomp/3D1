/*
*******  changed up example code Nov. 2020 ******
  Pitch follower

  Plays a pitch that changes based on a changing analog input

  circuit:
  - 8 ohm speaker on digital pin 9
  - photoresistor on analog 0 to 5V
  - 4.7 kilohm resistor on analog 0 to ground
***** use a 10 kilohm resister instead ******** Doug Whitton Nov. 2020
  
  created 21 Jan 2010
  modified 31 May 2012
  by Tom Igoe, with suggestion from Michael Flynn

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone2
*/

void setup() {
  // initialize serial communications (for debugging only):
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  int sensorReading = analogRead(A0);
  
  
  
  // map the analog input range from the photoresistor
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below depending on the range
  // your sensor's giving:
  int thisPitch = map(sensorReading, 10, 150, 120, 1024);

  // play the pitch:
  //tone(9, thisPitch, 10);
  tone(9, sensorReading, 100);
  
  delay(100);        // delay in between reads for stability

  // print the sensor reading so you know its range
  Serial.print(sensorReading);
  Serial.print(" , ");
  Serial.println(thisPitch);
}
