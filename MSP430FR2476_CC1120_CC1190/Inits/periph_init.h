/*
 * periph_init.h
 *
 *  Created on: 28 Eyl 2021
 *      Author: Fydil
 */

#ifndef PERIPH_INIT_H_
#define PERIPH_INIT_H_

//LIBS--------------------------------------------------
#include <msp430.h>

//DEFINES-----------------------------------------------
#define MCLK_FREQ_MHZ        8                    // MCLK = 8MHz

#define TIM_PERIODE          8000  // 1ms
#define All_BITS             (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7 )

#if defined(UART_BAUDRATE_9600)

#define UART_BR0            3
#define UART_BR1            0x00
#define UART_BRS            0x5300
#define UART_BRF            UCBRF_0
#define UART_UCOS16         0x0000
#endif

#if defined(UART_BAUDRATE_57600)    //BRCLK = 8MHz.

#define UART_BR0            8
#define UART_BR1            0x00
#define UART_BRS            0xF700
#define UART_BRF            UCBRF_10
#define UART_UCOS16         UCOS16
#endif

#if defined(UART_BAUDRATE_38400)    //BRCLK = 8MHz.

#define UART_BR0            13
#define UART_BR1            0x00
#define UART_BRS            0x8400
#define UART_BRF            UCBRF_1
#define UART_UCOS16         UCOS16
#endif


/*---------------------------------------------------------------------*/
#define Crystal_PXOUT            P2OUT
#define Crystal_PXDIR            P2DIR
#define Crystal_PXSEL0           P2SEL0
#define Crystal_PXSEL1           P2SEL1
#define Crystal_XIN_PIN          BIT1
#define Crystal_XOUT_PIN         BIT0


#define LED1_PXIN              P1IN
#define LED1_PXOUT             P1OUT
#define LED1_PXDIR             P1DIR         //Direction Registers
#define LED1_PXREN             P1REN        //Pullup or Pulldown Resistor Enable Registers
#define LED1_PIN               BIT0
#define LED1_PXSEL0            P1SEL0          //Function Select Registers
#define LED1_PXSEL1            P1SEL1          //Function Select Registers
#define LED1_PXIES             P1IES           //  Hi/Low edge
#define LED1_PXIE              P1IE           // interrupt enabled
#define LED1_PXIFG             P1IFG          // IFG
#define LED1_ON                LED1_PXOUT |=  LED1_PIN
#define LED1_OFF               LED1_PXOUT &=~ LED1_PIN
#define LED1_TOGGLE            LED1_PXOUT ^= ~ LED1_PIN


#define LED2_PXIN              P5IN
#define LED2_PXOUT             P5OUT
#define LED2_PXDIR             P5DIR
#define LED1_PXREN             P5REN        //Pullup or Pulldown Resistor Enable Registers
#define LED2_PIN               BIT1
#define LED2_PXSEL0            P5SEL0          //Function Select Registers
#define LED2_PXSEL1            P5SEL1          //Function Select Registers
#define LED2_PXIES             P5IES           //  Hi/Low edge
#define LED2_PXIE              P5IE           // interrupt enabled
#define LED2_PXIFG             P5IFG          // IFG
#define LED2_ON                LED2_PXOUT |=  LED2_PIN
#define LED2_OFF               LED2_PXOUT &=~ LED2_PIN
#define LED2_TOGGLE            LED2_PXOUT ^= ~ LED2_PIN


#define LED3_PXIN              P5IN
#define LED3_PXOUT             P5OUT
#define LED3_PXDIR             P5DIR
#define LED3_PXREN             P5REN        //Pullup or Pulldown Resistor Enable Registers
#define LED3_PIN               BIT0
#define LED3_PXSEL0            P5SEL0          //Function Select Registers
#define LED3_PXSEL1            P5SEL1          //Function Select Registers
#define LED3_PXIES             P5IES           //  Hi/Low edge
#define LED3_PXIE              P5IE           // interrupt enabled
#define LED3_PXIFG             P5IFG          // IFG
#define LED3_ON                LED3_PXOUT |=  LED3_PIN
#define LED3_OFF               LED3_PXOUT &=~ LED3_PIN
#define LED3_TOGGLE            LED3_PXOUT ^= ~ LED3_PIN

#define RF_POWER_EN_PXOUT             P3OUT
#define RF_POWER_EN_PXDIR             P3DIR
#define RF_POWER_EN_PIN               BIT7
#define RF_POWER_EN_OFF               RF_POWER_EN_PXOUT &=~ RF_POWER_EN_PIN
#define RF_POWER_EN_ON                RF_POWER_EN_PXOUT |=  RF_POWER_EN_PIN


