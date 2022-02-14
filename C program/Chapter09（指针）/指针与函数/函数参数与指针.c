#include <stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void get_arr(int c[10])//传进去的是地址 
{
	int i;
	c[5] = 520;
	for(i=0;i<10;i++) printf("a[%d] = %d ",i,c[i]);
	printf("\n");
	printf("%d\n",sizeof(c));//8 
}

int main()
{
	int a = 3,b = 5;
	swap(&a,&b);
	printf("a = %d,b = %d\n",a,b);//a = 5,b = 3
	
	int c[10] = {0,1,2,3,4,5,6,7,8,9};
	get_arr(c);//a[0] = 0 a[1] = 1 a[2] = 2 a[3] = 3 a[4] = 4 a[5] = 520 a[6] = 6 a[7] = 7 a[8] = 8 a[9] = 9
	int i;
	for(i=0;i<10;i++) printf("a[%d] = %d ",i,c[i]);//a[0] = 0 a[1] = 1 a[2] = 2 a[3] = 3 a[4] = 4 a[5] = 520 a[6] = 6 a[7] = 7 a[8] = 8 a[9] = 9
	printf("\n");
	printf("%d\n",sizeof(c));//40 
	

	return 0;
} 
