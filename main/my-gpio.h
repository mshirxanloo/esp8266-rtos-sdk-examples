#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "hw.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GPIO_OUTPUT_IO_0    15
#define GPIO_OUTPUT_IO_1    2
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_0) | (1ULL<<GPIO_OUTPUT_IO_1))
#define GPIO_INPUT_IO_0     4
#define GPIO_INPUT_IO_1     5
#define GPIO_INPUT_PIN_SEL  ((1ULL<<GPIO_INPUT_IO_0) | (1ULL<<GPIO_INPUT_IO_1))

#define GPIO_LED 2
#define GPIO_LED_PIN_SEL (1ULL << GPIO_LED)
#define GPIO_BUTTON 5
#define GPIO_BUTTON_PIN_SEL (1ULL << GPIO_BUTTON)
#define ESP_INTR_FLAG_DEFAULT 0


static xQueueHandle gpio_evt_queue = NULL;
void initialize_gpio(void);

#ifdef __cplusplus
}
#endif



