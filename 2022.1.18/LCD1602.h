#ifndef __LCD1602_H_
#define __LCD1602_H_
#include"include.h"

#define LCD1602_DATAPORT P0	//宏定义LCD1602数据端口,这里用sbit 也可以
#define LCD_RW P2_5
#define LCD_RS P2_6
#define LCD_E  P2_7

void init_1602();
void clear_1602();	
void Show_String(unsigned char a,unsigned char b,unsigned char* str);

#endif