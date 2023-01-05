#include "driver_a4988.h"
#include "app_driver_a4988.h"

A4988_Func app_a4988_func_gpio_init(uint32_t id)
{
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            break;
        default:
            break;
    }
}

A4988_Func app_a4988_func_set_dir(uint32_t id,ClockDirection dir)
{
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            if(id == CW){
                
            }
            else if(id == CCW){

            }
            break;
        default:
            break;
    }
}

A4988_Func app_a4988_func_pwm_init(uint32_t id)
{
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            break;
        default:
            break;
    }
}

A4988_Func app_a4988_func_pwm_set_speed(uint32_t id,uint16_t rpm)
{
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            break;
        default:
            break;
    }
}

A4988_Func app_a4988_func_pwm_start(uint32_t id)
{
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            break;
        default:
            break;
    }
}

A4988_Func app_a4988_func_pwm_pause(uint32_t id)
{
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            break;
        default:
            break;
    }
}
/* End */