/*
 * CC1120.h
 *
 *  Created on: 30 Eyl 2021
 *      Author: @GALACICEK
 */

#ifndef CC112X_H_
#define CC112X_H_

#include "CC112X_regs.h"
#include <msp430.h>


/******************************************************************************
 * DEFINES
 */

#define RF_XTAL_FREQ             32000       /* XTAL frequency, given in 1kHz steps */
#define RF_LO_DIVIDER            4             /* there is a hardware LO divider CC112x */

#define CC112X_TXBUFFER_SIZE       20





typedef struct cc112x_setvar{
    uint16_t addr;
    uint16_t data;

}cc112xSetting_t;


#define CarierFrq   868000

#define PREAMBLE                                       0xAAAA


// Address Config = No address check
// Bit Rate = 19.6
// Carrier Frequency = 868.000000
// Deviation = 10.009766
// Device Address = 0
// Manchester Enable = false
// Modulation Format = 2-GFSK
// PA Ramping = true
// Packet Bit Length = 0
// Packet Length = 25
// Packet Length Mode = Fixed
// Performance Mode = High Performance
// RX Filter BW = 50.000000
// Symbol rate = 19.6
// TX Power = 15
// Whitening = true

#define RFSettingsValue_IOCFG3                         0x33    //CC1190 IS CONNECTED LNA_EN PIN
#define RFSettingsValue_IOCFG2                         0x06    //INTERRUPT PKT_CRC_OK
#define RFSettingsValue_IOCFG1                         0XB0    //DEFAULT VALUE CUZ CONNECT SO PIN
#define RFSettingsValue_IOCFG0                         0XB0    //default
#define RFSettingsValue_SYNC3                          0x93    //default
#define RFSettingsValue_SYNC2                          0x0B    //default
#define RFSettingsValue_SYNC1                          0x51    //default
#define RFSettingsValue_SYNC0                          0xDE    //default
#define RFSettingsValue_SYNC_CFG1                      0X0B    //Setting modulation format
#define RFSettingsValue_SYNC_CFG0                      0x17     //default
#define RFSettingsValue_DEVIATION_M                    0x48
#define RFSettingsValue_MODCFG_DEV_E                   0x0C     //2GFSK
#define RFSettingsValue_DCFILT_CFG                     0x1C
#define RFSettingsValue_PREAMBLE_CFG1                  0x18     //preamble 4 bytes & preamble values 0xAA
#define RFSettingsValue_PREAMBLE_CFG0                  0x2A     //default
#define RFSettingsValue_FREQ_IF_CFG                    0x40
#define RFSettingsValue_IQIC                           0x00
#define RFSettingsValue_CHAN_BW                        0x04     // RX filter BW 50khz
#define RFSettingsValue_MDMCFG1                        0x46      //default
#define RFSettingsValue_MDMCFG0                        0x05
#define RFSettingsValue_SYMBOL_RATE2                   0x84
#define RFSettingsValue_SYMBOL_RATE1                   0x12
#define RFSettingsValue_SYMBOL_RATE0                   0x06
#define RFSettingsValue_AGC_REF                        0X36     //default
#define RFSettingsValue_AGC_CS_THR                     0X00     //default
#define RFSettingsValue_AGC_GAIN_ADJUST                0X00     //default
#define RFSettingsValue_AGC_CFG3                       0x91     //default
#define RFSettingsValue_AGC_CFG2                       0x20     //default
#define RFSettingsValue_AGC_CFG1                       0xA9
#define RFSettingsValue_AGC_CFG0                       0xC3      //default
#define RFSettingsValue_FIFO_CFG                       0x00     //CRC_AUTOFLUSH = 1
#define RFSettingsValue_DEV_ADDR                       0x00     //default
#define RFSettingsValue_SETTLING_CFG                   0x0B     //default
#define RFSettingsValue_FS_CFG                         0x12
#define RFSettingsValue_WOR_CFG1                       0x08     //default
#define RFSettingsValue_WOR_CFG0                       0x21     //default
#define RFSettingsValue_WOR_EVENT0_MSB                 0x00     //default
#define RFSettingsValue_WOR_EVENT0_LSB                 0X00     //default
#define RFSettingsValue_PKT_CFG2                       0x04     //DEFAULT
#define RFSettingsValue_PKT_CFG1                       0x45
#define RFSettingsValue_PKT_CFG0                       0x20     //variable packet length mode
#define RFSettingsValue_RFEND_CFG1                     0x0F     //default
#define RFSettingsValue_RFEND_CFG0                     0x00     //default
#define RFSettingsValue_PA_CFG2                        0x66     //TX POWER 24dbm CC1190  // 0x7F TX POWER 15dBm
#define RFSettingsValue_PA_CFG1                        0x56     //default
#define RFSettingsValue_PA_CFG0                        0x7C     //default
#define RFSettingsValue_PKT_LEN                        0x15     //20 paket uzunlugu
#define RFSettingsValue_EXTENDED_IF_MIX_CFG            0x00
#define RFSettingsValue_EXTENDED_FREQOFF_CFG           0x22
#define RFSettingsValue_EXTENDED_FREQ2                 0x6C  //Carrier Frequency
#define RFSettingsValue_EXTENDED_FREQ1                 0x80  //Carrier Frequency
#define RFSettingsValue_EXTENDED_FS_DIG1               0x00
#define RFSettingsValue_EXTENDED_FS_DIG0               0x5F
#define RFSettingsValue_EXTENDED_FS_CAL1               0x40
#define RFSettingsValue_EXTENDED_FS_CAL0               0x0E
#define RFSettingsValue_EXTENDED_FS_DIVTWO             0x03
#define RFSettingsValue_EXTENDED_FS_DSM0               0x33
#define RFSettingsValue_EXTENDED_FS_DVC0               0x17
#define RFSettingsValue_EXTENDED_FS_PFD                0x50
#define RFSettingsValue_EXTENDED_FS_PRE                0x6E
#define RFSettingsValue_EXTENDED_FS_REG_DIV_CML        0x14
#define RFSettingsValue_EXTENDED_FS_SPARE              0xAC
#define RFSettingsValue_EXTENDED_FS_VCO0               0xB4
#define RFSettingsValue_EXTENDED_XOSC5                 0x0E
#define RFSettingsValue_EXTENDED_XOSC1                 0x03




