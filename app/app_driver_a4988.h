#ifndef _APP_A4988_H_
#define _APP_A4988_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "driver_a4988.h"


#define ID_A4988_1 16547965


A4988_Func app_a4988_func_gpio_init(uint32_t id);

A4988_Func app_a4988_func_gpio_init(uint32_t id);

A4988_Func app_a4988_func_set_dir(uint32_t id,ClockDirection dir);

A4988_Func app_a4988_func_pwm_init(uint32_t id);

A4988_Func app_a4988_func_pwm_set_speed(uint32_t id,uint16_t rpm);

A4988_Func app_a4988_func_pwm_start(uint32_t id);

A4988_Func app_a4988_func_pwm_pause(uint32_t id);


#ifdef __cplusplus
}
#endif

#endif
