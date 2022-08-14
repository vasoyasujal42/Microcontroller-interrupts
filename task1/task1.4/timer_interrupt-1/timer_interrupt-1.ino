int i=0;
int j=0;
void setup() {
   DDRB = B00000111;
   DDRD = B11111100;
   
   //reset Timer counter Reg A 
   TCCR1A = 0;

   //set prescaler of 256
//   TCCR1B |= (1<<CS12);
//   TCCR1B &= ~(1<<CS11);
//   TCCR1B &= ~(1<<CS10);

    TCCR1B = B00000100;
    
   //Reset Timer and set compare value 
   TCNT1 = 0;
   OCR1A = 6250;      // time 100ms=6250    t=100ms, f=10Hz  (16Mhz/(256*10)) = 6250
   
   
   //Enabel timer1 comper interrupt 
//   TIMSK1 |= (1<<OCIE1A); 
   TIMSK1 |= B00000010;
   sei(); //Enable globle interrupt
}
void loop() {
  
 }

ISR(TIMER1_COMPA_vect)
{  
   TCNT1 = 0;
   abc(); // calling abc function

}

void led()
{     cl();
      i++;
      if(i <=6 ) // when the loop rotating first PORTD pins control by this IF statment
      {          
      PORTD |= (1 << i+1);  //i+2 because bit start from 2
      }
      if(i>=7 && i<=10) // when the loop rotating first PORTB pins control by this IF statment
      {
      PORTB |= (1 << i-7);  // i-7 because bit start from 0
      }
    
    if(i==10) // for when sequnce was complited then stated from first led
    {
      i=0;
    }
}

void cl(){   // for the clear the bit
     PORTD = B00000000; 
     PORTB = B00000000;
}


//////////////////////////////////////////////////////
//function:-abc()
//when first output compare interrupt was genereted then first 
//time led will be glow for next 100ms but when secound time output  
//compare interrupt was genereted then led will low for 100ms and 
//its running in loop
/////////////////////////////////////////////////////
void abc()   //  
{
  if(j==0)
   {
    led();
   j=1;
   }
   else{
    j=0;
    cl();
   }
}
