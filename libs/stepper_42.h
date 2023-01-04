#ifndef _STEP_MOTOR_42_H_ 
#define _STEP_MOTOR_42_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "driver_a4988.h"
#include "ctrl_pid.h"
#include "encoder_as5600.h"

typedef enum {
    ac_linear,
    ac_cubic
} acMode;

typedef struct {

    uint32_t id;
    uint16_t rpm;
    uint32_t pos;

    A4988_InitTypeDef* driver;
    AS5600_InitTypeDef* encoder;
    PID_InitTypeDef* pid;

} StepMotor42_InitTypeDef;

StepMotor42_InitTypeDef* StepMotor42__New(void);

void StepMotor42_Del(StepMotor42_InitTypeDef* handle);

void StepMotor42_Initialize(StepMotor42_InitTypeDef* handle,
                            uint32_t id,
                            A4988_InitTypeDef* driver,
                            AS5600_InitTypeDef* encoder,
                            PID_InitTypeDef* pid);

/*
    常见的步进电机启动加速方式有以下几种：

    1.线性加速：步进电机从起始位置开始线性地加速，然后保持目标速度。
    2.加速-匀速-减速：步进电机从起始位置开始加速，达到目标速度后保持匀速，然后在到达终止位置时减速。
    3.三次函数加速：步进电机从起始位置开始使用三次函数加速，然后保持目标速度。
    4.自然加速：步进电机从起始位置开始使用自然加速，然后保持目标速度。
    5.其他加速方式：还有其他许多加速方式，如使用五次函数加速、使用 S 形加速等。
*/

void StepMotor42_Run_toSpeed(StepMotor42_InitTypeDef* handle, 
                            acMode mode, uint16_t rpm,ClockDirection dir);

void StepMotor42_Run_toHome(StepMotor42_InitTypeDef* handle);

void StepMotor42_Run_toPosition(StepMotor42_InitTypeDef* handle, 
                            uint32_t angle,ClockDirection dir);

void StepMotor42_Run_incAngle(StepMotor42_InitTypeDef* handle, 
                            uint32_t angle,ClockDirection dir);

#ifdef __cplusplus
}
#endif

#endif
/* End */