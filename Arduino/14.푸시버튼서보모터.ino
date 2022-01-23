#include <Servo.h>
Servo myServo; //서보모터 객체를 생성하고 이름을 myServo로 설정
int motorPin = 12; //서보모터를 12번 핀에 연결
int pushPin = 7; //푸시버튼을 7번 핀에 연결
int angle = 90; //초기에 샤프트는 중간에 위치
int state = 0; //회전방향 설정 (0은 시계방향 1은 반시계방향)

void setup() {
  myServo.attach(motorPin); //서보모터를 아두이노의 해당 핀12에 연결
  pinMode(pushPin,INPUT); //푸시버튼이 연결된 핀을 입력모드로 설정
  Serial.begin(9600); //시리얼모니터와 통신
  Serial.println("Enter the push button.");
}

void loop() {
  if(digitalRead(pushPin) == HIGH){
    if(state == 0){
      angle += 1; //시계방향으로 각도 1씩 증가
      if(angle >= 180)
        state = 1; //반시계방향으로 방향전환
       myServo.write(angle); //angle값을 서보에게 전달하여 기록
       delay(10);
       Serial.println(angle); //현재 각도 시리얼모니터에 출력
      }
    else {
      angle -= 1; // 각도를 -1씩 증가
      if(angle <= 0)
        state = 0; //시계방향으로 방향전환
        myServo.write(angle);
        delay(10);
        Serial.println(angle); //현재 각도 시리얼모니터에 출력
      }
    }
  }
