#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef int INTERGE;
typedef char NAME[20];//声明 NAME 为字符数组类型，数组长度为 20 
typedef char * STRING;//声明 STRING 是字符指针类型，可以用 STRING 定义变量 
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
	
	NAME xiaomai = "小埋"; 
	printf("名字为：%s\n",xiaomai);
	
	STRING str = "土间埋";
	STRING p_str = str;
	printf("小埋的全名是：%s\n",p_str); 
	
	CHARACTER Alice;
	strcpy(Alice.name,"爱丽丝");
	strcpy(Alice.cv,"茅野爱衣");
	CHARACTER *p;
	p = &Alice;
	printf("Alice 的名字是：%s\n",p->name);
	printf("Alice 的声优是：%s\n",p->cv);
	
	PDATE Date;//定义一个结构体指针 
	Date = (PDATE)malloc(sizeof(DATE));//相当于 (struct Date *)malloc(struct Date)
	Date->year = 2000;
	Date->month = 1;
	Date->day = 1;
	printf("现在的时间是：%d-%d-%d\n",Date->year,Date->month,Date->day);
	free(Date);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
