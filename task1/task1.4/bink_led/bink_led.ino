const int led = PB5;

//counter and comper value
const uint16_t t1_load = 0;
const uint16_t t1_comp = 6250;// time 100ms

void setup() {
   DDRB |= (1<<led);
   
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
{
   TCNT1 = t1_load;
   PORTB ^= (1<<led); 
}
