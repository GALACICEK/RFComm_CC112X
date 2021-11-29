/*
 * periph_init.c
 *
 *  Created on: 28 Eyl 2021
 *      Author: @GALACICEK
 */

#include "global.h"


void     Perip_Init(void){

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer


    Perip_Init_GPIO();
    Perip_Init_CLK();
    Perip_Init_TIMA();
    Perip_Init_SPI(2);
//    __enable_interrupt();                     // Enable the global interrupt

}

/*
 * Configure ACLK = 32768Hz,
 * MCLK = DCO + XT1CLK REF = 8MHz,
 *
 */
void     Perip_Init_CLK(void){


    do
        {
            CSCTL7 &= ~(XT1OFFG | DCOFFG);      // Clear XT1 and DCO fault flag
            SFRIFG1 &= ~OFIFG;
        } while (SFRIFG1 & OFIFG);              // Test oscillator fault flag

        __bis_SR_register(SCG0);                // disable FLL
        CSCTL3 |= SELREF__XT1CLK;               // Set XT1CLK as FLL reference source
        CSCTL1 = DCOFTRIMEN_1 | DCOFTRIM0 | DCOFTRIM1 | DCORSEL_3;// DCOFTRIM=3, DCO Range = 8MHz
        CSCTL2 = FLLD_0 + 243;                  // DCODIV = 8MHz
        __delay_cycles(3);
        __bic_SR_register(SCG0);                // enable FLL
        Software_Trim();                        // Software Trim to get the best DCOFTRIM value

        CSCTL4 = SELMS__DCOCLKDIV | SELA__XT1CLK;  // Set ACLK = XT1CLK = 32768Hz
                                                   // DCOCLK = MCLK and SMCLK source
        CSCTL5 |= DIVM_0 | DIVS_0;                 // MCLK = DCOCLK = 8MHZ,
                                                   // SMCLK = MCLK = 8MHz



}

void    Software_Trim(void)
{
    unsigned int oldDcoTap = 0xffff;
    unsigned int newDcoTap = 0xffff;
    unsigned int newDcoDelta = 0xffff;
    unsigned int bestDcoDelta = 0xffff;
    unsigned int csCtl0Copy = 0;
    unsigned int csCtl1Copy = 0;
    unsigned int csCtl0Read = 0;
    unsigned int csCtl1Read = 0;
    unsigned int dcoFreqTrim = 3;
    unsigned char endLoop = 0;

    do
    {
        CSCTL0 = 0x100;                         // DCO Tap = 256
        do
        {
            CSCTL7 &= ~DCOFFG;                  // Clear DCO fault flag
        }while (CSCTL7 & DCOFFG);               // Test DCO fault flag

        __delay_cycles((unsigned int)3000 * MCLK_FREQ_MHZ);// Wait FLL lock status (FLLUNLOCK) to be stable
                                                           // Suggest to wait 24 cycles of divided FLL reference clock
        while((CSCTL7 & (FLLUNLOCK0 | FLLUNLOCK1)) && ((CSCTL7 & DCOFFG) == 0));

        csCtl0Read = CSCTL0;                   // Read CSCTL0
        csCtl1Read = CSCTL1;                   // Read CSCTL1

        oldDcoTap = newDcoTap;                 // Record DCOTAP value of last time
        newDcoTap = csCtl0Read & 0x01ff;       // Get DCOTAP value of this time
        dcoFreqTrim = (csCtl1Read & 0x0070)>>4;// Get DCOFTRIM value

        if(newDcoTap < 256)                    // DCOTAP < 256
        {
            newDcoDelta = 256 - newDcoTap;     // Delta value between DCPTAP and 256
            if((oldDcoTap != 0xffff) && (oldDcoTap >= 256)) // DCOTAP cross 256
                endLoop = 1;                   // Stop while loop
            else
            {
                dcoFreqTrim--;
                CSCTL1 = (csCtl1Read & (~DCOFTRIM)) | (dcoFreqTrim<<4);
            }
        }
        else                                   // DCOTAP >= 256
        {
            newDcoDelta = newDcoTap - 256;     // Delta value between DCPTAP and 256
            if(oldDcoTap < 256)                // DCOTAP cross 256
                endLoop = 1;                   // Stop while loop
            else
            {
                dcoFreqTrim++;
                CSCTL1 = (csCtl1Read & (~DCOFTRIM)) | (dcoFreqTrim<<4);
            }
        }

        if(newDcoDelta < bestDcoDelta)         // Record DCOTAP closest to 256
        {
            csCtl0Copy = csCtl0Read;
            csCtl1Copy = csCtl1Read;
            bestDcoDelta = newDcoDelta;
        }

    }while(endLoop == 0);                      // Poll until endLoop == 1

    CSCTL0 = csCtl0Copy;                       // Reload locked DCOTAP
    CSCTL1 = csCtl1Copy;                       // Reload locked DCOFTRIM
    while(CSCTL7 & (FLLUNLOCK0 | FLLUNLOCK1)); // Poll until FLL is locked
}

