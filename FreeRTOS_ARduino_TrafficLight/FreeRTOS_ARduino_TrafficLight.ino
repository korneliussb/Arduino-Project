#include <Arduino_FreeRTOS.h>
#include <croutine.h>
#include <event_groups.h>
#include <FreeRTOSConfig.h>
#include <FreeRTOSVariant.h>
#include <list.h>
#include <message_buffer.h>
#include <mpu_wrappers.h>
#include <portable.h>
#include <portmacro.h>
#include <projdefs.h>
#include <queue.h>
#include <semphr.h>
#include <StackMacros.h>
#include <stack_macros.h>
#include <stream_buffer.h>
#include <task.h>
#include <timers.h>

/*     FreeRTOS V10.0.1 - Copyright (C) 2016 Real Time Engineers Ltd. 
 
    This file is part of the FreeRTOS distribution. */ 
 
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>
 
/* Scheduler include files. */ 

#include "task.h" 
 
static void vTaskLED1(void *pvParameters); 
int main(void) 
{
  DDRA |= (1 << PA0) | (1 << PA1) |
          (1 << PA2) | (1 << PA3) | 
          (1 << PA4) | (1 << PA5) |
          (1 << PA6); 
 
/* Create the tasks defined within this file. */ 

xTaskCreate( vTaskLED1, ( signed char * ) 
"vTaskLED1", configMINIMAL_STACK_SIZE,
NULL, tskIDLE_PRIORITY + 1, NULL ); 
 
/* Start Scheduler */     
vTaskStartScheduler(); 
 
 return 0; 
 } 
 
/*---------------------------------*/ 
 
static void vTaskLED1( void *pvParameters ) 
{  
  /* The parameters are not used. */  
  ( void ) pvParameters; 
  
  /* Cycle for ever, delaying then checking all 
  the other tasks are still  operating 
  without error. */  
  
  for( ;; )  
  {
    PORTA &= ~(1 << PA6);
    PORTA |= (1 << PA5);
    PORTA &= ~(1 << PA4);
    PORTA &= ~(1 << PA3); 
    
    PORTA |= (1 << PA0);   
    PORTA &= ~(1 << PA1);   
    PORTA &= ~(1 << PA2); 
    
    vTaskDelay( 45 );   
    PORTA &= ~(1 << PA6);   
    PORTA &= ~(1 << PA5);   
    PORTA |= (1 << PA4);   
    PORTA |= (1 << PA3); 
    
    PORTA |= (1 << PA0);   
    PORTA &= ~(1 << PA1);   
    PORTA &= ~(1 << PA2);
    
    vTaskDelay( 45 );   
    PORTA &= ~(1 << PA6);   
    PORTA &= ~(1 << PA5);   
    PORTA |= (1 << PA4);   
    PORTA &= ~(1 << PA3);
    
    PORTA |= (1 << PA0);   
    PORTA &= ~(1 << PA1);   
    PORTA &= ~(1 << PA2); 
    
    vTaskDelay( 45 );   
    PORTA &= ~(1 << PA6);   
    PORTA &= ~(1 << PA5);   
    PORTA &= ~(1 << PA4);   
    PORTA |= (1 << PA3);
    
    PORTA &= ~(1 << PA0);   
    PORTA |= (1 << PA1);   
    PORTA &= ~(1 << PA2);
    
    vTaskDelay( 45 );   
    PORTA &= ~(1 << PA6);   
    PORTA &= ~(1 << PA5); 
    PORTA &= ~(1 << PA4);   
    PORTA &= ~(1 << PA3); 
    
    PORTA &= ~(1 << PA0);   
    PORTA &= ~(1 << PA1);   
    PORTA |= (1 << PA2); 
    
    vTaskDelay( 45 );  
    } 
}   
