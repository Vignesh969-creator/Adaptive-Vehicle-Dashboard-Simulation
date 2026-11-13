#include "header.h"


void adc_init(void){
PINSEL1|=0X15400000;
ADCR=0x00201300;
}

unsigned int adc_read(unsigned int ch){
unsigned int result=0;
ADCR|=1<<ch;
ADCR|=1<<24;
while(DONE==0);
ADCR^=1<<ch;
ADCR^=1<<24;
result=((ADDR>>6)&0X3FF);
return result;


}
