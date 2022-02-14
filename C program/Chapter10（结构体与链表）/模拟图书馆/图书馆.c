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
}book[N];// N 为该图书馆最多所能容纳的书籍数

void get_book(struct Library *book)
{
	struct Library *p;
	p = (struct Library *)malloc(sizeof(struct Library));
	p = book;
	if (p == NULL)
	{
		printf("内存空间已满，不能继续录入！");
		exit(1); 
	}
	printf("请输入书名：");
	scanf("%s",p->name);
	printf("请输入作者名：");
	scanf("%s",p->auther);
	printf("请输入出版日期(XXXX-XX-XX)：");
	scanf("%d-%d-%d",&p->date.year,&p->date.month,&p->date.day);
	printf("请输入出版社：");
	scanf("%s",p->publisher);
	
	
}

void print_book(struct Library *book)
{
	struct Library *p;
	p = (struct Library *)malloc(sizeof(struct Library));
	p = book;
	if (p == NULL)
	{
		printf("内存空间已满，不能继续录入！");
		exit(1); 
	}
	printf("书名：%s\n",p->auther); 
	printf("作者名：%s\n",p->name); 
	printf("出版日期：%d-%d-%d\n",p->date.year,p->date.month,p->date.day); 
	printf("出版社：%s\n",p->publisher); 

}

void print_books(int n)// n 为已录入的书籍本书 
{
	for (int i = 0; i <= n; i++)
	{
		printf("书籍编号为：%d\n",i+1);
		print_book(&book[i]);
	}
}

void rewrite_book(struct Library *book,int j) // j 为所要更改的书的索引
{
	
	printf("请输入您要修改的书籍内容代号（书名：1，作者名：2，出版日期：3，出版社：4）：");
	int num;
	scanf("%d",&num);
	
	if (num == 1) 
	{
		printf("请输入您要修改的内容为：");
		char ch2[128];
		scanf("%s",ch2);
		for (int i=0;i<=32;i++) book[j].name[i] = ch2[i];
	} 
	if (num == 2) 
	{
		printf("请输入您要修改的内容为：");
		char ch2[32];
		scanf("%s",ch2);
		for (int i=0;i<=32;i++) book[j].auther[i] = ch2[i];
	}
	if (num == 3) 
	{
		printf("请输入您要修改的内容为：");
		char ch2[32];
		scanf("%d-%d-%d",&book[j].date.year,&book[j].date.month,&book[j].date.day);
		for (int i=0;i<=32;i++) book[j].auther[i] = ch2[i];
	}
	if (num == 4) 
	{
		printf("请输入您要修改的内容为：");
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
		printf("是否继续录入下一本书的信息？（是填 1 ，否填 -1） : ");
		int r1 = -1;
		scanf("%d",&r1);
		if (r1 == -1) break;
		else i++;
	}
	
	
	printf("是否要查看您所录入的所有书籍？（是填 1 ，否填 -1） : ");
	int r2 = -1;
	scanf("%d",&r2);
	if (r2 == 1) print_books(i);

	printf("是否要更改您所录入的书籍信息？（是填 1 ，否填 -1） : ");
	int r3 = -1;
	scanf("%d",&r3);
	if (r3 != -1)
	{
		while (1)
		{
			printf("请输入您要更改的书籍的编号 : ");
			int snum = 0;
			scanf("%d",&snum);
			rewrite_book(&book[snum-1],snum-1);
			
			printf("是否继续更改下一本书的信息？（是填 1 ，否填 -1） : ");
			int r4 = -1;
			scanf("%d",&r4);
			if (r4 == -1) break;
		
		}
    } 
	
	
	
	
	
	return 0;
}
