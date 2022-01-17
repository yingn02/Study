int led1 = 5; //led를 PWM 5번에 연결
int led2 = 11; //led를 PWM 5번에 연결

void setup() {
  pinMode(led1, OUTPUT); //LED는 출력
  pinMode(led2, OUTPUT); 

}

void loop() {
  analogWrite(led1, 50); //analogWrite값은 0~255
  analogWrite(led2, 255);
}
