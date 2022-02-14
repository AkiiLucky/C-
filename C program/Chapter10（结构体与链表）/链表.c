#include <stdio.h>
#include <stdlib.h>

struct Student 
{
	int num;
	int score;
	struct Student *next;
};

int n;

struct Student *create_head()//(输入顺序与链表顺序相反)
{
	n = 0;
	struct Student *head = NULL;
	struct Student *p;
	
	p = (struct Student *)malloc(sizeof(struct Student));
	printf("请输入第一条记录，学号为 0 表示结束\n");
	printf("学号：");
	scanf("%d",&p->num);
	printf("分数：");
	scanf("%d",&p->score);
	
	while (p->num != 0)
	{
		printf("请输入下一条记录，学号为 0 表示结束\n");
		n = n+1;
		
		p->next = head;
		head = p;
		
		p = (struct Student *)malloc(sizeof(struct Student));
		printf("学号：");
		scanf("%d",&p->num);
		printf("分数：");
		scanf("%d",&p->score);
		
	}
	return (head);
}

struct Student *create_tail()//尾插法建立链表 (输入顺序与链表顺序一致)
{
	printf("正在建立一个新的链表...\n");
	n = 0;
	struct Student *head = NULL;
	struct Student *p = NULL;
	struct Student *tail; 
	
	tail = head;
	
	p = (struct Student *)malloc(sizeof(struct Student));
	printf("请输入第一条记录，学号为 0 表示结束\n");
	printf("学号：");
	scanf("%d",&p->num);
	if (p->num == 0) 
	{
		printf("输入完毕！\n");
		free(p);
		return (head);
	}
	printf("分数：");
	scanf("%d",&p->score);
	p->next = NULL;
	
	while (p->num != 0)
	{
		printf("请输入下一条记录，学号为 0 表示结束\n");
		n = n+1;
		
		if (n == 1) head = p;
		else tail->next = p;	
		tail = p;
		
		p = (struct Student *)malloc(sizeof(struct Student));
		printf("学号：");
		scanf("%d",&p->num);
		if (p->num == 0) 
		{
			printf("输入完毕！\n");
			free(p);
			break;
		}
		printf("分数：");
		scanf("%d",&p->score);
		p->next = NULL;
	}
	tail->next = NULL;
	return (head);
}

void putout(struct Student *head)//输出链表 
{
	
	if (head == NULL) 
	{
		printf("链表为空！\n");
	}
	else
	{
		printf("==============学生成绩=================\n"); 
		struct Student *p = NULL;
		p = head;
		while (p != NULL)
		{
			printf("学号：%d\n",p->num);
			printf("分数：%d\n",p->score);
			p = p->next;
		}
		printf("==============输出完毕=================\n");
	}
	
}

void search_num(struct Student *head)
{
	int num = 0;
	printf("请输入您所要查找的学生的学号：");
	scanf("%d",&num);
	struct Student *p;
	p = head;
	while (p != NULL)
	{
		if (p->num == num)
		{
			printf("学号：%d\n",p->num);
			printf("分数：%d\n",p->score);
		}
		p = p->next;
	}
	printf("查询完毕！\n"); 
}

void search_score(struct Student *head)
{
	int min,max;
	printf("请输入您所要查找的学生的成绩范围：\n");
	printf("最小值：");
	scanf("%d",&min);
	printf("最大值：");
	scanf("%d",&max);
	struct Student *p;
	p = head;
	while (p != NULL)
	{
		if (p->score <= max && p->score >= min)
		{
			printf("学号：%d\n",p->num);
			printf("分数：%d\n",p->score);
		}
		p = p->next;
	}
	printf("查询完毕！\n"); 
}


void search_max_score(struct Student *head)//查找成绩最高分 
{
	int max;
	struct Student *p;
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



struct Student *insert_num(struct Student *head,struct Student *s) //插入学号为 XXXX 的个人信息， s 为待插入结点 
{
	struct Student *p=NULL,*q1=NULL,*q2=NULL;
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

struct Student *create_p()//创建一个结点 p 
{
	printf("正在创建一个新的结点...\n");
	struct Student *p;
	printf("学号：");
	scanf("%d",&p->num);
	printf("分数：");
	scanf("%d",&p->score);
	p->next = NULL;
	printf("创建成功！\n");
	return (p);
}

struct Student *delete_p(struct Student *head)//删除一个结点 
{
	int num;
	printf("您即将删除某位学生的学生信息，请输入该学生的学号：");
	scanf("%d",&num);
	
	struct Student *p1 = NULL,*p2 = NULL;
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
		
		struct Student *head;
		
		if (choice == 1)
		{
			head = create_tail();
		}
		else if (choice == 2)
		{
			struct Student *s;
			s = (struct Student *)malloc(sizeof(struct Student));
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
