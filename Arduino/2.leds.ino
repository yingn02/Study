int led1 = 2, led2 = 4, led3 = 6;

void setup() 
{
pinMode(led1, OUTPUT); //핀모드 출력으로 설정
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT); 
}

void loop() 
{
digitalWrite(led1, HIGH); //LED에 5V 공급
digitalWrite(led2, HIGH); 
digitalWrite(led3, HIGH); 
delay(1000); 
digitalWrite(led1, LOW); //LED에 0V 공급
digitalWrite(led2, LOW); 
digitalWrite(led3, LOW); 
delay(1000); 
}
