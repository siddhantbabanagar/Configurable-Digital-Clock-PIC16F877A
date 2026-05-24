
#include <xc.h>
#include "timer.h"

void init_timer0()
{
    //start timer from
    TMR0=6;
    
    //select internal clock to config timer module
    T0CS=0;
    
    //enable timer0 interrupt
    TMR0IE=1;
    
    TMR0IF=0;
    
    PSA=1;
    
}
