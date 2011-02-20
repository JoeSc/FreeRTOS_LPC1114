/*
 *  uart.c
 *  TEST
 *
 *  Created by Joe  Schaack on 8/13/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "uart.h"
#include "cpu_init.h"


void UART_IRQHandler(void)
{
}

void uartInit(uint32_t baudrate)
{
   uint32_t regVal, num;
   
   
   NVIC_DisableIRQ(UART_IRQn);
   
   /* Set 1.6 UART RXD */
   IOCON_PIO1_6 &= ~IOCON_PIO1_6_FUNC_MASK;
   IOCON_PIO1_6 |= IOCON_PIO1_6_FUNC_UART_RXD;
   
   /* Set 1.7 UART TXD */
   IOCON_PIO1_7 &= ~IOCON_PIO1_7_FUNC_MASK;	
   IOCON_PIO1_7 |= IOCON_PIO1_7_FUNC_UART_TXD;
   
   /* Enable UART clock */
   SCB_SYSAHBCLKCTRL |= (SCB_SYSAHBCLKCTRL_UART);
   SCB_UARTCLKDIV = SCB_UARTCLKDIV_DIV1;     /* divided by 1 */
   
   /* 8 bits, no Parity, 1 Stop bit */
   UART_U0LCR = (UART_U0LCR_Word_Length_Select_8Chars |
                 UART_U0LCR_Stop_Bit_Select_1Bits |
                 UART_U0LCR_Parity_Disabled |
                 UART_U0LCR_Parity_Select_OddParity |
                 UART_U0LCR_Break_Control_Disabled |
                 UART_U0LCR_Divisor_Latch_Access_Enabled);
   
   regVal = SCB_UARTCLKDIV;
   num = (((SYS_CLOCK * SCB_SYSAHBCLKDIV)/regVal)/16)/baudrate;
   
   UART_U0DLM = (num & 0xFF00) >> 8;
   UART_U0DLL = num & 0xFF;
   
//   UART_U0DLM = 0x00; // for 38400 baud
//   UART_U0DLL = 0x51;
   
   
   /* Set DLAB back to 0 */
   UART_U0LCR = (UART_U0LCR_Word_Length_Select_8Chars |
                 UART_U0LCR_Stop_Bit_Select_1Bits |
                 UART_U0LCR_Parity_Disabled |
                 UART_U0LCR_Parity_Select_OddParity |
                 UART_U0LCR_Break_Control_Disabled |
                 UART_U0LCR_Divisor_Latch_Access_Disabled);
   
   /* Enable and reset TX and RX FIFO. */
   UART_U0FCR = (UART_U0FCR_FIFO_Enabled | 
                 UART_U0FCR_Rx_FIFO_Reset | 
                 UART_U0FCR_Tx_FIFO_Reset); 
   
   regVal = UART_U0LSR;
   
   while (( UART_U0LSR & (UART_U0LSR_THRE|UART_U0LSR_TEMT)) != (UART_U0LSR_THRE|UART_U0LSR_TEMT) );
   while ( UART_U0LSR & UART_U0LSR_RDR_DATA )
   {
      /* Dump data from RX FIFO */
      regVal = UART_U0RBR;
   }
   UART_U0IER = 0x0;
   UART_U0TER = UART_U0TER_TXEN_Enabled;
}

void uartSend(char data)
{
   while ( !(UART_U0LSR & UART_U0LSR_THRE) ); // sit and spin untill fifo is empty.  
                                              //it would be nice to be able to fill the fifo
                                              // 16 bytes and then wait for it to be empty?
   UART_U0THR = data;
}

uint32_t uartDataAvailable()
{
   return UART_U0LSR & UART_U0LSR_RDR_DATA;
}


char uartReceive()
{
   return UART_U0RBR;
}


/**************************************************************************/
/*! 
  @brief Sends a single byte over UART.

  @param[in]  byte
  Byte value to send
 */
/**************************************************************************/
void __putchar(const char c)
{
    uartSend(c);
}

/**************************************************************************/
/*! 
  @brief Sends a single byte over UART.

  @param[in]  byte
  Byte value to send
 */
/**************************************************************************/
int puts(const char * str)
{
    int i =0;
    while(*str)
    {
        __putchar(*str++);
        i++;
    }
    return i;
}






