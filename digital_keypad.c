#include <xc.h>
#include "digital_keypad.h"
void init_digital_keypad(void){
    //config RB to RB5 pins as input pin
    TRISB=TRISB|0x3f;
}
unsigned char read_digital_keypad(unsigned char mode){
    static unsigned char once=1;
    //detect the key and return key level or edge
    if(mode==LEVEL){
        return (PORTB & 0x3F);//SW1,SW2,SW3,SW4,SW5,SW6,ALL_RELEASED
    }
    else if(mode==STATE){
        if((PORTB & 0x3F)!=ALL_RELEASED && once){
            once=0;
            return (PORTB & 0x3F);
        }
        else if((PORTB & 0x3F)==ALL_RELEASED ){
            once=1;
        }
    }
    return ALL_RELEASED;
}
