/*
 * smartrf.h
 *
 *  Created on: 15 Eki 2021
 *      Author: @GALACICEK
 */

#ifndef RADIO_H_
#define RADIO_H_

#include <msp430.h>

extern void     RF_GPIO_Interrupt(void);
extern void     RF_Init(void);
extern void     RF_RXTask(void);
extern void     RF_TXTask(void);

extern void     RF_RX(void);
extern void     RF_RXFlush(void);
extern void     RF_TX(void);
extern void     RF_TXFlush(void);
extern void     Rf_Channel_Set(unsigned char chnl);

extern void     createPacket(uint8_t *buffer);


#endif /* RADIO_H_ */
