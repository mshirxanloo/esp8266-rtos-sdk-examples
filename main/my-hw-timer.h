#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_log.h"

#include "driver/gpio.h"
#include "driver/hw_timer.h"


#include "hw.h"
#include "my-gpio.h"



static const char *TAG = "hw_timer_example";

#define TEST_ONE_SHOT false
#define TEST_RELOAD   true





#ifdef __cplusplus
}
#endif



