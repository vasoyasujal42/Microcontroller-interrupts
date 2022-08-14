// teammates name sujal chintan darshnik
// project description:- learning timer interrupt
// blink 8 led in sequence pin 2-9 
void setup() {
  DDRD = B11111100; 
  DDRB = B00000011;
}

void loop() {
  PORTD |=  B00000100;   // Add OR logical expression for add bit
  delay(100);
  PORTD &= !B00000100;   // Add AND logical expression for remove bit
  delay(100);

  PORTD = B00001000;   
  delay(100);
  cl();
  PORTD = B00010000;   
  delay(100);
  cl();
  PORTD = B00100000;   
  delay(100);
  cl();
  PORTD = B01000000;   
  delay(100);
  cl();
  PORTD = B10000000;
  delay(100);
  cl();
  PORTB = B00000001;   
  delay(100);
  cl();
  PORTB = B00000010;   
  delay(100);
  cl();
}

void cl()
{
PORTD = B00000000;
PORTB = B00000000;
}
