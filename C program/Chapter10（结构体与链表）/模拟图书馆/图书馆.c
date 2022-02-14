#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct Date
{
	int year;
	int month;
	int day;
};

struct Library 
{
	char name[128];
	char auther[32];
	struct Date date;
	char publisher[32];
}book[N];// N Ϊ��ͼ�������������ɵ��鼮��

void get_book(struct Library *book)
{
	struct Library *p;
	p = (struct Library *)malloc(sizeof(struct Library));
	p = book;
	if (p == NULL)
	{
		printf("�ڴ�ռ����������ܼ���¼�룡");
		exit(1); 
	}
	printf("������������");
	scanf("%s",p->name);
	printf("��������������");
	scanf("%s",p->auther);
	printf("�������������(XXXX-XX-XX)��");
	scanf("%d-%d-%d",&p->date.year,&p->date.month,&p->date.day);
	printf("����������磺");
	scanf("%s",p->publisher);
	
	
}

void print_book(struct Library *book)
{
	struct Library *p;
	p = (struct Library *)malloc(sizeof(struct Library));
	p = book;
	if (p == NULL)
	{
		printf("�ڴ�ռ����������ܼ���¼�룡");
		exit(1); 
	}
	printf("������%s\n",p->auther); 
	printf("��������%s\n",p->name); 
	printf("�������ڣ�%d-%d-%d\n",p->date.year,p->date.month,p->date.day); 
	printf("�����磺%s\n",p->publisher); 

}

void print_books(int n)// n Ϊ��¼����鼮���� 
{
	for (int i = 0; i <= n; i++)
	{
		printf("�鼮���Ϊ��%d\n",i+1);
		print_book(&book[i]);
	}
}

void rewrite_book(struct Library *book,int j) // j Ϊ��Ҫ���ĵ��������
{
	
	printf("��������Ҫ�޸ĵ��鼮���ݴ��ţ�������1����������2���������ڣ�3�������磺4����");
	int num;
	scanf("%d",&num);
	
	if (num == 1) 
	{
		printf("��������Ҫ�޸ĵ�����Ϊ��");
		char ch2[128];
		scanf("%s",ch2);
		for (int i=0;i<=32;i++) book[j].name[i] = ch2[i];
	} 
	if (num == 2) 
	{
		printf("��������Ҫ�޸ĵ�����Ϊ��");
		char ch2[32];
		scanf("%s",ch2);
		for (int i=0;i<=32;i++) book[j].auther[i] = ch2[i];
	}
	if (num == 3) 
	{
		printf("��������Ҫ�޸ĵ�����Ϊ��");
		char ch2[32];
		scanf("%d-%d-%d",&book[j].date.year,&book[j].date.month,&book[j].date.day);
		for (int i=0;i<=32;i++) book[j].auther[i] = ch2[i];
	}
	if (num == 4) 
	{
		printf("��������Ҫ�޸ĵ�����Ϊ��");
		char ch2[32];
		scanf("%s",ch2);
		for (int i=0;i<=32;i++) book[j].publisher[i] = ch2[i];
	}
}

int main(void)
{
	int i = 0,j = 0;
	while (1)
	{
		get_book(&book[i]);
		printf("�Ƿ����¼����һ�������Ϣ�������� 1 ������ -1�� : ");
		int r1 = -1;
		scanf("%d",&r1);
		if (r1 == -1) break;
		else i++;
	}
	
	
	printf("�Ƿ�Ҫ�鿴����¼��������鼮�������� 1 ������ -1�� : ");
	int r2 = -1;
	scanf("%d",&r2);
	if (r2 == 1) print_books(i);

	printf("�Ƿ�Ҫ��������¼����鼮��Ϣ�������� 1 ������ -1�� : ");
	int r3 = -1;
	scanf("%d",&r3);
	if (r3 != -1)
	{
		while (1)
		{
			printf("��������Ҫ���ĵ��鼮�ı�� : ");
			int snum = 0;
			scanf("%d",&snum);
			rewrite_book(&book[snum-1],snum-1);
			
			printf("�Ƿ����������һ�������Ϣ�������� 1 ������ -1�� : ");
			int r4 = -1;
			scanf("%d",&r4);
			if (r4 == -1) break;
		
		}
    } 
	
	
	
	
	
	return 0;
}
