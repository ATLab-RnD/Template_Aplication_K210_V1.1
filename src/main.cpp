#include <Arduino.h>
// frertos 
#include <FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
//Applications
#include "../src/apps/App_atABC.h"
TaskHandle_t Task_atABC;
void atABC_Application(void *parameter)
{
  while(1)
  {
    atABC.Run_Application();
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  // put your setup code here, to run once:
  atABC.Debug();

  
  xTaskCreateAtProcessor(
    0, // core 1
    atABC_Application,  //task function
    "atABC_Application",  // name task
    10000,  //stack size of task
    NULL, 
    3,
    &Task_atABC
  );

  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:
}  