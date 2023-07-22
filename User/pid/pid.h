#ifndef  _PID_H
#define  _PID_H
#include "stm32f10x.h"

/***************************PID*************************/

// PID�ṹ����

extern int SetPoint; //�趨Ŀ�� Desired Value 
extern float Balance_KP; //�������� Proportional Const 
extern float Balance_KI; //���ֳ��� Integral Const 
extern float Balance_KD; //΢�ֳ��� Derivative Const 
extern int LastError; //Error[-1] 
extern int PrevError; //Error[-2] 
extern int SumError; //Sums of Errors 

 int balance(float now_Value);

#endif
