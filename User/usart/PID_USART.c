#include "pid_usart.h"

void send_PID2USART(uint16_t CHx,uint32_t P,uint32_t I,uint32_t D){
	
	Usart_SendByte( USART1, 0x53);
	Usart_SendByte( USART1, 0x5A);
	Usart_SendByte( USART1, 0x48);
	Usart_SendByte( USART1, 0x59);//包头
	
	Usart_SendByte( USART1, CHx);//通道
	
	Usart_SendByte( USART1, 0x17);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);//包长度
	
	Usart_SendByte( USART1, 0x03);//指令
	
	Usart_SendByte( USART1, P);
	Usart_SendByte( USART1, P>>8);
	Usart_SendByte( USART1, P>>16);
	Usart_SendByte( USART1, P>>24);
	
	Usart_SendByte( USART1, I);
	Usart_SendByte( USART1, I>>8);
	Usart_SendByte( USART1, I>>16);
	Usart_SendByte( USART1, I>>24);
	
	Usart_SendByte( USART1, D);
	Usart_SendByte( USART1, D>>8);
	Usart_SendByte( USART1, D>>16);
	Usart_SendByte( USART1, D>>24);
	
	Usart_SendByte( USART1, 0x00);
}

void tongbustar(uint16_t CHx){
	Usart_SendByte( USART1, 0x53);
	Usart_SendByte( USART1, 0x5A);
	Usart_SendByte( USART1, 0x48);
	Usart_SendByte( USART1, 0x59);//包头
	
	Usart_SendByte( USART1, CHx);//通道

	Usart_SendByte( USART1, 0x0F);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);//包长度
	
	Usart_SendByte( USART1, 0x04);//指令
	
	Usart_SendByte( USART1, 0x00);//校验
}

void tongbuclose(uint16_t CHx){
	Usart_SendByte( USART1, 0x53);
	Usart_SendByte( USART1, 0x5A);
	Usart_SendByte( USART1, 0x48);
	Usart_SendByte( USART1, 0x59);//包头
	
	Usart_SendByte( USART1, CHx);//通道

	Usart_SendByte( USART1, 0x0F);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);//包长度
	
	Usart_SendByte( USART1, 0x05);//指令
	
	Usart_SendByte( USART1, 0x00);//校验
}
void send_target(uint16_t CHx,uint32_t target){
	Usart_SendByte( USART1, 0x53);
	Usart_SendByte( USART1, 0x5A);
	Usart_SendByte( USART1, 0x48);
	Usart_SendByte( USART1, 0x59);//包头
	
	Usart_SendByte( USART1, CHx);//通道
	
	Usart_SendByte( USART1, 0x0F);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);//包长度
	
	Usart_SendByte( USART1, 0x01);//指令	
	
	Usart_SendByte( USART1, target);
	Usart_SendByte( USART1, target>>8);
	Usart_SendByte( USART1, target>>16);
	Usart_SendByte( USART1, target>>24);
	
	Usart_SendByte( USART1, 0x00);//校验
}

void send_current(uint16_t CHx,uint32_t current){
	Usart_SendByte( USART1, 0x53);
	Usart_SendByte( USART1, 0x5A);
	Usart_SendByte( USART1, 0x48);
	Usart_SendByte( USART1, 0x59);//包头
	
	Usart_SendByte( USART1, CHx);//通道
	
	Usart_SendByte( USART1, 0x0F);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);//包长度
	
	Usart_SendByte( USART1, 0x02);//指令	
	
	Usart_SendByte( USART1, current);
	Usart_SendByte( USART1, current>>8);
	Usart_SendByte( USART1, current>>16);
	Usart_SendByte( USART1, current>>24);
	
	Usart_SendByte( USART1, 0x00);//校验
}

void send_T(uint16_t CHx,uint32_t t){
	Usart_SendByte( USART1, 0x53);
	Usart_SendByte( USART1, 0x5A);
	Usart_SendByte( USART1, 0x48);
	Usart_SendByte( USART1, 0x59);//包头
	
	Usart_SendByte( USART1, CHx);//通道
	
	Usart_SendByte( USART1, 0x0F);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);
	Usart_SendByte( USART1, 0x00);//包长度
	
	Usart_SendByte( USART1, 0x06);//指令

	Usart_SendByte( USART1, t);
	Usart_SendByte( USART1, t>>8);
	Usart_SendByte( USART1, t>>16);
	Usart_SendByte( USART1, t>>24);

	Usart_SendByte( USART1, 0x00);//校验
}

void send_current_target(float current,float target,uint16_t CHx)
{
	int cur = (int)current;
	int tar = (int)target;
	send_target( CHx,tar);
	send_current( CHx,cur);
}
