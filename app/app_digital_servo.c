#include "app_digital_servo.h"

#include "main.h"
#include "tim.h"

Servo_Func app_servo_func_pwm_init(uint32_t id)
{
    switch (id)
    {
    case ID_Servo_1:
        /* code */
        MX_TIM3_Init();
        break;
    
    default:
        break;
    }
}

Servo_Func app_servo_func_pwm_set_dutycycle(uint32_t id, uint16_t duty)
{
    switch (id)
    {
    case ID_Servo_1:
        /* code */
        // __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, duty);
        if ((uint32_t)duty <= (&htim3)->Instance->ARR) {
            (&htim3)->Instance->CCR1 = (uint32_t)duty;
        }else {
            Error_Handler();
        }
        break;
    default:
        break;
    }
}

Servo_Func app_servo_func_pwm_start(uint32_t id)
{
    switch (id)
    {
    case ID_Servo_1:
        /* code */
        HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);
        break;
    default:
        break;
    }
}

Servo_Func app_servo_func_pwm_pause(uint32_t id)
{
    switch (id)
    {
    case ID_Servo_1:
        /* code */
        HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);
        break;
    default:
        break;
    }
}

/*End*/