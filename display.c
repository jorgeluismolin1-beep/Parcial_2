Display C
#define F_CPU 1000000UL

#include <avr/io.h>

#include <avr/pgmspace.h>

#include <util/delay.h>
 
const uint8_t tabla[] PROGMEM={

    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,

0x7D, 0x07 , 0x7F, 0x67, 0x77, 0x7C,

0x39 , 0x5E, 0x79 , 0x71

};
 
void setup()

{

}
 
int main()

{

uint8_t conta;

  DDRB=0x00;

  PORTB=0xFF;

  DDRD=0xFF;

  conta=0;

  PORTD=0x3F;

  while(1){

if (!(PINB&0x01)){

conta = conta+1;

conta = conta%16;   

PORTD = pgm_read_byte(&tabla[conta]);

   _delay_ms(1000);

}

}

}
 
