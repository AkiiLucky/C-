#include <stdio.h>

char *getcap(cap)//指针函数的返回值是指针变量，可以返回字符串，但不能返回局部变量的指针 
{
	switch(cap)
	{
		case 'A':return "Apple";break;
		case 'B':return "Banana";break;
		case 'C':return "Cat";break;
		case 'D':return "Doctor";break;
		default:return "None";
	}
}
int main()
{
	char input;
	scanf("%c",&input);
	printf("%s\n",getcap(input));

	return 0;
	
} 
