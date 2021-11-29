/*
 * interrrupts.c
 *
 *  Created on: 28 Eyl 2021
 *      Author: @GALACICEK
 */

#include "global.h"

volatile uint32_t timeTick;
Flag_t flag;

// Timer0_A0 interrupt service routine

#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR (void)
{
//    LED1_TOGGLE;
    timeTick++;
//   __bic_SR_register_on_exit(LPM3_bits);    // Wake up
}



#pragma vector=PORT3_VECTOR
__interrupt void Port_3(void){

    if(RF_GPIO2_PXIFG & RF_GPIO2_PIN){

        flag.Bits.CC1120_GPIO2 = 1;
        RF_GPIO2_ClrFLAG;
    }

//    __bic_SR_register_on_exit(LPM3_bits);   // Exit LPM3
}
