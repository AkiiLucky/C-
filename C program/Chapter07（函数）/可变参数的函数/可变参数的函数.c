#include <stdio.h>
#include <stdarg.h> 

int sum(int n, ...)//nΪ��������ĸ��� 
{
	int i,sum = 0;
	__builtin_va_list vap;//����һ��ָ�� 
	
	__builtin_va_start(vap,n);//��ָ�������ȡֵ 
	for(i=0;i<n;i++)
	{
		sum += __builtin_va_arg(vap,int);//ÿ����һ�Σ�ָ���Զ�ָ����һ������ 
	}
	__builtin_va_end(vap);//���ָ�� 
	return sum;
}

int main()
{
	int s;
	s = sum(4,1,2,3,4);
	printf("%d\n",s);//10
	
	return 0;
}
