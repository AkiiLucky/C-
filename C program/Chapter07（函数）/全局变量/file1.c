#include <stdio.h>
#include "file2.c"

int a = 1;
static int b = 2;//ȫ�ֱ��� b ��������Ϊ file1.c 


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
	extern float x,y;//�����ⲿ���� x,y ��������չ��fun3() 
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


	fun4();//�����ļ� file2.c�е��ⲿ���� fun4() 
	fun5();//�������ļ� file2.c�е��ڲ����� fun4() Ŀǰ��֪��Ϊɶ�ܵ��óɹ��������� 
	 
	printf("%d\n",num);//�����ļ� file2.c �е��ⲿ��ȫ�ֱ��� num 
	
	return 0;
}
