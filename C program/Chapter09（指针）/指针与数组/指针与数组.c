#include<stdio.h>
#include<string.h>

int main()
{
	char str[128];
	printf("������һ���ַ���\n"); 
	scanf("%s\0",&str);
	printf("��������ַ��ǣ�%s\n",str);
	
	char a[16] = "wecome";
	//����ĵ�ַ�������һ��Ԫ�صĵ�ַ��ͬ 
	printf("�ַ����� a �ĵ�ַ��%p\n",&a);//000000000062FD90
	printf("�ַ����� a �ĵ�һ��Ԫ�� a[0] �ĵ�ַ��%p\n",&a[0]);//000000000062FD90
	
	int b[5] = {1,2,3,4,5};
	int *pb = &b[0];// pb ָ������ĵ�һ��Ԫ�صĵ�ַ���ȼ��� int *pb = b;
	printf("*pb = %d, *(pb+1) = %d, *(pb+2) = %d\n",*pb,*(pb+1),*(pb+2));//*pb = 1, *(pb+1) = 2, *(pb+2) = 3
	
	char *pc = "I am xiaomai!";//pcָ��ָ���ַ����� "I am xiaomai!"
	int i,length;
	length = strlen(pc);
	for(i=0;i<length;i++)
	{
		printf("%c",*(pc+i));
	}
	printf("\n");
	for(i=0;i<length;i++)
	{
		printf("%c",pc[i]);//*(pc+i)��pc[i]�ȼ� 
	}
	printf("\n");	
	
	//������(����)ֻ��һ����ַ�����ɸı䣻ָ��(����)��һ����ֵ�����Ըı� 
	char d[20] = "I am xiaomai!";
	char *pd = d;
	int count;
	while(*pd != '\0')
	{
		count++;
		pd++;
	}
	printf("���ַ���һ����%d���ַ�\n",count);
	
	//ָ�������飺������ÿһ��Ԫ�ض���һ��ָ�����
	char *pe[5] = {"һ��","����","����","��Ҷ","����"};
	int k;
	for(k = 0; k < 5; k++) 
	{
		printf("%s\n",pe[k]);
	}
	
	//������ָ�룺һ��ָ��һ�������ָ��
	int nums[5] = {1,2,3,4,5};
	int (*p_nums)[5] = &nums;
	int n;
	for(n=0;n<5;n++)
	{
		printf("%d\n",*(*p_nums+n));//*p��һ����ַ 
	}
	
	//ָ�����ά���� 
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
			printf("%d ",*(*(array+i4)+i5));//*(*(array+i4)+i5)) == array[i4][i5] ����ǽ����ã��൱�ڰ����ֵ����� 
		}
		printf("\n"); 
	}
	printf("array[1]�ĵ�ַ��%p\n",array[1]);//000000000062FC74
	printf("array+1�ĵ�ַ��%p\n",array+1);//000000000062FC74    array+i Ϊ��ָ�룬ָ���ά����ĵ� i�� 
	printf("*(array+1)�ĵ�ַ��%p\n",*(array+1));//000000000062FC74  *(array+i) Ϊ��ָ�룬ָ���λ����ĵ� i�е�0��  *(array+i) == array[i] 
	
	printf("array[1][1]�ĵ�ַ��%p\n",&array[1][1]);//000000000062FC78 
	printf("*(array+1)�ĵ�ַ��%p\n",*(array+1)+1);//000000000062FC78  *(array+1)+1ָ���λ����ĵ�1�е�1�� �������Ǵ�0��ʼ��ģ� 
	
	printf("array[1][1]��ֵ��%d\n",array[1][1]);//6 
	printf("*(*(array+1)+1)��ֵ��%d\n",*(*(array+1)+1));//6 
	
	//����ָ�����ά����
	int arr[2][3] = {{0,1,2},{3,4,5}};
	int (*p_arr)[3] = arr;//����ָ��Ŀ��Ϊ sizeof(int) * 3
	
	printf("%d\n",**(p_arr+1));//3
	printf("%d\n",**(arr+1));//3
	printf("%d\n",arr[1][0]);//3
	
	printf("%d\n",*(*(p_arr+1)+2));//5
	printf("%d\n",*(*(arr+1)+2));//5
	printf("%d\n",arr[1][2]);//5
	
	
	
	return 0;
}
