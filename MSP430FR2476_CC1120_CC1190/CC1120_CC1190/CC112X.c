/*
 * CC1120.c
 *
 *  Created on: 30 Eyl 2021
 *      Author: @GALACICEK

 *

 */

#include "global.h"


static void trxReadWriteBurstSingle(uint8_t reg_address, uint8_t *pdata, uint16_t len);

CC112xVar_t CC112XVar;


const cc112xSetting_t preferredSettings_RF[]=
{


 {CC112X_IOCFG3                    ,         RFSettingsValue_IOCFG3                      },
 {CC112X_IOCFG2                     ,         RFSettingsValue_IOCFG2                     },
 {CC112X_IOCFG1                     ,         RFSettingsValue_IOCFG1                     },
 {CC112X_IOCFG0                     ,         RFSettingsValue_IOCFG0                     },
 {CC112X_SYNC3                      ,         RFSettingsValue_SYNC3                      },
 {CC112X_SYNC2                      ,         RFSettingsValue_SYNC2                      },
 {CC112X_SYNC1                      ,         RFSettingsValue_SYNC1                      },
 {CC112X_SYNC0                      ,         RFSettingsValue_SYNC0                      },
 {CC112X_SYNC_CFG1                  ,         RFSettingsValue_SYNC_CFG1                  },
 {CC112X_SYNC_CFG0                  ,         RFSettingsValue_SYNC_CFG0                  },
 {CC112X_DEVIATION_M                ,         RFSettingsValue_DEVIATION_M                },
 {CC112X_MODCFG_DEV_E               ,         RFSettingsValue_MODCFG_DEV_E               },
 {CC112X_DCFILT_CFG                 ,         RFSettingsValue_DCFILT_CFG                 },
 {CC112X_PREAMBLE_CFG1              ,         RFSettingsValue_PREAMBLE_CFG1              },
 {CC112X_PREAMBLE_CFG0              ,         RFSettingsValue_PREAMBLE_CFG0              },
 {CC112X_FREQ_IF_CFG                ,         RFSettingsValue_FREQ_IF_CFG                },
 {CC112X_IQIC                       ,         RFSettingsValue_IQIC                       },
 {CC112X_CHAN_BW                    ,         RFSettingsValue_CHAN_BW                    },
 {CC112X_MDMCFG1                    ,         RFSettingsValue_MDMCFG1                    },
 {CC112X_MDMCFG0                    ,         RFSettingsValue_MDMCFG0                    },
 {CC112X_SYMBOL_RATE2               ,         RFSettingsValue_SYMBOL_RATE2               },
 {CC112X_SYMBOL_RATE1               ,         RFSettingsValue_SYMBOL_RATE1               },
 {CC112X_SYMBOL_RATE0               ,         RFSettingsValue_SYMBOL_RATE0               },
 {CC112X_AGC_REF                    ,         RFSettingsValue_AGC_REF                    },
 {CC112X_AGC_CS_THR                 ,         RFSettingsValue_AGC_CS_THR                 },
 {CC112X_AGC_GAIN_ADJUST            ,         RFSettingsValue_AGC_GAIN_ADJUST            },
 {CC112X_AGC_CFG3                   ,         RFSettingsValue_AGC_CFG3                   },
 {CC112X_AGC_CFG2                   ,         RFSettingsValue_AGC_CFG2                   },
 {CC112X_AGC_CFG1                   ,         RFSettingsValue_AGC_CFG1                   },
 {CC112X_AGC_CFG0                   ,         RFSettingsValue_AGC_CFG0                   },
 {CC112X_FIFO_CFG                   ,         RFSettingsValue_FIFO_CFG                   },
 {CC112X_DEV_ADDR                   ,         RFSettingsValue_DEV_ADDR                   },
 {CC112X_SETTLING_CFG               ,         RFSettingsValue_SETTLING_CFG               },
 {CC112X_FS_CFG                     ,         RFSettingsValue_FS_CFG                     },
 {CC112X_WOR_CFG1                   ,         RFSettingsValue_WOR_CFG1                   },
 {CC112X_WOR_CFG0                   ,         RFSettingsValue_WOR_CFG0                   },
 {CC112X_WOR_EVENT0_MSB             ,         RFSettingsValue_WOR_EVENT0_MSB             },
 {CC112X_WOR_EVENT0_LSB             ,         RFSettingsValue_WOR_EVENT0_LSB             },
 {CC112X_PKT_CFG2                   ,         RFSettingsValue_PKT_CFG2                   },
 {CC112X_PKT_CFG1                   ,         RFSettingsValue_PKT_CFG1                   },
 {CC112X_PKT_CFG0                   ,         RFSettingsValue_PKT_CFG0                   },
 {CC112X_RFEND_CFG1                 ,         RFSettingsValue_RFEND_CFG1                 },
 {CC112X_RFEND_CFG0                 ,         RFSettingsValue_RFEND_CFG0                 },
 {CC112X_PA_CFG2                    ,         RFSettingsValue_PA_CFG2                    },
 {CC112X_PA_CFG1                    ,         RFSettingsValue_PA_CFG1                    },
 {CC112X_PA_CFG0                    ,         RFSettingsValue_PA_CFG0                    },
 {CC112X_PKT_LEN                    ,         RFSettingsValue_PKT_LEN                    },
 {CC112X_EXTENDED_IF_MIX_CFG        ,         RFSettingsValue_EXTENDED_IF_MIX_CFG        },
 {CC112X_EXTENDED_FREQOFF_CFG       ,         RFSettingsValue_EXTENDED_FREQOFF_CFG       },
 {CC112X_EXTENDED_FREQ2             ,         RFSettingsValue_EXTENDED_FREQ2             },
 {CC112X_EXTENDED_FREQ1             ,         RFSettingsValue_EXTENDED_FREQ1             },
 {CC112X_EXTENDED_FS_DIG1           ,         RFSettingsValue_EXTENDED_FS_DIG1           },
 {CC112X_EXTENDED_FS_DIG0           ,         RFSettingsValue_EXTENDED_FS_DIG0           },
 {CC112X_EXTENDED_FS_CAL1           ,         RFSettingsValue_EXTENDED_FS_CAL1           },
 {CC112X_EXTENDED_FS_CAL0           ,         RFSettingsValue_EXTENDED_FS_CAL0           },
 {CC112X_EXTENDED_FS_DIVTWO         ,         RFSettingsValue_EXTENDED_FS_DIVTWO         },
 {CC112X_EXTENDED_FS_DSM0           ,         RFSettingsValue_EXTENDED_FS_DSM0           },
 {CC112X_EXTENDED_FS_DVC0           ,         RFSettingsValue_EXTENDED_FS_DVC0           },
 {CC112X_EXTENDED_FS_PFD            ,         RFSettingsValue_EXTENDED_FS_PFD            },
 {CC112X_EXTENDED_FS_PRE            ,         RFSettingsValue_EXTENDED_FS_PRE            },
 {CC112X_EXTENDED_FS_REG_DIV_CML    ,         RFSettingsValue_EXTENDED_FS_REG_DIV_CML    },
 {CC112X_EXTENDED_FS_SPARE          ,         RFSettingsValue_EXTENDED_FS_SPARE          },
 {CC112X_EXTENDED_FS_VCO0           ,         RFSettingsValue_EXTENDED_FS_VCO0           },
 {CC112X_EXTENDED_XOSC5             ,         RFSettingsValue_EXTENDED_XOSC5             },
 {CC112X_EXTENDED_XOSC1             ,         RFSettingsValue_EXTENDED_XOSC1             },

};




