

#include "ledTask.h"
#include "taskHandles.h"
#include "lpc111x.h"



void ledTask(void *pvParameters)
{
//    TASKHANDLES *taskHandles = (TASKHANDLES*)pvParameters;

    SYSTICK_LED_IOCON = 0x0;
    SYSTICK_LED_DIR = (1<<SYSTICK_LED_PIN);
    
    vTaskDelay(1000);
    unsigned int i;
    for ( i=0; ;i++)
    {
		SYSTICK_LED_DATA ^= (1<<SYSTICK_LED_PIN);	
        vTaskDelay(500 / portTICK_RATE_MS);
    }
}


