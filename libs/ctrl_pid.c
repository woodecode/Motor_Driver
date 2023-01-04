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

    handle->_use_integr_limit = 0;
    handle->_use_output_limit = 0;

    handle->_lastError = 0;
    handle->_curtError = 0;
    handle->_output = 0;
}

void PID_SetLimits(PID_InitTypeDef* handle,
                int use_o_limit, float o_min, float o_max,
                int use_i_limit, float i_min, float i_max)
{
    if (use_i_limit > 0) {
        handle->_use_integr_limit = 1;
        handle->i_max = i_max;
        handle->i_min = i_min;
    }

    if (use_o_limit > 0) {
        handle->_use_output_limit = 1;
        handle->o_max = o_max;
        handle->o_min = o_min;
    }
    
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
    if(handle->_use_integr_limit > 0){
        if(handle->_iOut > handle->i_max) handle->_iOut = handle->i_max;
        if(handle->_iOut < handle->i_min) handle->_iOut = handle->i_min;
    }
    /* Kd */
    handle->_dOut =  handle->Kd * (handle->_curtError - handle->_lastError);

    /* Output */
    handle->_output =   handle->_pOut + 
                        handle->_iOut + 
                        handle->_dOut;

    if (handle->_use_output_limit > 0) {
        if(handle->_output > handle->o_max) handle->_output = handle->o_max;
        if(handle->_output < handle->o_min) handle->_output = handle->o_min;
    }
    
    
    handle->_lastError = handle->_curtError;

    return handle->_output;
}
