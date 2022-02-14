#include<stdio.h>

int main()
{
	printf("Hello world!\n");
	printf("abc\tabc\n");
	
	int a=100;
	printf("%d\n",a);
	float b=12.58;
	float c=b*2;
	printf("%.2f\n",c);
	printf("a=%d,b=%.2f,c=%.2f\n",a,b,c);
	
	char d[]="我是小埋！";
	char f='A';
	printf("你好！%c\n",f);
	printf("%s\n","我是小埋！");
	printf("%s\n",d);

	char ch1='A',ch2,ch3,ch4='8',ch5;
	ch2=ch1+1;
	printf("%c\n",ch2);//B
	ch3=ch1+32;
	printf("%c\n",ch3);//a
	ch4=ch4-'0';//将字符'8'转换为数字8 
	printf("%d\n",ch4);
	ch5='0'+6;//把数字6转换为字符'6'
	printf("%c\n",ch5);
	
	int num1=3,num2=3,num3,num4;
	num3=num1++;
	num4=++num2;
	printf("%d %d\n",num3,num4);//num3=3,num4=4   num++代表先赋值后自增，++num代表先自增后赋值
	
	int a1=3,a2=4;
	printf("%d\n",(a1,a2));//4   将 a2 的值赋予 %d 
	
	int b1=3,b2=4,max;
	max = b1 > b2 ? b1 : b2;//如果 b1>b2 为真，则把 b1 赋值给 max ,如果b1>b2为假，则把 b2 赋值给 max
	printf("%d\n",max);//4  
	
	int c1=3,c2=4;
	printf("%d\n",1 < 2);//1  代表真 
	printf("%d\n",c1 > c2);//0 代表假 
	printf("%d\n",c1 > c2 && 1 < 2);//0
	printf("%d\n",c1 > c2 || 1 < 2);//1
	printf("%d\n",!0);//1
	printf("%d\n",c1 != 1);//1
	
	
	//八进制 (以0开头)  例 024561 
	//十六进制 (以0x开头) 例 0x5623 
	
	//-1的补码是1111111111
	//float 能表示6-7位有效数字 
	//double 能表示15-16位有效数字 
	return 0;
}