void CC112x_RegisterInit(void){

    cc112xSetting_t *preferredSettings;
    uint8_t  preferredSettings_length = 0;

    CC112X_cmdStrobe(CC112X_SRES);

   /* give the tranciever time enough to complete reset cycle */
//      __delay_cycles(16000);

      preferredSettings_length = sizeof(preferredSettings_RF)/sizeof(cc112xSetting_t);
      preferredSettings = (cc112xSetting_t *)preferredSettings_RF;


      uint8_t writeByte=0 ,i;
      /* Write registers to radio */


      for(i = 0; i < preferredSettings_length; i++) {

          if(preferredSettings[i].addr < 0x2F) {
              writeByte = preferredSettings[i].data;
              CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, preferredSettings[i].addr, &writeByte, 1);
          } else {
              writeByte = preferredSettings[i].data;
              CC112x_16BitRegAccess(CC112X_WRITE_SINGLE, preferredSettings[i].addr,&writeByte, 1);
          }
      }

#ifdef DebugMODE
      CC112X_GetDeviceID();
#endif
}

#ifdef DebugMODE

#define CC1120ID    0x48
void CC112X_GetDeviceID(void){

    uint8_t ret_partnum;
    uint8_t ret_version;
    uint8_t ret_modemstatus1;


    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_PARTNUMBER, &ret_partnum, 1);
    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_PARTVERSION, &ret_version, 1);
    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_MODEM_STATUS1, &ret_modemstatus1, 1);

