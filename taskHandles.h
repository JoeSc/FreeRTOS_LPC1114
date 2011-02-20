
#ifndef TASKHANDLES_H
#define TASKHANDLES_H

#include "FreeRTOS.h"        
#include "task.h"
#include "queue.h"
#include "semphr.h"


typedef struct
{

        struct {
                //xTaskHandle userInterface;
                //xTaskHandle flight_task;
                xTaskHandle ledTask;
                xTaskHandle cnt;
                xTaskHandle stack_checker;
        }task;

        struct {
                //xSemaphoreHandle SPI;  // spi lock
        }lock;

        struct {
                //PID_DATA * pid_roll;
                //PID_DATA * pid_pitch;
                //PID_DATA * pid_yaw;
                //uint8_t flying_mode; //X_MODE or PLUS_MODE
                //uint8_t led_mode;
                //uint16_t pitch_roll_tx_scale;
                //uint16_t yaw_tx_scale;
        }flight_settings;

        struct {
                //unsigned char armed;
                //unsigned char telem_mode;
                //int tx_throttle, tx_yaw, tx_pitch, tx_roll;
                //unsigned int command_used_number;
                //unsigned char please_update_sensors;
        }flight_control;


}TASKHANDLES;

#endif
 


