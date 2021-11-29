/*
 * 
 *
 *  RF COMMUNICATIONS USING CC1120
 *      Author: @GALACICEK
 */

#include "global.h"

uint32_t RXTASK_Time=0;
uint32_t TXTASK_Time=0;


void main(void) {


    Perip_Init();
    _delay_cycles(5);
    __bis_SR_register(GIE);  // Enable the global interrupt
    LED2_ON;
    RF_POWER_EN_ON;
    RF_Init();

    TXTASK_Time = GetTimeTick();
    RXTASK_Time = GetTimeTick();



    while(1){

      if(IsTimeEllapsed(&TXTASK_Time, 450)){
          RF_TXTask();
        }

      if(IsTimeEllapsed(&RXTASK_Time, 1000)){
          RF_RXTask();
        }

    }
}




uint8_t IsTimeEllapsed(uint32_t *LastCall,uint32_t Time){
    if(*LastCall>timeTick){
        if(((0xFFFFFFFF+timeTick)-(*LastCall))>= Time){
            (*LastCall) =timeTick;
            return 1;
        }

    }else{
        if((timeTick)-(*LastCall)>=Time){
            (*LastCall) =timeTick;
            return 1;
        }

    }
    return 0;

}


uint32_t GetTimeTick(void){

    return timeTick;
}
