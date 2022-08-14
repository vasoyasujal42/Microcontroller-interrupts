const uint8_t led=2; // here i use contant unsign interger for 8 bit microcontroller
const uint8_t button=3;

// Globles
uint8_t led_state=0;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button),toggle,FALLING);
}

void loop() 
{      
    delay(200);
}

void toggle()
{
  led_state=!led_state;
  digitalWrite(led,led_state);
}
