const uint8_t led=2; // here i use contant unsign interger for 8 bit microcontroller
const uint8_t button=3;
// Globles
uint8_t led_state=0;
uint8_t button_prev=1;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT_PULLUP);
}

void loop() 
{      
    uint8_t button_state = digitalRead(button);
      
    if((button_state==LOW)&&(button_prev==HIGH))
    {
     led_state=!led_state;
     digitalWrite(led,led_state);   
    }
    button_prev=button_state;
    delay(10);
}
