#ifndef SSD_H
#define SSD_H

#define SSD_DATA_PORT PORTD
#define SSD_CNT_PORT PORTA
#define SSD_DATA_PORT_DDR TRISD
#define SSD_CNT_PORT_DDR TRISA

#define ZERO 0xBF
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX  0x7D
#define SEVEN 0x07
#define EIGHT 0x07F
#define NINE 0x6F

void init_ssd_display(void);
void display(unsigned char ssd[]);

#endif