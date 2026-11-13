#include "header.h"
unsigned int result=0;
void adc_init(){
PINSEL1|=0X15400000;
ADCR=0X00200400;
}
unsigned int adc_read(unsigned int ch){
ADCR|=1<<ch	;
ADCR|=1<<24;
delay_ms(20);
while(DONE==0);
ADCR^=1<<ch;
ADCR^=1<<24;
result=ADDR>>6&0X3FF;
return result;


}
