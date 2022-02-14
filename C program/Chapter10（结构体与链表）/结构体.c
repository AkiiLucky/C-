#include <stdio.h>

struct Date
{
	int year;
	int month;
	int day;
};

struct Character
{
	char name[10];
	char sex[2];
	struct Date birthday;
	int height;
	char hair_color[10];
	char cv[10];
	
};

struct Character xiaomai=
	{
		"土间埋",
		"女",
		{2000,9,26},
		160,
		"亚麻色",
		"田中爱美"
		
	};

struct Snack
{
	char name[20];
	float price;
}snack[3] = {{"可乐",3.0},{"薯片",4.5},{.price=5.0,.name="辣条"}};



int main()
{
	printf("%s的声优是%s\n",xiaomai.name,xiaomai.cv);
	printf("%s的生日是%d月%d日\n",xiaomai.name,xiaomai.birthday.month,xiaomai.birthday.day);
	for (int i;i < 3;i++) printf("%s的价格是%.2f元\n",snack[i].name,snack[i].price);
	struct Character *p;
	p = &xiaomai;
	printf("%s的发色是%s\n",p->name,p->hair_color);
	printf("%s的声优是%s\n",(*p).name,(*p).cv);
	
	
	return 0;
}
