int inPin = 4; // pushbutton은 디지털 핀 4에 연결됨
int val = 0; // 읽은 값을 저장할 변수

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT); //디지털 7을 입력으로 설정
}

void loop() {
  val =digitalRead(inPin);
  Serial.println(val);
  delay(100);

}
