#ifndef DIGITAL_KEYPAD_H
#define DIGITAL_KEYPAD_H


#define LEVEL 1
#define STATE 0

#define SW1 0x3E
#define SW2 0x3D
#define SW3 0X3B
#define SW4 0X37
#define SW5 0x2F
#define SW6 0x1F

#define ALL_RELEASED 0x3F

// This line is likely missing or misspelled!
void init_digital_keypad(void); 
unsigned char read_digital_keypad(unsigned char mode);

#endif

