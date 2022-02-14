#include <stdio.h>
#include <math.h>
#include <string.h>

int fun1(int m) //��� m�Ƿ�Ϊ���� 
{
	int i;
	m = sqrt(m);
	for(i=2;i<=m;i++)
	{
		if(m % i == 0) return -1;
	}
	return 1;
}

void fun2(int m)
{
	int answer;
	answer = fun1(m);//����Ƕ�׵��ú�����������Ƕ�׶��壨һ���������治���ٶ�����һ�������� 
	if(answer==1) printf("%d������\n",m);
	if(answer==-1) printf("%d��������\n",m);
}

//�ݹ麯���������ŵ������
void hanoi(int n,char a,char b,char c)
{
	if(n==1){
		printf("%c-->%c\n",a,c);
	} 
	else {
		hanoi(n-1,a,c,b);
		printf("%c-->%c\n",a,c);
		hanoi(n-1,b,a,c);
	}

}

void fun3(char ch)
{
	printf("%c",ch);
}

int l=0;// lΪȫ�ֱ��� 
void fun4(char str[])
{
	printf("%c",str[l]);
	l++;
}

int main()
{
	printf("%d\n",fun1(15));//-1    15�������������Է���-1 
	fun2(15);
	hanoi(4,'A','B','C');
	
	int j;
	char str1[20] = "ssadsadx5414";
	int lenth = strlen(str1);
	for(j=0;j<lenth;j++)
	{
		fun3(str1[j]);
	}
	printf("\n");
	
	for(j=0;j<lenth;j++)
	{
		fun4(str1);
	}
	printf("\n");
	
	return 0;
}
