#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Date
{
	int year;
	int month;
	int day;
} DATE, *PDATE;

typedef struct Book
{
	int number;//图书编号 
	int quantity;//图书数量 
	char title[128];
	char auther[128];
	DATE publish_date;
	char publisher[128];
	float price;
	struct Book *next;
} BOOK, *PBOOK;

BOOK *create_books(BOOK *head);
BOOK *output_books(BOOK *head);
BOOK *output_book(BOOK *p);
BOOK *save_file(BOOK *head); 
BOOK *open_file(BOOK *head);
BOOK *search_number(BOOK *head);
BOOK *search_title(BOOK *head);
BOOK *delete_book_number(BOOK *head);
BOOK *delete_book_title(BOOK *head);
BOOK *add_book(BOOK *head);
BOOK *change_book(BOOK *head);

int n;

int main(void)
{
	printf("******************************************************\n");
	printf("*----------------------------------------------------*\n");
	printf("*-**************************************************-*\n");
	printf("*-****************                 *****************-*\n");
	printf("*-***************  图书信息管理系统  ***************-*\n");
	printf("*-****************                 *****************-*\n");
	printf("*-**************************************************-*\n");
	printf("*----------------------------------------------------*\n");
	printf("******************************************************\n");
	
	BOOK *head = NULL;
	int choice = 1;
	
	while (1)
	{
		printf("1----建立新的数据库文件\n");
		printf("2----打开现有数据库文件\n");
		printf("3----增加图书信息\n");
		printf("4----删除图书信息\n");
		printf("5----查询图书信息\n");
		printf("6----修改图书信息\n");
		printf("7----浏览图书信息\n");
		printf("8----保存图书信息\n");
		printf("0----退出系统\n");
		printf("您要执行的内容（请输入 0-5 之间的数字）：");
		scanf("%d",&choice); 
		
		if (choice == 1)
		{
			head = create_books(head);
			while (1)
			{
				printf("是否保存文件？（1 代表是，0 代表否）: ");
				int i = -1;
				scanf("%d",&i);
				if (i == 1) 
				{
					head = save_file(head);
					break;
				}
				else if (i == 0) break;
				else printf("输入有误，请重新输入！\n");
			}
		}
		else if (choice == 2)
		{
			head = open_file(head);
		}
		else if (choice == 3)
		{
			head = add_book(head);
		}
		else if (choice == 4)
		{
			printf("1 代表按图书编号查找，2 代表按图书标题查找，请输入输入索引方式: ");
			int i = -1;
			scanf("%d",&i);
			while (1)
			{
				if (i == 1) 
				{
					head = delete_book_number(head);
					break;
				}
				else if (i == 2)
				{
					head = delete_book_title(head);
					break;
				} 
				else printf("输入有误，请重新输入！\n");
			}
		}
		else if (choice == 5)
		{
			printf("1 代表按图书编号查找，2 代表按图书标题查找，请输入输入索引方式: ");
			int i = -1;
			scanf("%d",&i);
			while (1)
			{
				if (i == 1) 
				{
					head = search_number(head);
					break;
				}
				else if (i == 2)
				{
					head = search_title(head);
					break;
				} 
				else printf("输入有误，请重新输入！\n");
			}
		}
		else if (choice == 6)
		{
			head = change_book(head);
		}
		else if (choice == 7)
		{
			head = output_books(head);
		}
		else if (choice == 8)
		{
			head = save_file(head);
		}
		else if (choice == 0)
		{
			exit(0);
		}
		else 
		{
			printf("输入有误，请重新输入！\n");
		}
	}
	return 0;
}

