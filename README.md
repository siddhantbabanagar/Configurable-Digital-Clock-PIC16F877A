# Configurable Digital Clock using PIC16F877A

A 24-hour configurable digital clock developed using a PIC16F877A microcontroller and Embedded C.  
The project uses a 4-digit 7-segment display and digital keypad switches for real-time clock configuration.

---

## Features

- 24-hour digital clock format
- Time starts from 00:00 after power ON/reset
- 500 ms blinking indication for editable fields
- Configuration mode using the Set/Edit key
- Field selection using the Choose Field key
- Increment and Decrement support for selected fields
- Run mode and Configuration mode implementation
- Timer interrupt-based accurate timing
- Stable clock operation with minimal timing drift

---

## Hardware Used

- PIC16F877A Microcontroller
- 4-Digit Seven Segment Display
- Digital Keypad Switches
- Timer Module
- MPLAB X IDE
- XC8 Compiler

---

## Key Functions

| Key | Function |
|-----|----------|
| DKS1 | Increment |
| DKS2 | Decrement |
| DKS3 | Choose Field |
| DKS4 | Set/Edit |

---

## Project Structure

```text
Configurable-Digital-Clock/
│
├── main.c
├── isr.c
├── timer.c
├── digital_keypad.c
├── ssd.c
│
├── timer.h
├── digital_keypad.h
├── ssd.h
│
├── README.md
└── images/
```

---

## Working

1. On power ON/reset, clock starts from `00:00`
2. Decimal point blinks every 500 ms
3. Press `Set/Edit` key to enter configuration mode
4. Selected field blinks every 500 ms
5. Use:
   - Increment key to increase value
   - Decrement key to decrease value
6. Press `Set/Edit` again to enter run mode

---

## Concepts Used

- Embedded C Programming
- GPIO Interfacing
- Timer Interrupts
- Seven Segment Display Multiplexing
- Keypad Scanning
- State Machine Logic

---

## Future Improvements

- Add RTC module support
- Add AM/PM format
- EEPROM time storage
- Alarm feature

---

## 👨‍💻 Author

**Siddhant Babanagar**
🎓 Electronics & Telecommunication Engineer (2025)
💡 Interested in Embedded Systems & Low-Level Programming