#ifdef DebugMODE
    CC112XVar.partnumber = ret_partnum;
    CC112XVar.partversion = ret_version;
    CC112XVar.modemstatus1 = ret_modemstatus1;

    while(ret_partnum!= CC1120ID);

#endif
}


/******************************************************************************
 * @fn         rf_default_setup
 *
 * @brief      You check registers
 *			   use in RF_Init functions in radio.c files
 *
 * @param       trx_cfg_struct *trx_cfg    -  structure for control information
 *
 * output parameters
 *
 * @return      void
 *
 */
//void RF_READREGS(void){
//
//    CC112x_8BitRegAccess(CC112X_READ_BURST, CC112X_IOCFG3,          &CC112XVar.IOCFG3,           ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_IOCFG2,         &CC112XVar.IOCFG2,           ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_IOCFG1,         &CC112XVar.IOCFG1,           ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_IOCFG0,         &CC112XVar.IOCFG0,           ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_SYNC_CFG1,      &CC112XVar.SYNC_CFG1,        ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_DEVIATION_M,    &CC112XVar.DEVIATION_M,      ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_MODCFG_DEV_E,   &CC112XVar.MODCFG_DEV_E,     ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_DCFILT_CFG,     &CC112XVar.DCFILT_CFG,       ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PREAMBLE_CFG1,  &CC112XVar.PREAMBLE_CFG1,    ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PREAMBLE_CFG0,  &CC112XVar.PREAMBLE_CFG0,    ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_IQIC,           &CC112XVar.IQIC,             ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_CHAN_BW,        &CC112XVar.CHAN_BW,          ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_MDMCFG0,        &CC112XVar.MDMCFG0,          ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_AGC_REF,        &CC112XVar.AGC_REF,          ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_AGC_CS_THR,     &CC112XVar.AGC_CS_THR,       ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_AGC_CFG3,       &CC112XVar.AGC_CFG3,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_AGC_CFG1,       &CC112XVar.AGC_CFG1,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_AGC_CFG0,       &CC112XVar.AGC_CFG0,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_FIFO_CFG,       &CC112XVar.FIFO_CFG,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_SETTLING_CFG,   &CC112XVar.SETTLING_CFG,     ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_FS_CFG,         &CC112XVar.FS_CFG,           ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_WOR_CFG1,       &CC112XVar.WOR_CFG1,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_WOR_CFG0,       &CC112XVar.WOR_CFG0,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_WOR_EVENT0_MSB, &CC112XVar.WOR_EVENT0_MSB,   ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_WOR_EVENT0_LSB, &CC112XVar.WOR_EVENT0_LSB,   ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PKT_CFG1,       &CC112XVar.PKT_CFG1,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PKT_CFG0,       &CC112XVar.PKT_CFG0,         ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_RFEND_CFG1,     &CC112XVar.RFEND_CFG1,       ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_RFEND_CFG0,     &CC112XVar.RFEND_CFG0,       ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PA_CFG2,        &CC112XVar.PA_CFG2,          ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PA_CFG1,        &CC112XVar.PA_CFG1,          ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PA_CFG0,        &CC112XVar.PA_CFG0,          ,1);
//    CC112x_8BitRegAccess(CC112X_READ_SINGLE, CC112X_PKT_LEN,        &CC112XVar.PKT_LEN,          ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_IF_MIX_CFG,     &CC112XVar.IF_MIX_CFG,        ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FREQOFF_CFG,    &CC112XVar.FREQOFF_CFG,       ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FREQ2,          &CC112XVar.FREQ2,             ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FREQ1,          &CC112XVar.FREQ1,             ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_DIG1,        &CC112XVar.FS_DIG1,           ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_DIG0,        &CC112XVar.FS_DIG0,           ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_CAL1,        &CC112XVar.FS_CAL1,           ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_CAL0,        &CC112XVar.FS_CAL0,           ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_DIVTWO,      &CC112XVar.FS_DIVTWO,         ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_DSM0,        &CC112XVar.FS_DSM0,           ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_DVC0,        &CC112XVar.FS_DVC0,           ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_PFD,         &CC112XVar.FS_PFD,            ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_PRE,         &CC112XVar.FS_PRE,            ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_REG_DIV_CML, &CC112XVar.FS_REG_DIV_CML,    ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_SPARE,       &CC112XVar.FS_SPARE,          ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_FS_VCO0,        &CC112XVar.FS_VCO0,           ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_XOSC5,          &CC112XVar.XOSC5,             ,1);
//    CC112x_16BitRegAccess(CC112X_READ_SINGLE,CC112X_EXTENDED_XOSC1,          &CC112XVar.XOSC1,             ,1);
//
//}

