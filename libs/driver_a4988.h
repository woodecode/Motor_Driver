#ifndef _A4988_H_
#define _A4988_H_

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

/*
    每个A4988驱动模块实例创建时都应该分配一个唯一的`id`用来标记它的身份,
这样在实现多个`_FUNC_GPIO_INIT()`等函数功能时就可以使用id来区分并将
要实现的功能都写在一个函数中。

    例如，我要实现三个A4988驱动模块，我当然可以分别实现他们的_FUNC_GPIO_INIT()
等函数，我也可以这样写。（其他实现都可类比）当然，如果仅实现一个模块的实例，
可以不管参数id，直接写内部程序就好。

void _FUNC_GPIO_INIT(uint32_t id)
{
    switch (id) {
        case 46561234:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            GPIO_InitTypeDef gpio_config;
            gpio_config.Pin = GPIO_PIN_13;
            gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
            gpio_config.Pull = GPIO_NOPULL;
            gpio_config.Speed = GPIO_SPEED_FREQ_LOW;
            HAL_GPIO_Init(GPIOA, &gpio_config);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, GPIO_PIN_SET);
            break;
        case 87616646:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            GPIO_InitTypeDef gpio_config;
            gpio_config.Pin = GPIO_PIN_2;
            gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
            gpio_config.Pull = GPIO_NOPULL;
            gpio_config.Speed = GPIO_SPEED_FREQ_LOW;
            HAL_GPIO_Init(GPIOB, &gpio_config);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
            break;
        case 86132146:
            __HAL_RCC_GPIOD_CLK_ENABLE();
            GPIO_InitTypeDef gpio_config;
            gpio_config.Pin = GPIO_PIN_7;
            gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
            gpio_config.Pull = GPIO_NOPULL;
            gpio_config.Speed = GPIO_SPEED_FREQ_LOW;
            HAL_GPIO_Init(GPIOD, &gpio_config);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
            break;
        default:
            break;
    }
}
*/

typedef void A4988_Func;

typedef enum{
    CW = 1,
    CCW = -1
}  ClockDirection ;

typedef struct {
    /* 参数 */
    uint32_t id; 
    uint8_t direction;
    uint8_t microStep;
	/*  */
    A4988_Func (* _FUNC_GPIO_INIT)(uint32_t id);/* for setting clock direction */
    A4988_Func (* _FUNC_SET_DIRECTION)(uint32_t id,ClockDirection dir);
	/*  */
    A4988_Func (* _FUNC_PWM_INIT)(uint32_t id);/*  */
	A4988_Func (* _FUNC_PWM_SET_SPEED)(uint32_t id,uint16_t rpm);
	A4988_Func (* _FUNC_PWM_START)(uint32_t id);
	A4988_Func (* _FUNC_PWM_PAUSE)(uint32_t id);

} A4988_InitTypeDef;

A4988_InitTypeDef* A4988_New(void);
void A4988_Del(A4988_InitTypeDef* handle);

void A4988_Initialize(A4988_InitTypeDef *handle, uint32_t id, uint8_t microStep,
                    A4988_Func (* func_gpio_init)(uint32_t),
                    A4988_Func (* func_set_dir)(uint32_t,ClockDirection),
                    A4988_Func (* func_pwm_init)(uint32_t),
                    A4988_Func (* func_pwm_set_speed)(uint32_t,uint16_t),
                    A4988_Func (* func_pwm_start)(uint32_t),
	                A4988_Func (* func_pwm_pause)(uint32_t));

void A4988_SetSpeed(A4988_InitTypeDef *handle, uint16_t rpm);

void A4988_SetDirection(A4988_InitTypeDef *handle, ClockDirection dir);

void A4988_Start(A4988_InitTypeDef *handle);

void A4988_RunStep(A4988_InitTypeDef *handle);
void A4988_RunRotate(A4988_InitTypeDef *handle);
void A4988_Enable(A4988_InitTypeDef *handle);
void A4988_Disable(A4988_InitTypeDef *handle);

#ifdef __cplusplus
}
#endif

#endif
