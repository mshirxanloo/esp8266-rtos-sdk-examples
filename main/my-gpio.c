#include "my-gpio.h"



/*static void gpio_isr_handler(void *arg)
{
    uint32_t gpio_num = (uint32_t) arg;
    xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
}*/

static TickType_t next = 0;
static bool led_state = false;
static void IO_0_isr_handler(void *arg)
{
    TickType_t now = xTaskGetTickCountFromISR();
    if (now > next)
    {
        led_state = !led_state;
        gpio_set_level( GPIO_OUTPUT_IO_0, led_state);
        next = now + 500 / portTICK_PERIOD_MS;
    }
}



void initialize_gpio(void) {
    gpio_config_t io_conf;

    //-------------------------------------------------------led
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO15/16
    io_conf.pin_bit_mask = GPIO_LED_OUTPUT_PIN_SEL; 
    //disable pull-down mode
    io_conf.pull_down_en = 0;
    //disable pull-up mode
    io_conf.pull_up_en = 0;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
    //---------------------------------------------------------button
    //interrupt of rising edge
    io_conf.intr_type = GPIO_INTR_NEGEDGE;
    //set as input mode
    io_conf.mode = GPIO_MODE_INPUT;
    //bit mask of the pins, use GPIO4/5 here
    io_conf.pin_bit_mask = GPIO_BTN_INPUT_PIN_SEL;
    //enable pull-up mode
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);
    //----------------------------------------------------------------------------
    //change gpio intrrupt type for one pin
    //gpio_set_intr_type(GPIO_INPUT_IO_0, GPIO_INTR_NEGEDGE);

    //create a queue to handle gpio event from isr
    //gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
    //start gpio task
    
    //install gpio isr service
    gpio_install_isr_service(0);

    
    //gpio_isr_handler_add(GPIO_BUTTON, button_handler, NULL);
    //hook isr handler for specific gpio pin
    //gpio_isr_handler_add(GPIO_INPUT_IO_0, gpio_isr_handler, (void *) GPIO_INPUT_IO_0);
    gpio_isr_handler_add(GPIO_INPUT_IO_0, IO_0_isr_handler, NULL);
    
    //remove isr handler for gpio number.
    //gpio_isr_handler_remove(GPIO_INPUT_IO_0);
    //hook isr handler for specific gpio pin again
    //gpio_isr_handler_add(GPIO_INPUT_IO_0, gpio_isr_handler, (void *) GPIO_INPUT_IO_0); 
}



