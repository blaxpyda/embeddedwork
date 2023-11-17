#include<avr/io.h>
#include<avr/interrupt.h>

int extraTime = 0;

int main(void){
  DDRB = 0x01;
  TCCR0A = (1<< WGM01); //sets ctc bit
  OCR0A = 195;
  TIMSK0 = (1<< OCIE0A);

  sei();
  TCCR0B = (1<< CS02 | (1<< CS00));

  while(1){

  }
  

}
ISR(TIMER0_COMPA_vect){
  extraTime++;
  if(extraTime>100){
    PORTB ^= (1<< PORTB);
  }
}