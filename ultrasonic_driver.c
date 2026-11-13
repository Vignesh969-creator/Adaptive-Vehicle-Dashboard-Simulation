#include "header.h"
#define TRIG (1<<4)
#define ECHO (IOPIN0>>5&1)

unsigned int get_distance(){

unsigned int time=0;
IODIR0|=TRIG;
T0TCR=0X02;
  T0PR=60-1;
  T0TC=T0PC=0;
  IOCLR0=TRIG;
  delay_us(2);
  IOSET0=TRIG;
  delay_us(10);
  IOCLR0=TRIG;

  while(ECHO==0);
  T0TCR=0X01;
  while(ECHO==1);
  T0TCR=0;
  time=T0TC;

	return time;




}