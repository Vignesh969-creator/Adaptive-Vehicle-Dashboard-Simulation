#include "header.h"
int main(){
extern char toggle;
extern char led1;
extern char led2;
extern char flag;
extern CAN e;
unsigned int pot=0,temp=0,i=0,time=0;

uart0_init(9600);
can1_init();
adc_init();
eint_init();
eint0_vic_init();
uart0_str("Node A:uart_initialized\n\r");
while(1){
for(i=0;i<10;i++){
	temp=temp+adc_read(0);
	pot=pot+adc_read(2);
	time=get_distance();
	
}
  pot/=10;
  temp/=10;
  time/=10;


if(flag){
		e.byteA=pot|time<<16;
		e.byteB=temp;
		can1_tx(e);
		uart0_str("\r\n");
		
}else{
	e.id=0x333;
	e.dlc=8;
	e.rtr=0;
	e.byteA=pot|time<<16;
	
	
	e.byteB=temp;
	can1_tx(e);
}
uart0_str("pot=");
uart0_integer(pot);
uart0_str(" temp=");
uart0_integer(temp);
uart0_str(" id=");
uart0_integer(e.id);
uart0_str(" Time=");
uart0_integer(time);
uart0_str("\r\n");

delay_s(2);
pot=0;
temp=0;
time=0;
}
}
