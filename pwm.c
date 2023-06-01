#include <msp430.h> 
void configuracion_Timer(void);

/**
 * main.c
 */
int main(void)
{
    configuracion_Timer();

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR |=BIT6;
    P1SEL1 |=BIT6;
    P1SEL0 |=BIT6;

    TA0CTL = TASSEL_2  + MC_1;
    TA0CCTL1 = OUTMOD_7;

    TA0CCR0 = 100; //frec. de se al
    TA0CCR1 = 95;  //ciclo de servicio

    PM5CTL0 &= ~LOCKLPM5;


}

void configuracion_Timer(void){
    CSCTL0_H = CSKEY_H;
    CSCTL1 = DCOFSEL_0;
    CSCTL2 = SELA__VLOCLK |SELS__DCOCLK | SELM__DCOCLK;
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;
    CSCTL0_H = 0;

}