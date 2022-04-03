#include"include.h"

int Parray[8][3] = 
	{0,0,0,
	 0,0,1,
	 0,1,0,
	 0,1,1,
	 1,0,0,
	 1,0,1,
	 1,1,0,
	 1,1,1};
unsigned char NixieTable[] = {0x3F,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void Static_Dynamic_Digital(unsigned char Position,unsigned char Num){

	Position -= 1;
		//给第三位数码管上低电平
		P2_4 = Parray[Position][0];
		P2_3 = Parray[Position][1];		
		P2_2 = Parray[Position][2];
		P0 = NixieTable[Num];
	
}


void LEDTurnBit(){//按键led移位
	unsigned char LEDnum = 0;
	while(1){
		if(P3_0 == 0){//实现按键左移led灯
			delay(20);
			while(P3_0 == 0);
			delay(20);
			if(LEDnum == 8)
				LEDnum = 0;
			P2 = ~(0x01<<LEDnum++);
		}
				if(P3_1 == 0){//实现按键右移led灯
			delay(20);
			while(P3_1 == 0);
			delay(20);
			if(LEDnum == -1)
				LEDnum = 7;
			P2 = ~(0x01<<LEDnum--);
		}
	}

}

void delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	if(xms > 10) 
		xms /= 10;
	i = 108;
	j = 145;
	while(xms--)
	do
	{
		while (--j);
	} while (--i);
}

void delay1ms(int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--){
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		}while (--i);
	}
}

void LEDShrink(){ //led灯闪烁
	
	while(1){
		P2 = 0xfe;
		delay(1000);
		P2 = 0xff;
		delay(1000);	
	}

}

void LEDBinary(){//按键实现led二进制
	unsigned char LNUM = 0;
	while(1){
		if(P3_0 == 0){
			delay(20);
			while(!P3_0);
			delay(20);//用延时来抵消电压震荡的影响
			LNUM++;
			P2 = ~LNUM;
		}

	}
}

void Get_Key_Num(){
			if(P3_1){
			delay(20);
			while(P3_1);
			delay(20);
			P2_0 = !P2_0;
			}
}