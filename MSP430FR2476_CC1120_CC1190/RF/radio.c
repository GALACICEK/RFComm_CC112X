/*
 * smartrf.c
 *
 *  Created on: 15 Eki 2021
 *      Author: @GALACICEK
 *
 *      
 */

#include "global.h"

uint32_t rxtimecheck;


/*******************************************************************************
* LOCAL VARIABLES
*/
static uint32_t packetCounter = 0;

/*******************************************************************************
* STATIC FUNCTIONS
*/

static void manualCalibration(void);
static void calibrateRCOsc(void);

/******************************************************************************
 * @fn         CC112x_Task
 *
*   @brief      Puts radio in RX Sniff Mode and waits for packets. A packet
*               counter is incremented for each packet received and the LCD is
*               updated
*
 *
 *              input parameters
 *
 * @param       void
 *
 *              output parameters
 *
 * @return      void
 *
 */
volatile uint32_t rxdata=0;
uint8_t rxBuffer[64] = {0};

void RF_RXTask(void){

    uint8_t sizerxBytes;
    uint8_t marcState;
    uint8_t marcStatus1,modemStatus0;

    RF_RX();

    CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARC_STATUS1, &marcStatus1, 1);
    CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MODEM_STATUS1, &modemStatus0, 1);

    CC1190_Receive_On();

   if(flag.Bits.CC1120_GPIO2){


        // Read number of bytes in RX FIFO
       CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_NUM_RXBYTES, &sizerxBytes, 1);

        // Check that we have bytes in FIFO
        if(sizerxBytes != 0) {

            // Read MARCSTATE to check for RX FIFO error
            CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcState, 1);

            // Mask out MARCSTATE bits and check if we have a RX FIFO error
            if((marcState & 0x1F) == RX_FIFO_ERROR) {

                if(IsTimeEllapsed(&rxtimecheck, 300)){
                 // Flush RX FIFO

                    RF_RXFlush();

                }
//                CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcState, 1);
//                do {
//                        CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcState, 1);
//                        CC112X_cmdStrobe(CC112X_SIDLE);   //hata veriyordu ve hatanýn ne olduðunu öðprenmek için koydum
//                    } while (marcState != 0x41);
//                Rf_Channel_Set(0);
                ERASE_BUFF(&rxBuffer[0],(sizeof(rxBuffer)/sizeof(uint8_t)));

            } else {

                CC112X_ReadRxFifo(&rxBuffer[0], sizerxBytes);

                CC112X_cmdStrobe(CC112X_SNOP | CC112X_READ_SINGLE);

                LED3_OFF;
                LED2_TOGGLE;

               // If CRC is disabled the CRC_OK field will read
                if(rxBuffer[(sizerxBytes) - 1] & 0x80) {
                    // Update packet counter
                    packetCounter++;
                }


                if((sizeof(rxBuffer)/sizeof(uint8_t))!=0)
                {
                    rxdata++;
                    ERASE_BUFF(&rxBuffer[0],(sizeof(rxBuffer)/sizeof(uint8_t)));

                }

            }
        }

        flag.Bits.CC1120_GPIO2=0;
   }

   RF_GPIO2_ENFLAG;
   LED3_TOGGLE;
   CC1190_Power_Down();



}

/**
 *   @brief      Parametrede gelen RF kanalýna geç
 *
 *   @param      chnl: Geçilecek RF kanalý
 *
 *   @return     none
 */

#define Ch_SPACE    500
void Rf_Channel_Set(unsigned char chnl)
{
    unsigned long freq;
    freq= (unsigned long )CarierFrq+(unsigned long )(Ch_SPACE*chnl);

    CC112X_SetFreq(freq);

}


uint32_t RFPKTTime=0;
uint8_t txBuffer[CC112X_TXBUFFER_SIZE];

