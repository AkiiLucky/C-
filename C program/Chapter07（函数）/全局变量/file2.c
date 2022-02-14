#include <stdio.h>

int num=100;//num  为外部型全局变量，可以把 extern 省略 

void fun4()
{
	int num1 = 5;
	float num2 = 10.0,num3 = 15.0;
	printf("%d\n",num1);
	printf("%.2f,%.2f\n",num2,num3);
	
}

static void fun5()//fun5()为内部函数，去掉 static 会把 fun5()转换为外部函数 
{
	int num = 50;
	printf("%d\n",num);
}