BOOK *create_books(BOOK *head)
{
	printf("正在建立一个新的文件...\n");
	n = 0;
	BOOK *p = NULL;
	BOOK *tail = NULL; 
	
	tail = head;
	
	p = (BOOK *)malloc(sizeof(BOOK));
	printf("请输入第一本书的信息（图书编号为 -1 表示结束）\n");
	printf("图书编号：");
	scanf("%d",&p->number);
	if (p->number == -1) 
	{
		printf("输入完毕！\n");
		free(p);
		return (head);
	}
	printf("图书标题：");
	scanf("%s",p->title);
	printf("图书作者：");
	scanf("%s",p->auther);
	printf("出版日期：");
	scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
	printf("出版单位：");
	scanf("%s",p->publisher);
	printf("图书定价：");
	scanf("%f",&p->price);
	printf("图书数量：");
	scanf("%d",&p->quantity);
	p->next = NULL;
	 
	while (p->number != -1)
	{
		fflush(stdin);
		printf("请输入下一本书的信息（图书编号为 -1 表示结束）\n");
		n = n+1;
		
		if (n == 1) head = p;
		else tail->next = p;	
		tail = p;
		
		p = (BOOK *)malloc(sizeof(BOOK));
		
		printf("图书编号：");
		scanf("%d",&p->number);
		
		if (p->number == -1) 
		{
			printf("输入完毕！\n");
			free(p);
			break;
		}
		printf("图书标题：");
		scanf("%s",p->title);
		printf("图书作者：");
		scanf("%s",p->auther);
		printf("出版日期：");
		scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
		printf("出版单位：");
		scanf("%s",p->publisher);
		printf("图书定价：");
		scanf("%f",&p->price);
		printf("图书数量：");
	    scanf("%d",&p->quantity);
		p->next = NULL;
	}
	tail->next = NULL;
	return (head);
}

BOOK *output_books(BOOK *head)
{
	printf("------------------图书总览---------------------\n"); 
	BOOK *p = head;
	int i = 1;
	while (p != NULL)
	{
		output_book(p);
		printf("\n");
		p = p->next;
	}
	printf("------------------总览完毕---------------------\n"); 
	return (head);
}

BOOK *output_book(BOOK *p)
{
	printf("图书编号：%d\n",p->number);
	printf("图书标题：%s\n",p->title);
	printf("图书作者：%s\n",p->auther);
	printf("出版日期：%d-%d-%d\n",p->publish_date.year,p->publish_date.month,p->publish_date.day);
	printf("出版单位：%s\n",p->publisher);
	printf("图书定价：%.2f\n",p->price);
	printf("图书数量：%d\n",p->quantity);
}


BOOK *save_file(BOOK *head)
{
	BOOK *p = head;
	
	FILE *fp = fopen("booklist_1.txt","wb+");
	if (fp == NULL)
	{
		perror("文件保存失败!!! 原因是");
		exit(1);
	}
	rewind(fp);
	while (p != NULL)
	{
		fwrite(p,sizeof(BOOK),1,fp);
		p = p->next;
	}
	printf("文件已保存至当前文件夹！\n");
	fclose(fp);
	return (head);
}

BOOK *open_file(BOOK *head)
{
	FILE *fp = fopen("booklist_1.txt","rb+");
	if (fp == NULL)
	{
		perror("文件打开失败!!! 原因是");
		exit(1);
	}
	rewind(fp);
	
	n = 0;
	BOOK *p, *tail = NULL;
	p = (BOOK *)calloc(1,sizeof(BOOK));
	fread(p,sizeof(BOOK),1,fp);
	head = p;
	tail = p;
	n++;
	while(1)
	{
		p = (BOOK *)calloc(1,sizeof(BOOK));
		fread(p,sizeof(BOOK),1,fp);
		if (feof(fp) != 0) 
		{
			free(p);
			break;
		}
		tail->next = p;
		tail = p;
		n++;
		//printf("*%d*\n",ftell(fp));
	}
	tail->next = NULL;
	fclose(fp);
	printf("文件已打开！\n");
	return (head);
}

BOOK *search_number(BOOK *head)
{
	if (head == NULL)
	{
		printf("书库为空！\n");
		return (head);
	}
	int number;
	printf("请输入您要查找的图书编号：");
	scanf("%d",&number);
	
	BOOK *p = head;
	int i = 0;
	while (p != NULL)
	{
		if (p->number == number) 
		{
			output_book(p);
			printf("\n"); 
			i++;
		}
		p = p->next;
	}
	printf("查找完毕！共 %d 个结果\n",i);
	return (head);
}

