/*
 * Full Traffic Light with Button
 */

 //setup button pin
 int buttonPin = 2;

 //setup LEDs
 int stopRedPin = 12;
 int stopYellowPin = 11;
 int stopGreenPin = 10;
 int pedRedPin = 9;
 int pedGreenPin = 8;

 long pedLightTimer;
 int timeout= 5000;


void setup()
{
  //setup pin modes
  pinMode(stopRedPin, OUTPUT);
  pinMode(stopYellowPin, OUTPUT);
  pinMode(stopGreenPin, OUTPUT);
  pinMode(stopRedPin, OUTPUT);
  pinMode(stopGreenPin, OUTPUT);

  // Traffic Lighjt green by default
  digitalWrite(stopGreenPin, HIGH);
  //Pedestrian light Red by default
  digitalWrite(pedRedPin, HIGH);

  pedestrian();
}

void loop()
{
  bool buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH && (millis() - pedLightTimer) > timeout)
  {
    stoplight();
  }
}

void stoplight()
{
      //go through cycle -turn off Green Light, Turn Light Yellow for 2 seconds,
      // turn off yellow light, turn on Red Light
      digitalWrite(stopGreenPin, LOW);

      //turn yellow light on for 2 seconds
      digitalWrite(stopYellowPin, HIGH);
      delay(2000);
      digitalWrite(stopYellowPin, LOW);

      //turn on red light
      digitalWrite(stopRedPin, HIGH);

      pedestrian();
}

void pedestrian()
{
  //turn off pedestrian red light
  digitalWrite(pedRedPin, LOW);

  //turn green light on for 2 seconds
  digitalWrite(pedGreenPin, HIGH);
  delay(5000);
  digitalWrite(pedGreenPin, LOW);

  for(int x = 0; x <10; x++)
  {
    digitalWrite(stopYellowPin, HIGH);
    delay(250);
    digitalWrite(stopYellowPin, LOW);
    delay(250);
  }

  //turn light red
  digitalWrite(pedRedPin, HIGH);
      
  //turn green stoplight on
  digitalWrite(stopGreenPin, HIGH);
   
  //turn red stoplight off
  digitalWrite(stopRedPin, LOW);

  pedLightTimer = millis();
}
