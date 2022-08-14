const uint8_t led=3; // here i use contant unsign interger for 8 bit microcontroller
const uint8_t button=2;

void setup() {
  // set pin-3 to pull-up input
  DDRD &= ~(1<<button);  //pinMode(2,INPUT_PULLUP);
  PORTD |= (1<<button); //pull-up pin-3.
  
  // set led to output
  DDRD |= (1<<led); //pinMode(3,OUTPUT);
   
  //falling edge of INT0 generates interrupt
  EICRA |=(1<<ISC01);
  EICRA &= ~(1<<ISC00);

  //enable interrupt for INT0
  EIMSK |=(1<<INT0);  

  //enable globle interrupt
  sei();
}
 
void loop() 
{      
    delay(500);
}

ISR(INT0_vect) 
{
  PORTD ^= (1<<led);
}
