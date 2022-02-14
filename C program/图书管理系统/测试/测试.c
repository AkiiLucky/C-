#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book
{
	int num;
	char title[128];
	struct Book *next;
} BOOK,*PBOOK;

int main(void)
{
	FILE *fp;
	fp = fopen("abc.txt","wb+");
	
	BOOK *p1 = (BOOK *)calloc(1,sizeof(BOOK));
	BOOK *p2 = (BOOK *)calloc(1,sizeof(BOOK));
	BOOK *p3 = (BOOK *)calloc(1,sizeof(BOOK));
	
	p1->num = 1;
	strcpy(p1->title,"C++");
	//p1->title = "C++";
	
	fwrite(p1,sizeof(BOOK),1,fp);
	fwrite(p1,sizeof(BOOK),1,fp);
	rewind(fp);
	fread(p2,sizeof(BOOK),1,fp);
	fread(p3,sizeof(BOOK),1,fp);
	fclose(fp);
	
	printf("%d %s\n",p2->num,p2->title);
	printf("%d %s\n",p2->num,p2->title);
	
	return 0;
}
