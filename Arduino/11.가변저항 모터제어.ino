#include <Servo.h>
Servo myServo;

void setup() {
  myServo.attach(12);
}

int val;
int angle;

void loop() {
  val = analogRead(A0);
  angle = map(val, 0, 1023, 0, 180);
  myServo.write(angle);
  delay(50);
}
