#include "header.h"
void delay_s(unsigned int s){
T0PR=60000000-1;
T0TC=T0PC=0;
T0TCR=0X2;
T0TCR=0X1;
while(T0TC<s);
T0TCR=0X0;
}

void delay_ms(unsigned int ms){
T0PR=60000-1;
T0TC=T0PC=0;
T0TCR=0X2;
T0TCR=0X1;
while(T0TC<ms);
T0TCR=0X0;
}

void delay_us(unsigned int us){
T0PR=60-1;
T0TC=T0PC=0;
T0TCR=0X2;
T0TCR=0X1;
while(T0TC<us);
T0TCR=0X0;
}