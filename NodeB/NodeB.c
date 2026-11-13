#include "header.h"
#define led1 (1<<11)
#define led2 (1<<12)
#define led3 (1<<13)
char flag1=0,flag2=0,flag3=0;
int main(){
int i=0;
double speed=0,temp=0;
extern char check;
unsigned int time=0,value0=0,value1=0;
extern CAN r1;
char l1=0,l2=0,l3=0;
uart0_init(9600);
can1_init();
can1_vic_init();
IODIR0|=LED;
IOSET0=LED;
uart0_str("Node B:uart_initialized\n\r");
while(1){

	if(check){
		value0=r1.byteA&0xffff;
		uart0_str("  speed=");
		time=r1.byteA>>16&0xffff;
		speed=((value0)*120)/1023;
		uart0_float(speed);
		uart0_str("  km/hr");
		uart0_str("  temp");
		temp=((r1.byteB*3.3)/1023)*100;
		uart0_float(temp);
		uart0_str(" distance=");	
		time=(time*34300)/(200000);
		uart0_float(time);

		check=0;
		if(r1.id==0x123){
			IOSET0=led2;
			l2=0;		
			l1=1;
		
		}else if(r1.id==0x111){
			  IOSET0=led1;
			  l1=0;
			  l2=0;
		
		}else if(r1.id==0x456){
			IOCLR0=led2;
			IOSET0=led1;
			delay_ms(250);
			IOSET0=led2;
			IOSET0=led1;
			l2=1;
			l1=0;
		}else if(r1.id==0x444){
			 IOSET0=led2;
			 l2=0;
			 l1=0;
		
		}else if(r1.id==0x789){
			l3=1;
		
		}else if(r1.id==0x777){
			IOSET0=led3;
			l3=0;
		
		}

		if(l1){
		uart0_str("  Left Light is on\r\n");
		IOCLR0=led1;
		delay_ms(250);
		IOSET0=led1;	
		}
		if(l2){
			IOCLR0=led2;
			delay_ms(250);
			IOSET0=led2;
			uart0_str("  Right light is on\r\n");
		}
		if(l3){
			IOCLR0=led3;
			uart0_str("  Headlight is on\r\n");
		}
		uart0_str("\r\n\r\n\r\n\r\n");
}

}

}
