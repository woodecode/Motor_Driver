#include "driver_a4988.h"
#include <stdlib.h>

A4988_InitTypeDef* A4988_New(void)
{
    return malloc(sizeof(A4988_InitTypeDef));
}

void A4988_Del(A4988_InitTypeDef* handle)
{
    free(handle);
}

void A4988_Initialize(A4988_InitTypeDef *handle,
                    uint32_t id, uint8_t microStep,
                    A4988_Func (* func_gpio_init)(uint32_t),
                    A4988_Func (* func_set_dir)(uint32_t,ClockDirection),
                    A4988_Func (* func_pwm_init)(uint32_t),
                    A4988_Func (* func_pwm_set_speed)(uint32_t,uint16_t),
                    A4988_Func (* func_pwm_start)(uint32_t),
	                A4988_Func (* func_pwm_pause)(uint32_t))
{
    handle->id = id;
    handle->microStep = microStep;

    handle->_FUNC_GPIO_INIT     = func_gpio_init;
    handle->_FUNC_SET_DIRECTION = func_set_dir;
    handle->_FUNC_PWM_INIT      = func_pwm_init;
    handle->_FUNC_PWM_START     = func_pwm_start;
    handle->_FUNC_PWM_PAUSE     = func_pwm_pause;
    handle->_FUNC_PWM_SET_SPEED = func_pwm_set_speed;

    handle->_FUNC_GPIO_INIT(handle->id);
    handle->_FUNC_PWM_INIT(handle->id);
}

void A4988_SetSpeed(A4988_InitTypeDef *handle, uint16_t rpm)
{
    handle->_FUNC_PWM_SET_SPEED(handle->id, rpm);
}

void A4988_SetDirection(A4988_InitTypeDef *handle, ClockDirection dir)
{
    handle->_FUNC_SET_DIRECTION(handle->id, dir);
}

/* End */