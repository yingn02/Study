//가변 저항 테스트
void setup() {
  Serial.begin(9600);

}

void loop() {
  int a = analogRead(A0);
  Serial.println(a);
  delay(100);
}
