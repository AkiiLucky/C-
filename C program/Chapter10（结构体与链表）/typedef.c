#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef int INTERGE;
typedef char NAME[20];//���� NAME Ϊ�ַ��������ͣ����鳤��Ϊ 20 
typedef char * STRING;//���� STRING ���ַ�ָ�����ͣ������� STRING ������� 
typedef struct
{
	char name[20];
	char cv[20];
	int age;
} CHARACTER;
typedef struct Date
{
	int year;
	int month;
	int day;
} DATE,* PDATE;// DATE == struct Date, PDATE == (struct Date *)


int main(void)
{	
	INTERGE a = 123;
	printf("a = %d,sizeof(a) = %d\n",a,sizeof(a));
	
	NAME xiaomai = "С��"; 
	printf("����Ϊ��%s\n",xiaomai);
	
	STRING str = "������";
	STRING p_str = str;
	printf("С���ȫ���ǣ�%s\n",p_str); 
	
	CHARACTER Alice;
	strcpy(Alice.name,"����˿");
	strcpy(Alice.cv,"éҰ����");
	CHARACTER *p;
	p = &Alice;
	printf("Alice �������ǣ�%s\n",p->name);
	printf("Alice �������ǣ�%s\n",p->cv);
	
	PDATE Date;//����һ���ṹ��ָ�� 
	Date = (PDATE)malloc(sizeof(DATE));//�൱�� (struct Date *)malloc(struct Date)
	Date->year = 2000;
	Date->month = 1;
	Date->day = 1;
	printf("���ڵ�ʱ���ǣ�%d-%d-%d\n",Date->year,Date->month,Date->day);
	free(Date);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
