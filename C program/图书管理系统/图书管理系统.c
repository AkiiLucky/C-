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
	int number;//ͼ���� 
	int quantity;//ͼ������ 
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
	printf("*-***************  ͼ����Ϣ����ϵͳ  ***************-*\n");
	printf("*-****************                 *****************-*\n");
	printf("*-**************************************************-*\n");
	printf("*----------------------------------------------------*\n");
	printf("******************************************************\n");
	
	BOOK *head = NULL;
	int choice = 1;
	
	while (1)
	{
		printf("1----�����µ����ݿ��ļ�\n");
		printf("2----���������ݿ��ļ�\n");
		printf("3----����ͼ����Ϣ\n");
		printf("4----ɾ��ͼ����Ϣ\n");
		printf("5----��ѯͼ����Ϣ\n");
		printf("6----�޸�ͼ����Ϣ\n");
		printf("7----���ͼ����Ϣ\n");
		printf("8----����ͼ����Ϣ\n");
		printf("0----�˳�ϵͳ\n");
		printf("��Ҫִ�е����ݣ������� 0-5 ֮������֣���");
		scanf("%d",&choice); 
		
		if (choice == 1)
		{
			head = create_books(head);
			while (1)
			{
				printf("�Ƿ񱣴��ļ�����1 �����ǣ�0 �����: ");
				int i = -1;
				scanf("%d",&i);
				if (i == 1) 
				{
					head = save_file(head);
					break;
				}
				else if (i == 0) break;
				else printf("�����������������룡\n");
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
			printf("1 ����ͼ���Ų��ң�2 ����ͼ�������ң�����������������ʽ: ");
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
				else printf("�����������������룡\n");
			}
		}
		else if (choice == 5)
		{
			printf("1 ����ͼ���Ų��ң�2 ����ͼ�������ң�����������������ʽ: ");
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
				else printf("�����������������룡\n");
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
			printf("�����������������룡\n");
		}
	}
	return 0;
}

BOOK *create_books(BOOK *head)
{
	printf("���ڽ���һ���µ��ļ�...\n");
	n = 0;
	BOOK *p = NULL;
	BOOK *tail = NULL; 
	
	tail = head;
	
	p = (BOOK *)malloc(sizeof(BOOK));
	printf("�������һ�������Ϣ��ͼ����Ϊ -1 ��ʾ������\n");
	printf("ͼ���ţ�");
	scanf("%d",&p->number);
	if (p->number == -1) 
	{
		printf("������ϣ�\n");
		free(p);
		return (head);
	}
	printf("ͼ����⣺");
	scanf("%s",p->title);
	printf("ͼ�����ߣ�");
	scanf("%s",p->auther);
	printf("�������ڣ�");
	scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
	printf("���浥λ��");
	scanf("%s",p->publisher);
	printf("ͼ�鶨�ۣ�");
	scanf("%f",&p->price);
	printf("ͼ��������");
	scanf("%d",&p->quantity);
	p->next = NULL;
	 
	while (p->number != -1)
	{
		fflush(stdin);
		printf("��������һ�������Ϣ��ͼ����Ϊ -1 ��ʾ������\n");
		n = n+1;
		
		if (n == 1) head = p;
		else tail->next = p;	
		tail = p;
		
		p = (BOOK *)malloc(sizeof(BOOK));
		
		printf("ͼ���ţ�");
		scanf("%d",&p->number);
		
		if (p->number == -1) 
		{
			printf("������ϣ�\n");
			free(p);
			break;
		}
		printf("ͼ����⣺");
		scanf("%s",p->title);
		printf("ͼ�����ߣ�");
		scanf("%s",p->auther);
		printf("�������ڣ�");
		scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
		printf("���浥λ��");
		scanf("%s",p->publisher);
		printf("ͼ�鶨�ۣ�");
		scanf("%f",&p->price);
		printf("ͼ��������");
	    scanf("%d",&p->quantity);
		p->next = NULL;
	}
	tail->next = NULL;
	return (head);
}

BOOK *output_books(BOOK *head)
{
	printf("------------------ͼ������---------------------\n"); 
	BOOK *p = head;
	int i = 1;
	while (p != NULL)
	{
		output_book(p);
		printf("\n");
		p = p->next;
	}
	printf("------------------�������---------------------\n"); 
	return (head);
}

BOOK *output_book(BOOK *p)
{
	printf("ͼ���ţ�%d\n",p->number);
	printf("ͼ����⣺%s\n",p->title);
	printf("ͼ�����ߣ�%s\n",p->auther);
	printf("�������ڣ�%d-%d-%d\n",p->publish_date.year,p->publish_date.month,p->publish_date.day);
	printf("���浥λ��%s\n",p->publisher);
	printf("ͼ�鶨�ۣ�%.2f\n",p->price);
	printf("ͼ��������%d\n",p->quantity);
}


BOOK *save_file(BOOK *head)
{
	BOOK *p = head;
	
	FILE *fp = fopen("booklist_1.txt","wb+");
	if (fp == NULL)
	{
		perror("�ļ�����ʧ��!!! ԭ����");
		exit(1);
	}
	rewind(fp);
	while (p != NULL)
	{
		fwrite(p,sizeof(BOOK),1,fp);
		p = p->next;
	}
	printf("�ļ��ѱ�������ǰ�ļ��У�\n");
	fclose(fp);
	return (head);
}

