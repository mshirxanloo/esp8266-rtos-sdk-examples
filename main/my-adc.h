#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "driver/adc.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


static const char *TAG = "adc example";

void initialize_adc() ;

#ifdef __cplusplus
}
#endif