typedef struct cc112x_var{

    char buff[CC112X_TXBUFFER_SIZE];
    uint16_t data;

}cc112x_t;

#ifdef  DebugMODE

typedef struct CC112x_Variable{
    uint8_t   partnumber;
    uint8_t   partversion;
    uint8_t   modemstatus1;
//	uint8_t   IOCFG3,        
//	uint8_t   IOCFG2,        
//	uint8_t   IOCFG1,        
//	uint8_t   IOCFG0,        
//	uint8_t   SYNC_CFG1,     
//	uint8_t   DEVIATION_M,   
//	uint8_t   MODCFG_DEV_E,  
//	uint8_t   DCFILT_CFG,    
//	uint8_t   PREAMBLE_CFG1, 
//	uint8_t   PREAMBLE_CFG0, 
//	uint8_t   IQIC,          
//	uint8_t   CHAN_BW,       
//	uint8_t   MDMCFG0,       
//	uint8_t   AGC_REF,       
//	uint8_t   AGC_CS_THR,    
//	uint8_t   AGC_CFG3,      
//	uint8_t   AGC_CFG1,      
//	uint8_t   AGC_CFG0,      
//	uint8_t   FIFO_CFG,      
//	uint8_t   SETTLING_CFG,  
//	uint8_t   FS_CFG,        
//	uint8_t   WOR_CFG1,      
//	uint8_t   WOR_CFG0,      
//	uint8_t   WOR_EVENT0_MSB,
//	uint8_t   WOR_EVENT0_LSB,
//	uint8_t   PKT_CFG1,      
//	uint8_t   PKT_CFG0,      
//	uint8_t   RFEND_CFG1,    
//	uint8_t   RFEND_CFG0,    
//	uint8_t   PA_CFG2,       
//	uint8_t   PA_CFG1,       
//	uint8_t   PA_CFG0,       
//	uint8_t   PKT_LEN,    
//	uint8_t	  IF_MIX_CFG,    	
//	uint8_t	  FREQOFF_CFG,   	
//	uint8_t	  FREQ2,         	
//	uint8_t	  FREQ1,         	
//	uint8_t	  FS_DIG1,       	
//	uint8_t	  FS_DIG0,       	
//	uint8_t	  FS_CAL1,       	
//	uint8_t	  FS_CAL0,       	
//	uint8_t	  FS_DIVTWO,     	
//	uint8_t	  FS_DSM0,       	
//	uint8_t	  FS_DVC0,       	
//	uint8_t	  FS_PFD,        	
//	uint8_t	  FS_PRE,        	
//	uint8_t	  FS_REG_DIV_CML,	
//	uint8_t	  FS_SPARE,      	
//	uint8_t	  FS_VCO0,       	
//	uint8_t	  XOSC5,         	
//	uint8_t	  XOSC1, 
	
} CC112xVar_t;

extern CC112xVar_t CC112XVar;

#endif



extern void     CC112x_RegisterInit(void);

extern void     CC112X_GetDeviceID(void);
extern void     CC112X_SetFreq(uint32_t  freq);
extern void     CC112X_SetPacketLength(unsigned char length);
extern int      CC112X_GetRSSI(void);
extern uint8_t  CC112X_ReadRxFifo(uint8_t * pData, uint8_t len);
extern uint8_t  CC112X_WriteTxFifo(uint8_t *pData, uint8_t len);
extern uint8_t  CC112X_cmdStrobe(uint8_t cmd);

extern uint8_t  CC112x_8BitRegAccess (uint8_t accessType, uint8_t regAddr, uint8_t *pData, uint16_t len);
extern uint8_t  CC112x_16BitRegAccess(uint8_t accessType, uint16_t regAddr, uint8_t *pData, uint8_t len);


#endif /* CC112X_H_ */
