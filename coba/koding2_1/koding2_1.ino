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
int merah1 = 2;
int merah2 = 3;
int merah3 = 4;
int merah4 = 5;
int kuning1 = 6;
int kuning2 = 7;
int kuning3 = 8;
int kuning4 = 9;
int hijau1 = 10;
int hijau2 = 11;
int hijau3 = 12;
int hijau4 = 13;

void setup() {

  //Initialize the Serial Monitor with 9600 baud rate

  Serial.begin(9600);
  Serial.println(F("In Setup function"));

  //Set the digital pins 2  to 13 as output
  pinMode(merah1,OUTPUT); //2
  pinMode(merah2,OUTPUT); //3
  pinMode(merah3,OUTPUT); //4
  pinMode(merah4,OUTPUT); //5
  pinMode(kuning1,OUTPUT); //6
  pinMode(kuning2,OUTPUT); //7
  pinMode(kuning3,OUTPUT); //8
  pinMode(kuning4,OUTPUT); //9
  pinMode(hijau1,OUTPUT); //10
  pinMode(hijau2,OUTPUT); //11
  pinMode(hijau3,OUTPUT); //12
  pinMode(hijau4,OUTPUT); //13

  //Create 8 tasks with labels Task1, Task2, Task3, Task 4,
  //Task 5, Task 6, Task 7, Task 8 and assign the priority as 1
  xTaskCreate(Task1, "Task1", 100, NULL, 1, NULL);
  xTaskCreate(Task2, "Task2", 100, NULL, 2, NULL);
  xTaskCreate(Task3, "Task3", 100, NULL, 3, NULL);
  xTaskCreate(Task4, "Task4", 100, NULL, 4, NULL);
  xTaskCreate(Task5, "Task5", 100, NULL, 5, NULL);
  xTaskCreate(Task6, "Task6", 100, NULL, 6, NULL);
  xTaskCreate(Task7, "Task7", 100, NULL, 7, NULL);
  xTaskCreate(Task8, "Task8", 100, NULL, 8, NULL); //100=stack size
}

//The following function is Task1. I display the task label on Serial Monitor
static void Task1(void* pvParameters)
{while (1)
  {
     // Hidupkan H1
  digitalWrite(merah1,LOW);
  digitalWrite(kuning1,LOW);
  digitalWrite(hijau1,HIGH);

  digitalWrite(merah2,HIGH);
  digitalWrite(kuning2,LOW);
  digitalWrite(hijau2,LOW);

  digitalWrite(merah3,HIGH);
  digitalWrite(kuning3,LOW);
  digitalWrite(hijau3,LOW);

  digitalWrite(merah4,HIGH);
  digitalWrite(kuning4,LOW);
  digitalWrite(hijau4,LOW);
  Serial.println(F("Task1"));
  vTaskDelay(8000/portTICK_PERIOD_MS);
  }
}

