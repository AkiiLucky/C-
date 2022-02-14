//局部变量（auto,register,static）
//auto变量
#include <stdio.h>
int fun1(int a,int b)//a,b以及sum均为局部自动变量 ，作用域为该函数内部 
{
	int sum;
	sum = a + b;
	return sum;
} 
//register变量 （访问速度快，存放在CPU的寄存器内） 
int fun2(int n)
{
	int i;
	register int s=1;// s为寄存器变量
	if(n==0||n==1) s = 1;
	else if(n>1)
	{
		for(i=1;i<=n;i++) s = s * i; 
	}
	else
	{
		printf("格式错误，n必须大于零");
	}
	return s;
}
//static变量（函数调用结束后不消失而保留原值） 
int fun3(int c)
{
	static int d = 0;//d为静态局部变量，不能定义为寄存器变量 
	d++;
	return (c+d);
}

void main()
{
	int i;
	printf("%d + %d = %d\n",2,3,fun1(2,3));//2 + 3 = 5
	printf("%d! = %d\n",5,fun2(5));//5! = 120
	for(i=0;i<5;i++) printf("%d ",fun3(1));//2 3 4 5 6
}

