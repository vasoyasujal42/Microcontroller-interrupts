// made by sujal
// project description:- learning timer interrupt
// blink 9 (pin 2-10) led in sequence with push button (pin 11) no added any pull up registor externally
// https://www.javatpoint.com/avr-input-output-port-programming
// https://www.hackster.io/Hack-star-Arduino/learn-arduino-port-manipulation-2022-10f9af
// https://www.arduino.cc/en/Reference/PortManipulation
// https://learn.sparkfun.com/tutorials/digital-logic
// https://www.youtube.com/watch?v=6q1yEb_ukw8
// https://www.youtube.com/watch?v=yGJq2XxfdlY
// https://www.youtube.com/watch?v=UhTRrjYXqPU
// https://www.youtube.com/watch?v=dLYeuXTsmgQ

void setup() {
  DDRD = B11111100; // set direction of registor
  DDRB = B00000111; // set direction of registor
  PORTB = B00001000; // pull-up registor
  
}

void loop() 
{ int READ;
  PORTB = B00001000; // pull-up registor
  READ = (PINB >> 3 & B00001000 >> 3); // read B3 = pin 10
  Serial.println(READ);
  if(READ == 0)
  {   
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
    PORTB = B00001001;   
    delay(100);
    cl();
    PORTB = B00001010;   
    delay(100);
    cl();
    PORTB = B00001100;   
    delay(100);
    cl();  
  } 
}
//////////////////////////////////
//function name: cl()
//description: for clear the bits
//////////////////////////////////
void cl()
{
PORTD &= !B11111111;
PORTB &= !B00000111;
}
