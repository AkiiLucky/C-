#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	//malloc ���붯̬�ڴ�ռ� (�˺�����ͷ�ļ�<stdlib.h>��)
	int *ptr;
	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)  
	{
		printf("�����ڴ�ʧ�ܣ�");
		exit(1);
	} 
	else 
	{
		printf("�����ڴ�ɹ���\n");
	
	}
	printf("������һ��������");
	scanf("%d",ptr);
	printf("�������������%d\n",*ptr); 
	free(ptr);//�ͷ� ptr ��ָ����ڴ�ռ䣬�� ptr ��ָ��ĵ�ַ���� 
	
	//����һ���������ڴ�ռ� 
	int *ptr1 = NULL;
	int num;
	printf("������¼�������ĸ�����"); 
	scanf("%d",&num);
	ptr1 = (int *)malloc(num * sizeof(int));
	if (ptr1 == NULL) 
	{
		printf("�����ڴ�ʧ�ܣ�");
		exit(1);
	}
	memset(ptr1,0,num * sizeof(int));//��������ڴ�ռ��ŵ�ֵ����ʼ��Ϊ 0 (�˺�����ͷ�ļ�<string.h>��)
	printf("��ʼ����ֵΪ��");
	for (int i=0;i<num;i++)
	{
		printf("%d ",ptr1[i]);
	}
	printf("\n");
	for (int i=0;i<num;i++)
	{
		printf("��¼���%d��������",i+1);
		scanf("%d",&ptr1[i]);
	}
	printf("��¼��������ǣ�");
	for (int i=0;i<num;i++)
	{
		printf("%d ",ptr1[i]);
	}
	printf("\n");
	free(ptr1);
	
	//calloc ����һ���ѳ�ʼ�����ڴ�ռ�
	int *ptr2 = NULL;
	ptr2 = (int *)calloc(8,sizeof(int));//���� 8 ��������ͱ������ڴ�ռ䣬����ʼ��Ϊ 0 
	printf("��ʼ����ֵΪ��");
	for (int i=0;i<8;i++)
	{
		printf("%d ",ptr2[i]);
	}
	printf("\n");
	free(ptr2);
	
	//realloc �޸�ptrָ����ڴ�ռ�Ĵ�С
	int *ptr_1 = NULL;
	int n = 1;
	int i = 0;

	printf("��¼���������������¼��-1ʱ����¼��ֹͣ\n");
	while (i < n)
	{
		ptr_1 = (int *)realloc(ptr_1,n * sizeof(int));
		if (ptr_1 == NULL) 
		{
			printf("�ڴ�ռ䲻�㣬�����ڴ�ʧ�ܣ�"); 
			exit(1);
		} 
		scanf("%d",&ptr_1[i]);
		if (ptr_1[i] == -1) 
		{
			printf("¼����ϣ�");
			break;
		}
		n++;
		i++;
	}
	printf("��¼��������ǣ�");
	for (int i=0;i<n-1;i++)
	{
		printf("%d ",ptr_1[i]);
	}
	printf("\n");
	free(ptr_1);
	
	return 0;
}
