/*

This is a simple example that allows you to connect 4 buttons and a rotary encoder to your Arduino.
The Arduino acts as a keyboard by outputting button presses.

You will need this table to figure the code for the characters you are trying to output.
http://www.asciitable.com/

*/

#include <USBKeyboard.h>  // include library that let's Arduino act as a keyboard
// #include <RotaryEncoder.h> // include rotary encoder library

// // Setup a RoraryEncoder for pins A0 and A1:
// RotaryEncoder encoder(A0, A1);

// some useful values
#define OFF 0
#define ON 1

// start by assuming no buttons are pressed
bool key1Right = OFF;
bool key1Set = OFF;
bool key1Left = OFF;
bool key2Right = OFF;
bool key2Set = OFF;
bool key2Left = OFF;
// bool key3Right = OFF;
// bool key3Set = OFF;
// bool key3Left = OFF;


void setup() {

  // connect to serial port for debugging
  Serial.begin(57600);

  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  for (int i = 2; i < 8; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
  Keyboard.init();
  // Keyboard.begin();
}

void loop() {
  // All the key presses happen here
  //////////////////////////////////////////////
  //player1 right arrow
  if ((digitalRead(2) == HIGH) && key1Right == OFF) {
    key1Right = ON;
    Keyboard.sendKeyStroke(KEY_RIGHT_ARROW,0);  // Right
  }
  if (digitalRead(2) == LOW) {
    key1Right = OFF;
  }
  //player1 set arrow
  if ((digitalRead(3) == HIGH) && key1Set == OFF) {
    key1Set = ON;
    Keyboard.sendKeyStroke(KEY_DOWN_ARROW,0);  // D
  }
  if (digitalRead(3) == LOW) {
    key1Set = OFF;
  }
  //player1 left arrow
  if ((digitalRead(4) == HIGH) && key1Left == OFF) {
    key1Left = ON;
   Keyboard.sendKeyStroke(KEY_LEFT_ARROW,0);  // J
  }
  if (digitalRead(4) == LOW) {
    key1Left = OFF;
  }


  //player2 right arrow
  if ((digitalRead(5) == HIGH) && key2Right == OFF) {
    key2Right = ON;
    Keyboard.sendKeyStroke(KEY_D, 0);  // L
  }
  if (digitalRead(5) == LOW) {
    key2Right = OFF;
  }
  //player2 set arrow
  if ((digitalRead(6) == HIGH) && key2Set == OFF) {
    key2Set = ON;
    Keyboard.sendKeyStroke(KEY_S, 0);  // L
  }
  if (digitalRead(6) == LOW) {
    key2Set = OFF;
  }
  //player2 left arrow
  if ((digitalRead(7) == HIGH) && key2Left == OFF) {
    key2Left = ON;
    Keyboard.sendKeyStroke(KEY_A, 0);  // L
  }
  if (digitalRead(7) == LOW) {
    key2Left = OFF;
  }


  // //player3 left arrow
  // if ((digitalRead(8) == HIGH) && key3Right == OFF)
  // {
  //   key3Right = ON;
  //   Keyboard.write(76); // L
  // }
  // if (digitalRead(8) == LOW)
  // {
  //   key3Right = OFF;
  // }
  // //player3 set arrow
  // if ((digitalRead(9) == HIGH) && key3Set == OFF)
  // {
  //   key3Set = ON;
  //   Keyboard.write(75); // L
  // }
  // if (digitalRead(9) == LOW)
  // {
  //   key3Set = OFF;
  // }
  // //player3 right arrow
  // if ((digitalRead(10) == HIGH) && key3Left == OFF)
  // {
  //   key3Left = ON;
  //   Keyboard.write(74); // L
  // }
  // if (digitalRead(10) == LOW)
  // {
  //   key3Left = OFF;
  // }
}