void RF_TXTask(void){

    uint8_t marcState = 0;
    uint8_t txbufsize = 0;

        // Update packet counter
        packetCounter++;

        createPacket(&txBuffer[0]);

        // Write packet to TX FIFO
        CC112X_WriteTxFifo(&txBuffer[0], (sizeof(txBuffer)/sizeof(uint8_t))+1);
        CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_NUM_TXBYTES, &txbufsize, 1);


       // CC1190_Receive_On();
        CC1190_Transmit_On();
         // Strobe TX to send packet
        RF_TX();
        RFPKTTime = GetTimeTick();


        do{

            CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcState, 1);

            if((marcState & 0x1F) == TX_FIFO_ERROR || IsTimeEllapsed(&RFPKTTime, 240) ) {
            //if((marcState & 0x1F) == TX_FIFO_ERROR){
                RF_TXFlush();
                CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcState, 1);
                ERASE_BUFF(&txBuffer[0],(sizeof(txBuffer)/sizeof(uint8_t)));
                Rf_Channel_Set(0);
                LED2_TOGGLE;
                break;
            }

        }while((marcState & 0x1F) != TX_END_STATE);

        if(flag.Bits.CC1120_GPIO2){
            flag.Bits.CC1120_GPIO2=0;
            RF_GPIO2_ENFLAG;
        }

        LED3_TOGGLE;
        CC1190_Power_Down();

}


void RF_GPIO_Interrupt(void){

    RF_GPIO2_ClrFLAG;
    RF_GPIO2_IntEN;

}
void RF_Init(void){

    uint8_t marcState;

    CC112X_cmdStrobe(CC112X_SRES);  //Reset chip

    CC112x_RegisterInit();

    RF_GPIO_Interrupt();

    // Calibrate radio
    CC112X_cmdStrobe(CC112X_SCAL);

//    RF_READREGS();
    // Calibrate radio according to errata
    manualCalibration();


    // Wait for calibration to be done (radio back in IDLE state)
    do {
        CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcState, 1);
    } while (marcState != 0x41);

    CC1190_Power_Down();



    Rf_Channel_Set(0);


}

void createPacket(uint8_t *buffer){

    *buffer = (uint8_t)(CC112X_TXBUFFER_SIZE);
    *(buffer+1) = (uint8_t) (packetCounter >> 8);     // MSB of packetCounter
    *(buffer+2) = (uint8_t) (packetCounter );        // LSB of packetCounter

    uint8_t i;
    for(i=3 ; i<19 ; i++){
        *(buffer+i) = i;
    }

    *(buffer+19) = 0x80;
}

void RF_RX(void){

    CC112X_cmdStrobe(CC112X_SRX);
}

void RF_RXFlush(void){

    CC112X_cmdStrobe(CC112X_SFRX);

}

void RF_TX(void){

    CC112X_cmdStrobe(CC112X_STX);
}

void RF_TXFlush(void){

    CC112X_cmdStrobe(CC112X_SFTX);

}





/*******************************************************************************
*   @fn         calibrateRcOsc
*
*   @brief      Calibrates the RC oscillator used for the eWOR timer. When this
*               function is called, WOR_CFG0.RC_PD must be 0
*
*   @param      none
*
*   @return     none
*/
static void calibrateRCOsc(void) {

    uint8_t temp;

    // Read current register value
    CC112x_8BitRegAccess(CC112X_READ_BURST,CC112X_WOR_CFG0, &temp,1);

    // Mask register bit fields and write new values
    temp = (temp & 0xF9) | (0x02 << 1);

    // Write new register value
    CC112x_8BitRegAccess(CC112X_READ_BURST,CC112X_WOR_CFG0, &temp,1);

    // Strobe IDLE to calibrate the RCOSC
    CC112X_cmdStrobe(CC112X_SIDLE);

    // Disable RC calibration
    temp = (temp & 0xF9) | (0x00 << 1);
    CC112x_8BitRegAccess(CC112X_READ_BURST,CC112X_WOR_CFG0, &temp, 1);
}

/******************************************************************************
* @fn          getBitRate
*
*@brief        Returns bitrate based on current register settings.
*
*
* @param       none
*
*
* @return      bitrate - the current bitrate
*/
static long getBitRate(void) {
  uint32_t drateM;
  uint32_t drateE;
  uint8_t readByte2;
  uint8_t readByte1;
  uint8_t readByte0;
  float bitratetemp;
  uint32_t bitrate;
  //Read datarate from registers
  CC112x_8BitRegAccess(CC112X_READ_BURST,CC112X_SYMBOL_RATE2, &readByte2, 1);
  CC112x_8BitRegAccess(CC112X_READ_BURST,CC112X_SYMBOL_RATE1, &readByte1, 1);
  CC112x_8BitRegAccess(CC112X_READ_BURST,CC112X_SYMBOL_RATE0, &readByte0, 1);
  drateE = (readByte2&0xF0)>>4;
  drateM = readByte2&0x0F;
  drateM = drateM<<16;
  drateM |= (uint16_t)readByte1<<8;
  drateM |= readByte0;
  bitratetemp = ((pow(2,20)+drateM)*pow(2,drateE))/(pow(2,39))*40000000;
  bitrate = (uint32_t)roundf(bitratetemp);
  return bitrate;
}


