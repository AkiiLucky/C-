#include<stdio.h>

int main(){
	int num;
	printf("input your number(range(1,7)):\n");
	scanf("%d",&num);
	if(num==1){
		printf("%s\n","Today is Monday!\n");
	}
	else if(num==2){
		printf("%s\n","Today is Tuesday!\n");
	}
	else if(num==3){
		printf("%s\n","Today is Wednesday!\n");
	}
	else if(num==4){
		printf("%s\n","Today is Thursday!\n");
	}
	else if(num==5){
		printf("%s\n","Today is Friday!\n");
	}
	else if(num==6){
		printf("%s\n","Today is Saturday!\n");
	}
	else if(num==7){
		printf("%s\n","Today is Sunday!\nYou can stay at home.\n");
	}
	else{
		printf("%s\n","your number is error\n");
	}
	return 0;
	
	
} 
