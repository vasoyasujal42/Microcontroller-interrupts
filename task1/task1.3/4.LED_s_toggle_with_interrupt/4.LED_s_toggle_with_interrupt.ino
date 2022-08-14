const uint8_t led1=3; // here i use contant unsign interger for 8 bit microcontroller
const uint8_t led2=4;
const uint8_t led3=5;
const uint8_t led4=6;
const uint8_t led5=7;
const uint8_t led6=8;
const uint8_t led7=9;
const uint8_t led8=10;
const uint8_t led9=11;
const uint8_t button=2;

// Globles

int READ=1;
int j;

void setup() {
  for(int i=3;i<=11;i++)
  {
  pinMode(i,OUTPUT);
  }
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button),toggle,LOW);
}

void loop() 
{   READ=digitalRead(button);
    
    if(READ==0)
     {  
        for(j=3;j<=11;j++)
        {
        digitalWrite(j,1);
        delay(100);
        digitalWrite(j,0);
        delay(10);
        }
    }
}

void toggle()
{ 
 j=3;
}
