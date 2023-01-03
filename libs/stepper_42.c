#include "stepper_42.h"
#include <stdlib.h>

StepMotor42_InitTypeDef* StepMotor42__New(void)
{
    return malloc(sizeof(StepMotor42_InitTypeDef));
}

void StepMotor42_Del(StepMotor42_InitTypeDef* handle)
{
    free(handle);
}

void StepMotor42_Initialize(StepMotor42_InitTypeDef* handle,
                            uint32_t id,
                            A4988_InitTypeDef* driver,
                            AS5600_InitTypeDef* encoder,
                            PID_InitTypeDef* pid)
{
    handle->id = id;
    
    handle->driver = driver;
    handle->encoder = encoder;
    handle->pid = pid;
}

void StepMotor42_Run_toSpeed(StepMotor42_InitTypeDef* handle, 
                            acMode mode, uint16_t rpm,ClockDirection dir)
{
    /* set direction */
    A4988_SetDirection(handle->driver, dir);
    /* set target speed */
    A4988_SetSpeed(handle->driver, rpm);
}

void StepMotor42_Run_toPosition(StepMotor42_InitTypeDef* handle, 
                            uint32_t angle,ClockDirection dir)
{
    /* set direction */
    A4988_SetDirection(handle->driver, dir);
}

/*End*/