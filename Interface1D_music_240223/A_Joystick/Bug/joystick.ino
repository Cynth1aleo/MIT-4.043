const int xPin = 7;
const int yPin = 6;
const int buttonPin = 5;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
int mapX = 0;
int mapY = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  xPosition = analogRead(mapX);
  yPosition = analogRead(mapX);
  buttonState = digitalRead(buttonPin);

  mapX = map(xPosition, 0, 1023, 0, 30);  
  mapY = map(yPosition, 0, 1023, 0, 30);

  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(200);
}
