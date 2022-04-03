#include"include.h"


void Serial_init(){//UART串口通信初始化
	
	PCON &= 0x80;//波特率加倍
	TMOD &= 0x0F;//重置
	TMOD |= 0x20;//选择方式2：8位自动重装计数
	SCON |= 0x50;//选择工作模式
	
	
	EA = 1;//中断总开关
	ES = 1;//串行口中断允许位
	TH1 = 0xfd; TH0 = 0xfd;//配置波特率
	TF1 = 0;//将中断清零
	TR1 = 1;//开始定时
}

void SerialUart() interrupt 4
{	
	unsigned char rec_data;
	
	RI = 0; //清除接收中断标志位 ,这里清零是因为TI和RI共用一个中断口
	rec_data=SBUF; //存储接收到的数据 
	REC_DATA = rec_data;
	SBUF=rec_data; //将接收到的数据放入到发送寄存器 
	while(!TI); //等待发送数据完成 
	TI=0; //清除发送完成标志位
}


/*
      定时器模块
*/

void initClock(){//T0定时器初始化
	TMOD |= 0x01;
	TH0 = 0xFC;//赋初值64535，代表每次1000us则会溢出一次并引发中断
	TL0 = 0x18;
	TR0 = 1;
	EA = 1;ET0 = 1;//打开总开关中断和T0计时器中断
	

} 

void time0() interrupt 1//定时器中断功能代码
{	static int CountNum = 1;
	TH0 = 0xFC;TL0 = 0x18;
	if(CountNum++ > 1000)
		{CountNum = 0;
		 P2_0 = ~P2_0;
		}
	    
}


/*
				外部中断
*/

void InitOutbreak(){
	EA = 1;
	EX1 = 1;
	IT1 = 1;
	
}

void Outbreak()interrupt 2
{	delay1ms(20);
	if(P3_3 == 0);
		P2_0 = !P2_0;
}

/*
		PWM调速
*/

void Init_PWMCount(){//用T1作计数器
    TMOD &= 0x00;
    TMOD |= 0x20;
    EA = 1;
    ET1 = 1;

	TL1 = 0x9b;		//设置定时初始值10ms
	TH1 = 0x9b;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
}

