#include <stdio.h>

char *getcap(cap)//ָ�뺯���ķ���ֵ��ָ����������Է����ַ����������ܷ��ؾֲ�������ָ�� 
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