#endif


/******************************************************************************
* @fn          radio_get_rssi
*
* @brief       Get and calculate the RSSI from unsigned char value
*                   Calculating in function now that ranging  from  –128  to  127  dBm.
*
*
* @param       void
*
* output parameters
*
* @return      int - rssi value in dB
*/
int CC112X_GetRSSI(void) {
    int rssi;
    uint8_t cc_rssi;

    CC112x_16BitRegAccess(CC112X_READ_SINGLE ,CC112X_EXTENDED_RSSI1, &cc_rssi, 1);

    rssi = cc_rssi;
    if (rssi >= 128) {
        rssi = rssi - 256;
    }
    rssi = rssi - 99;

    return rssi;
}

/******************************************************************************
 * @fn          CC112X_SetFreq
 *
 * @brief       Calculate the required frequency registers and send the using
 *              serial connection to the RF tranceiver.
 *
 * input parameters
 *
 * @param       freq   -  frequency word provided in [kHz] resolution
 *
 * output parameters
 *
 * @return      void
 */
void CC112X_SetFreq(uint32_t freq) {

    uint8_t freq_regs[3];
    uint32_t freq_regs_uint32;
    float f_vco;

    /* Radio frequency -> VCO frequency */
    f_vco = freq * RF_LO_DIVIDER;

    /* Divide by oscillator frequency */
    f_vco = f_vco * (1/(float)RF_XTAL_FREQ);

    /* Multiply by 2^16 */
    f_vco = f_vco * 65536;

    /* Convert value into uint32 from float */
    freq_regs_uint32 = (uint32_t)f_vco;

    /* return the frequency word */
    freq_regs[2] = ((uint8_t*)&freq_regs_uint32)[0];
    freq_regs[1] = ((uint8_t*)&freq_regs_uint32)[1];
    freq_regs[0] = ((uint8_t*)&freq_regs_uint32)[2];

    /* write the frequency word to the transciever */
    CC112x_16BitRegAccess(CC112X_WRITE_BURST , CC112X_EXTENDED_FREQ2, freq_regs, 3);

}


