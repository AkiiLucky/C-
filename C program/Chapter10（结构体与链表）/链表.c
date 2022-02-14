#include <stdio.h>
#include <stdlib.h>

struct Student 
{
	int num;
	int score;
	struct Student *next;
};

int n;

struct Student *create_head()//(����˳��������˳���෴)
{
	n = 0;
	struct Student *head = NULL;
	struct Student *p;
	
	p = (struct Student *)malloc(sizeof(struct Student));
	printf("�������һ����¼��ѧ��Ϊ 0 ��ʾ����\n");
	printf("ѧ�ţ�");
	scanf("%d",&p->num);
	printf("������");
	scanf("%d",&p->score);
	
	while (p->num != 0)
	{
		printf("��������һ����¼��ѧ��Ϊ 0 ��ʾ����\n");
		n = n+1;
		
		p->next = head;
		head = p;
		
		p = (struct Student *)malloc(sizeof(struct Student));
		printf("ѧ�ţ�");
		scanf("%d",&p->num);
		printf("������");
		scanf("%d",&p->score);
		
	}
	return (head);
}

struct Student *create_tail()//β�巨�������� (����˳��������˳��һ��)
{
	printf("���ڽ���һ���µ�����...\n");
	n = 0;
	struct Student *head = NULL;
	struct Student *p = NULL;
	struct Student *tail; 
	
	tail = head;
	
	p = (struct Student *)malloc(sizeof(struct Student));
	printf("�������һ����¼��ѧ��Ϊ 0 ��ʾ����\n");
	printf("ѧ�ţ�");
	scanf("%d",&p->num);
	if (p->num == 0) 
	{
		printf("������ϣ�\n");
		free(p);
		return (head);
	}
	printf("������");
	scanf("%d",&p->score);
	p->next = NULL;
	
	while (p->num != 0)
	{
		printf("��������һ����¼��ѧ��Ϊ 0 ��ʾ����\n");
		n = n+1;
		
		if (n == 1) head = p;
		else tail->next = p;	
		tail = p;
		
		p = (struct Student *)malloc(sizeof(struct Student));
		printf("ѧ�ţ�");
		scanf("%d",&p->num);
		if (p->num == 0) 
		{
			printf("������ϣ�\n");
			free(p);
			break;
		}
		printf("������");
		scanf("%d",&p->score);
		p->next = NULL;
	}
	tail->next = NULL;
	return (head);
}

void putout(struct Student *head)//������� 
{
	
	if (head == NULL) 
	{
		printf("����Ϊ�գ�\n");
	}
	else
	{
		printf("==============ѧ���ɼ�=================\n"); 
		struct Student *p = NULL;
		p = head;
		while (p != NULL)
		{
			printf("ѧ�ţ�%d\n",p->num);
			printf("������%d\n",p->score);
			p = p->next;
		}
		printf("==============������=================\n");
	}
	
}

void search_num(struct Student *head)
{
	int num = 0;
	printf("����������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf("%d",&num);
	struct Student *p;
	p = head;
	while (p != NULL)
	{
		if (p->num == num)
		{
			printf("ѧ�ţ�%d\n",p->num);
			printf("������%d\n",p->score);
		}
		p = p->next;
	}
	printf("��ѯ��ϣ�\n"); 
}

void search_score(struct Student *head)
{
	int min,max;
	printf("����������Ҫ���ҵ�ѧ���ĳɼ���Χ��\n");
	printf("��Сֵ��");
	scanf("%d",&min);
	printf("���ֵ��");
	scanf("%d",&max);
	struct Student *p;
	p = head;
	while (p != NULL)
	{
		if (p->score <= max && p->score >= min)
		{
			printf("ѧ�ţ�%d\n",p->num);
			printf("������%d\n",p->score);
		}
		p = p->next;
	}
	printf("��ѯ��ϣ�\n"); 
}


void search_max_score(struct Student *head)//���ҳɼ���߷� 
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
	printf("��߳ɼ�Ϊ��%d\n",max);
}



struct Student *insert_num(struct Student *head,struct Student *s) //����ѧ��Ϊ XXXX �ĸ�����Ϣ�� s Ϊ�������� 
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
	printf("==============�������=================\n");
	return (head);
}

struct Student *create_p()//����һ����� p 
{
	printf("���ڴ���һ���µĽ��...\n");
	struct Student *p;
	printf("ѧ�ţ�");
	scanf("%d",&p->num);
	printf("������");
	scanf("%d",&p->score);
	p->next = NULL;
	printf("�����ɹ���\n");
	return (p);
}

struct Student *delete_p(struct Student *head)//ɾ��һ����� 
{
	int num;
	printf("������ɾ��ĳλѧ����ѧ����Ϣ���������ѧ����ѧ�ţ�");
	scanf("%d",&num);
	
	struct Student *p1 = NULL,*p2 = NULL;
	p1 = head;
	if (head == NULL) printf("����Ϊ�գ�");
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
			printf("δ�ҵ�ƥ���\n");
		}	
	}
	return (head);
}

int main(void)
{
	
	int choice = 1;
	
	while (1)
	{
		printf("1----��������\n");
		printf("2----������\n");
		printf("3----ɾ�����\n");
		printf("4----���ҽ��\n");
		printf("5----�������\n");
		printf("0----�˳�\n");
		printf("��Ҫִ�е����ݣ������� 0-5 ֮������֣���");
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
			printf("1----��ѧ�Ų���\n");
			printf("2----���ɼ�����\n");
			printf("3----�������ɼ�\n");
			printf("��������ҷ�ʽ��");
			int cho = 0;
			scanf("%d",&cho);
			switch(cho)
			{
				case 1:search_num(head);break;
				case 2:search_score(head);break;
				case 3:search_max_score(head);break;
				default:printf("��������!\n");
			}
			
		}
		else if (choice == 5)
		{
			putout(head);
		}
		else if (choice == 0) 
		{
			printf("�����ѽ�����");
			break;
		}
		else 
		{
			printf("������������������!\n");
		}
		printf("\n");
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
