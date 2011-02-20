/*
 *  uart.h
 *  TEST
 *
 *  Created by Joe  Schaack on 8/13/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "lpc111x.h"
#include "sysdefs.h"

#ifndef _uart_H_
#define _uart_H_

void uartInit(uint32_t baudrate);
void uartSend(char data);
uint32_t uartDataAvailable();
char uartReceive();



#endif