BOOK *search_title(BOOK *head)
{
	if (head == NULL)
	{
		printf("书库为空！\n");
		return (head);
	}
	char title[128];
	printf("请输入您要查找的图书标题：");
	scanf("%s",title);
	
	BOOK *p = head;
	int i = 0;
	while (p != NULL)
	{
		if (!strcmp(p->title,title)) 
		{
			output_book(p);
			printf("\n"); 
			i++;
		}
		p = p->next;
	}
	printf("查找完毕！共 %d 个结果\n",i);
	return (head);
}

BOOK *delete_book_number(BOOK *head)
{
	int count = 0;
	if (head == NULL)
	{
		printf("书库为空！\n");
		return (head);
	}
	BOOK *p = head,*q = head; 
	int number;
	printf("您正在执行删除操作，请输入该书籍的编号：");
	scanf("%d",&number);
	if (head->number == number) 
	{
		head = p->next;
		free(p);
		printf("编号为 %d 的书籍信息已被删除！\n",number);
		count++;
		return (head);
	}
	p = p->next;
	while (p != NULL)
	{
		if (p->number == number)
		{
			q->next = p->next;
			count++;
			break;
		}
		q = p;
		p = p->next;
	}
	free(p);
	if (count == 0) printf("书库中没有此图书的信息！\n");
	else printf("编号为 %d 的书籍信息已被删除！\n",number);
	return (head);
}

BOOK *delete_book_title(BOOK *head)
{
	int count = 0;
	if (head == NULL)
	{
		printf("书库为空！\n");
		return (head);
	}
	BOOK *p = head,*q = head; 
	char title[128];
	printf("您正在执行删除操作，请输入该图书的标题：");
	scanf("%s",title);
	if (!strcmp(head->title,title)) 
	{
		head = p->next;
		free(p);
		printf("标题为 \"%s\" 的图书信息已被删除！\n",title);
		count++;
		return (head);
	}
	p = p->next;
	while (p != NULL)
	{
		if (!strcmp(p->title,title))
		{
			q->next = p->next;
			count++;
			break;
		}
		q = p;
		p = p->next;
	}
	free(p);
	if (count == 0) printf("书库中没有此图书的信息！\n");
	else printf("标题为 \"%s\" 的图书信息已被删除！\n",title);
	return (head);
}


BOOK *add_book(BOOK *head)
{
	if (head == NULL)
	{
		printf("书库为空！\n");
		return (head);
	}
	printf("正在执行增加操作，请输入图书的信息：\n");
	BOOK *p;
	p = (BOOK *)malloc(sizeof(BOOK));
	printf("图书编号：");
	scanf("%d",&p->number);
	printf("图书标题：");
	scanf("%s",p->title);
	printf("图书作者：");
	scanf("%s",p->auther);
	printf("出版日期：");
	scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
	printf("出版单位：");
	scanf("%s",p->publisher);
	printf("图书定价：");
	scanf("%f",&p->price);
	printf("图书数量：");
	scanf("%d",&p->quantity);
	p->next = head;
	head = p;
	printf("书籍信息已录入到书库！\n");
	return (head);
}

BOOK *change_book(BOOK *head)
{
	if (head == NULL)
	{
		printf("书库为空！\n");
		return (head);
	}
	printf("正在修改书籍信息...\n");
	BOOK *p = head;
	int number;
	printf("请输入您要修改的图书编号：");
	scanf("%d",&number);
	int i = 0;
	while (p != NULL)
	{
		if (p->number == number)
		{
		printf("图书标题修改为：");
		scanf("%s",p->title);
		printf("图书作者修改为：");
		scanf("%s",p->auther);
		printf("出版日期修改为：");
		scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
		printf("出版单位修改为：");
		scanf("%s",p->publisher);
		printf("图书定价修改为：");
		scanf("%f",&p->price);
		printf("图书数量修改为：");
	    scanf("%d",&p->quantity);
		printf("书籍信息已修改完毕！\n");
		i++;
		break;
		}
		p = p->next;
	}
	if (i == 0) printf("无效的图书编号！\n");
	return (head);
}



























