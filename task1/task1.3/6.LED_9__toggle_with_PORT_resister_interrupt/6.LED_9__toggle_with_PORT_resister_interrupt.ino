const uint8_t button=2; // here i use contant unsign interger for 8 bit microcontroller
int i=0;
int j=0;
void setup() {
  DDRD = B11111000; // set direction of registor
  DDRB = B00001111; // set direction of registor

  // set pin-2 to pull-up input
  DDRD &= ~(1<<button);  //pinMode(2,INPUT_PULLUP);
  PORTD |= (1<<button); //pull-up pin-2.
     
  //low level of INT0 generates interrupt
  EICRA &= ~(1<<ISC01);
  EICRA &= ~(1<<ISC00);

  //enable interrupt for INT0
  EIMSK |=(1<<INT0);  

  //enable globle interrupt
  sei();
}
 
void loop() 
{ int READ;
  READ = (PIND >> 2 & B00000100 >> 2); // read B3 = pin 2    
    if(READ == 0)
    { 
      for(i=0;i<=4;i++)
      {
        PORTD |= (1 << i+3);
        delay(200);
        PORTD &= ~B11111000;
      }  
      for(j=0;j<=3;j++)
      { 
        PORTB |= (1 << j);
        delay(200);
        PORTB &= ~B00001111;
      }  
    }
}

ISR(INT0_vect) 
{  
  //PORTD &=! (B11111000);
  i=0;
  j=0;
  //PORTD ^= (1<<led);
}