#define RF_GPIO2_PXIN              P3IN
#define RF_GPIO2_PXOUT             P3OUT
#define RF_GPIO2_PXDIR             P3DIR         //Direction Registers
#define RF_GPIO2_PXREN             P3REN        //Pullup or Pulldown Resistor Enable Registers
#define RF_GPIO2_PIN               BIT5
#define RF_GPIO2_PXSEL0            P3SEL0          //Function Select Registers
#define RF_GPIO2_PXSEL1            P3SEL1          //Function Select Registers
#define RF_GPIO2_PXIES             P3IES           //  Hi/Low edge
#define RF_GPIO2_PXIE              P3IE           // interrupt enabled
#define RF_GPIO2_PXIFG             P3IFG          // IFG
#define RF_GPIO2_ClrFLAG           RF_GPIO2_PXIFG &= ~RF_GPIO2_PIN
#define RF_GPIO2_ENFLAG            RF_GPIO2_PXIFG |= RF_GPIO2_PIN
#define RF_GPIO2_IntEN             RF_GPIO2_PXIE  |= RF_GPIO2_PIN



#define RF_GPIO0_PXIN              P4IN
#define RF_GPIO0_PXOUT             P4OUT
#define RF_GPIO0_PXDIR             P4DIR         //Direction Registers
#define RF_GPIO0_PXREN             P4REN        //Pullup or Pulldown Resistor Enable Registers
#define RF_GPIO0_PIN               BIT5
#define RF_GPIO0_PXSEL0            P4SEL0          //Function Select Registers
#define RF_GPIO0_PXSEL1            P4SEL1          //Function Select Registers
#define RF_GPIO0_PXIES             P4IES           //  Hi/Low edge
#define RF_GPIO0_PXIE              P4IE           // interrupt enabled
#define RF_GPIO0_PXIFG             P4IFG          // IFG
#define RF_GPIO0_ClrFLAG           RF_GPIO0_PXIFG &= ~RF_GPIO0_PIN;


/*----------------------SPI CONFIG Inside "functions.c"----------------------------------*/
/* --------------------------------------------------
 * P1.0 as LED1 SPI CS PÝN
 * P1.4 as UCA0TXD/MOSI
 * P1.5 as UCA0RXD/MISO
 * P1.6 as UCA0CLK/SPICLK
 */

#define SPITXBUF                UCA0TXBUF
#define SPIRXBUF                UCA0RXBUF
#define SPISTATW                UCA0STATW

#define SPI_SI_PXOUT            P1OUT
#define SPI_SI_PXDIR            P1DIR
#define SPI_SI_PXSEL0           P1SEL0
#define SPI_SI_PXSEL1           P1SEL1
#define SPI_SI_PIN              BIT4

#define SPI_SO_PXOUT            P1OUT
#define SPI_SO_PXDIR            P1DIR
#define SPI_SO_PXSEL0           P1SEL0
#define SPI_SO_PXSEL1           P1SEL1
#define SPI_SO_PIN              BIT5

#define SPI_CLK_PXOUT           P1OUT
#define SPI_CLK_PXDIR           P1DIR
#define SPI_CLK_PXSEL0          P1SEL0
#define SPI_CLK_PXSEL1          P1SEL1
#define SPI_CLK_PIN             BIT6

#define SPI_CS_PXOUT            P1OUT
#define SPI_CS_PXDIR            P1DIR
#define SPI_CS_PXSEL0           P1SEL0
#define SPI_CS_PXSEL1           P1SEL1
#define SPI_CS_PIN              BIT0

#define SPI_CS_LOW              SPI_CS_PXOUT &= ~SPI_CS_PIN   //CS=0
#define SPI_CS_HIGH             SPI_CS_PXOUT |= SPI_CS_PIN   //CS=1


/*--------- CC1190 --------------------------------------------------
 *              Port Config & Control signals
 *              PA Directly Connectted GPIO
 *              LNA Connectted by CC1120
 *
 */
//#warning LNA CC1120 DEN REGISTER ILE AKTIF HALE GETIRILIYOR
//#define    RF_LNA_EN_PxOUT         P1OUT
//#define    RF_LNA_EN_PxDIR         P1DIR
//#define    RF_LNA_EN_PIN           BIT6

#define RF_PA_EN_PxOUT           P5OUT
#define RF_PA_EN_PxDIR           P5DIR
#define RF_PA_EN_PIN             BIT3


#define CC1190_PA_DIS           RF_PA_EN_PxOUT &= ~RF_PA_EN_PIN
#define CC1190_PA_EN            RF_PA_EN_PxOUT |=RF_PA_EN_PIN





//Functions---------------------------------------------
extern void     Perip_Init(void);
extern void     Perip_Init_Crys(void);
extern void     Perip_Init_CLK(void);
extern void     Software_Trim(void);

extern void     Perip_Init_GPIO(void);
extern void     Perip_Init_TIMA(void);
extern void     Perip_Init_UARTA(void);
extern void     Perip_Init_SPI(uint8_t presclaerval);


#endif /* PERIPH_INIT_H_ */
