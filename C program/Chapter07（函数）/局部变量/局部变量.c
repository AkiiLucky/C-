//�ֲ�������auto,register,static��
//auto����
#include <stdio.h>
int fun1(int a,int b)//a,b�Լ�sum��Ϊ�ֲ��Զ����� ��������Ϊ�ú����ڲ� 
{
	int sum;
	sum = a + b;
	return sum;
} 
//register���� �������ٶȿ죬�����CPU�ļĴ����ڣ� 
int fun2(int n)
{
	int i;
	register int s=1;// sΪ�Ĵ�������
	if(n==0||n==1) s = 1;
	else if(n>1)
	{
		for(i=1;i<=n;i++) s = s * i; 
	}
	else
	{
		printf("��ʽ����n���������");
	}
	return s;
}
//static�������������ý�������ʧ������ԭֵ�� 
int fun3(int c)
{
	static int d = 0;//dΪ��̬�ֲ����������ܶ���Ϊ�Ĵ������� 
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

