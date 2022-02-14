#include <stdio.h>
#include "file2.c"

int a = 1;
static int b = 2;//全局变量 b 的作用域为 file1.c 


void fun1()
{
	printf("%d\n",a);
}

void fun2()
{
	printf("%d\n",b);
}

void fun3()
{
	extern float x,y;//声明外部变量 x,y 作用域扩展至fun3() 
	printf("x = %.2f, y = %.2f\n",++x,++y);
}

float x=3.0,y=4.0;

extern void fun4();
//extern void fun5();
extern int num;

int main()
{
	fun1();//1
	fun2();//2
	fun3();//x = 4.00, y = 5.00


	fun4();//调用文件 file2.c中的外部函数 fun4() 
	fun5();//调用了文件 file2.c中的内部函数 fun4() 目前不知道为啥能调用成功？？？？ 
	 
	printf("%d\n",num);//调用文件 file2.c 中的外部型全局变量 num 
	
	return 0;
}
