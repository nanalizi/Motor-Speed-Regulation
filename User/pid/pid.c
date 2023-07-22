#include "pid.h"
#include "key.h"

int SetPoint; //�趨Ŀ�� Desired Value 
float Balance_KP=70; //�������� Proportional Const 70
float Balance_KI=0.3; //���ֳ��� Integral Const 0.5
float Balance_KD=50; //50+_20΢�ֳ��� Derivative Const 50
int LastError=0; //Error[-1] 
int PrevError=0; //Error[-2] 
int SumError=0; //Sums of Errors 


 int balance(float now_Value)
{                         
   float Bias;                       //���ƫ��
	 static float Last_Bias,D_Bias,I_Bias;    //PID��ر���
	 int balance,SetPoint1;  
	 SetPoint1=SetPoint+11+qwer;	//PWM����ֵ 1200+15  480+11 700+12 800+13   1000+14
	if(SetPoint1<=480){SetPoint1=SetPoint1-2;}
	else if(SetPoint1>480 && SetPoint1<=530){SetPoint1=SetPoint1-1;}
	else if(SetPoint1>530 && SetPoint1<=650){SetPoint1=SetPoint1-1;}
	else if(SetPoint1>650 && SetPoint1<=700){SetPoint1=SetPoint1+4;}
	else if(SetPoint1>700 && SetPoint1<=800){SetPoint1=SetPoint1+8;}//+1
	else if(SetPoint1>800 && SetPoint1<=1000){SetPoint1=(SetPoint1+12);}//-2
	else if(SetPoint1>1000 && SetPoint1<=1100 ){SetPoint1=(SetPoint1+20);}//-2
	else if(SetPoint1>1100){SetPoint1=SetPoint1+8;}//+4
	 Bias = now_Value - SetPoint1;
	 I_Bias=Bias+Last_Bias;
//	 if(I_Bias>100)
//	 I_Bias=50;
	 D_Bias=Bias-Last_Bias;            //���ƫ���΢�� ����΢�ֿ���
	 balance=-Balance_KP*Bias-D_Bias*Balance_KD-I_Bias*Balance_KI;   //===������ǿ��Ƶĵ��PWM  PD����
     Last_Bias=Bias;                   //������һ�ε�ƫ��
	 if(balance>2000){balance=2000;}
	 if(balance<570){balance=570;}
	 
	 return balance;		
}
