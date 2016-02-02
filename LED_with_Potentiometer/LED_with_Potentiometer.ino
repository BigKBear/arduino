/*
 * Control brightness of a LED with Potentiometer
 */
/*must be a pin with tilday */
int ledPin = A0;

int potPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int potValue = analogRead(potPin);

  //map value from 0-1023 to 0-255
  int brightness = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, brightness);
}
