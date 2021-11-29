/*
 * CC1120.h
 *
 *  Created on: 29 Eyl 2021
 *      Author: Fydil
 */

#ifndef CC112X_REGS_H_
#define CC112X_REGS_H_

/*************************** REGISTER  SPACE  MAP ***************************/

/*
 *  Register Space
 *  Configuration Registers
 */
              //Packet Length Configuration

 #define CC112X_IOCFG3                                       0x0000               //GPIO3 IO Pin Configuration
 #define CC112X_IOCFG2                                       0x0001               //GPIO2 IO Pin Configuration
 #define CC112X_IOCFG1                                       0x0002               //GPIO1 IO Pin Configuration
 #define CC112X_IOCFG0                                       0x0003               //GPIO0 IO Pin Configuration
 #define CC112X_SYNC3                                        0x0004               //Sync Word Configuration [31:24]
 #define CC112X_SYNC2                                        0x0005               //Sync Word Configuration [23:16]
 #define CC112X_SYNC1                                        0x0006               //Sync Word Configuration [15:8]
 #define CC112X_SYNC0                                        0x0007               //Sync Word Configuration [7:0]
 #define CC112X_SYNC_CFG1                                    0x0008               //Sync Word Detection Configuration Reg. 1
 #define CC112X_SYNC_CFG0                                    0x0009               //Sync Word Length Configuration Reg. 0
 #define CC112X_DEVIATION_M                                  0x000A               //Frequency Deviation Configuration
 #define CC112X_MODCFG_DEV_E                                 0x000B               //Modulation Format and Frequency Deviation Configur..
 #define CC112X_DCFILT_CFG                                   0x000C               //Digital DC Removal Configuration
 #define CC112X_PREAMBLE_CFG1                                0x000D               //Preamble Length Configuration Reg. 1
 #define CC112X_PREAMBLE_CFG0                                0x000E               //Preamble Detection Configuration Reg. 0
 #define CC112X_FREQ_IF_CFG                                  0x000F               //RX Mixer Frequency Configuration
 #define CC112X_IQIC                                         0x0010               //Digital Image Channel Compensation Configuration
 #define CC112X_CHAN_BW                                      0x0011               //Channel Filter Configuration    //RX FILTER BW
 #define CC112X_MDMCFG1                                      0x0012               //General Modem Parameter Configuration Reg. 1
 #define CC112X_MDMCFG0                                      0x0013               //General Modem Parameter Configuration Reg. 0
 #define CC112X_SYMBOL_RATE2                                 0x0014               //Symbol Rate Configuration Exponent and Mantissa [1..
 #define CC112X_SYMBOL_RATE1                                 0x0015               //Symbol Rate Configuration Mantissa [15:8]
 #define CC112X_SYMBOL_RATE0                                 0x0016               //Symbol Rate Configuration Mantissa [7:0]
 #define CC112X_AGC_REF                                      0x0017               //AGC Reference Level Configuration
 #define CC112X_AGC_CS_THR                                   0x0018               //Carrier Sense Threshold Configuration
 #define CC112X_AGC_GAIN_ADJUST                              0x0019               //RSSI Offset Configuration
 #define CC112X_AGC_CFG3                                     0x001A               //Automatic Gain Control Configuration Reg. 3
 #define CC112X_AGC_CFG2                                     0x001B               //Automatic Gain Control Configuration Reg. 2
 #define CC112X_AGC_CFG1                                     0x001C               //Automatic Gain Control Configuration Reg. 1
 #define CC112X_AGC_CFG0                                     0x001D               //Automatic Gain Control Configuration Reg. 0
 #define CC112X_FIFO_CFG                                     0x001E               //FIFO Configuration
 #define CC112X_DEV_ADDR                                     0x001F               //Device Address Configuration
 #define CC112X_SETTLING_CFG                                 0x0020               //Frequency Synthesizer Calibration and Settling Con..
 #define CC112X_FS_CFG                                       0x0021               //Frequency Synthesizer Configuration
 #define CC112X_WOR_CFG1                                     0x0022               //eWOR Configuration Reg. 1
 #define CC112X_WOR_CFG0                                     0x0023               //eWOR Configuration Reg. 0
 #define CC112X_WOR_EVENT0_MSB                               0x0024               //Event 0 Configuration MSB
 #define CC112X_WOR_EVENT0_LSB                               0x0025               //Event 0 Configuration LSB
 #define CC112X_PKT_CFG2                                     0x0026               //Packet Configuration Reg. 2 //TX POWER
 #define CC112X_PKT_CFG1                                     0x0027               //Packet Configuration Reg. 1
 #define CC112X_PKT_CFG0                                     0x0028               //Packet Configuration Reg. 0
 #define CC112X_RFEND_CFG1                                   0x0029               //RFEND Configuration Reg. 1
 #define CC112X_RFEND_CFG0                                   0x002A               //RFEND Configuration Reg. 0
 #define CC112X_PA_CFG2                                      0x002B               //Power Amplifier Configuration Reg. 2
 #define CC112X_PA_CFG1                                      0x002C               //Power Amplifier Configuration Reg. 1
 #define CC112X_PA_CFG0                                      0x002D               //Power Amplifier Configuration Reg. 0
 #define CC112X_PKT_LEN                                      0x002E
