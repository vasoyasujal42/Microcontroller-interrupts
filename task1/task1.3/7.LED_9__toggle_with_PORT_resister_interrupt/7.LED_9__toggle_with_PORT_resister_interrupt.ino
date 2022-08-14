//Made by Sujal Vasoya
//description:- made 9 led rotating when we press push button and also when we press button secound time start 
//              rotating from first led

const uint8_t button=2; // Here i use contant unsign interger for 8 bit microcontroller

//Globle variable
int i=0;
int j=0;

void setup() {
  DDRD = B11111000; // set direction of registor pin-3 to pin 7 OUTPUT and pin-2 as INPUT 
  DDRB = B00001111; // set direction of registor pin-8 to pin 11 OUTPUT

  // set pin-2 to pull-up input
  PORTD |= (1<<button);  //pull-up pin-2.
     
  //Low level of INT0 generates interrupt
  EICRA &= ~(1<<ISC01);  //when ISC01 and ISC00 are 0 then = LOW level
  EICRA &= ~(1<<ISC00);

  //enable interrupt for INT0
  EIMSK |=(1<<INT0);  

  //enable globle interrupt
  sei();
}
 
void loop() 
{ int READ;
  READ = (PIND >> 2 & B00000100 >> 2); // Read B3 = pin 2    
    if(READ == 0)
    { 
      for(i=0;i<=8;i++)
      {   // if we not apply two separate IF then when interrupt is generate if we in first if condition then not any 
          // problem occurs but if we in secound loop and interrupt is generate then it's not start from first its stat
          // from 6th led or loop rotating in PORTD resister.
        if(i <= 4) // when the loop rotating first PORTD pins control by this IF statment
        {          
        PORTD |= (1 << i+3);  //i+3 because bit start from 3
        delay(200);
        PORTD &= ~B11111000;  // clear the bits
        }
        if(i>=5 && i<=8) // when the loop rotating first PORTB pins control by this IF statment
        {
        PORTB |= (1 << i-5);  // i-5 because bit start from 0
        delay(200);
        PORTB &= ~B00001111;  // clear the bits
        }
      }  
    }
}

ISR(INT0_vect) //Interrupt Service Routine 
{  
  i=0;
  j=0;
}
