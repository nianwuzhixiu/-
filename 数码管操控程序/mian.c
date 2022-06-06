#include <reg51.h>

typedef unsigned long d;	   //对数据类型进行声明定义
typedef unsigned int b;	
typedef unsigned char c;

sbit LSA=P3^0;		//74hc138的A B C引脚定义
sbit LSB=P3^1;
sbit LSC=P3^2;

#define SMG P0		//定义数码管段数据接口P0

c a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//分别显示0 1 2 3 4 5 6 7 8 9

void delay_ms(b t)
{
	b i,j;
	for(i=0; i<t; i++)
		for(j=0; j<120; j++);
	
}


void display(c match,number)	  //显示函数
{

		switch(match)	  //先位选
		{
			case 0:LSC=0;LSB=0;LSA=0;break;
			case 1:LSC=0;LSB=0;LSA=1;break;
			case 2:LSC=0;LSB=1;LSA=0;break;
			case 3:LSC=0;LSB=1;LSA=1;break;
			case 4:LSC=1;LSB=0;LSA=0;break;
			case 5:LSC=1;LSB=0;LSA=1;break;
			case 6:LSC=1;LSB=1;LSA=0;break;
			case 7:LSC=1;LSB=1;LSA=1;break;
		}
		SMG=a[number];	//后发送段数据
		delay_ms(500);	//小延时，显示更稳定
		SMG=0x00;   //消影
}

void main(void)
{
	d num=0;	 //要显示的数据
	d number=0;
	
	while(1)
	{
			display(0,1);
			delay_ms(200);
			display(1,2);
			delay_ms(200);
			display(2,3);
			delay_ms(200);
			display(3,4);
			delay_ms(200);			
			display(4,5);
			delay_ms(200);			
			display(5,6);
			delay_ms(200);			
			display(6,7);
			delay_ms(200);			
			display(7,8);
			delay_ms(200);			
	}
}
