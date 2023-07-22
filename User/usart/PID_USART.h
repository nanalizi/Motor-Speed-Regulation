#ifndef __PID_USART_H
#define __PID_USART_H


#include "bsp_usart.h"
//extern Angle_speed ag_speed;
//extern  Motor_speed mt_speed;

//int balance(Angle_speed ag_speed,float Balance_KP,float Balance_KD);
//int Position(Motor_speed mt_speed,float Position_KP, float Position_KD);


void send_current_target(float current,float target,uint16_t CHx);
void send_T(uint16_t CHx,uint32_t t);
void tongbuclose(uint16_t CHx);
void tongbustar(uint16_t CHx);
void send_PID2USART(uint16_t CHx,uint32_t P,uint32_t I,uint32_t D);
void send_current(uint16_t CHx,uint32_t current);
void send_target(uint16_t CHx,uint32_t target);
#endif 
