/*
 * functions.c
 *
 *  Created on: 30 Eyl 2021
 *      Author: @GALACICEK
 */
#include "global.h"

void ERASE_BUFF(uint8_t *Buff, int dataSize){

    while(--dataSize >0){
        *Buff='\0';
        Buff++;
    }
}



uint8_t SPI_ReadWriteBytes(uint8_t data){   //RX

    while(SPI_SI_PXOUT & SPI_SI_PIN);
    while((SPISTATW & UCBUSY));
    SPITXBUF = data;
    while((SPISTATW & UCBUSY));
    data = SPIRXBUF;

   return data;
}


void SPI_WriteBytes(uint8_t data){  //TX

   while((SPISTATW & UCBUSY)&(SPISTATW & UCOE));
   SPITXBUF = data;
   while((SPISTATW & UCBUSY));

}