/*
 *  Extended Address
 *  ((uint16_t)CC112X_EXTENDED_START_ADDRESS+(uint16_t)CC112X_EXTENDED_X)
 */
              //RX FIFO Status

 #define CC112X_EXTENDED_IF_MIX_CFG                           0x2F00              //IF Mix Configuration
 #define CC112X_EXTENDED_FREQOFF_CFG                          0x2F01              //Frequency Offset Correction Configuration
 #define CC112X_EXTENDED_TOC_CFG                              0x2F02              //Timing Offset Correction Configuration
 #define CC112X_EXTENDED_MARC_SPARE                           0x2F03              //MARC Spare
 #define CC112X_EXTENDED_ECG_CFG                              0x2F04              //External Clock Frequency Configuration
 #define CC112X_EXTENDED_CFM_DATA_CFG                         0x2F05              //Custom frequency modulation enable
 #define CC112X_EXTENDED_EXT_CTRL                             0x2F06              //External Control Configuration
 #define CC112X_EXTENDED_RCCAL_FINE                           0x2F07              //RC Oscillator Calibration Fine
 #define CC112X_EXTENDED_RCCAL_COARSE                         0x2F08              //RC Oscillator Calibration Coarse
 #define CC112X_EXTENDED_RCCAL_OFFSET                         0x2F09              //RC Oscillator Calibration Clock Offset
 #define CC112X_EXTENDED_FREQOFF1                             0x2F0A              //Frequency Offset MSB
 #define CC112X_EXTENDED_FREQOFF0                             0x2F0B              //Frequency Offset LSB
 #define CC112X_EXTENDED_FREQ2                                0x2F0C              //Frequency Configuration [23:16]
 #define CC112X_EXTENDED_FREQ1                                0x2F0D              //Frequency Configuration [15:8]
 #define CC112X_EXTENDED_FREQ0                                0x2F0E              //Frequency Configuration [7:0]
 #define CC112X_EXTENDED_IF_ADC2                              0x2F0F              //Analog to Digital Converter Configuration Reg. 2
 #define CC112X_EXTENDED_IF_ADC1                              0x2F10              //Analog to Digital Converter Configuration Reg. 1
 #define CC112X_EXTENDED_IF_ADC0                              0x2F11              //Analog to Digital Converter Configuration Reg. 0
 #define CC112X_EXTENDED_FS_DIG1                              0x2F12              //Frequency Synthesizer Digital Reg. 1
 #define CC112X_EXTENDED_FS_DIG0                              0x2F13              //Frequency Synthesizer Digital Reg. 0
 #define CC112X_EXTENDED_FS_CAL3                              0x2F14              //Frequency Synthesizer Calibration Reg. 3
 #define CC112X_EXTENDED_FS_CAL2                              0x2F15              //Frequency Synthesizer Calibration Reg. 2
 #define CC112X_EXTENDED_FS_CAL1                              0x2F16              //Frequency Synthesizer Calibration Reg. 1
 #define CC112X_EXTENDED_FS_CAL0                              0x2F17              //Frequency Synthesizer Calibration Reg. 0
 #define CC112X_EXTENDED_FS_CHP                               0x2F18              //Frequency Synthesizer Charge Pump Configuration
 #define CC112X_EXTENDED_FS_DIVTWO                            0x2F19              //Frequency Synthesizer Divide by 2
 #define CC112X_EXTENDED_FS_DSM1                              0x2F1A              //FS Digital Synthesizer Module Configuration Reg. 1
 #define CC112X_EXTENDED_FS_DSM0                              0x2F1B              //FS Digital Synthesizer Module Configuration Reg. 0
 #define CC112X_EXTENDED_FS_DVC1                              0x2F1C              //Frequency Synthesizer Divider Chain Configuration ..
 #define CC112X_EXTENDED_FS_DVC0                              0x2F1D              //Frequency Synthesizer Divider Chain Configuration ..
 #define CC112X_EXTENDED_FS_LBI                               0x2F1E              //Frequency Synthesizer Local Bias Configuration
 #define CC112X_EXTENDED_FS_PFD                               0x2F1F              //Frequency Synthesizer Phase Frequency Detector Con..
 #define CC112X_EXTENDED_FS_PRE                               0x2F20              //Frequency Synthesizer Prescaler Configuration
 #define CC112X_EXTENDED_FS_REG_DIV_CML                       0x2F21              //Frequency Synthesizer Divider Regulator Configurat..
 #define CC112X_EXTENDED_FS_SPARE                             0x2F22              //Frequency Synthesizer Spare
 #define CC112X_EXTENDED_FS_VCO4                              0x2F23              //FS Voltage Controlled Oscillator Configuration Reg..
 #define CC112X_EXTENDED_FS_VCO3                              0x2F24              //FS Voltage Controlled Oscillator Configuration Reg..
 #define CC112X_EXTENDED_FS_VCO2                              0x2F25              //FS Voltage Controlled Oscillator Configuration Reg..
 #define CC112X_EXTENDED_FS_VCO1                              0x2F26              //FS Voltage Controlled Oscillator Configuration Reg..
 #define CC112X_EXTENDED_FS_VCO0                              0x2F27              //FS Voltage Controlled Oscillator Configuration Reg..
 #define CC112X_EXTENDED_GBIAS6                               0x2F28              //Global Bias Configuration Reg. 6
 #define CC112X_EXTENDED_GBIAS5                               0x2F29              //Global Bias Configuration Reg. 5
 #define CC112X_EXTENDED_GBIAS4                               0x2F2A              //Global Bias Configuration Reg. 4
 #define CC112X_EXTENDED_GBIAS3                               0x2F2B              //Global Bias Configuration Reg. 3
 #define CC112X_EXTENDED_GBIAS2                               0x2F2C              //Global Bias Configuration Reg. 2
 #define CC112X_EXTENDED_GBIAS1                               0x2F2D              //Global Bias Configuration Reg. 1
 #define CC112X_EXTENDED_GBIAS0                               0x2F2E              //Global Bias Configuration Reg. 0
 #define CC112X_EXTENDED_IFAMP                                0x2F2F              //Intermediate Frequency Amplifier Configuration
 #define CC112X_EXTENDED_LNA                                  0x2F30              //Low Noise Amplifier Configuration
 #define CC112X_EXTENDED_RXMIX                                0x2F31              //RX Mixer Configuration
 #define CC112X_EXTENDED_XOSC5                                0x2F32              //Crystal Oscillator Configuration Reg. 5
 #define CC112X_EXTENDED_XOSC4                                0x2F33              //Crystal Oscillator Configuration Reg. 4
 #define CC112X_EXTENDED_XOSC3                                0x2F34              //Crystal Oscillator Configuration Reg. 3
 #define CC112X_EXTENDED_XOSC2                                0x2F35              //Crystal Oscillator Configuration Reg. 2
 #define CC112X_EXTENDED_XOSC1                                0x2F36              //Crystal Oscillator Configuration Reg. 1
 #define CC112X_EXTENDED_XOSC0                                0x2F37              //Crystal Oscillator Configuration Reg. 0
 #define CC112X_EXTENDED_ANALOG_SPARE                         0x2F38              //Analog Spare
 #define CC112X_EXTENDED_PA_CFG3                              0x2F39              //Power Amplifier Configuration Reg. 3
 #define CC112X_EXTENDED_WOR_TIME1                            0x2F64              //eWOR Timer Counter Value MSB
 #define CC112X_EXTENDED_WOR_TIME0                            0x2F65              //eWOR Timer Counter Value LSB
 #define CC112X_EXTENDED_WOR_CAPTURE1                         0x2F66              //eWOR Timer Capture Value MSB
 #define CC112X_EXTENDED_WOR_CAPTURE0                         0x2F67              //eWOR Timer Capture Value LSB
 #define CC112X_EXTENDED_BIST                                 0x2F68              //MARC Built-In Self-Test
 #define CC112X_EXTENDED_DCFILTOFFSET_I1                      0x2F69              //DC Filter Offset I MSB
 #define CC112X_EXTENDED_DCFILTOFFSET_I0                      0x2F6A              //DC Filter Offset I LSB
 #define CC112X_EXTENDED_DCFILTOFFSET_Q1                      0x2F6B              //DC Filter Offset Q MSB
 #define CC112X_EXTENDED_DCFILTOFFSET_Q0                      0x2F6C              //DC Filter Offset Q LSB
 #define CC112X_EXTENDED_IQIE_I1                              0x2F6D              //IQ Imbalance Value I MSB
 #define CC112X_EXTENDED_IQIE_I0                              0x2F6E              //IQ Imbalance Value I LSB
 #define CC112X_EXTENDED_IQIE_Q1                              0x2F6F              //IQ Imbalance Value Q MSB
 #define CC112X_EXTENDED_IQIE_Q0                              0x2F70              //IQ Imbalance Value Q LSB
 #define CC112X_EXTENDED_RSSI1                                0x2F71              //Received Signal Strength Indicator Reg. 1
 #define CC112X_EXTENDED_RSSI0                                0x2F72              //Received Signal Strength Indicator Reg.0
 #define CC112X_EXTENDED_MARCSTATE                            0x2F73              //MARC State
 #define CC112X_EXTENDED_LQI_VAL                              0x2F74              //Link Quality Indicator Value
 #define CC112X_EXTENDED_PQT_SYNC_ERR                         0x2F75              //Preamble and Sync Word Error
 #define CC112X_EXTENDED_DEM_STATUS                           0x2F76              //Demodulator Status
 #define CC112X_EXTENDED_FREQOFF_EST1                         0x2F77              //Frequency Offset Estimate MSB
 #define CC112X_EXTENDED_FREQOFF_EST0                         0x2F78              //Frequency Offset Estimate LSB
 #define CC112X_EXTENDED_AGC_GAIN3                            0x2F79              //Automatic Gain Control Reg. 3
 #define CC112X_EXTENDED_AGC_GAIN2                            0x2F7A              //Automatic Gain Control Reg. 2
 #define CC112X_EXTENDED_AGC_GAIN1                            0x2F7B              //Automatic Gain Control Reg. 1
 #define CC112X_EXTENDED_AGC_GAIN0                            0x2F7C              //Automatic Gain Control Reg. 0

 #define CC112X_EXTENDED_CFM_RX_DATA_OUT                      0x2F7D              ///*!< Number of bytes in TXFIFO */Custom Frequency Modulation RX Data
 #define CC112X_EXTENDED_CFM_TX_DATA_IN                       0x2F7E              ///*!< Number of bytes in RXFIFO */Custom Frequency Modulation TX Data

 #define CC112X_EXTENDED_ASK_SOFT_RX_DATA                     0x2F7F              //ASK Soft Decision Output
 #define CC112X_EXTENDED_RNDGEN                               0x2F80              //Random Number Generator Value
 #define CC112X_EXTENDED_MAGN2                                0x2F81              //Signal Magnitude after CORDIC [16]
 #define CC112X_EXTENDED_MAGN1                                0x2F82              //Signal Magnitude after CORDIC [15:8]
 #define CC112X_EXTENDED_MAGN0                                0x2F83              //Signal Magnitude after CORDIC [7:0]
 #define CC112X_EXTENDED_ANG1                                 0x2F84              //Signal Angular after CORDIC [9:8]
 #define CC112X_EXTENDED_ANG0                                 0x2F85              //Signal Angular after CORDIC [7:0]
 #define CC112X_EXTENDED_CHFILT_I2                            0x2F86              //Channel Filter Data Real Part [18:16]
 #define CC112X_EXTENDED_CHFILT_I1                            0x2F87              //Channel Filter Data Real Part [15:8]
 #define CC112X_EXTENDED_CHFILT_I0                            0x2F88              //Channel Filter Data Real Part [7:0]
 #define CC112X_EXTENDED_CHFILT_Q2                            0x2F89              //Channel Filter Data Imaginary Part [18:16]
 #define CC112X_EXTENDED_CHFILT_Q1                            0x2F8A              //Channel Filter Data Imaginary Part [15:8]
 #define CC112X_EXTENDED_CHFILT_Q0                            0x2F8B              //Channel Filter Data Imaginary Part [7:0]
 #define CC112X_EXTENDED_GPIO_STATUS                          0x2F8C              //General Purpose Input/Output Status
 #define CC112X_EXTENDED_FSCAL_CTRL                           0x2F8D              //Frequency Synthesizer Calibration Control
 #define CC112X_EXTENDED_PHASE_ADJUST                         0x2F8E              //Frequency Synthesizer Phase Adjust
 #define CC112X_EXTENDED_PARTNUMBER                           0x2F8F              //Part Number
 #define CC112X_EXTENDED_PARTVERSION                          0x2F90              //Part Revision
 #define CC112X_EXTENDED_SERIAL_STATUS                        0x2F91              //Serial Status
 #define CC112X_EXTENDED_MODEM_STATUS1                        0x2F92              //Modem Status Reg. 1
 #define CC112X_EXTENDED_MODEM_STATUS0                        0x2F93              //Modem Status Reg. 0
 #define CC112X_EXTENDED_MARC_STATUS1                         0x2F94              //MARC Status Reg. 1
 #define CC112X_EXTENDED_MARC_STATUS0                         0x2F95              //MARC Status Reg. 0
 #define CC112X_EXTENDED_PA_IFAMP_TEST                        0x2F96              //Power Amplifier Intermediate Frequency Amplifier T..
 #define CC112X_EXTENDED_FSRF_TEST                            0x2F97              //Frequency Synthesizer Test
 #define CC112X_EXTENDED_PRE_TEST                             0x2F98              //Frequency Synthesizer Prescaler Test
 #define CC112X_EXTENDED_PRE_OVR                              0x2F99              //Frequency Synthesizer Prescaler Override
 #define CC112X_EXTENDED_ADC_TEST                             0x2F9A              //Analog to Digital Converter Test
 #define CC112X_EXTENDED_DVC_TEST                             0x2F9B              //Digital Divider Chain Test
 #define CC112X_EXTENDED_ATEST                                0x2F9C              //Analog Test
 #define CC112X_EXTENDED_ATEST_LVDS                           0x2F9D              //Analog Test LVDS
 #define CC112X_EXTENDED_ATEST_MODE                           0x2F9E              //Analog Test Mode
 #define CC112X_EXTENDED_XOSC_TEST1                           0x2F9F              //Crystal Oscillator Test Reg. 1
 #define CC112X_EXTENDED_XOSC_TEST0                           0x2FA0              //Crystal Oscillator Test Reg. 0
 #define CC112X_EXTENDED_RXFIRST                              0x2FD2              //RX FIFO Pointer First Entry
 #define CC112X_EXTENDED_TXFIRST                              0x2FD3              //TX FIFO Pointer First Entry
 #define CC112X_EXTENDED_RXLAST                               0x2FD4              //RX FIFO Pointer Last Entry
 #define CC112X_EXTENDED_TXLAST                               0x2FD5              //TX FIFO Pointer Last Entry
 #define CC112X_EXTENDED_NUM_TXBYTES                          0x2FD6              //TX FIFO Status
 #define CC112X_EXTENDED_NUM_RXBYTES                          0x2FD7              //RX FIFO Status
 #define CC112X_EXTENDED_FIFO_NUM_TXBYTES                     0x2FD8              //TX FIFO Status
 #define CC112X_EXTENDED_FIFO_NUM_RXBYTES                     0x2FD9

