#include<stdio.h>
#define A 1
#define B 0

int fun1()
{
	int a=1,b=0,max;
	#ifdef A       //如果 A 被 #define 定义过，则编译  max = a; 否则编译 max = b;    
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
	#ifndef C       //如果 C 未被 #define 定义过，则编译  max = a; 否则编译 max = b;    
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
	#if A       //如果 A 为真，则编译  max = a; 若 A 为假，则编译 max = b;    
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
