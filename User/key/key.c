#include "key.h"
int qwer=0;
static void key_delay(uint16_t x)
{
	uint8_t Q;


	for (Q = 0; Q < x; Q++);
}

void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*���������˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK|KEY3_GPIO_CLK|KEY4_GPIO_CLK,ENABLE);
	
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 
	// ���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 
	//���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
		
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY3_GPIO_PIN; 
	// ���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStructure);
		
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY4_GPIO_PIN; 
	// ���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY4_GPIO_PORT, &GPIO_InitStructure);
	
}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��KEY_OFF(û���°���)��KEY_ON�����°�����
 */


void Key1(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 key_delay(200);
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )
			{	qwer+=40; 
			/*�ȴ������ͷ� */
				while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON); 
			}
	}

}


void Key2(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 key_delay(200);
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )
		{
			qwer-=40;
		/*�ȴ������ͷ� */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
	    }

	}

}


void key(void)
{
    Key2(KEY2_GPIO_PORT,KEY2_GPIO_PIN);
	Key1(KEY1_GPIO_PORT,KEY1_GPIO_PIN);
}

