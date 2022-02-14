#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	FILE *fp;
	/*�ַ���д����*/ 
	fp = fopen("test1.txt","wt");
	if (fp == NULL)
	{
		printf("error!");
		getchar();
		exit(1);
	}
	fputc('A',fp);//д���һ���ַ� 
	fputc('B',fp);
	fputc('C',fp);
	fclose(fp);
	
	fp = fopen("test1.txt","rt");
	char ch1 = fgetc(fp);//��ȡ��һ���ַ� 
	char ch2 = fgetc(fp);
	char ch3 = fgetc(fp);
	printf("%c%c%c\n",ch1,ch2,ch3);
	fclose(fp);
	
	fp = fopen("test1.txt","at");
	fputc('D',fp);//���ļ�ĩβ׷��һ���ַ� 
	fclose(fp);
	
	fp = fopen("test1.txt","rt");
	char ch = 1;
	while (1)
	{
		ch = fgetc(fp);
		printf("%c",ch);
		if (ch == 'D') break;
	}
	printf("\n");
	fclose(fp);
	
	/*�ַ�����д����*/
	fp = fopen("test2.txt","wt");
	fputs("scu.edu.net",fp);//д��һ���ַ��� 
	fclose(fp);
	
	fp = fopen("test2.txt","rt");
	char str1[20];
	fgets(str1,12,fp);//��ȡһ������Ϊ 11 ���ַ��� 
	printf("%s\n",str1);
	fclose(fp);
	
	/*���ݿ��д����*/
	fp = fopen("test3.txt","wb");//�Զ�������ʽ���ļ���ֻ��д�� 
	float real_array_1[8];
	float r1 = 1.23;
	for (int i=0;i<8;i++)
	{
		real_array_1[i] = r1 * i;
	}
	fwrite(real_array_1,4,8,fp);//д�� 8��ʵ����ÿ��ʵ��ռ 4���ֽ� 
	fclose(fp);
	
	fp = fopen("test3.txt","rb");
	float real_array_2[8];
	fread(real_array_2,4,8,fp);
	for (int i=0;i<8;i++) printf("%.2f ",real_array_2[i]);	
	printf("\n");
	fclose(fp);
	
	/*��ʽ����д����*/
	fp = fopen("test4.txt","wt");
	int num1 = 50;
	float real_num1 = 8.88;
	char array1[5] = "world";
	char ch_1 = 'A';
	fprintf(fp,"%d%c",num1,ch1);
	fprintf(fp,"%s%c%.2f",array1,ch1,real_num1);
	fclose(fp);
	
	fp = fopen("test4.txt","rt");
	int num2;
	char array2[10];
	char ch_2;
	fscanf(fp,"%d%c%s",&num2,&ch_2,array2);
	printf("%d%c%s\n",num2,ch_2,array2);
	fclose(fp);
	
	/*�ļ��������д*/
	fp = fopen("test5.txt","wt+");
	fputs("     ************\n",fp);
	fputs("  ******      ******\n",fp);
	fputs("******          ******\n",fp);
	fputs("******          ******\n",fp);
	fputs("  ******      ******\n",fp);
	fputs("     ************\n",fp);
	rewind(fp);//���ļ�λ��ָ���ƶ����ļ���ʼλ�� 
	char t1[50];
	for (int i = 0;i < 6;i++)
	{
		fgets(t1,50,fp);
		printf("%s",t1);
	}
	fclose(fp);
	
	fp = fopen("test6.txt","wb+");
	fprintf(fp,"%d%s%d",100,"00",1);
	fseek(fp,10L,0);//���ļ�λ��ָ���Ƶ������ļ���10�ֽڵ�λ�� 
	fputs("---",fp);
	fputs("world!",fp);
	fputs("\n---------------------\n",fp);
	fputs("0123456789",fp);
	
	rewind(fp);
	char str_1[10],str_2[6],str_3[10];
	fgets(str_1,11,fp);
	printf("%s\n",str_1);//100001 
	printf("�ļ�λ��ָ��ĵ�ǰλ�ã�%d\n",ftell(fp));//10
	fseek(fp,3L,1);//���ļ�λ��ָ���Ƶ����뵱ǰλ�����3�ֽڵ�λ�� 
	printf("�ļ�λ��ָ��ĵ�ǰλ�ã�%d\n",ftell(fp));//13
	fgets(str_2,7,fp);
	printf("%s\n",str_2);//world!
	fseek(fp,-10L,2);//���ļ�λ��ָ���Ƶ������ļ�ĩβ10�ֽڵ�λ��
	printf("�ļ�λ��ָ��ĵ�ǰλ�ã�%d\n",ftell(fp));
	fgets(str_3,12,fp);
	printf("%s\n",str_3);//0123456789
	 
	if (feof(fp)) printf("�ѵ����ļ�ĩβ��\n");//�ж��Ƿ񵽴��ļ�ĩβ 
	ferror(fp);//����ļ������־���ļ�������־ 
	fclose(fp);
	
	/*�ļ���⺯��*/
	fp = fopen("�����ڵ��ļ�.txt","rb");
	if ((fp == NULL))
	{
		perror("���ļ�ʧ�ܣ�ԭ����");
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	
	
	
	return 0;
}
