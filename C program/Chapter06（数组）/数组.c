#include<stdio.h>

int main(){
	
	//一维数组 
	int j,b[5]={1,2,3,4,5};
	for(j=0;j<5;j++){
		printf("%d,",b[j]);
		}
	printf("\n");
		
		
	//二维数组	
	int i1,i2;
	int c[3][4]={
		{14,55,66,25},
		{25,23,85,75},
		{54,65,69,36}
	};
	
	printf("%s","原数组为：\n");
	for(i1=0;i1<3;i1++){
		for(i2=0;i2<4;i2++){
			printf("%d ",c[i1][i2]);
		}
		printf("\n");
	} 
	
	printf("%s","原数组的转置为：\n");
	for(i1=0;i1<4;i1++){
		for(i2=0;i2<3;i2++){
			printf("%d ",c[i2][i1]);
		}
		printf("\n");
	}
	
	//字符数组
	char ch1[6] = {'h','e','l','l','o','!'};
	printf("%s\n",ch1);
	char ch2[] = "hello!"; 
	printf("%s\n",ch2);
	char ch3[3][6] = {
		{'z','h','a','n','g'},
		{'w','a','n','g'},
		{'l','i'}};
	int j1,j2;
	for(j1=0;j1<3;j1++){
		for(j2=0;j2<6;j2++){
			printf("%c ",ch3[j1][j2]);
		}
	}
		 

	
		
	//输入10个整数并按相反顺序输出 
	int i,a[10];
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=9;i>0;i--)
		printf("%d|",a[i]);
	printf("\n");
	
	
		
		
		
	return 0;
	
	
	
} 