/*
 *  Command Strobes
*/
 #define CC112X_SRES                                          0x30             // Reset chip.
 #define CC112X_SFSTXON                                       0x31             // Enable/calibrate freq synthesizer
 #define CC112X_SXOFF                                         0x32             // Turn off crystal oscillator.
 #define CC112X_SCAL                                          0x33             // Calibrate freq synthesizer & disable
 #define CC112X_SRX                                           0x34             // Enable RX.
 #define CC112X_STX                                           0x35             // Enable TX.
 #define CC112X_SIDLE                                         0x36             // Exit RX / TX
 #define CC112X_SWOR                                          0x38             // Start automatic RX polling sequence
 #define CC112X_SPWD                                          0x39             // Enter pwr down mode when CSn goes hi
 #define CC112X_SFRX                                          0x3A             // Flush the RX FIFO buffer.
 #define CC112X_SFTX                                          0x3B             // Flush the TX FIFO buffer.
 #define CC112X_SWORRST                                       0x3C             // Reset real time clock.
 #define CC112X_SNOP                                          0x3D             // No operation.


/*
 * Direct FIFO Access
 * FIFO Buffers
 *
 */
 #define CC1120_DIRECT_FIFO_ACCESS                            0x3E
 #define CC112X_TXFIFO                                        0x3F
 #define CC112X_RXFIFO                                        0x3F


/*
 * Definitions to support burst/single access:
 */
 #define CC112X_WRITE_SINGLE                                  0x00
 #define CC112X_WRITE_BURST                                   0x40
 #define CC112X_READ_SINGLE                                   0x80
 #define CC112X_READ_BURST                                    0xC0


/*
 * Masks for appended status bytes
 *
 */
 #define RSSI_RX                                              0x00        // Position of RSSI byte
 #define LQI_RX                                               0x01        // Position of LQI byte
 #define CRC_OK                                               0x80        // Mask "CRC_OK" bit within LQI byte
 #define MARCSTATE_IDLE                                       0x01        // The status register indicates idle

 #define RX_STATE                                             0x0D
 #define RX_END_STATE                                         0x0E
 #define RX_FIFO_ERROR                                        0x11

 #define TX_STATE                                             0x13
 #define TX_END_STATE                                         0x14
 #define TX_FIFO_ERROR                                        0x16
/******************************************************************************/


#endif /* CC112X_REGS_H_ */






