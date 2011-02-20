/*
 This file sets up the CPU
 
 */
#include "lpc111x.h"
#include "sysdefs.h"
#ifndef _CPU_H_
#define _CPU_H_


#define	EXTERNAL_OSCILLATOR _FREQ 		12000000	// if using the EXT OSC set this
                                                //#define	USE_EXTERNAL_OSCILLATOR	
#define INTERNAL_OSCILLATOR_FREQ		12000000

#define SYS_CLOCK						48000000	// set a 50Mhz clock
#define SYSCLK							SYS_CLOCK	

#define SYSTICK_DELAY_MS				1			// number of ms between systick interrupts

#define SYSTICK_LED									// used to enable a systick led
#define SYSTICK_LED_MS					500		// number of seconds between led toggle
#define SYSTICK_LED_IOCON				IOCON_PIO2_0
#define SYSTICK_LED_DIR					GPIO_GPIO0DIR	// the register that are for the led
#define SYSTICK_LED_DATA				GPIO_GPIO0DATA
#define SYSTICK_LED_PIN					7			// the actual led pin

   //#define UART_BAUDRATE					115200
   //#define UART_RX_BUFSIZE					80


void cpuPllInit();
void cpuInit();
void sysTickInit();
void delay(uint32_t ms);
uint32_t millis();

#endif
