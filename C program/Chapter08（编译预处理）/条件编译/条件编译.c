#include<stdio.h>
#define A 1
#define B 0

int fun1()
{
	int a=1,b=0,max;
	#ifdef A       //��� A �� #define ������������  max = a; ������� max = b;    
	  max = a;
	#else         
      max = b;     
	#endif
	printf("%d\n",max);// 1
	return 0;
}

int fun2()
{
	int a=1,b=0,max;
	#ifndef C       //��� C δ�� #define ������������  max = a; ������� max = b;    
	  max = a;
	#else 
      max = b;     
	#endif
	printf("%d\n",max);// 1
	return 0;
}

int fun3()
{
	int a=1,b=0,max;
	#if A       //��� A Ϊ�棬�����  max = a; �� A Ϊ�٣������ max = b;    
	  max = a;
	#else 
      max = b;     
	#endif
	printf("%d\n",max);// 1
	return 0;
}

int main()
{
	fun1();
	fun2();
	fun3();
	
	
	return 0;
}
