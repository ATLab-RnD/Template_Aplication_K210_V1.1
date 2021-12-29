#include <Arduino.h>
#include <bsp.h>
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
    // vTaskDelay( 1000 / portTICK_PERIOD_MS);
  }
}

#include "../src/apps/App_atEXHMI.h"
TaskHandle_t Task_atEXHMI;
void atEXHMI_Application(void *parameter)
{
  while(1)
  {
    atEXHMI.Run_Application();
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
  }
}

int core1_function(void *ctx);
void setup() {
  register_core1(core1_function,NULL);

  // put your setup code here, to run once:
  // atABC.Debug();
  atEXHMI.Debug();
  
  xTaskCreate(
    atABC_Application,  //task function
    "atABC_Application",  // name task
    10000,  //stack size of task
    NULL, 
    1,
    &Task_atABC
  );
}
int core1_function(void *ctx)
{
  xTaskCreate(
    atEXHMI_Application,  //task function
    "atEXHMI_Application",  // name task
    10000,  //stack size of task
    NULL, 
    3,
    &Task_atEXHMI
  );
  vTaskStartScheduler();
  while(1);
}
void loop() {
  // put your main code here, to run repeatedly:
}  