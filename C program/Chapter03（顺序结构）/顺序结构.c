#include<stdio.h>

int main(){
	
	//标志符 
	int a=123,b=-123;
	printf("%10d\n",a);//       123   输出最小宽度为 10 
	printf("%5d,%-5d\n",a,a);//负号代表左端靠齐，右端补空格 
	printf("%+d,%+d\n",a,b);//+123,-123  输出带正负号
	printf("% d,% d\n",a,b);// 123,-123  输出数值为正时先输出空格，为负时先输出负号 
	
	int c=1,d=2,e=3;
	printf("%#d,%#o,%#x\n",c,d,e);//1,02,0x3
	
	printf("%.8s\n","四川大学欢迎你！");//四川大学  注意一个汉字占两个字节 
	printf("%d%%\n",6);//6%
	
	//scanf函数
	int num1,num2;
	scanf("%3d%3d",&num1,&num2);
	printf("您输入的字符是：%d和%d",num1,num2);
	scanf("%3d%*2d%3d",&num1,&num2);
	
	 
	
	return 0;
}
