#include<stdio.h>
#include<string.h>

int main(){
	
	//��ȡ�ַ������� 
	char str1[] = "Wecome to SCU!";
	printf("sizeof str1 = %d\n",sizeof(str1));//sizeof str1 = 15
	printf("strlen str1 = %u\n",strlen(str1));//strlen str1 = 14   ����һ�� \0 
	//�����ַ���
	char str2[] = "old string";
	char str3[] = "new string"; 
	char str4[40];
	printf("str2: %s\n",str2);
	strcpy(str2,str3);//ע�⣬����Ҫ��֤ str2 �ĳ��������� str3 �ĳ��� 
	printf("str2: %s\n",str2);
	strncpy(str4,str3,3);//����ǰ�����ֽ�
	printf("str4: %s\n",str4);//str4: new
	//ƴ���ַ���  
	char str5[20] = "I am";
	char str6[20] = "xiao mai";
	strcat(str5," ");
	strcat(str5,str6);
	printf("str5: %s\n",str5); 
	//�Ƚ��ַ���
	char str7[] = "Fish.com";
	char str8[] = "Fish.com";
	if(!strcmp(str7,str8)){     //�����ұȽ������ַ����� ASCII�룬��ͬ�򷵻� 0��str7С�򷵻�һ����������str7���򷵻�һ�������� 
		printf("�����ַ�����ͬ\n"); 
	} 
	 else{
	 	printf("�����ַ�����ͬ\n"); 
	 }
	//ת����Сд
	char str9[] = "sCu";
	printf("str9: %s\n",strlwr(str9));//��ȫ����ĸСд 
	printf("str9: %s\n",strupr(str9));//��ȫ����ĸ��д 
	//�������
	char str10[40];
	printf("input string\n");
	gets(str10);
	puts(str10);
	
	
	 
	return 0;
}