static void Task2(void* pvParameters)
{while (1)
  {
  // K1 HIDUP, K3 HIDUP  
  digitalWrite(merah1,LOW);
  digitalWrite(kuning1,HIGH);
  digitalWrite(hijau1,LOW);

  digitalWrite(merah2,HIGH);
  digitalWrite(kuning2,LOW);
  digitalWrite(hijau2,LOW);

  digitalWrite(merah3,LOW);
  digitalWrite(kuning3,HIGH);
  digitalWrite(hijau3,LOW);

  digitalWrite(merah4,HIGH);
  digitalWrite(kuning4,LOW);
  digitalWrite(hijau4,LOW);
  Serial.println(F("Task2"));
  vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}

static void Task3(void* pvParameters)
{while (1)
  {
  // H3 HIDUP
  digitalWrite(merah1,HIGH);
  digitalWrite(kuning1,LOW);
  digitalWrite(hijau1,LOW);

  digitalWrite(merah2,HIGH);
  digitalWrite(kuning2,LOW);
  digitalWrite(hijau2,LOW);

  digitalWrite(merah3,LOW);
  digitalWrite(kuning3,LOW);
  digitalWrite(hijau3,HIGH);

  digitalWrite(merah4,HIGH);
  digitalWrite(kuning4,LOW);
  digitalWrite(hijau4,LOW);
  Serial.println(F("Task3"));
  vTaskDelay(8000/portTICK_PERIOD_MS);
  }
}

static void Task4(void* pvParameters)
{while (1)
  {
   // K3 HIDUP, K2 HIDUP, 
  digitalWrite(merah1,HIGH);
  digitalWrite(kuning1,LOW);
  digitalWrite(hijau1,LOW);

  digitalWrite(merah2,LOW);
  digitalWrite(kuning2,HIGH);
  digitalWrite(hijau2,LOW);

  digitalWrite(merah3,LOW);
  digitalWrite(kuning3,HIGH);
  digitalWrite(hijau3,LOW);

  digitalWrite(merah4,HIGH);
  digitalWrite(kuning4,LOW);
  digitalWrite(hijau4,LOW);
  Serial.println(F("Task4"));
  vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}

static void Task5(void* pvParameters)
{while (1)
  {
   //H2 HIDUP ,
  digitalWrite(merah1,HIGH);
  digitalWrite(kuning1,LOW);
  digitalWrite(hijau1,LOW);

  digitalWrite(merah2,LOW);
  digitalWrite(kuning2,LOW);
  digitalWrite(hijau2,HIGH);

  digitalWrite(merah3,HIGH);
  digitalWrite(kuning3,LOW);
  digitalWrite(hijau3,LOW);

  digitalWrite(merah4,HIGH);
  digitalWrite(kuning4,LOW);
  digitalWrite(hijau4,LOW);
  Serial.println(F("Task5"));
  vTaskDelay(8000/portTICK_PERIOD_MS);
  }
}

static void Task6(void* pvParameters)
{while (1)
  {
    //K2 HIDUP, K4 HIDUP
  digitalWrite(merah1,HIGH);
  digitalWrite(kuning1,LOW);
  digitalWrite(hijau1,LOW);

  digitalWrite(merah2,LOW);
  digitalWrite(kuning2,HIGH);
  digitalWrite(hijau2,LOW);

  digitalWrite(merah3,HIGH);
  digitalWrite(kuning3,LOW);
  digitalWrite(hijau3,LOW);

  digitalWrite(merah4,LOW);
  digitalWrite(kuning4,HIGH);
  digitalWrite(hijau4,LOW);
  Serial.println(F("Task6"));
  vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}

static void Task7(void* pvParameters)
{while (1)
  {
  // H4 HIDUP, LAINNYA MERAH  
  digitalWrite(merah1,HIGH);
  digitalWrite(kuning1,LOW);
  digitalWrite(hijau1,LOW);

  digitalWrite(merah2,HIGH);
  digitalWrite(kuning2,LOW);
  digitalWrite(hijau2,LOW);

  digitalWrite(merah3,HIGH);
  digitalWrite(kuning3,LOW);
  digitalWrite(hijau3,LOW);

  digitalWrite(merah4,LOW);
  digitalWrite(kuning4,LOW);
  digitalWrite(hijau4,HIGH);
  Serial.println(F("Task7"));
  vTaskDelay(8000/portTICK_PERIOD_MS);
  }
}

static void Task8(void* pvParameters)
{while (1)
  {
  // K1 HIDUP, K4 HIDUP, LAINNYA MERAH  
  digitalWrite(merah1,LOW);
  digitalWrite(kuning1,HIGH);
  digitalWrite(hijau1,LOW);

  digitalWrite(merah2,HIGH);
  digitalWrite(kuning2,LOW);
  digitalWrite(hijau2,LOW);

  digitalWrite(merah3,HIGH);
  digitalWrite(kuning3,LOW);
  digitalWrite(hijau3,LOW);

  digitalWrite(merah4,LOW);
  digitalWrite(kuning4,HIGH);
  digitalWrite(hijau4,LOW);
  Serial.println(F("Task8"));
  vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}

void loop()
{
}
