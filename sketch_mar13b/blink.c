#include <msp430.h>
#include "mystuff.h"
 
volatile unsigned int i;

#define  lessThan(X, Y)  ((X) < (Y) ? (1) : (0))




void main(void) {
 
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR |= (1<<0);
  P1OUT &= ~(1<<0);
  int x = 5;
  int y = 10;
  
  while(1) {

    swap(&x,&y);

    while(lessThan(x,y)){
      P1OUT ^= (1<<0);
      i = 65535;// SW Delay
      while(i --!= 0);
    }
  
  }
}


