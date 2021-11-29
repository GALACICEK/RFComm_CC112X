/*
 * CC1190.h
 *
 *  Created on: 15 Eki 2021
 *      Author: @GALACICEK
 */

#ifndef CC1190_H_
#define CC1190_H_

#include <msp430.h>

////GPIO3 connected to CC1120
//#define CC1190_LNA_DIS
//#define CC1190_LNA_EN

/*******************************************************************************
 * DEFINES
 */
#define SMARTRF_SETTING_IOCFGX_SLEEP       0x33 //!<
#define SMARTRF_SETTING_IOCFGX_LOW         0x33 //!<
#define SMARTRF_SETTING_IOCFGX_HIGH        0x73 //!<

/*******************************************************************************
 * PROTOTYPES
 */
extern void CC1190_Power_Down(void);
extern void CC1190_Receive_On(void);
extern void CC1190_Transmit_On(void);

#endif /* CC1190_H_ */
