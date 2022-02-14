#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	//malloc 申请动态内存空间 (此函数在头文件<stdlib.h>中)
	int *ptr;
	ptr = (int *)malloc(sizeof(int));
	if (ptr == NULL)  
	{
		printf("分配内存失败！");
		exit(1);
	} 
	else 
	{
		printf("分配内存成功！\n");
	
	}
	printf("请输入一个整数：");
	scanf("%d",ptr);
	printf("您输入的整数是%d\n",*ptr); 
	free(ptr);//释放 ptr 所指向的内存空间，但 ptr 所指向的地址不变 
	
	//申请一段连续的内存空间 
	int *ptr1 = NULL;
	int num;
	printf("请输入录入整数的个数："); 
	scanf("%d",&num);
	ptr1 = (int *)malloc(num * sizeof(int));
	if (ptr1 == NULL) 
	{
		printf("分配内存失败！");
		exit(1);
	}
	memset(ptr1,0,num * sizeof(int));//将申请的内存空间存放的值都初始化为 0 (此函数在头文件<string.h>中)
	printf("初始化的值为：");
	for (int i=0;i<num;i++)
	{
		printf("%d ",ptr1[i]);
	}
	printf("\n");
	for (int i=0;i<num;i++)
	{
		printf("请录入第%d个整数：",i+1);
		scanf("%d",&ptr1[i]);
	}
	printf("您录入的整数是：");
	for (int i=0;i<num;i++)
	{
		printf("%d ",ptr1[i]);
	}
	printf("\n");
	free(ptr1);
	
	//calloc 申请一段已初始化的内存空间
	int *ptr2 = NULL;
	ptr2 = (int *)calloc(8,sizeof(int));//申请 8 个存放整型变量的内存空间，并初始化为 0 
	printf("初始化的值为：");
	for (int i=0;i<8;i++)
	{
		printf("%d ",ptr2[i]);
	}
	printf("\n");
	free(ptr2);
	
	//realloc 修改ptr指向的内存空间的大小
	int *ptr_1 = NULL;
	int n = 1;
	int i = 0;

	printf("请录入任意个整数，当录入-1时代表录入停止\n");
	while (i < n)
	{
		ptr_1 = (int *)realloc(ptr_1,n * sizeof(int));
		if (ptr_1 == NULL) 
		{
			printf("内存空间不足，分配内存失败！"); 
			exit(1);
		} 
		scanf("%d",&ptr_1[i]);
		if (ptr_1[i] == -1) 
		{
			printf("录入完毕！");
			break;
		}
		n++;
		i++;
	}
	printf("您录入的整数是：");
	for (int i=0;i<n-1;i++)
	{
		printf("%d ",ptr_1[i]);
	}
	printf("\n");
	free(ptr_1);
	
	return 0;
}
