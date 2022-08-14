int i=0;
int j=0;

void setup() {
   DDRB = B00001111;    // led pin configauration pin 3-11, button pin-2 
   DDRD = B11111000;    //(DDRD /DDRB = Data Direction register PortD/PortB ) 

   
//////////////////////////-->External Interrupt<--//////////////////////////////
   // set pin-2 to pull-up input
   PORTD |= (1<<2);     //pull-up pin-2. (PORTD = The Port B Data Register)
     
   //Low level of INT0 generates interrupt
   //when ISC01 and ISC00 are 0 then = LOW level
   EICRA = 0x02;        //(EICRA = Exterbal Interrupt Control Register A)

   //enable interrupt for INT0  
   EIMSK = 0x01;        //(EIMSK = External Interrupt Mask Register)
///////////////////////////////////////////////////////////////////////////////

   
//////////////////////////-->Timer Interrupt<--////////////////////////////////  
   //reset Timer counter Reg A 
   TCCR1A = 0x00;       //(TCCR1A = Timer/Counter1 Control Register A)

   //set prescaler of 256
   TCCR1B = B00000100;  //(TCCR1B = Timer/Counter1 Control Register B)
    
   //Reset Timer  
   TCNT1 = 0;           //(TCNT = Timer/Counter1)

   //Set compare value
   //(OCR1A = Output Compare Register A)
   OCR1A = 6250;        //time 100ms=6250    t=100ms, f=10Hz  (16Mhz/(256*10)) = 6250
   
   //Enabel timer1 comper interrupt 
   //(TIMSK1 = Timer/Counter1 Interrupt Mask Register)
   //TIMSK1 |= B00000010;  //Enabel timer1 comper interrupt 
     TIMSK1 = B00000000;   //Disable timer1 comper interrupt 
////////////////////////////////////////////////////////////////////////////////

   sei(); //Enable globle interrupt
}


void loop() 
{  

}

ISR(INT0_vect) //Interrupt Service Routine 
{  
    TIMSK1 = B00000010; //Enabel timer1 comper interrupt 
    OCR1A = 6250;       //Set comper match interrupt value
}


ISR(TIMER1_COMPA_vect)
{  
   TCNT1 = 0;          //Reser Timer1 
   abc(); // calling abc function   
}

void led()    // led function for led sequnce 
{     cl();   // clear the led
      i++;
      if(i <=6 ) // when the loop rotating first PORTD pins control by this IF statment
      {          
      PORTD |= (1 << i+1);  //i+2 because bit start from 2
      }
      if(i>=7 && i<=11) // when the loop rotating first PORTB pins control by this IF statment
      {
      PORTB |= (1 << i-7);  // i-7 because bit start from 0
      }
    
    if(i==11) // for when sequnce was complited then stated from first led
    {
      i=0;
      TIMSK1 = B00000000;   //Disable timer1 comper interrupt 
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
