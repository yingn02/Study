int ir1 = 13;
int ir2 = 11;
int ir3 = 12;

int mt1 = 6;
int mt2 = 3;

void setup() {
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);}

void loop() {
  
  //직진

  if(digitalRead(ir1)==1 && digitalRead(ir2)==0 && digitalRead(ir3)==1){
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    analogWrite(6,130);
    
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(3,130);}

    //좌회전

  else if(digitalRead(ir1)==0 && digitalRead(ir2)==0 && digitalRead(ir3)==1){
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    analogWrite(6,20);
    
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(3,130);}

    //우회전

    else if(digitalRead(ir1)==1 && digitalRead(ir2)==0 && digitalRead(ir3)==0){
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    analogWrite(6,130);
    
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(3,20);}




    //좌회전

    else if(digitalRead(ir1)==0 && digitalRead(ir2)==1 && digitalRead(ir3)==1){
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    analogWrite(6,20);
    
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(3,130);}

    //우회전

    else if(digitalRead(ir1)==1 && digitalRead(ir2)==1 && digitalRead(ir3)==0){
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    analogWrite(6,130);
    
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    analogWrite(3,20);}}
