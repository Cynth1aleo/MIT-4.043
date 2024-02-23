/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int metalPin = 2;  // the number of the pushbutton pin
const int ledPin = 4;    // the number of the LED pin
const int xPin = 9;
const int yPin = 8;


// variables will change:
int metalState = 0;
int lastState = 0;  // variable for reading the pushbutton status
int flag = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(metalPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  metalState = digitalRead(metalPin);

  if (lastState - metalState == 1 || lastState - metalState == -1) {
    flag = 1;
  } else {
    flag = 0;
  }
  //if  metalstate change from 0 to 1, flag = 1

  //if metalstate change from 1 to 0, flag = 0;

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (metalState == 1 && flag == 1) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  Serial.println(flag);
  lastState = metalState;
  delay(100);  // delay in between reads for stability

}
