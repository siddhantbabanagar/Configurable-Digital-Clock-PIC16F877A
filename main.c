
#include <xc.h>
#include "timer.h"
#include "ssd.h"
#include "digital_keypad.h"

//turn off WDT
#pragma config WDTE=OFF

unsigned char ssd[4];
unsigned char digit[]={ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
unsigned char hr = 12;
unsigned char min = 0;
unsigned char sec = 0;
unsigned char half_sec = 0;
unsigned char blink = 0;

void init_config() {
    init_digital_keypad();
    init_ssd_display();
    init_timer0();
    ssd[0]=ZERO;
    ssd[1]=ZERO;
    ssd[2]=ZERO;
    ssd[3]=ZERO;
    display(ssd);
    
    //to enable peripheral and global interrupts
    PEIE=1;
    GIE=1;    
    
}

void main(void) 
{
    init_config();
    
    unsigned char mode = 0;
    unsigned char field = 0;
    unsigned char key;

    while (1) 
    {
        key = read_digital_keypad(STATE);

        if(key == SW4)
        {
            mode = !mode;     // toggle run/edit
        }

        if(mode == 0)
        {
            // RUN MODE

            ssd[0] = digit[hr / 10];

            if(half_sec)
                ssd[1] = digit[hr % 10] | 0x80;   // DP blink
            else
                ssd[1] = digit[hr % 10];

            ssd[2] = digit[min / 10] & 0x7F;
            ssd[3] = digit[min % 10] & 0x7F;

            display(ssd);

            if(sec == 60)
            {
                sec = 0;
                min++;

                if(min == 60)
                {
                    min = 0;
                    hr++;

                    if(hr == 24)
                        hr = 0;
                }
            }
        }

        else
        {
            // EDIT MODE

            if(key == SW3)
            {
                field = !field;      // toggle hr/min edit
            }

            // Update normal display first
            ssd[0] = digit[hr / 10];
            ssd[1] = digit[hr % 10];
            ssd[2] = digit[min / 10];
            ssd[3] = digit[min % 10];

            if(field == 0)
            {
                // EDIT MINUTES

                if(blink == 0)
                {
                    ssd[2] = 0x00;
                    ssd[3] = 0x00;
                }

                if(key == SW1)
                {
                    min++;
                    if(min == 60)
                        min = 0;
                }

                else if(key == SW2)
                {
                    if(min == 0)
                        min = 59;
                    else
                        min--;
                }
            }

            else
            {
                // EDIT HOURS

                if(blink == 0)
                {
                    ssd[0] = 0x00;
                    ssd[1] = 0x00;
                }

                if(key == SW1)
                {
                    hr++;
                    if(hr == 24)
                        hr = 0;
                }

                else if(key == SW2)
                {
                    if(hr == 0)
                        hr = 23;
                    else
                        hr--;
                }
            }

            display(ssd);
        }
    }
}