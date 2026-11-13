#include "header.h"
//P0.16 EINT0 
//P0.14 EINT1
//P0.7 EINT2
char flag=0,led1=0,led2=0,led3=0;

CAN e;
void eint0_hanlder(void)__irq
{
delay_ms(50);
uart0_str("eint0 occured\n\r");
e.rtr=0;
e.dlc=8;
e.ff=0;
flag=1;
if(led1==0){
e.id=0x123;
led2=0;
led1=1;

}else{
e.id=0x111;
led1=0;
led2=0;
}
EXTINT=1;
VICVectAddr=0;


}
void eint1_handler(void)__irq
{
delay_ms(50);
if(led2==0){
led1=0;
led2=1;
e.id=0x456;
}else{
led1=0;
led2=0;
e.id=0x444;
}
uart0_str("eint1 occured\n\r");
e.rtr=0;
e.dlc=8;
e.ff=0;
flag=1;
EXTINT=1<<1;
VICVectAddr=0;


}

void eint2_handler(void)__irq
{
delay_ms(50);
uart0_str("eint2 occured\n\r");
if(led3==0){
led3=1;
e.id=0x789;
}else{
led3=0;
e.id=0x777;
}
e.rtr=0;
e.dlc=8;
e.ff=0;
flag=1;
EXTINT=4;
VICVectAddr=0;


}

void eint_init(void){
PINSEL0|=0x2000C000;//1100
PINSEL1|=0x1;
EXTMODE=0X7;
EXTPOLAR=0X0;
}

void eint0_vic_init(void){
VICIntSelect=0;
VICVectAddr0=(unsigned int)eint0_hanlder;
VICVectAddr1=(unsigned int)eint1_handler;
VICVectAddr2=(unsigned int)eint2_handler;

VICVectCntl0=1<<5|14;
VICVectCntl1=1<<5|15;
VICVectCntl2=1<<5|16;


VICIntEnable=1<<14|1<<15|1<<16;


}