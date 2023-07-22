#ifndef __SPEED_H
#define __SPEED_H


#include "stm32f10x.h"

/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM5

#define            SPEED_TIM                   TIM3
#define            SPEED_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            SPEED_TIM_CLK               RCC_APB1Periph_TIM3
#define            SPEED_TIM_PERIOD            0XFFFF
#define            SPEED_TIM_PSC              (72-1)

// TIM ���벶��ͨ��GPIO��غ궨��
// ���벶���ܲ��񵽵���С��Ƶ��Ϊ 72M/{ (ARR+1)*(PSC+1) }
#define            SPEED_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            SPEED_TIM_CH1_PORT          GPIOA
#define            SPEED_TIM_CH1_PIN           GPIO_Pin_6
#define            SPEED_TIM_CHANNEL_x         TIM_Channel_1

// �ж���غ궨��
#define            SPEED_TIM_IT_CCx            TIM_IT_CC1
#define            SPEED_TIM_IRQ               TIM3_IRQn//��ʱ�������ж϶�������������ж��ٸ���ʵ����������������ж�
#define            SPEED_TIM_INT_FUN           TIM3_IRQHandler

// ��ȡ����Ĵ���ֵ�����궨��
#define            SPEED_TIM_GetCapturex_FUN                 TIM_GetCapture1
// �����źż��Ժ����궨��
#define            SPEED_TIM_OCxPolarityConfig_FUN           TIM_OC1PolarityConfig

// ��������ʼ����
#define            SPEED_TIM_STRAT_ICPolarity                TIM_ICPolarity_Rising
// �����Ľ�������
#define            SPEED_TIM_END_ICPolarity                  TIM_ICPolarity_Falling


// ��ʱ�����벶���û��Զ�������ṹ������
typedef struct
{   
	uint8_t   Capture_FinishFlag;   // ���������־λ
	uint8_t   Capture_StartFlag;    // ����ʼ��־λ  
	uint16_t  Capture_CcrValue;     // ����Ĵ�����ֵ
	uint16_t  Capture_Period;       // �Զ���װ�ؼĴ������±�־ 
}TIM_ICUserValueTypeDef;




extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;
extern float speed;
extern uint32_t TIM_PscCLK ;
/**************************��������********************************/
void SPEED_TIM_Init(void);



#endif	/* __SPEED_H */


