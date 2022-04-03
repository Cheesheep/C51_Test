#include "include.h"

void main(){
	unsigned char* STR;
	STR = malloc(sizeof(char)*10);	
	//initClock();//定时器初始化

	//LEDTurnBit();

	Serial_init();//串口通信
	//显示屏代码
	init_1602();
	Show_String(0,0,"Happy New Year");
	//Show_String(0,1,"Saul");
	//Init_PWMCount();
	//LEDBinary();
	// while(1)
	// {	P1_0 = 1;
	// 	delay(200);
	// 	P1_0 = 0;
	// 	delay(200);
	// }
	while(1){

		P2_0 = 1;
		delay(200);
		P2_0 = 0;
		delay(200);
	}

}

// void PWM_rountine() interrupt 3
// {	unsigned char temp = PTime;
// 	P1_0 = 1;
// 	while(temp--);
// 	P1_0 = 0;
	
// }




