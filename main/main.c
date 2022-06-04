/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "hw.h"
#include "my-adc.h"
#include "my-gpio.h"


static void adc_task() {
    int x;
    uint16_t adc_data[100];
    while(1) {
        if(ESP_OK == adc_read(&adc_data[0])) {
            ESP_LOGI(TAG, "adc read: %d\r\n", adc_data[0]);
        }
        ESP_LOGI(TAG, "adc read fast:\r\n");
        if(ESP_OK == adc_read_fast(adc_data, 100)) {
            for(x=0; x<100; x++) {
                printf("%d\n", adc_data[x]);
            }
        }
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}
static void gpio_task() {
    vTaskSuspend(NULL);
}

void app_main()
{
    initialize_adc();
    initialize_gpio();
    //...................................................................
   

    xTaskCreate(adc_task, "adc_task", 1024, NULL, 5, NULL);
    xTaskCreate(gpio_task, "gpio_task", 2048, NULL, 10, NULL);
}

