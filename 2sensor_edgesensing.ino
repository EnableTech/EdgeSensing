#include <SharpIR.h>

int vibes;
const int interval = 600; // in units of 100 ms
int timer = interval;


SharpIR topSensor( SharpIR::GP2Y0A21YK0F, A0 );
int topSensorDistance = 0;

int vibrationPin = 5;
int outputPin1 = 7;
int outputPin2 = 9;

SharpIR bottomSensor( SharpIR::GP2Y0A21YK0F, A1);
int bottomSensorDistance = 0;

void setup() {
  pinMode(vibrationPin, INPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);  
  
  topSensorDistance = topSensor.getDistance();
  bottomSensorDistance = bottomSensor.getDistance();

  if (topSensorDistance > 55) {
    tone(3, 500);
  } else if (bottomSensorDistance > 55) {
    tone(3, 500);
  } else {
    noTone(3);
  }

  vibes = digitalRead(vibrationPin); // read vibration sensor, A0 and A1 taken
  
  
  if (vibes < 1000){ //reads up to 1023, >1000 means no motion
    timer = interval;
    digitalWrite(outputPin1, HIGH);
    digitalWrite(outputPin2, HIGH);
  }
  else if (timer > 0){ //check if not moving
    timer--;
  }
  else { //no motion and out of time
    digitalWrite(outputPin1, LOW);
    digitalWrite(outputPin2, LOW);
  }
}
