#ifndef _CTRL_PID_H_
#define _CTRL_PID_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus
#include <stdint.h>

typedef struct {
    /* pid parameter */
	float Kp, Ki, Kd;

    float i_max, i_min;
    float o_max, o_min;

	float _pOut,_iOut,_dOut;
    int _curtError, _lastError;
	/* output  */
    int _output;
} PID_InitTypeDef;

PID_InitTypeDef* PID_New(void);
void PID_Del(PID_InitTypeDef* handle);

void PID_Initialize(
    PID_InitTypeDef* handle,
    float Kp, float Ki, float Kd);

float PID_Compute(
    PID_InitTypeDef*handle,
    float currentValue, float targetValue);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_PID_H_
