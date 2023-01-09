#include "driver_a4988.h"
#include "app_driver_a4988.h"
#include "main.h"
#include "tim.h"


static uint16_t M_A4988_PWM_CONFIG[2] = {0, 0};


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

A4988_Func app_a4988_func_pwm_init(uint32_t id)
{
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            MX_TIM4_Init();
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
            if(dir == CW){
                HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_SET);
            }
            else if(dir == CCW){
                HAL_GPIO_WritePin(GPIOC,GPIO_PIN_9,GPIO_PIN_RESET);
            }
            break;
        default:
            break;
    }
}



A4988_Func app_a4988_func_pwm_set_speed(uint32_t id,uint16_t rpm)
{
    /**
     * STM32中如何计算rpm (转/分钟)
     * PWM的占空比保持50%
     * PWM由TIM产生,与下面几个参数有关
     * 1.TIM的时钟频率- 72
     * 2.PWM的分频系数- 8
     * 3.PWM的计数周期- cp
     * 4.步进电机一周的步数- 360° / 1.8°(步距角) = 200
     * 5.步进电机驱动器的细分系数- 16
     * 则，旋转一周需要200*16=3200个脉冲。
     * PWM计数的频率 = TIM时钟频率 / PWM分频系数 = 72 / 8 = 9Mhz
     * 如果PWM的计数周期 为 cp
     * 则产生PWM波的频率为 9Mhz / cp
     * 则1s内步进电机将旋转 (9Mhz / cp / 3200) 圈。设为 rps 
     * rpm = rps * 60
     * 
     * 如果 cp 设为 9, 则
     * rpm = 9,000,000 / 9 / 3,200 * 60 = 18750 
     * 这个数字就非常大了
     * 所以在计算公式中
     * rpm = TIM的时钟频率/ PWM的分频系数 / PWM的计数周期 / 电机旋转一周脉冲数 * 60
     * 可以改变的一般只有 PWM的分频系数 和 PWM的计数周期 
     * 也可以通过只改变 PWM的计数周期 来实现
     */
    switch (id)
    {
        case ID_A4988_1:
            /* code */
            /* compute rpm */
            
            // static uint32_t tim4_clock_freq = HAL_RCC_GetPCLK1Freq();
            // tim4_clock_freq 一般都为 72,000,000
            // rpm = 72,000,000 / 18 / () / 3200 * 60
            // () = 72,000,000 / 18 / rpm / 3200 * 60
            
            /* use dma */
            M_A4988_PWM_CONFIG[0] = 20;
            M_A4988_PWM_CONFIG[1] = (M_A4988_PWM_CONFIG[0] >> 1);
            HAL_TIM_DMABurst_WriteStart(&htim4, TIM_DMABase_CCR1, TIM_DMA_UPDATE, 
                                        (uint32_t*)M_A4988_PWM_CONFIG, 2);
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
            HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_1,(uint32_t*)M_A4988_PWM_CONFIG,2);
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
            HAL_TIM_PWM_Stop_DMA(&htim4, TIM_CHANNEL_1);
            break;
        default:
            break;
    }
}
/* End */