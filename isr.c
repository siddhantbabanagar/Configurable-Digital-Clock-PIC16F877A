#include <xc.h>

extern unsigned char sec;
extern unsigned char half_sec;
extern unsigned char blink;

void __interrupt() isr(void)
{
    static unsigned int count = 0;

    if(TMR0IF)
    {
        TMR0IF = 0;
        TMR0 = 6;   // reload timer

        count++;

        if(count == 10000)     // 0.5 sec
        {
            half_sec = 1;
            blink = !blink;
        }

        if(count == 20000)     // 1 sec
        {
            sec++;
            half_sec = 0;
            count = 0;
        }
    }
}