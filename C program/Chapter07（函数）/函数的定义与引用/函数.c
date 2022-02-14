#include <stdio.h>
#include <math.h>
#include <string.h>

int fun1(int m) //检查 m是否为素数 
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
	answer = fun1(m);//可以嵌套调用函数，但不能嵌套定义（一个函数里面不能再定义另一个函数） 
	if(answer==1) printf("%d是素数\n",m);
	if(answer==-1) printf("%d不是素数\n",m);
}

//递归函数，解决汉诺塔问题
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

int l=0;// l为全局变量 
void fun4(char str[])
{
	printf("%c",str[l]);
	l++;
}

int main()
{
	printf("%d\n",fun1(15));//-1    15不是素数，所以返回-1 
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
