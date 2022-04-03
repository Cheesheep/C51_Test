#include<include.h>

void lcd1602_write_cmd(unsigned char cmd){
	LCD_RS = 0;//写指令
	LCD_RW = 0;//写入，若是1则为读取
	LCD1602_DATAPORT = cmd;
	LCD_E = 0;
	delay1ms(1);
	LCD_E = 1;//从低位变高位获取数据
	delay1ms(1);
	LCD_E = 0;
}
	

void lcd1602_write_data(unsigned char dat){//用于写入要显示的内容
	LCD_RS = 1;
	LCD_RW = 0;
	LCD1602_DATAPORT = dat;
	LCD_E = 0;
	delay1ms(1);
	LCD_E = 1;
	delay1ms(1);
	LCD_E = 0;

}

void init_1602(){
	lcd1602_write_cmd(0x38);//数据总线8位，显示2行，5*7点阵/字符
	lcd1602_write_cmd(0x0c);//显示功能开，无光标，光标闪烁
	lcd1602_write_cmd(0x06);//写入新数据后光标右移，显示屏不移动
	lcd1602_write_cmd(0x01);//清屏	
}

void clear_1602(){
	lcd1602_write_cmd(0x01);	//清屏
}


void Show_String(unsigned char X,unsigned char Y,unsigned char*str){
	unsigned char i = 0;
	if(X > 15||Y>1)//若超出了可以显示的范围
	{	str = "ERROR DATA";
		X = Y = 0;
	}
	
	if(!Y)
		while(*str != '\0'){//遇到结束符前一直循环
			if(i < 16 - X)
				lcd1602_write_cmd(0x80 + i + X);//确定某个字符显示的位置
			else
				lcd1602_write_cmd(0x40+0x80 + i + X - 16);//当第一行满了则去到第二行显示
			lcd1602_write_data(*str);
			str++;
			i++;
			
		}
	else
		while(*str != '\0'){
			if(i < 16 - X)
				lcd1602_write_cmd(0x40+0x80 + i + X);//从第二行开始
			else
				lcd1602_write_cmd(0x80 + i + X - 16);
			lcd1602_write_data(*str);
			str++;
			i++;
		}
	
}
	
