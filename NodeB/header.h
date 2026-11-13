#include <lpc21xx.h>
#define LED (1<<11|1<<12|1<<13)
#define THRE (U0LSR>>5&1)
#define RDR (U0LSR&1)
#define DONE (ADDR>>31&1)
extern void uart0_init(unsigned int );
extern void uart0_tx(unsigned char );
extern unsigned char uart0_rx(void);
extern void uart0_str(char*);
extern void uart0_integer(int );
extern void uart0_float(double );


extern void adc_init(void);
extern unsigned int adc_read(unsigned int );

extern void delay_s(unsigned int );
extern void delay_ms(unsigned int );

typedef struct nodeA{
unsigned int byteA;
unsigned int byteB;
unsigned char ff;
unsigned char rtr;
unsigned int id;
unsigned char dlc;
}CAN;