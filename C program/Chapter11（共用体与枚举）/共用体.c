#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union Text
{
	int a;
	float b;
	char c[8];
}TEXT;

int main(void)
{
	TEXT text;
	text.a = 50;
	text.b = 66.6;
	strcpy(text.c,"abc");
	
	printf("%p\n",&text.a);//000000000062FE10  ������ĳ�Ա����ͬһ����ַ 
	printf("%p\n",&text.b);//000000000062FE10
	printf("%p\n",text.c);//000000000062FE10   
	
	printf("%d\n",text.a);
	printf("%.2f\n",text.b);
	printf("%s\n",text.c);//ֻ����ȷ��ӡ���һ������ֵ�Ĺ������Ա��ֵ����Ϊ���渳ֵ�Ļ��ǰ��ĸ��ǵ� 
	
	text.a = 100;
	printf("%d\n",text.a);
	
	return 0;
}
