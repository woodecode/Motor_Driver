#ifndef _DIGITAL_SERVO_H_
#define _DIGITAL_SERVO_H_

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

typedef void Servo_Func;

typedef struct  {
    /* data */
    uint32_t id;
    Servo_Func (* _FUNC_PWM_Init)(uint32_t id);
    Servo_Func (* _FUNC_PWM_Set_DutyCycle)(uint32_t id, uint16_t duty);
    Servo_Func (* _FUNC_PWM_Start)(uint32_t id);
    Servo_Func (* _FUNC_PWM_Pause)(uint32_t id);
} Servo_InitTypeDef;

Servo_InitTypeDef* Servo_New(void);

void Servo_Del(Servo_InitTypeDef* handle);

void Servo_Init(Servo_InitTypeDef* handle,uint32_t id,
                Servo_Func (* _func_pwm_init)(uint32_t id),
                Servo_Func (* _func_pwm_set_dutycycle)(uint32_t id, uint16_t duty),
                Servo_Func (* _func_pwm_start)(uint32_t id),
                Servo_Func (* _func_pwm_pause)(uint32_t id));

void Servo_SetAngle(Servo_InitTypeDef* handle, uint16_t angle);
void Servo_Start(Servo_InitTypeDef* handle);
void Servo_Pause(Servo_InitTypeDef* handle);

#ifdef __cplusplus
}
#endif

#endif
