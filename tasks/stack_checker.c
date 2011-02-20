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
        signed char list[200];
        vTaskList(list);
        puts("\nName\t     State  Priority\tStack\tNum");
        printf("%s",list);
        vTaskDelay(5000 / portTICK_RATE_MS);        
    }    
}



