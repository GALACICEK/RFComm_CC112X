/*
 * functions.h
 *
 *  Created on: 30 Eyl 2021
 *      Author: @GALACICEK
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <msp430.h>

extern void SPI_WriteBytes(uint8_t data);
extern uint8_t SPI_ReadWriteBytes(uint8_t data);
extern void ERASE_BUFF(uint8_t *Buff, int dataSize);

#endif /* FUNCTIONS_H_ */
