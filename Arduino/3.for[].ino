int myLed[] = {2,4,6};
int ledDelay[] = {500,300,500};

void setup()
{
  for(int i = 0; i < 3; i++)
  {
    pinMode(myLed[i], OUTPUT);  
  }
 
}

void loop() 
{
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(myLed[i],HIGH);
    delay(ledDelay[i]);
    digitalWrite(myLed[i],LOW);
    delay(ledDelay[i]);
  }
}
