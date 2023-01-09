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
    PID_Initialize(pid, 0.6, 0, 0.3);
	
    A4988_Initialize(driver,ID_A4988_1,16,
                    app_a4988_func_gpio_init,
                    app_a4988_func_set_dir,
                    app_a4988_func_pwm_init,
                    app_a4988_func_pwm_set_speed,
                    app_a4988_func_pwm_start,
                    app_a4988_func_pwm_pause);

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



