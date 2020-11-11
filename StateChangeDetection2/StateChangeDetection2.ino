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

  Modified a lot by Doug Whitton Nov 2020
  This code demonstrates how to use a push button to toggle an LED on and off 
*/

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:

int buttonState = 0;// current state of the button
boolean ledState;
//int lastButtonState = 0;     // previous state of the button
//int toggle = 0;
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
  ledState = digitalRead(ledPin);
  
  /*Serial.print("buttonState");
  Serial.println(buttonState);
  Serial.print("ledState");
  Serial.println(ledState);*/
    
    if (buttonState == 1 && ledState == 0) {
      
      digitalWrite(ledPin, HIGH);
    } 
    else if (ledState == 1 && buttonState == 1){
      digitalWrite(ledPin, LOW);
    }
    
    delay(400);
  }
  
  
  
  