/******************************************************************************
* @fn          CC112X_SetPacketLength
*
* @brief       Configure the radio to handle fixed packets with a certain
*              packet length.
*
* input parameters
*
* @param       unsigned char length - length of fixed payload
*
* output parameters
*
* @return      0 - no_error
*/
void CC112X_SetPacketLength(unsigned char length) {
    uint8_t regs_uint8;

/* configure set_rf_packet_length */
    regs_uint8 = length;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE , CC112X_PKT_LEN, &regs_uint8, 1);

/* configure set_rf_packet_lengthe
* 00 : Fixed packet length mode.
* Packet Length configured through the PKT_LEN register
*
*/
    regs_uint8 = 0x00;
    CC112x_8BitRegAccess(CC112X_WRITE_SINGLE , CC112X_PA_CFG0, &regs_uint8, 1);


}


/***************************************************************************//**
 * @brief       Write pData to radio transmit FIFO.
 *
 * @param       pData   is pointer to data array that is written to TX FIFO
 * @param       len     is the length of data array to be written
 *
 * @return
 ******************************************************************************/
uint8_t CC112X_WriteTxFifo(uint8_t *pData, uint8_t len)
{

  uint8_t rc;
  rc = CC112x_8BitRegAccess(CC112X_WRITE_SINGLE, CC112X_TXFIFO | CC112X_WRITE_BURST , pData, len);
  return (rc);
}


/***************************************************************************//**
 * @brief       Reads RX FIFO values to pData array
 *
 * @param       pData   is pointer to data array where RX FIFO bytes are saved
 * @param       len     is the number of bytes to read from the RX FIFO
 *
 * @return      status byte ::rfStatus_t
 ******************************************************************************/
uint8_t CC112X_ReadRxFifo(uint8_t * pData, uint8_t len)
{

  uint8_t rc;
  rc = CC112x_8BitRegAccess(CC112X_READ_BURST, CC112X_RXFIFO , pData, len);
  return (rc);
}


/*******************************************************************************
 * @fn          CC112X_cmdStrobe
 *
 * @brief       Send command strobe to the radio. Returns status byte read
 *              during transfer of command strobe. Validation of provided
 *              is not done. Function assumes chip is ready.
 *
 * input parameters
 *
 * @param       cmd - command strobe
 *
 * output parameters
 *
 * @return      status byte
 */
uint8_t CC112X_cmdStrobe(uint8_t cmd){

    uint8_t rcmd;

    SPI_CS_LOW;
    _nop(); _nop();
    rcmd = SPI_ReadWriteBytes(cmd);
    _nop(); _nop();
    SPI_CS_HIGH;

    return rcmd;
}

/*******************************************************************************
 * @fn          CC112x_8BitRegAccess
 *
 * @brief       This function performs a read or write from/to a 8bit register
 *              address space. The function handles burst and single read/write
 *              as specfied in addrByte. Function assumes that chip is ready.
 *
 * input parameters
 *
 * @param       accessType - Specifies if this is a read or write and if it's
 *                           a single or burst access. Bitmask made up of
 *                           CC112X_READ_SINGLE
 *                           CC112X_WRITE_SINGLE
 * @param       addrByte - address byte of register.
 * @param       pData    - data array
 * @param       len      - Length of array to be read(TX)/written(RX)
 *
 * output parameters
 *
 * @return      chip status
 */
