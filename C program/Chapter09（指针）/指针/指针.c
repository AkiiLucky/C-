#include<stdio.h>

int main(){
	
	int a = 123;
	char b = 'f';
	int *pa = &a;// & 为取地址运算符 
	char *pb = &b;
	
	// 打印时，* 为取值运算符 
	printf("a = %d\n",*pa);//a = 123 
	printf("b = %c\n",*pb);//b = 'f' 
	
	*pa += 3;
	printf("a = %d\n",a);//a = 126
	printf("a = %d\n",*pa);//a = 126
	*pb += 3; 
	printf("b = %c\n",b);//b = 'i'
	printf("b = %c\n",*pb);//b ='i'
	
	printf("sizeof pa = %d\n",sizeof(pa));//sizeof pa = 8
	printf("sizeof pb = %d\n",sizeof(pb));//sizeof pb = 8
	printf("the addr pa is %p\n",pa);//the addr pa is 000000000062FE0C   %p是指取地址 
	printf("the addr pb is %p\n",pb);//the addr pb is 000000000062FE0B
	
	printf("sizeof a = %d\n",sizeof(*pa));//sizeof a = 4
	printf("sizeof b = %d\n",sizeof(*pb));//sizeof b = 1
	printf("sizeof a = %d\n",sizeof(a));//sizeof a = 4
	printf("sizeof b = %d\n",sizeof(b));//sizeof b = 1
	printf("the addr a is %p\n",a);//the addr a is 000000000000007E
	printf("the addr b is %p\n",b);//the addr b is 0000000000000069
	printf("the addr a is %p\n",*pa);//the addr a is 000000000000007E
	printf("the addr b is %p\n",*pb);////the addr b is 0000000000000069
	
	//void指针(可以指向任意类型的指针)
	int num1 = 100;
	char str1[] = "c program";
	int *p_num1  = &num1;
	char *p_str1 = str1;  
	void *p;
	
	p = p_num1;
	printf("%p,%p\n",p,p_num1);
	printf("%d\n",*(int *)p);//如果要打印 p 的解引用的话，必须要进行强制类型转换 
	
	p = p_str1;
	printf("%p,%p\n",p,p_str1);
	printf("%s\n",(char *)p);//"c program"  
	
	//NULL指针(不清楚要初始化指向哪个地址时，将指针初始化指向NULL)
	int *p0 = NULL;
	printf("%p\n",p0);//0000000000000000
	//printf("%d\n",*p0);//无法对 NULL指针进行解引用 
	
	//指向指针的指针
	int num2 = 100;
	int *p_num2 = &num2;
	int **pp_num2 = &p_num2;
	printf("%d\n",*p_num2);//100
	printf("%d\n",**pp_num2);//100
	
	//常量与指针
	float pi = 3.141;
	const float cpi = 3.14;//利用const关键字把变量 cpi 转换为常量（只可读取，不可写入）  
	printf("%f\n",cpi);
	//cpi = 3.1415;//[Error] assignment of read-only variable 'pi'
	
	//指向常量的指针 
	const float *p_cpi_1 = &cpi;
	//*p_cpi_2 = 3.1415;//[Error] assignment of read-only location '*p_cpi_2'
	printf("%f\n",*p_cpi_1);
	p_cpi_1 = &pi;                      //可以通过对地址操作来改变指针的指向，但不能用解引用
	printf("%f,%f\n",*p_cpi_1,pi);//3.141000,3.141000
	
	//指针常量 
	float * const p_cpi_2 = &pi;
	*p_cpi_2 = 3.1415;                 //不可以通过对地址操作来改变指针的指向，但能用解引用 
	printf("%f,%f\n",*p_cpi_2,pi);//3.141500,3.141500
	
	
	const float * const p_cpi_3 = &cpi;//既不可以通过对地址操作来改变指针的指向，又不能用解引用 
	printf("%f,%f\n",*p_cpi_3,cpi);//3.140000,3.140000
	
	return 0;
}
