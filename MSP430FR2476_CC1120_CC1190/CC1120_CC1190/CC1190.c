/*
 * CC1190.c
 *
 *  Created on: 15 Eki 2021
 *      Author: @GALACICEK
 *
 *       LNA_EN   CC1120_GPIO3
 *       PA_EN    CC1190 MSP430FR2476_GPIO
 */

#include "global.h"




/**
 * @brief   CC1190 power down moduna alýnýr
 */
void CC1190_Power_Down(void)
{
    uint8_t regs_uint8;



#ifdef CC1190_PAEN_ACTIVE_GPIO

    CC1190_PA_DIS;  //PA_EN

#else
    regs_uint8 = SMARTRF_SETTING_IOCFGX_SLEEP;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, CC112X_IOCFG0, &regs_uint8, 1);
#endif

    regs_uint8 = SMARTRF_SETTING_IOCFGX_SLEEP;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, CC112X_IOCFG3, &regs_uint8, 1);   //LNA_EN = 0
	
}

/**
 * @brief   CC1190 power RX moduna alýnýr
 *                       PA_EN  LNA_EN
 *                          0     1
 */
void CC1190_Receive_On(void)
{
    uint8_t regs_uint8;


#ifdef CC1190_PAEN_ACTIVE_GPIO

    CC1190_PA_DIS;
#else
    regs_uint8 = SMARTRF_SETTING_IOCFGX_LOW;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, CC112X_IOCFG0, &regs_uint8, 1);   //PA_EN
#endif

    regs_uint8 = SMARTRF_SETTING_IOCFGX_HIGH;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, CC112X_IOCFG3, &regs_uint8,1);    //LNA_EN

}

/**
 * @brief   CC1190 power TX moduna alýnýr
 *                       PA_EN  LNA_EN
 *                          1     0
 */
void CC1190_Transmit_On(void)
{
    uint8_t regs_uint8;



#ifdef CC1190_PAEN_ACTIVE_GPIO

    CC1190_PA_EN;
#else
    regs_uint8 = SMARTRF_SETTING_IOCFGX_HIGH;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, CC112X_IOCFG0, &regs_uint8,1);    //PA_EN
#endif

    regs_uint8 = SMARTRF_SETTING_IOCFGX_LOW;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, CC112X_IOCFG3, &regs_uint8, 1);   //LNA_EN

}






