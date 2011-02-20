/*
 * leds.h
 *
 *  Created on: Jan 30, 2011
 *      Author: timo
 */

#ifndef LEDTASK_H_
#define LEDTASK_H_

#define SYSTICK_LED_IOCON				IOCON_PIO2_0
#define SYSTICK_LED_DIR					GPIO_GPIO0DIR	// the register that are for the led
#define SYSTICK_LED_DATA				GPIO_GPIO0DATA
#define SYSTICK_LED_PIN					7			// the actual led pin

void ledTask(void *pvParameters);

#endif /* LEDS_H_ */


