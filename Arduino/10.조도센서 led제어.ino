int led = 3; //~3

void setup() {
  pinMode(led, OUTPUT);

}

void loop() {
  int sensorValue = analogRead(A0);
  if (sensorValue > 700) analogWrite(3,550);
  else analogWrite(3,1023);
  delay(200);
}
