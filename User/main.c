#include "stm32f10x.h"  
#include "pwm.h" 
#include "speed.h"
#include "bsp_usart.h"
#include "pid_usart.h"
#include "oled.h"
#include "TimExit.h"
#include "filt.h"
#include "pid.h"
#include "key.h"

float  value_buf[N];
uint8_t   string[10];
float speed;
//uint32_t TIM_PscCLK = 72000000 / (SPEED_TIM_PSC+1);

int main(void)
{	
	OLEDInit();
	OLEDClear();
	USART_Config();
	Key_GPIO_Config();

	PWM_TIM_Init();

	tongbustar(1);
	SPEED_TIM_Init();
	TIM_EXIT_Init();
	printf ("hello");
	SetPoint=450;
	 while(1)
  {
	//key();
  }
}


