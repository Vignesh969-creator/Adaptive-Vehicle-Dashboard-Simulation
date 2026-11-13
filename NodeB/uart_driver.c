#include "header.h"
void uart0_init(unsigned int baud){
unsigned int result=60000000/(16*baud);
PINSEL0|=0X5;
U0LCR=0X83;
U0DLL=result&0xff;
U0DLM=((result>>8)&0xff);
U0LCR=0X03;
}

void uart0_tx(unsigned char data){
U0THR=data;
while(THRE==0);
}

unsigned char uart0_rx(void){
while(RDR==0);
return U0RBR;
}

void uart0_str(char*p){
while(*p){
uart0_tx(*p);
p++;
}
}

void uart0_integer(int b){
char flag=0;
char a[40];
long long int n;
int i=0;
if(b==0){
uart0_tx('0');
}
if(b<0){
flag=1;

}
if(flag){
uart0_tx('-');
n=-b;
}else{
n=b;
}

while(n){
a[i++]=n%10+48;
n/=10;
}

for(i=i-1;i>=0;i--)
	uart0_tx(a[i]);
}


void uart0_float(double n){

int a=(int)n;
uart0_integer(n);
a=n*1000000-a*1000000;
uart0_tx('.');
uart0_integer(a);


}
