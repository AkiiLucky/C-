#include <stdio.h>
#include <stdarg.h> 

int sum(int n, ...)//n为后面参数的个数 
{
	int i,sum = 0;
	__builtin_va_list vap;//定义一个指针 
	
	__builtin_va_start(vap,n);//给指针变量获取值 
	for(i=0;i<n;i++)
	{
		sum += __builtin_va_arg(vap,int);//每调用一次，指针自动指向下一个参数 
	}
	__builtin_va_end(vap);//清除指针 
	return sum;
}

int main()
{
	int s;
	s = sum(4,1,2,3,4);
	printf("%d\n",s);//10
	
	return 0;
}
