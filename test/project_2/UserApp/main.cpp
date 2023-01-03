/* Main Include */
#include "include.h"
/* Drivers */
#include "main.h"
/* Library */
#include "libs/support/uart/serial.h"
#include "digital_servo.h"
/* App */
#include "app_digital_servo.h"

void Main(void)
{
	Servo_InitTypeDef* servo = Servo_New();
	
	Servo_Init(servo,ID_Servo_1,
            app_servo_func_pwm_init,
            app_servo_func_pwm_set_dutycycle,
            app_servo_func_pwm_start,
            app_servo_func_pwm_pause);
	
	Servo_Del(servo);
	
	for(;;){
		print("ok, stm32");
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



