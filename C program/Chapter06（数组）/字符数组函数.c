#include<stdio.h>
#include<string.h>

int main(){
	
	//获取字符串长度 
	char str1[] = "Wecome to SCU!";
	printf("sizeof str1 = %d\n",sizeof(str1));//sizeof str1 = 15
	printf("strlen str1 = %u\n",strlen(str1));//strlen str1 = 14   少了一个 \0 
	//拷贝字符串
	char str2[] = "old string";
	char str3[] = "new string"; 
	char str4[40];
	printf("str2: %s\n",str2);
	strcpy(str2,str3);//注意，这里要保证 str2 的长度能容纳 str3 的长度 
	printf("str2: %s\n",str2);
	strncpy(str4,str3,3);//拷贝前三个字节
	printf("str4: %s\n",str4);//str4: new
	//拼接字符串  
	char str5[20] = "I am";
	char str6[20] = "xiao mai";
	strcat(str5," ");
	strcat(str5,str6);
	printf("str5: %s\n",str5); 
	//比较字符串
	char str7[] = "Fish.com";
	char str8[] = "Fish.com";
	if(!strcmp(str7,str8)){     //从左到右比较两个字符串的 ASCII码，相同则返回 0，str7小则返回一个负整数，str7大则返回一个正整数 
		printf("两个字符串相同\n"); 
	} 
	 else{
	 	printf("两个字符串不同\n"); 
	 }
	//转换大小写
	char str9[] = "sCu";
	printf("str9: %s\n",strlwr(str9));//将全部字母小写 
	printf("str9: %s\n",strupr(str9));//将全部字母大写 
	//输入输出
	char str10[40];
	printf("input string\n");
	gets(str10);
	puts(str10);
	
	
	 
	return 0;
}
