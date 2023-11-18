#include<avr/io.h>
#include<avr/interrupt.h>

#define F_CPU 16000000

ISR(TIMER1_OVF_vect){
  PORTB ^= 0xFF;
  TCNT1 = 65535 - (F_CPU/1024);
}  

int main(void){
  DDRB = 0xFF;

  TCNT1 = 0;

  //set prescalar to 1024
  //16M/1024
  TCCR1B = (1<< CS10) | (1<< CS12);
  TCCR1A = 0x00;
  TIMSK1 = (1<< TOIE1);

  sei();
  while(1){

  }
 
}