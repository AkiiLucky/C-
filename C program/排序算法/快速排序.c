#include <stdio.h>

void quick_sort(int array[],int left,int right)
{
	int i = left;
	int j = right;
	int temp;
	int pivot;
	
	pivot = (left + right)/2;
	
	while (i <= j)
	{
		while(array[i] < array[pivot])
		{
			i++;
		}
		while(array[j] > array[pivot])
		{
			j--;
		}
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
		
	}
	if (j > left)
	{
		quick_sort(array,left,j);
	}
	if (i < right)
	{
		quick_sort(array,i,right);
	}
}

int main()
{
	int array[] = {14,2,6,84,65,10,56,10,71,55,1};
	int length = sizeof(array) / sizeof(array[0]);
	quick_sort(array,0,length-1);
	for(int i=0;i<length;i++)
	{
		printf("%d ",array[i]);
	}
	return 0;
}
