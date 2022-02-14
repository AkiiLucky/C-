#include<stdio.h>

void main(){
	int i,s1=0;
	for(i=1;i<=100;i++)
		s1=s1+i;
	printf("sum1 = %d\n",s1);
	
	int j=1,s2=0;
	while(j<=100){
		s2=s2+j;
		j++;
	}
	printf("sum2 = %d\n",s2);
	
	int k=100,s3=0;
	while(k){
		s3=s3+k;
		k--;
	}
	printf("sum3 = %d\n",s3);
	
	int n=0,s4=0;
	do
	{
		s4=s4+n;
		n++;
	}while(n<=100);
	printf("sum4 = %d\n",s4);
	
	
	
}