void     Perip_Init_Crys(void){

    Crystal_PXSEL0 |= Crystal_XIN_PIN | Crystal_XOUT_PIN;

}
void     Perip_Init_GPIO(void){
///* Set all GPIO to output low to reduce power consumption */


         P1DIR |=  All_BITS ;
         P1OUT = 0;
/*--------------------------------------------------*/

         P2DIR |=  ( BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7 );
         P2OUT = 0;

/*-------------------------------------------------- */
        P3DIR |=  All_BITS ;
        P3OUT = 0;

/*-------------------------------------------------- */
        P4DIR |=  All_BITS ;
        P4OUT = 0;

/*-------------------------------------------------- */
        P5DIR |=  All_BITS ;
        P5OUT = 0;
/*--------------------------------------------------*/
        P6DIR |=   ( BIT0 | BIT1 | BIT2) ;
        P6OUT = 0;
/*--------------------------------------------------*/
        Perip_Init_Crys();

         SPI_CS_PXDIR |= SPI_CS_PIN;
         SPI_CS_PXOUT |= SPI_CS_PIN;

         SPI_CS_PXDIR  |= SPI_SI_PIN;
         SPI_SI_PXSEL0 |= SPI_SI_PIN;
         SPI_SI_PXSEL1 &= ~SPI_SI_PIN;

         SPI_CLK_PXDIR  |= SPI_CLK_PIN;
         SPI_CLK_PXSEL0 |= SPI_CLK_PIN;
         SPI_CLK_PXSEL1 &= ~SPI_CLK_PIN;

         SPI_SO_PXDIR &= ~SPI_SO_PIN;
         SPI_SO_PXSEL0 |= SPI_SO_PIN;   //secondory function
         SPI_SO_PXSEL1 &= ~SPI_SO_PIN;

         //PA for CC1190
         RF_PA_EN_PxDIR |= RF_PA_EN_PIN;
         RF_PA_EN_PxOUT &=~RF_PA_EN_PIN;

         LED2_PXDIR |= LED2_PIN;
         LED2_PXOUT &=~LED2_PIN;

         LED3_PXDIR |= LED3_PIN;
         LED3_PXOUT &=~LED3_PIN;

         RF_POWER_EN_PXDIR |= RF_POWER_EN_PIN;
         RF_POWER_EN_OFF;

         RF_GPIO2_PXOUT |= RF_GPIO2_PIN;
         RF_GPIO2_PXREN |= RF_GPIO2_PIN;    //pull-up
         RF_GPIO2_PXIES |= RF_GPIO2_PIN;    //falling edge
//         RF_GPIO2_PXIES &=~ RF_GPIO2_PIN;    //rising edge




/*--------------------------------------------------*/
         PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                                    // to activate previously configured port settings


}


//TIMA0 CONFÝGURATÝON----------------------------------------------------------------------
//  time = TIM_PERIODE/ CLK
//
void    Perip_Init_TIMA(void){

     TA0CCTL0 = CCIE;                          // TACCR0 interrupt enabled
     TA0CCR0 = TIM_PERIODE;
     TA0CTL = TASSEL__SMCLK | MC__UP | ID_1;          // ACLK, UP mode, divider=1

}


void     Perip_Init_UARTA(void){


}

//SPI CONFÝGURATÝON----------------------------------------------------------------------
/*
 * SPI 3-Wire Master 8-bit
 *  fBRCLK =  4MHz // a period of 250 ns.
 */
void    Perip_Init_SPI(uint8_t presclaerval){

 //   Control Word Register   250 ns

//    SYSCFG3|=USCIA0RMP;                       //Set the remapping source
    UCA0CTLW0 |= UCSWRST;                       // **Put state machine in reset**

    UCA0CTLW0 |= UCMST|UCSYNC|UCCKPL|UCMSB;      //  Master mode, Synchronous mode ,MSB first
                                                // Clock polarity high, MSB
    UCA0CTLW0 |= UCSSEL__SMCLK;                  // Select SMCLK
    UCA0BR0 = presclaerval;                      // BRCLK = SMCLK/2  prescaler setting
    UCA0BR1 = 0;                                //
    UCA0MCTLW = 0;                              // No modulation
    UCA0CTLW0 &= ~UCSWRST;                      // **Initialize USCI state machine**
    UCA0IE =0;                                  // Enable USCI_A0 RX interrupt
    UCA0IFG &=~UCRXIFG;

    __delay_cycles(5);

}
