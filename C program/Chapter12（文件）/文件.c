#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	FILE *fp;
	/*字符读写函数*/ 
	fp = fopen("test1.txt","wt");
	if (fp == NULL)
	{
		printf("error!");
		getchar();
		exit(1);
	}
	fputc('A',fp);//写入第一个字符 
	fputc('B',fp);
	fputc('C',fp);
	fclose(fp);
	
	fp = fopen("test1.txt","rt");
	char ch1 = fgetc(fp);//读取第一个字符 
	char ch2 = fgetc(fp);
	char ch3 = fgetc(fp);
	printf("%c%c%c\n",ch1,ch2,ch3);
	fclose(fp);
	
	fp = fopen("test1.txt","at");
	fputc('D',fp);//在文件末尾追加一个字符 
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
	
	/*字符串读写函数*/
	fp = fopen("test2.txt","wt");
	fputs("scu.edu.net",fp);//写入一个字符串 
	fclose(fp);
	
	fp = fopen("test2.txt","rt");
	char str1[20];
	fgets(str1,12,fp);//读取一个长度为 11 的字符串 
	printf("%s\n",str1);
	fclose(fp);
	
	/*数据块读写函数*/
	fp = fopen("test3.txt","wb");//以二进制形式打开文件，只可写入 
	float real_array_1[8];
	float r1 = 1.23;
	for (int i=0;i<8;i++)
	{
		real_array_1[i] = r1 * i;
	}
	fwrite(real_array_1,4,8,fp);//写入 8个实数，每个实数占 4个字节 
	fclose(fp);
	
	fp = fopen("test3.txt","rb");
	float real_array_2[8];
	fread(real_array_2,4,8,fp);
	for (int i=0;i<8;i++) printf("%.2f ",real_array_2[i]);	
	printf("\n");
	fclose(fp);
	
	/*格式化读写函数*/
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
	
	/*文件的随机读写*/
	fp = fopen("test5.txt","wt+");
	fputs("     ************\n",fp);
	fputs("  ******      ******\n",fp);
	fputs("******          ******\n",fp);
	fputs("******          ******\n",fp);
	fputs("  ******      ******\n",fp);
	fputs("     ************\n",fp);
	rewind(fp);//把文件位置指针移动到文件开始位置 
	char t1[50];
	for (int i = 0;i < 6;i++)
	{
		fgets(t1,50,fp);
		printf("%s",t1);
	}
	fclose(fp);
	
	fp = fopen("test6.txt","wb+");
	fprintf(fp,"%d%s%d",100,"00",1);
	fseek(fp,10L,0);//把文件位置指针移到距离文件首10字节的位置 
	fputs("---",fp);
	fputs("world!",fp);
	fputs("\n---------------------\n",fp);
	fputs("0123456789",fp);
	
	rewind(fp);
	char str_1[10],str_2[6],str_3[10];
	fgets(str_1,11,fp);
	printf("%s\n",str_1);//100001 
	printf("文件位置指针的当前位置：%d\n",ftell(fp));//10
	fseek(fp,3L,1);//把文件位置指针移到距离当前位置向后3字节的位置 
	printf("文件位置指针的当前位置：%d\n",ftell(fp));//13
	fgets(str_2,7,fp);
	printf("%s\n",str_2);//world!
	fseek(fp,-10L,2);//把文件位置指针移到距离文件末尾10字节的位置
	printf("文件位置指针的当前位置：%d\n",ftell(fp));
	fgets(str_3,12,fp);
	printf("%s\n",str_3);//0123456789
	 
	if (feof(fp)) printf("已到达文件末尾！\n");//判断是否到达文件末尾 
	ferror(fp);//清除文件出错标志和文件结束标志 
	fclose(fp);
	
	/*文件检测函数*/
	fp = fopen("不存在的文件.txt","rb");
	if ((fp == NULL))
	{
		perror("打开文件失败，原因是");
		exit(EXIT_FAILURE);
	}
	fclose(fp);
	
	
	
	return 0;
}
