#include <stdio.h>
//宏定义：用一个标识符表示一个字符串（常量，表达式，格式串） 
#define A 100
#define F(x) ((x)*((x)+1))  //在形参外面加(),以防程序出错 
#define G(x) (4*A + (x))
#define D "%d\n"
#define HELLO hi
#define STR(s) # s
#define TOGETHER(x,y) x ## y
#define SHOWLIST(...) printf(# __VA_ARGS__)
#define PRINT(format,...) printf(# format, ## __VA_ARGS__ )

int fun1()
{
	printf("%d\n",A);//100
	printf("%d\n",F(20));//420
	printf("%d\n",G(100));//500
	printf(D,123);//123
	printf("HELLO\n");//HELLO   宏定义不会替换双引号里的内容 
	printf(STR(该字符串为%s\n),STR(string));//该字符串为string  将STR()里面的内容转换为字符串 
	printf("%d\n",TOGETHER(2,50));//250 ##是记号连接运算符，可以连接两个参数 
	SHOWLIST(fish,520,3.14\n);//fish,520,3.14  可变参数
	PRINT(NUM = %d\n,100);//NUM = 100
	PRINT(NUM = 100\n);//NUM = 100
	return 0;
}

//终止宏的作用域 
#undef A  
#undef F

int main()
{
	fun1();
	return 0;
}
