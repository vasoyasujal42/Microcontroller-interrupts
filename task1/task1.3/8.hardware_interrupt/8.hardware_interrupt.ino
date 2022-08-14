//Made by Sujal Vasoya
//description:- made 9 led rotating when we press push button and also when we press button secound time start 
//              rotating from first led

const uint8_t button=2; // Here i use contant unsign interger for 8 bit microcontroller

//Globle variable
int i=0;
int j=0;
int a=1;
void setup() {
  DDRD = B11111000; // set direction of registor pin-3 to pin 7 OUTPUT and pin-2 as INPUT 
  DDRB = B00001111; // set direction of registor pin-8 to pin 11 OUTPUT

  // set pin-2 to pull-up input
  PORTD |= (1<<button);  //pull-up pin-2.
     
  //Low level of INT0 generates interrupt
  //EICRA &= ~(1<<ISC00);  //when ISC01 and ISC00 are 0 then = LOW level
  //EICRA &= ~(1<<ISC01); //ISC00
  
  EICRA = 0x01;  
  EICRA = 0x02;

  //enable interrupt for INT0
  //EIMSK |=(1<<INT0);  
    EIMSK = 0x01;
  //enable globle interrupt
  sei();
}
 
void loop() 
{ 
}

void ledblink()
{
  for(i=0;i<=8;i++)
   { 
      if(i <= 4) // when the loop rotating first PORTD pins control by this IF statment
      {          
      PORTD |= (1 << i+3);  //i+3 because bit start from 3
      delay(10000);
      PORTD &= ~B11111000;  // clear the bits
      }
      if(i>=5 && i<=8) // when the loop rotating first PORTB pins control by this IF statment
      {
      PORTB |= (1 << i-5);  // i-5 because bit start from 0
      delay(10000);
      PORTB &= ~B00001111;  // clear the bits
      }
    }
}
ISR(INT0_vect) //Interrupt Service Routine 
{  if(a==0)
    {
     ledblink();  
     a=1;
    }
    else
    {
    a=0;
    }
}
