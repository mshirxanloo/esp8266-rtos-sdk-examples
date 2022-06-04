#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "hw.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG_GPIO = "main";

#define GPIO_OUTPUT_IO_0    2  

#define GPIO_INPUT_IO_0     5   

#define GPIO_LED_OUTPUT_PIN_SEL  (1ULL<<GPIO_OUTPUT_IO_0) 
#define GPIO_BTN_INPUT_PIN_SEL     (1ULL<<GPIO_INPUT_IO_0)


static xQueueHandle gpio_evt_queue = NULL;
void initialize_gpio(void);

#ifdef __cplusplus
}
#endif



