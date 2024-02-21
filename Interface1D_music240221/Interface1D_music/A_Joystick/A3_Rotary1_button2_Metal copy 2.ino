/*

This is a simple example that allows you to connect 4 buttons and a rotary encoder to your Arduino.
The Arduino acts as a keyboard by outputting button presses.

You will need this table to figure the code for the characters you are trying to output.
http://www.asciitable.com/

*/

#include <Keyboard.h>      // include library that let's Arduino act as a keyboard
#include <RotaryEncoder.h> // include rotary encoder library
RotaryEncoder encoder(6, 7);

// some useful values
#define OFF 0
#define ON 1

bool player1_L = OFF;
bool player1_R = OFF;
bool player2_L = OFF;
bool player2_R = OFF;

// set the pins
const int player1_L_Pin = 2;
const int player1_R_Pin = 3;
const int player2_L_Pin = 4;
const int player2_R_Pin = 5;
const int player3_PinA = 6;
const int player3_PinB = 7;
const int player3_Metal= 9;

// values for Player3 Set
int metalState = 0;
int metalLastState = 0; 
int metalFlag = 0;

void setup()
{
  // connect to serial port for debugging
  Serial.begin(57600);
  pinMode(player1_L_Pin, INPUT_PULLUP);
  pinMode(player1_R_Pin, INPUT_PULLUP);
  pinMode(player2_L_Pin, INPUT_PULLUP);
  pinMode(player2_R_Pin, INPUT_PULLUP);
  pinMode(player3_PinA, INPUT);
  pinMode(player3_PinB, INPUT);
  pinMode(player3_Metal, INPUT_PULLUP);

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
  metalState = digitalRead(player3_Metal);

  //if metalstate changes, flag = 1; if keeps stable, flag = 0;
  if (metalLastState - metalState == 1) {
    metalFlag = 1;
  } else {
    metalFlag = 0;
  }
  //if metal is clicked, set by 'k'
  if (metalFlag == 1) {
    Keyboard.write(75);
  }
  metalLastState = metalState;




 //////////////////////////////////////////////
 //player1 right arrow
  if ((digitalRead(player1_L_Pin) == HIGH) && player1_L == OFF)
  {
    player1_L = ON;
    Keyboard.write(KEY_LEFT_ARROW); // A
  }
  if (digitalRead(player1_L_Pin) == LOW)
  {
    player1_L = OFF;
  }

//player1 left arrow
  if ((digitalRead(player1_R_Pin) == HIGH) && player1_R == OFF)
  {
    player1_R = ON;
    Keyboard.write(KEY_RIGHT_ARROW); // J
  }
  if (digitalRead(player1_R_Pin) == LOW)
  {
    player1_R = OFF;
  }


//player2 right arrow
  if ((digitalRead(player2_L_Pin) == HIGH) && player2_L == OFF)
  {
    player2_L = ON;
    Keyboard.write(68); // L
  }
  if (digitalRead(player2_L_Pin) == LOW)
  {
    player2_L = OFF;
  }

//player2 left arrow
  if ((digitalRead(player2_R_Pin) == HIGH) && player2_R == OFF)
  {
   player2_R = ON;
    Keyboard.write(65); // L
  }
  if (digitalRead(player2_R_Pin) == LOW)
  {
    player2_R = OFF;
  }

Serial.println(metalFlag);
delay(100);
}