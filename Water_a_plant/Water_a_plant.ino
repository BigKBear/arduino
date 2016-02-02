/*
*Mahees plant challenge
*
*/

#define SECOND 1000L
#define MINUTE (60*SECOND)
#define HOUR (60*MINUTE)

int motorSwitchPin = 12;
int sensorSwitch = 11;

float sensorValue1=0;
float sensorValue2=0;
float sensorValue3=0;

float averageValue =0;
float sensorOutput = 0;

void setup(){
  pinMode(motorSwitchPin, OUTPUT);
}

void loop(){
  float averageValue=0;
  //moisture check
  averageValue = moistureCheck();

// if the soil is dry repeat below twice
if(averageValue < 500){
  wetPlant();
wetPlant();
}else if(averageValue < 700){
wetPlant();
  }

  //delay 24 hours
  delay(12*HOUR);
  delay(12*HOUR);
}

void wetPlant(){
  digitalRead(motorSwitchPin);
  //wet for 5 seconds 
    //turn on motor
    int speed = map(250, 0 , 1023, 0, 255);
analogWrite(motorSwitchPin, speed);

    //stop motor after 5 seconds
    delay(5*SECOND);
analogWrite(motorSwitchPin,LOW);

}

float moistureCheck(){
  float averageValue=0;
      //turn on sensor    
    digitalWrite(sensorSwitch, HIGH);
    delay(5*SECOND);

    //read sensor value
sensorValue1 =analogRead(sensorOutput);
    delay(5*SECOND);
sensorValue2 =analogRead(sensorOutput);
    delay(5*SECOND);
    sensorValue3 =analogRead(sensorOutput); 
delay(5*SECOND);
    digitalWrite(sensorSwitch, LOW);

    //check the values read
     averageValue = (sensorValue1 + sensorValue2 + sensorValue3 )/3;
    return averageValue;
}
