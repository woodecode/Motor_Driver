#include "digital_servo.h"
#include <stdlib.h>

Servo_InitTypeDef* Servo_New(void)
{
    return malloc(sizeof(Servo_InitTypeDef));
}

void Servo_Del(Servo_InitTypeDef* handle)
{
    free(handle);
}

void Servo_Init(Servo_InitTypeDef* handle,uint32_t id,
                Servo_Func (* _func_pwm_init)(uint32_t id),
                Servo_Func (* _func_pwm_set_dutycycle)(uint32_t id, uint16_t duty),
                Servo_Func (* _func_pwm_start)(uint32_t id),
                Servo_Func (* _func_pwm_pause)(uint32_t id))
{
    handle->id = id;

    handle->_FUNC_PWM_Init = _func_pwm_init;
    handle->_FUNC_PWM_Set_DutyCycle = _func_pwm_set_dutycycle;
    handle->_FUNC_PWM_Start = _func_pwm_start;
    handle->_FUNC_PWM_Pause = _func_pwm_pause;
}

void Servo_SetAngle(Servo_InitTypeDef* handle, uint16_t angle)
{
    
}

void Servo_Start(Servo_InitTypeDef* handle)
{
    handle->_FUNC_PWM_Start(handle->id);
}

void Servo_Pause(Servo_InitTypeDef* handle)
{
    handle->_FUNC_PWM_Pause(handle->id);
}

/*End*/