#include <Arduino.h>

#define LED 2

int counter1 = 0;
int counter2 = 0;
int led_state = 1;

void task1(void * parameters){
    for(;;){
        Serial.print("Task 1 counter: ");
        Serial.println(counter1++);
        // digitalWrite(LED, led_state);
        // led_state = !led_state;
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void task2(void * parameters){
    for(;;){
        Serial.print("Task 2 counter: ");
        Serial.println(counter2++);
        digitalWrite(LED, led_state);
        led_state = !led_state;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    xTaskCreate(
        task1,      //function name
        "Task 1",   //task name
        1000,       //stack size 
        NULL,       //task parameters
        1,          //task priority
        NULL        //task handle
    );
    xTaskCreate(
        task2,      //function name
        "Task 2",   //task name
        1000,       //stack size 
        NULL,       //task parameters
        1,          //task priority
        NULL        //task handle
    );
}

void loop() {

}
