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
		"������",
		"Ů",
		{2000,9,26},
		160,
		"����ɫ",
		"���а���"
		
	};

struct Snack
{
	char name[20];
	float price;
}snack[3] = {{"����",3.0},{"��Ƭ",4.5},{.price=5.0,.name="����"}};



int main()
{
	printf("%s��������%s\n",xiaomai.name,xiaomai.cv);
	printf("%s��������%d��%d��\n",xiaomai.name,xiaomai.birthday.month,xiaomai.birthday.day);
	for (int i;i < 3;i++) printf("%s�ļ۸���%.2fԪ\n",snack[i].name,snack[i].price);
	struct Character *p;
	p = &xiaomai;
	printf("%s�ķ�ɫ��%s\n",p->name,p->hair_color);
	printf("%s��������%s\n",(*p).name,(*p).cv);
	
	
	return 0;
}
