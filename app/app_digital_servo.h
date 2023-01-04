#ifndef _APP_SERVO_H_
#define _APP_SERVO_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "digital_servo.h"

#define ID_Servo_1 (uint32_t)23131537

Servo_Func app_servo_func_pwm_init(uint32_t id);
Servo_Func app_servo_func_pwm_set_dutycycle(uint32_t id, uint16_t duty);
Servo_Func app_servo_func_pwm_start(uint32_t id);
Servo_Func app_servo_func_pwm_pause(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif

/*End*/