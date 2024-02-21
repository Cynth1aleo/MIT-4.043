/*

This is a simple example that allows you to connect 4 buttons and a rotary encoder to your Arduino.
The Arduino acts as a keyboard by outputting button presses.

You will need this table to figure the code for the characters you are trying to output.
http://www.asciitable.com/

*/

#include <Keyboard.h>      // include library that let's Arduino act as a keyboard
#include <RotaryEncoder.h> // include rotary encoder library
RotaryEncoder encoder(8, 9);

// some useful values
#define OFF 0
#define ON 1



// set the pins
const int player1XPin = 3;
const int player1SetPin = 2;
const int player2Xpin = 6;
const int plar2SetPin = 5;
const int player3XPinA = 8;
const int player3XPinB = 9;
const int player3MetalPin = 10;

// values for Player3 Set
int metalState = 0;
int metalLastState = 0; 
int metalFlag = 0;

// values for Player1 Movement
int player1XPosition = 0;
int player1ButtonState = 0;

// values for Player2 Movement
int player2XPosition = 0;
int player2ButtonState = 0;


void setup()
{

  // connect to serial port for debugging
  Serial.begin(57600);
  pinMode(player1XPin, INPUT);
  pinMode(player1SetPin, INPUT_PULLUP);
  pinMode(player2Xpin, INPUT);
  pinMode(plar2SetPin, INPUT_PULLUP);
  pinMode(player3XPinA, INPUT);
  pinMode(player3XPinB, INPUT);
  pinMode(player3MetalPin, INPUT_PULLUP);

  // start the keyboard
  Keyboard.begin();
}

void loop()
{
  // All the key presses happen here
  //////////////////////////////////////////////

  //player3 Movement: Rotary encoder
  static int pos = 0;
  encoder.tick();

  int newPos = encoder.getPosition();
  if (pos != newPos)
  {
    Serial.print(newPos);
    Serial.println();
    // move left by "J"
    if (newPos > pos)
    {
      Keyboard.write(76); 
    }
    // move RIGHT by "l"
    if (newPos < pos)
    {
      Keyboard.write(74); 
    }
    pos = newPos;
  }

//player3 Set: Metal Knock
  metalState = digitalRead(player3MetalPin);

  //if metalstate changes, flag = 1; if keeps stable, flag = 0;
  if (metalLastState - metalState != 0) {
    metalFlag = 1;
  } else {
    metalFlag = 0;
  }
  //if metal is clicked, set by 'k'
  if (metalState == 1 && metalFlag == 1) {
    Keyboard.write(75);
  }
  metalLastState = metalState;




 //////////////////////////////////////////////
  // player1
  player1XPosition = analogRead(player1XPin);
  player1ButtonState = digitalRead(player1SetPin);
  //if xPosition > 614, Move Right;
  if (player1XPosition > 614) {
    Keyboard.write(KEY_RIGHT_ARROW);
  }
  //if xPosition < 514 , Move Left;
  if (player1XPosition < 414) {
    Keyboard.write(KEY_LEFT_ARROW);
  }
  //if button clicked
  if (player1ButtonState = 1) {
    Keyboard.write(KEY_DOWN_ARROW);
  }

  // player2
  player2XPosition = analogRead(player1XPin);
  player2ButtonState = digitalRead(player1SetPin);
  //if xPosition > 614, Move Right;
  if (player2XPosition > 614) {
    Keyboard.write(68);
  }
  //if xPosition < 514 , Move Left;
  if (player2XPosition < 414) {
    Keyboard.write(65);
  }
  //if button clicked
  if (player2ButtonState = 1) {
    Keyboard.write(83);
  }

  delay(500);
}