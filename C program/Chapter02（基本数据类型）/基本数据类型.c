#include<stdio.h>

int main()
{
	printf("Hello world!\n");
	printf("abc\tabc\n");
	
	int a=100;
	printf("%d\n",a);
	float b=12.58;
	float c=b*2;
	printf("%.2f\n",c);
	printf("a=%d,b=%.2f,c=%.2f\n",a,b,c);
	
	char d[]="����С��";
	char f='A';
	printf("��ã�%c\n",f);
	printf("%s\n","����С��");
	printf("%s\n",d);

	char ch1='A',ch2,ch3,ch4='8',ch5;
	ch2=ch1+1;
	printf("%c\n",ch2);//B
	ch3=ch1+32;
	printf("%c\n",ch3);//a
	ch4=ch4-'0';//���ַ�'8'ת��Ϊ����8 
	printf("%d\n",ch4);
	ch5='0'+6;//������6ת��Ϊ�ַ�'6'
	printf("%c\n",ch5);
	
	int num1=3,num2=3,num3,num4;
	num3=num1++;
	num4=++num2;
	printf("%d %d\n",num3,num4);//num3=3,num4=4   num++�����ȸ�ֵ��������++num������������ֵ
	
	int a1=3,a2=4;
	printf("%d\n",(a1,a2));//4   �� a2 ��ֵ���� %d 
	
	int b1=3,b2=4,max;
	max = b1 > b2 ? b1 : b2;//��� b1>b2 Ϊ�棬��� b1 ��ֵ�� max ,���b1>b2Ϊ�٣���� b2 ��ֵ�� max
	printf("%d\n",max);//4  
	
	int c1=3,c2=4;
	printf("%d\n",1 < 2);//1  ������ 
	printf("%d\n",c1 > c2);//0 ����� 
	printf("%d\n",c1 > c2 && 1 < 2);//0
	printf("%d\n",c1 > c2 || 1 < 2);//1
	printf("%d\n",!0);//1
	printf("%d\n",c1 != 1);//1
	
	
	//�˽��� (��0��ͷ)  �� 024561 
	//ʮ������ (��0x��ͷ) �� 0x5623 
	
	//-1�Ĳ�����1111111111
	//float �ܱ�ʾ6-7λ��Ч���� 
	//double �ܱ�ʾ15-16λ��Ч���� 
	return 0;
}
