#include <stdio.h>

int square(int num)
{
	return num * num;
}

int add(int num1,int num2)
{
	return num1 + num2;
}

int sub(int num1,int num2)
{
	return num1 - num2;
}

int calc(int (*fp)(int,int),int num1,int num2)
{
	return (*fp)(num1,num2);
}

int (*select(op))(int,int)
{
	switch(op)
	{
		case '+':return add;break;
		case '-':return sub;break;
	}
}

int main()
{
	int num = 5;
	int (*fp)(int);
	fp = &square;//可以去掉 & ，因为函数名就是函数地址 
	printf("%d\n",(*fp)(num));//25
	
	printf("3 + 5 = %d\n",calc(&add,3,5));//3 + 5 = 8
	printf("3 - 5 = %d\n",calc(&sub,3,5));//3 - 5 = -2
	
	int num1,num2;
	char op;
	printf("请输入一个式子（如1+1）：");
	scanf("%d%c%d",&num1,&op,&num2);
	printf("%d%c%d = %d\n",num1,op,num2,calc(select(op),num1,num2));
	
	return 0;
} 
