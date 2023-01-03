/* Main Include */
#include "include.h"
/* Drivers */
#include "main.h"
/* Library */
#include "libs/support/uart/serial.h"
#include "driver_a4988.h"
#include "ctrl_pid.h"
/* App */
#include "app_driver_a4988.h"

void Main(void)
{
	A4988_InitTypeDef* driver= A4988_New();
	PID_InitTypeDef*  pid= PID_New();
	
	A4988_Del(driver);
	PID_Del(pid);
	
	for(;;){
		print("ok,stm32");
		HAL_Delay(100);
	}
}

/* 
 stm32XXxx_it.c		extern void TimxCallback1kHz();
 TIMx_IRQHandler()	TimxCallback1kHz();return;
 main.cpp				HAL_TIM_Base_Start_IT(&htimx);	
*/
extern "C" void Tim1Callback1kHz(){
	
	static unsigned int freq_100Hz = 0;

	// __HAL_TIM_CLEAR_IT(&htim1, TIM_IT_UPDATE);

	if(freq_100Hz++ >= 10){
		// do something ...
	}
}



