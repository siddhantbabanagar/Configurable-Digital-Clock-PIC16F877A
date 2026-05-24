/*
 * File:   ssc.c
 * Author: HP
 *
 * Created on 16 February, 2026, 10:44 PM
 */


#include <xc.h>
#include "ssd.h"

//turn off WDT
#pragma config WDTE=OFF

void init_ssd_display(void){
    //config PORTD as OUTPUT
    SSD_DATA_PORT_DDR=0x00;
    
    //config PORTA RA2 3 4 5 as i/p pins
    SSD_CNT_PORT_DDR=SSD_CNT_PORT_DDR & 0xC3;
    //clear all SSD
    SSD_CNT_PORT= SSD_CNT_PORT & 0xC3;
}

void display(unsigned char ssd[]){
    //display 1 on first ssd
    for(unsigned char digit=0;digit<4;digit++){
        SSD_DATA_PORT=ssd[digit];
        SSD_CNT_PORT= (SSD_CNT_PORT & 0xC3) | 0x04 << digit;
        for(unsigned int wait=100;wait--;);
    }
    
}