/*

void search_max_score(BOOK *head)//查找成绩最高分 
{
	int max;
	BOOK *p;
	p = head;
	max = p->score;
	p = p->next;
	while (p != NULL)
	{
		if (p->score > max) max = p->score;
		p = p->next;		
	}
	printf("最高成绩为：%d\n",max);
}



BOOK *insert_num(BOOK *head,BOOK *s) //插入学号为 XXXX 的个人信息， s 为待插入结点 
{
	BOOK *p=NULL,*q1=NULL,*q2=NULL;
	p = s;
	q1 = head;
	if (head == NULL)
	{
		head = p;
		p->next = NULL;
	} 
	else
	{	
		while ((p->num > q1->num) && (q1->next != NULL))
		{
			q2 = q1;
			q1 = q1->next;
		}
		if (p->num <= q1->num)
		{
			if (head == q1)
			{
				head = p;
				p->next = q1;
			}
			else
			{
				p->next = q1;
				q2->next = p;
			}
		}
		else
		{
			q1->next = p;
			p->next = NULL;
		}
				
	}
	n = n+1; 
	printf("==============插入完毕=================\n");
	return (head);
}

BOOK *create_p()//创建一个结点 p 
{
	printf("正在创建一个新的结点...\n");
	BOOK *p;
	printf("学号：");
	scanf("%d",&p->num);
	printf("分数：");
	scanf("%d",&p->score);
	p->next = NULL;
	printf("创建成功！\n");
	return (p);
}

BOOK *delete_p(BOOK *head)//删除一个结点 
{
	int num;
	printf("您即将删除某位学生的学生信息，请输入该学生的学号：");
	scanf("%d",&num);
	
	BOOK *p1 = NULL,*p2 = NULL;
	p1 = head;
	if (head == NULL) printf("链表为空！");
	else
	{
		while (p1->num != num && p1 != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p1->num == num)   
		{
			if (p1 == head) head = p1->next;
			else p2->next = p1->next;
			free(p1);
			n = n-1;
		}
		else 
		{
			printf("未找到匹配项！\n");
		}	
	}
	return (head);
}

int main(void)
{
	
	int choice = 1;
	
	while (1)
	{
		printf("1----建立链表\n");
		printf("2----插入结点\n");
		printf("3----删除结点\n");
		printf("4----查找结点\n");
		printf("5----输出链表\n");
		printf("0----退出\n");
		printf("您要执行的内容（请输入 0-5 之间的数字）：");
		scanf("%d",&choice);
		
		BOOK *head;
		
		if (choice == 1)
		{
			head = create_tail();
		}
		else if (choice == 2)
		{
			BOOK *s;
			s = (BOOK *)malloc(sizeof(BOOK));
			s = create_p();
			head = insert_num(head,s);
		}
		else if (choice == 3)
		{
			head = delete_p(head);
		}
		else if (choice == 4)
		{
			printf("1----按学号查找\n");
			printf("2----按成绩查找\n");
			printf("3----查找最大成绩\n");
			printf("请输入查找方式：");
			int cho = 0;
			scanf("%d",&cho);
			switch(cho)
			{
				case 1:search_num(head);break;
				case 2:search_score(head);break;
				case 3:search_max_score(head);break;
				default:printf("输入有误!\n");
			}
			
		}
		else if (choice == 5)
		{
			putout(head);
		}
		else if (choice == 0) 
		{
			printf("程序已结束！");
			break;
		}
		else 
		{
			printf("输入有误，请重新输入!\n");
		}
		printf("\n");
		
		
	}
	
	
	return 0;
}
*/
