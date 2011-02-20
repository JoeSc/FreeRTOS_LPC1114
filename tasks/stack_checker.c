#include "stack_checker.h"
#include "taskHandles.h"
#include "lpc111x.h"
#include "stdio.h"
#include "uart.h"

void stack_checker(void *pvParameters)
{
    //TASKHANDLES *taskHandles = (TASKHANDLES*)pvParameters;

    while(1)
    {
        int bytesFree;
        int bytesUsed;
        int blocksFree;
        vPortUsedMem (&bytesFree, &bytesUsed, &blocksFree);
        
        signed char list[200];
        vTaskList(list);
        
        printf ("Task\t\tState\tPrty\tStack\tTask#\n");
        printf ("%s\nHeap size=%d, used=%d, ", list, configTOTAL_HEAP_SIZE, bytesUsed);
        printf("free=%d (%d blocks)\n", bytesFree, blocksFree);
        vTaskDelay(5000 / portTICK_RATE_MS);        
    }    
}



