#ifndef __PWM_H
#define __PWM_H


#include "stm32f10x.h"


/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3

#define            PWM_TIM                   TIM4
#define            PWM_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            PWM_TIM_CLK               RCC_APB1Periph_TIM4
#define            PWM_TIM_Period            7199//7199
#define            PWM_TIM_Prescaler         0
// TIM3 输出比较通道1
#define            PWM_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            PWM_TIM_CH1_PORT          GPIOB
#define            PWM_TIM_CH1_PIN           GPIO_Pin_6

//// TIM3 输出比较通道2
//#define            GENERAL_TIM_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
//#define            GENERAL_TIM_CH2_PORT          GPIOA
//#define            GENERAL_TIM_CH2_PIN           GPIO_Pin_7

//// TIM3 输出比较通道3
//#define            GENERAL_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
//#define            GENERAL_TIM_CH3_PORT          GPIOB
//#define            GENERAL_TIM_CH3_PIN           GPIO_Pin_0

//// TIM3 输出比较通道4
//#define            GENERAL_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
//#define            GENERAL_TIM_CH4_PORT          GPIOB
//#define            GENERAL_TIM_CH4_PIN           GPIO_Pin_1

/**************************函数声明********************************/
#define	 CCR1_Val     TIM4->CCR1
//extern	uint16_t CCR2_Val ;
//extern	uint16_t CCR3_Val ;
//extern	uint16_t CCR4_Val ;

void PWM_TIM_Init(void);

#endif	/* __PWM_H */


