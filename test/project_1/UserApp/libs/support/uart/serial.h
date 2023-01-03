/**********************************************
 * 如何使用？
 *  ↓ ↓ ↓ ↓ ↓ ↓
 * 	更改宏`SerialUartHandle`指定串口后
 * 	直接使用print()打印串口
 **********************************************/
#if 1

#ifndef _SERIAL_H
#define _SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "main.h"


#define SerialUartHandle huart1
#define SerialBufferSize 128 /*byte*/

int print(const char *,...);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_SERIAL_H

#endif