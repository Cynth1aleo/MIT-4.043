/*

This is a simple example that allows you to connect 4 buttons and a rotary encoder to your Arduino.
The Arduino acts as a keyboard by outputting button presses.

You will need this table to figure the code for the characters you are trying to output.
http://www.asciitable.com/

*/

#include <Keyboard.h>      // include library that let's Arduino act as a keyboard

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

void setup()
{

  // connect to serial port for debugging
  Serial.begin(57600);

  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);


  // start the keyboard
  Keyboard.begin();
}

void loop()
{
  // All the key presses happen here
  //////////////////////////////////////////////

  //player1 right arrow
  if ((digitalRead(2) == HIGH) && key1Right == OFF)
  {
    key1Right = ON;
    Keyboard.write(KEY_RIGHT_ARROW); // A
  }
  if (digitalRead(2) == LOW)
  {
    key1Right = OFF;
  }
//player1 set arrow
  if ((digitalRead(3) == HIGH) && key1Set == OFF)
  {
    key1Set = ON;
    Keyboard.write(KEY_DOWN_ARROW); // D
  }
  if (digitalRead(3) == LOW)
  {
    key1Set = OFF;
  }
//player1 left arrow
  if ((digitalRead(4) == HIGH) && key1Left == OFF)
  {
    key1Left = ON;
    Keyboard.write(KEY_LEFT_ARROW); // J
  }
  if (digitalRead(4) == LOW)
  {
    key1Left = OFF;
  }

//player2 right arrow
  if ((digitalRead(5) == HIGH) && key2Right == OFF)
  {
    key2Right = ON;
    Keyboard.write(68); // L
  }
  if (digitalRead(5) == LOW)
  {
    key2Right = OFF;
  }
//player2 set arrow
  if ((digitalRead(6) == HIGH) && key2Set == OFF)
  {
    key2Set = ON;
    Keyboard.write(83); // L
  }
  if (digitalRead(6) == LOW)
  {
    key2Set = OFF;
  }
//player2 left arrow
  if ((digitalRead(7) == HIGH) && key2Left == OFF)
  {
   key2Left = ON;
    Keyboard.write(65); // L
  }
  if (digitalRead(7) == LOW)
  {
    key2Left = OFF;
  }
}