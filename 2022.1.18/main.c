#include "include.h"

void main(){
	unsigned char* STR;
	STR = malloc(sizeof(char)*10);	
	//initClock();//定时器初始化

	//LEDTurnBit();

	Serial_init();//串口通信
	//显示屏代码
	init_1602();
	Show_String(0,0,"CYT SB");
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

		P2_1 = 1;
		delay(200);
		P2_1 = 0;
		delay(200);
	}

}


//删掉了这里的部分，并增加了这句话
//现在再加一句话


