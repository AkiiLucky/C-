#include <stdio.h>

int num=100;//num  Ϊ�ⲿ��ȫ�ֱ��������԰� extern ʡ�� 

void fun4()
{
	int num1 = 5;
	float num2 = 10.0,num3 = 15.0;
	printf("%d\n",num1);
	printf("%.2f,%.2f\n",num2,num3);
	
}

static void fun5()//fun5()Ϊ�ڲ�������ȥ�� static ��� fun5()ת��Ϊ�ⲿ���� 
{
	int num = 50;
	printf("%d\n",num);
}
