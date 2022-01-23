#include <Servo.h>// 서보모터 라이브러리
Servo myServo; //서보모터 사용을 위한 객체 생성
int motor = 12; //서보모터의 핀
int angle = 90; //서보모터 초기 각도 값

void setup() {
  myServo.attach(motor); //서보모터 연결
  Serial.begin(9600);
  Serial.println("Initial angle : 90 degrees"); //초기값 출력
  Serial.println("Enter U or D"); //U 또는 D 입력하세요
  Serial.println("U: Increase the angle by 5 degrees."); //+5도
  Serial.println("D: Decrease the angle by 5 degrees."); //-5도
}

void loop() {
  if(Serial.available()){ //시리얼모니터가 사용가능일 때 
    char input = Serial.read(); //문자 입력받기 (=scanf)
    if(input == 'U' || input == 'u'){ //U를 입력받으면
      for(int i = 0; i < 5; i++){ //현재 각도에서 +15도
        angle += 1;
        if(angle >= 180)
          angle = 180;
        myServo.write(angle);
        delay(10);
        }
        Serial.println(angle); // 현재 각도 출력
      }
      //
      else if(input == 'D' || input == 'd'){ //D를 입력받으면
        for(int i = 0; i < 5; i++){//현재 각도에서 -15도
          angle -= 1;
          if(angle <= 0)
            angle = 0;
            myServo.write(angle);
            delay(10);          
          }
          Serial.println(angle); //현재 각도 출력
        }
        else if(input == '\n'){ 
          //엔터키 입력에는 무반응
          }
        else { //U 혹은 D 의외의 문자를 입력받았을 때 
          Serial.println("wrong character!!");
          }
        }
      }
