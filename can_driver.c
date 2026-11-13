#include "header.h"
#define TCS (C1GSR>>3&1)
#define RBS (C1GSR&1)
void can1_init(void){
VPBDIV=1;
PINSEL1|=0x00040000;
C1MOD=1;
AFMR=2;
C1BTR=0x001C001D;
C1MOD=0;
}

void can1_tx(CAN v){

	C1TID1=v.id;
	C1TFI1=(v.dlc<<16);
	if(v.rtr==0){
	  	C1TDA1=v.byteA;
		C1TDB1=v.byteB;
	
	
	}else{
		C1TFI1|=(1<<30);
	
	}
	C1CMR=0X21;
	while(TCS==0);
}
void can1_rx(CAN*ptr){

while(RBS==0);
ptr->id=C1RID;
ptr->ff=C1RFS>>31&1;
ptr->rtr=C1RFS>>30&1;
if(ptr->rtr==0){
ptr->byteA=C1RDA;
ptr->byteB=C1RDB;
}
ptr->dlc=((C1RFS>>16)&0XF);

C1CMR=0X4;

}
