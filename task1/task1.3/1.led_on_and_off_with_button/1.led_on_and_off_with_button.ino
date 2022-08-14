void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT_PULLUP);
}

void loop() {
    if(digitalRead(3)==0)
    {
     digitalWrite(2,1);   
    }
    else
    {
      digitalWrite(2,0);
    }
}