BOOK *open_file(BOOK *head)
{
	FILE *fp = fopen("booklist_1.txt","rb+");
	if (fp == NULL)
	{
		perror("�ļ���ʧ��!!! ԭ����");
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
	printf("�ļ��Ѵ򿪣�\n");
	return (head);
}

BOOK *search_number(BOOK *head)
{
	if (head == NULL)
	{
		printf("���Ϊ�գ�\n");
		return (head);
	}
	int number;
	printf("��������Ҫ���ҵ�ͼ���ţ�");
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
	printf("������ϣ��� %d �����\n",i);
	return (head);
}

BOOK *search_title(BOOK *head)
{
	if (head == NULL)
	{
		printf("���Ϊ�գ�\n");
		return (head);
	}
	char title[128];
	printf("��������Ҫ���ҵ�ͼ����⣺");
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
	printf("������ϣ��� %d �����\n",i);
	return (head);
}

BOOK *delete_book_number(BOOK *head)
{
	int count = 0;
	if (head == NULL)
	{
		printf("���Ϊ�գ�\n");
		return (head);
	}
	BOOK *p = head,*q = head; 
	int number;
	printf("������ִ��ɾ����������������鼮�ı�ţ�");
	scanf("%d",&number);
	if (head->number == number) 
	{
		head = p->next;
		free(p);
		printf("���Ϊ %d ���鼮��Ϣ�ѱ�ɾ����\n",number);
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
	if (count == 0) printf("�����û�д�ͼ�����Ϣ��\n");
	else printf("���Ϊ %d ���鼮��Ϣ�ѱ�ɾ����\n",number);
	return (head);
}

BOOK *delete_book_title(BOOK *head)
{
	int count = 0;
	if (head == NULL)
	{
		printf("���Ϊ�գ�\n");
		return (head);
	}
	BOOK *p = head,*q = head; 
	char title[128];
	printf("������ִ��ɾ���������������ͼ��ı��⣺");
	scanf("%s",title);
	if (!strcmp(head->title,title)) 
	{
		head = p->next;
		free(p);
		printf("����Ϊ \"%s\" ��ͼ����Ϣ�ѱ�ɾ����\n",title);
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
	if (count == 0) printf("�����û�д�ͼ�����Ϣ��\n");
	else printf("����Ϊ \"%s\" ��ͼ����Ϣ�ѱ�ɾ����\n",title);
	return (head);
}


BOOK *add_book(BOOK *head)
{
	if (head == NULL)
	{
		printf("���Ϊ�գ�\n");
		return (head);
	}
	printf("����ִ�����Ӳ�����������ͼ�����Ϣ��\n");
	BOOK *p;
	p = (BOOK *)malloc(sizeof(BOOK));
	printf("ͼ���ţ�");
	scanf("%d",&p->number);
	printf("ͼ����⣺");
	scanf("%s",p->title);
	printf("ͼ�����ߣ�");
	scanf("%s",p->auther);
	printf("�������ڣ�");
	scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
	printf("���浥λ��");
	scanf("%s",p->publisher);
	printf("ͼ�鶨�ۣ�");
	scanf("%f",&p->price);
	printf("ͼ��������");
	scanf("%d",&p->quantity);
	p->next = head;
	head = p;
	printf("�鼮��Ϣ��¼�뵽��⣡\n");
	return (head);
}

BOOK *change_book(BOOK *head)
{
	if (head == NULL)
	{
		printf("���Ϊ�գ�\n");
		return (head);
	}
	printf("�����޸��鼮��Ϣ...\n");
	BOOK *p = head;
	int number;
	printf("��������Ҫ�޸ĵ�ͼ���ţ�");
	scanf("%d",&number);
	int i = 0;
	while (p != NULL)
	{
		if (p->number == number)
		{
		printf("ͼ������޸�Ϊ��");
		scanf("%s",p->title);
		printf("ͼ�������޸�Ϊ��");
		scanf("%s",p->auther);
		printf("���������޸�Ϊ��");
		scanf("%d-%d-%d",&p->publish_date.year,&p->publish_date.month,&p->publish_date.day);
		printf("���浥λ�޸�Ϊ��");
		scanf("%s",p->publisher);
		printf("ͼ�鶨���޸�Ϊ��");
		scanf("%f",&p->price);
		printf("ͼ�������޸�Ϊ��");
	    scanf("%d",&p->quantity);
		printf("�鼮��Ϣ���޸���ϣ�\n");
		i++;
		break;
		}
		p = p->next;
	}
	if (i == 0) printf("��Ч��ͼ���ţ�\n");
	return (head);
}



























/*

void search_max_score(BOOK *head)//���ҳɼ���߷� 
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
	printf("��߳ɼ�Ϊ��%d\n",max);
}



BOOK *insert_num(BOOK *head,BOOK *s) //����ѧ��Ϊ XXXX �ĸ�����Ϣ�� s Ϊ�������� 
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
	printf("==============�������=================\n");
	return (head);
}

BOOK *create_p()//����һ����� p 
{
	printf("���ڴ���һ���µĽ��...\n");
	BOOK *p;
	printf("ѧ�ţ�");
	scanf("%d",&p->num);
	printf("������");
	scanf("%d",&p->score);
	p->next = NULL;
	printf("�����ɹ���\n");
	return (p);
}

BOOK *delete_p(BOOK *head)//ɾ��һ����� 
{
	int num;
	printf("������ɾ��ĳλѧ����ѧ����Ϣ���������ѧ����ѧ�ţ�");
	scanf("%d",&num);
	
	BOOK *p1 = NULL,*p2 = NULL;
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
*/
