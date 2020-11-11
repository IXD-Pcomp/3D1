/*
  State change detection (edge detection)

  Often, you don't need to know the state of a digital input all the time, but
  you just need to know when the input changes from one state to another.
  For example, you want to know when a button goes from OFF to ON. This is called
  state change detection, or edge detection.

  This example shows how to detect when a button or button changes from off to on
  and on to off.

  The circuit:
  - pushbutton attached to pin 2 from +5V
  - 10 kilohm resistor attached to pin 2 from ground
  - LED attached from pin 13 to ground (or use the built-in LED on most
    Arduino boards)

  created  27 Sep 2005
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ButtonStateChange

Modified Nov 2020 Doug Whitton
*/

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin 2 as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output pin 13:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  
  //buttonPin is a digital pin set to be an input
  //The button in the circuit inputs voltage to pin 2 (buttonPin)
  // When a voltage is input to pin 2, it is set to "1"
  // When there is no voltage input to pin 2, it's set to "0"
  // You can see this in the Serial Monitor - Serial.println(buttonPin); or Serial.println(digitalRead(2)); 
  // buttonState will have a value of either 1 or 0, in other words it can only have 2 states, 0 or 1
  //Serial.println(buttonState);
  
  // compare the buttonState to its previous state
  // If buttonState has a value different than lastButtonState, then the state has changed
  if (buttonState != lastButtonState) {
    Serial.println("state change");
   
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      // then we turn on the LED by switching pin 13 (aka ledPin) to HIGH, so voltage goes from pin 13 to the LED on the breadboard 
      digitalWrite(ledPin, HIGH);
    } else {
      // if the current state is LOW then the button went from on to off:
      //set pin 13 to LOW, so no voltage is going to the LED
      digitalWrite(ledPin, LOW);
      
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  
  
}
