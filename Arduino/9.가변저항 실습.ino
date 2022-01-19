int val = 0;
int ledPin = 13;

void setup() {
  pinMode(ledPin,OUTPUT);
}

void loop() {
  val = analogRead(A0); // A0핀에 꽂혀있는 것을 읽어오시오

  if(val > 512){
    digitalWrite(ledPin,HIGH);
    delay(val); //잠시 프로그램을 종료하시오
    }
  else{
    digitalWrite(ledPin,LOW);
    delay(val);
    }
}
