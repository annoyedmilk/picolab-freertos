/*********************************************************************
 * Program: FreeRTOS_Blink
 * Author: annoyedmilk
 * Description: Demonstrating FreeRTOS with Raspberry Pi Pico using Arduino IDE.
 *              This example covers a basic LED blink using FreeRTOS.
 *              Visit https://github.com/annoyedmilk/FreeRTOS-PicoLab
 *              for more information and updates.
 *********************************************************************/

#include <FreeRTOS.h>
#include <task.h>

// Define a task for Blink
void TaskBlink( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {
  // Set up the Blink task.
  xTaskCreate(
    TaskBlink
    ,  "Blink"   // Task name for humans
    ,  128       // Stack size
    ,  NULL
    ,  2         // Priority
    ,  NULL );
  // The task scheduler takes over control of scheduling individual tasks.
}

void loop() {
  // Empty. The operation is handled in Tasks.
}

void TaskBlink(void *pvParameters) { // This is a task for blinking an LED.
  (void) pvParameters;

  pinMode(LED_BUILTIN, OUTPUT); // Initialize LED_BUILTIN as an output.

  for (;;) { // A Task should never return or exit.
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED on
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // Wait for one second
    digitalWrite(LED_BUILTIN, LOW); // Turn the LED off
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // Wait for one second
  }
}