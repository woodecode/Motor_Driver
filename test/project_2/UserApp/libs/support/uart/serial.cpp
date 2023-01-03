#include "./serial.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "usart.h"

int print(const char *fmt,...){
    int size = 0;
    static char buf[SerialBufferSize];
    char *p = buf;

    va_list arg_list;
    va_start(arg_list,fmt);
    vsprintf(buf,fmt,arg_list);
    while (*p++) size++;/*计算字符串大小*/

    int ret = HAL_UART_Transmit(&SerialUartHandle,
								(uint8_t*)buf,size,10);

    va_end(arg_list);
	
	memset(buf, 0, sizeof(buf));
	
    return ret;
}







