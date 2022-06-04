
#include "my-hw-timer.h"


void hw_timer_callback1(void *arg)
{
    static int state = 0;

    //gpio_set_level(GPIO_OUTPUT_IO_0, (state ++) % 2);
}

void hw_timer_callback2(void *arg)
{
    static int state = 0;

    //gpio_set_level(GPIO_OUTPUT_IO_1, (state ++) % 2);
}

void hw_timer_callback3(void *arg)
{
    //gpio_set_level(GPIO_OUTPUT_IO_0, 0);
    //gpio_set_level(GPIO_OUTPUT_IO_1, 1);
}