/*******************************************************************************
*   @fn         manualCalibration
*
*   @brief      Calibrates radio according to CC112x errata
*
*   @param      none
*
*   @return     none
*/
#define VCDAC_START_OFFSET 2
#define FS_VCO2_INDEX 0
#define FS_VCO4_INDEX 1
#define FS_CHP_INDEX 2

static void manualCalibration(void) {

    uint8_t original_fs_cal2;
    uint8_t calResults_for_vcdac_start_high[3];
    uint8_t calResults_for_vcdac_start_mid[3];
    uint8_t marcstate;
    uint8_t writeByte;

//    uint8_t VCDAC_START_OFFSET = 2, FS_VCO2_INDEX = 0,FS_VCO4_INDEX = 1,FS_CHP_INDEX = 2;

    // 1) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_VCO2,  &writeByte, 1);

    // 2) Start with high VCDAC (original VCDAC_START + 2):
    CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_FS_CAL2,  &original_fs_cal2, 1);
    writeByte = original_fs_cal2 + VCDAC_START_OFFSET;
    CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_CAL2,  &writeByte, 1);


    // 3) Calibrate and wait for calibration to be done
    //   (radio back in IDLE state)
    CC112X_cmdStrobe(CC112X_SCAL);

    do {
        CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcstate, 1);
        CC112X_cmdStrobe(CC112X_SNOP | CC112X_READ_SINGLE);   //hata veriyordu ve hatanýn ne olduðunu öðprenmek için koydum
    } while (marcstate != 0x41);

    // 4) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained with
    //    high VCDAC_START value
    CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_FS_VCO2,&calResults_for_vcdac_start_high[FS_VCO2_INDEX], 1);
    CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_FS_VCO4,&calResults_for_vcdac_start_high[FS_VCO4_INDEX], 1);
    CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_FS_CHP, &calResults_for_vcdac_start_high[FS_CHP_INDEX], 1);

    // 5) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_VCO2, &writeByte, 1);

    // 6) Continue with mid VCDAC (original VCDAC_START):
    writeByte = original_fs_cal2;
    CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_CAL2,  &writeByte, 1);

    // 7) Calibrate and wait for calibration to be done
    //   (radio back in IDLE state)
    //   (radio back in IDLE state)
        CC112X_cmdStrobe(CC112X_SCAL);

        do {
            CC112x_16BitRegAccess(CC112X_READ_BURST,CC112X_EXTENDED_MARCSTATE, &marcstate, 1);
        } while (marcstate != 0x41);

    // 8) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained
    //    with mid VCDAC_START value
    CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_FS_VCO2,&calResults_for_vcdac_start_mid[FS_VCO2_INDEX], 1);
    CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_FS_VCO4,&calResults_for_vcdac_start_mid[FS_VCO4_INDEX], 1);
    CC112x_16BitRegAccess(CC112X_READ_BURST, CC112X_EXTENDED_FS_CHP,&calResults_for_vcdac_start_mid[FS_CHP_INDEX], 1);

    // 9) Write back highest FS_VCO2 and corresponding FS_VCO
    //    and FS_CHP result
    if (calResults_for_vcdac_start_high[FS_VCO2_INDEX] > calResults_for_vcdac_start_mid[FS_VCO2_INDEX]) {
        writeByte = calResults_for_vcdac_start_high[FS_VCO2_INDEX];
        CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_VCO4_INDEX];
        CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_CHP_INDEX];
        CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_CHP,  &writeByte, 1);
    } else {
        writeByte = calResults_for_vcdac_start_mid[FS_VCO2_INDEX];
        CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_VCO4_INDEX];
        CC112x_16BitRegAccess(CC112X_WRITE_BURST,CC112X_EXTENDED_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_CHP_INDEX];
        CC112x_16BitRegAccess(CC112X_WRITE_BURST, CC112X_EXTENDED_FS_CHP, &writeByte, 1);
    }
}













