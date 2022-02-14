#include <stdio.h>
#include <time.h>

void print_color(void)
{
	enum Color {red,green,blue};
	enum Color RGB;
	for (RGB = red;RGB <= blue;RGB++)
	{
		printf("RGB is %d,",RGB);//RGB is 0,RGB is 1,RGB is 2,
	}
	printf("\n");
}

void print_level(void)
{
	enum Level {very_easy,easy,normal,hard = 10,very_hard};
	enum Level level;
	printf("level is %d\n",very_easy);//level is 0
	printf("level is %d\n",easy);     //level is 1
	printf("level is %d\n",normal);   //level is 2
	printf("level is %d\n",hard);     //level is 10
	printf("level is %d\n",very_hard);//level is 11
}

int main(void)
{
	enum Weekday {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};
	enum Weekday today;
	
	struct tm *p;
	time_t t;
	time(&t);
	p = localtime(&t);
	today = p->tm_wday;
	
	switch(today)
	{
		case Monday:
		case Tuesday:
		case Wednesday:
		case Thursday:	
		case Friday:
			printf("¸É»î£¡T_T\n");
			break;
		case Saturday:
		case Sunday:
			printf("ÐÝÏ¢£¡^_^\n");
			break;
			
	}
	
	print_color();
	print_level();
	
	return 0;
}