uint8_t CC112x_8BitRegAccess(uint8_t accessType, uint8_t regAddr, uint8_t *pData, uint16_t len)
{

    uint8_t readValue = 0;


    SPI_CS_LOW;
    _nop(); _nop(); _nop();

    readValue = SPI_ReadWriteBytes(accessType|regAddr);

    trxReadWriteBurstSingle(accessType|regAddr,pData,len);

    _nop(); _nop(); _nop();
    SPI_CS_HIGH;

    return readValue;

}


/******************************************************************************
 * @fn          CC112x_16BitRegAccess
 *
 * @brief       This function performs a read or write in the extended adress
 *              space of CC112X.
 *
 * input parameters
 *
 * @param       accessType - Specifies if this is a read or write and if it's
 *                           a single or burst access. Bitmask made up of
 *                           CC112X_READ_SINGLE
 *                           CC112X_WRITE_SINGLE
 * @param       extAddr - Extended register space address = 0x2F.
 * @param       regAddr - Register address in the extended address space.
 * @param       *pData  - Pointer to data array for communication
 * @param       len     - Length of bytes to be read/written from/to radio
 *
 * output parameters
 *
 * @return      uint8_t
 */
uint8_t CC112x_16BitRegAccess(uint8_t accessType, uint16_t regAddr, uint8_t *pData, uint8_t len)
{

    uint8_t readValue = 0;


    SPI_CS_LOW;
    _nop(); _nop();  _nop();//2cycle =500ns

    readValue = SPI_ReadWriteBytes(accessType|(uint8_t)(regAddr>>8) );    //(uint8_t)(0xFF00 & regAddr)
//    SPI_WriteBytes(0xFF & regAddr);   //15.11.21 1045
    SPI_ReadWriteBytes(0xFF & regAddr);
    trxReadWriteBurstSingle(accessType| (0x00FF & regAddr),pData,len);

    _nop();  _nop();  _nop(); //2cycle =500ns
    SPI_CS_HIGH;

    return readValue;

}

/*******************************************************************************
 * @fn          trxReadWriteBurstSingle
 *
 * @brief       When the address byte is sent to the SPI slave, the next byte
 *              communicated is the data to be written or read. The address
 *              byte that holds information about read/write -and single/
 *              burst-access is provided to this function.
 *
 *              Depending on these two bits this function will write len bytes to
 *              the radio in burst mode or read len bytes from the radio in burst
 *              mode if the burst bit is set. If the burst bit is not set, only
 *              one data byte is communicated.
 *
 *              NOTE: This function is used in the following way:
 *
 *              SPI_CS_LOW;
 *               _nop(); _nop();
 *              while(RF_PORT_IN & RF_SPI_MISO_PIN);
 *              ...[Depending on type of register access]
 *              trxReadWriteBurstSingle(uint8 addr,uint8 *pData,uint16 len);
 *              _nop(); _nop(); //2cycle =500ns
 *              SPI_CS_HIGH;
 *
 * input parameters
 *
 * @param       none
 *
 * output parameters
 *
 * @return      void
 */

static void trxReadWriteBurstSingle(uint8_t reg_address, uint8_t *pdata, uint16_t len)
{
    auto int i;

    /* Communicate len number of bytes: if RX - the procedure sends 0x00 to push bytes from slave*/
    if(reg_address & CC112X_READ_SINGLE){

        if(reg_address & CC112X_READ_BURST){

                    for (i = 0; i < len; i++)
                    {
                        *pdata=SPI_ReadWriteBytes(0);
                         pdata++;
                    }

                }else { //CC112X_WRITE_SINGLE

                    *pdata=SPI_ReadWriteBytes(0);

                }
    }
    else { // if(reg_address & CC112X_WRITE_BURST){

        if(reg_address & CC112X_WRITE_BURST){

                auto int i;

                for (i = 0; i < len; i++)
                {
                    SPI_WriteBytes(*pdata);
                    pdata++;
                }

            }else {

                SPI_WriteBytes(*pdata);
            }
    }


}





