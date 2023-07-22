#ifndef  _PID_H
#define  _PID_H
#include "stm32f10x.h"

/***************************PID*************************/

// PID结构声明

extern int SetPoint; //设定目标 Desired Value 
extern float Balance_KP; //比例常数 Proportional Const 
extern float Balance_KI; //积分常数 Integral Const 
extern float Balance_KD; //微分常数 Derivative Const 
extern int LastError; //Error[-1] 
extern int PrevError; //Error[-2] 
extern int SumError; //Sums of Errors 

 int balance(float now_Value);

#endif
