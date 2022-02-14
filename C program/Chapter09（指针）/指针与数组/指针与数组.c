#include<stdio.h>
#include<string.h>

int main()
{
	char str[128];
	printf("请输入一串字符：\n"); 
	scanf("%s\0",&str);
	printf("您输入的字符是：%s\n",str);
	
	char a[16] = "wecome";
	//数组的地址和数组第一个元素的地址相同 
	printf("字符数组 a 的地址：%p\n",&a);//000000000062FD90
	printf("字符数组 a 的第一个元素 a[0] 的地址：%p\n",&a[0]);//000000000062FD90
	
	int b[5] = {1,2,3,4,5};
	int *pb = &b[0];// pb 指向数组的第一个元素的地址，等价于 int *pb = b;
	printf("*pb = %d, *(pb+1) = %d, *(pb+2) = %d\n",*pb,*(pb+1),*(pb+2));//*pb = 1, *(pb+1) = 2, *(pb+2) = 3
	
	char *pc = "I am xiaomai!";//pc指针指向字符数组 "I am xiaomai!"
	int i,length;
	length = strlen(pc);
	for(i=0;i<length;i++)
	{
		printf("%c",*(pc+i));
	}
	printf("\n");
	for(i=0;i<length;i++)
	{
		printf("%c",pc[i]);//*(pc+i)与pc[i]等价 
	}
	printf("\n");	
	
	//数组名(常量)只是一个地址，不可改变；指针(变量)是一个左值，可以改变 
	char d[20] = "I am xiaomai!";
	char *pd = d;
	int count;
	while(*pd != '\0')
	{
		count++;
		pd++;
	}
	printf("该字符串一共有%d个字符\n",count);
	
	//指针型数组：数组中每一个元素都是一个指针变量
	char *pe[5] = {"一花","二乃","三玖","四叶","五月"};
	int k;
	for(k = 0; k < 5; k++) 
	{
		printf("%s\n",pe[k]);
	}
	
	//数组型指针：一个指向一个数组的指针
	int nums[5] = {1,2,3,4,5};
	int (*p_nums)[5] = &nums;
	int n;
	for(n=0;n<5;n++)
	{
		printf("%d\n",*(*p_nums+n));//*p是一个地址 
	}
	
	//指针与二维数组 
	int array[4][5];
	int i1,i2,i3=0,i4,i5;
	for(i1=0;i1<4;i1++)
	{
		for(i2=0;i2<5;i2++)
		{
			array[i1][i2] = i3++;
		}
	}
	for(i4=0;i4<4;i4++)
	{
		for(i5=0;i5<5;i5++)
		{
			printf("%d ",*(*(array+i4)+i5));//*(*(array+i4)+i5)) == array[i4][i5] 这个是解引用，相当于把这个值解出来 
		}
		printf("\n"); 
	}
	printf("array[1]的地址：%p\n",array[1]);//000000000062FC74
	printf("array+1的地址：%p\n",array+1);//000000000062FC74    array+i 为行指针，指向二维数组的第 i行 
	printf("*(array+1)的地址：%p\n",*(array+1));//000000000062FC74  *(array+i) 为列指针，指向二位数组的第 i行第0列  *(array+i) == array[i] 
	
	printf("array[1][1]的地址：%p\n",&array[1][1]);//000000000062FC78 
	printf("*(array+1)的地址：%p\n",*(array+1)+1);//000000000062FC78  *(array+1)+1指向二位数组的第1行第1列 （这里是从0开始算的） 
	
	printf("array[1][1]的值：%d\n",array[1][1]);//6 
	printf("*(*(array+1)+1)的值：%d\n",*(*(array+1)+1));//6 
	
	//数组指针与二维数组
	int arr[2][3] = {{0,1,2},{3,4,5}};
	int (*p_arr)[3] = arr;//数组指针的跨度为 sizeof(int) * 3
	
	printf("%d\n",**(p_arr+1));//3
	printf("%d\n",**(arr+1));//3
	printf("%d\n",arr[1][0]);//3
	
	printf("%d\n",*(*(p_arr+1)+2));//5
	printf("%d\n",*(*(arr+1)+2));//5
	printf("%d\n",arr[1][2]);//5
	
	
	
	return 0;
}
