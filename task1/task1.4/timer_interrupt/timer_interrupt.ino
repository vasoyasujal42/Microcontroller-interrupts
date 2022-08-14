int i=0;

//counter and comper value
const uint16_t t1_load = 0;
const uint16_t t1_comp = 10000;// time 100ms=6250

void setup() {
   DDRB = B00011111;
   DDRD = B11111100;
   //reset Timer counter Reg A 
   TCCR1A = 0;

   //set prescaler of 256
   TCCR1B |= (1<<CS12);
   TCCR1B &= ~(1<<CS11);
   TCCR1B &= ~(1<<CS10);

   //Reset Timer and set compare value 
   TCNT1 = t1_load;
   OCR1A = t1_comp;

   //Enabel timer1 comper interrupt 
   TIMSK1 = (1<<OCIE1A); 

   sei(); //Enable globle interrupt
}
void loop() {
  delay(500);
 }

ISR(TIMER1_COMPA_vect)
{  PORTD = B00000000;
   PORTB = B00000000;
   TCNT1 = t1_load;
   
   led(); 
}

void led()
{    i++;
      if(i <= 6) // when the loop rotating first PORTD pins control by this IF statment
      {          
      PORTD |= (1 << i+1);  //i+3 because bit start from 3
      }
      if(i>=6 && i<=10) // when the loop rotating first PORTB pins control by this IF statment
      {
      PORTB |= (1 << i-6);  // i-5 because bit start from 0
      }
    
    if(i==10)
    {
      i=0;
    }
}
