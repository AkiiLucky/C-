#include <stdio.h>

int add(int num1,int num2)
{
	return num1 + num2;
}

int sub(int num1,int num2)
{
	return num1 - num2;
}

int rid(int num1,int num2)
{
	return num1 * num2;
}

int exc(int num1,int num2)
{
	return num1 / num2;
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
		case '*':return rid;break;
		case '/':return exc;break;
		
	}
}

int main()
{
	int num1,num2;
	char op;
	printf("请输入一个式子（如1+1）：");
	scanf("%d%c%d",&num1,&op,&num2);
	printf("%d%c%d = %d\n",num1,op,num2,calc(select(op),num1,num2));
	
	return 0;
} 
