#include "ctrl_pid.h"
#include <stdlib.h>

PID_InitTypeDef* PID_New(void)
{
    return malloc(sizeof(PID_InitTypeDef));
}

void PID_Del(PID_InitTypeDef* handle)
{
    free(handle);
}

void PID_Init(PID_InitTypeDef* handle,
            float Kp, float Ki, float Kd)
{
    handle->Kd = Kd;
    handle->Ki = Ki;
    handle->Kd = Kd;

    handle->i_max = 10;
    handle->i_min = 0;
    handle->o_max = 100;
    handle->o_min = -100;

    handle->_lastError = 0;
    handle->_curtError = 0;
    handle->_output = 0;
}

float PID_Compute(PID_InitTypeDef*handle,
                float currentValue, float targetValue)
{
    /* Error */
    handle->_curtError = currentValue - targetValue;
    /* Kp */
    handle->_pOut =  handle->Kp * handle->_curtError;
    /* Ki */
    handle->_iOut += handle->Ki * handle->_curtError;
    if(handle->_iOut > handle->i_max) handle->_iOut = handle->i_max;
    if(handle->_iOut < handle->i_min) handle->_iOut = handle->i_min;
    /* Kd */
    handle->_dOut =  handle->Kd * (handle->_curtError - handle->_lastError);

    /* Output */
    handle->_output =   handle->_pOut + 
                        handle->_iOut + 
                        handle->_dOut;
    
    if(handle->_output > handle->o_max) handle->_output = handle->o_max;
    if(handle->_output < handle->o_min) handle->_output = handle->o_min;

    handle->_lastError = handle->_curtError;

    return handle->_output;
}
