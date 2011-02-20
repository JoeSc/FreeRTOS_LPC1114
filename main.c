/*
 *  main.c
 *  Test1
 *
 *  Created by Joe  Schaack on 8/13/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include <stdio.c>
#include "uart.h"
#include <cpu_init.h>

//  #include "osHandles.h"
//  #include "FreeRTOS.h"
//  #include "task.h"
//  #include "queue.h"
//  #include "croutine.h"
//  
//  #include "ledTask.h"
//  #include "stack_checker.h"
//  
//  void vTaskPrint(void *pvParameters);


int main (void)
{
//    OSHANDLES System;            // Should contain all OS Handles
    
    cpuInit();
    uartInit(BAUDRATE);
    

//    xTaskCreate( vTaskPrint , (const signed portCHAR * const) "cnt", configMINIMAL_STACK_SIZE, &System, 3, &System.task.cnt);

//    xTaskCreate( ledTask , (const signed portCHAR * const) "led", configMINIMAL_STACK_SIZE, &System, 3, &System.task.ledTask);
//    xTaskCreate( stack_checker , (const signed portCHAR * const) "stack_check", 500, &System, 3, &System.task.stack_checker);

    
    printf("Starting OS!!\n");

//    vTaskStartScheduler(); // does not return


    printf("ERROR END");
    while(1);
}




////    /**************************************************************************/
////    /*! 
////      @brief Sends a single byte over UART.
////    
////      @param[in]  byte
////      Byte value to send
////     */
////    /**************************************************************************/
////    void __putchar(const char c)
////    {
////        uartSend(c);
////    }
////    
////    /**************************************************************************/
////    /*! 
////      @brief Sends a single byte over UART.
////    
////      @param[in]  byte
////      Byte value to send
////     */
////    /**************************************************************************/
////    int puts(const char * str)
////    {
////        int i =0;
////        while(*str)
////        {
////            __putchar(*str++);
////            i++;
////        }
////        return i;
////    }




//  void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed portCHAR *pcTaskName )
//  {
//      puts("Stack overflow in thread: ");
//      puts((char *)pcTaskName);
//      puts("\n");
//      while(1);
//  }
//  void HardFault_Handler (void)
//  {printf("ERRRRRRR");
//      while(1);
//  }
//  void vApplicationIdleHook( void )
//  {
//      __WFI();
//  }
//  
//  void vTaskPrint(void *pvParameters)
//  {
//      int cnt = 0;
//      while(1)
//      {
//          printf("cnt = %d\n",cnt++);
//          vTaskDelay((configTICK_RATE_HZ/2));//*200/1000);
//      }
//  }




//
