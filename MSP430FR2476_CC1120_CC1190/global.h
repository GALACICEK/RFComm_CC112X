/*
 * global.h
 *
 *  Created on: 28 Eyl 2021
 *      Author: @GALACICEK
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_



#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "strings.h"
#include "math.h"

#include "defines.h"
#include "periph_init.h"
#include "spi.h"

#include "CC112X.h"
#include "CC1190.h"

#include "radio.h"

/*----------------------------------------------------------------*/

extern volatile uint32_t timeTick;

extern uint8_t IsTimeEllapsed(uint32_t *LastCall,uint32_t Time);
extern uint32_t GetTimeTick(void);

/*Time Check Variables----------------------------------------------------------*/
extern uint32_t rxtimecheck;
extern uint32_t RFPKTTime;

//extern volatile uint32_t MainCheck_Time;

typedef union {

    struct{
        uint8_t CC1120_GPIO2:1;  // CC1120_GPIO2 interrupt =1
        uint8_t Flag2:1;
        uint8_t Flag3:1;
        uint8_t Flag4:1;
        uint8_t Flag5:1;
        uint8_t Flag6:1;
        uint8_t Flag7:1;
        uint8_t Flag8:1;
    }Bits;
    uint8_t AllBits;

}Flag_t;

extern Flag_t flag;

#endif /* GLOBAL_H_ */
