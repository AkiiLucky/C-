#include <stdio.h>
//�궨�壺��һ����ʶ����ʾһ���ַ��������������ʽ����ʽ���� 
#define A 100
#define F(x) ((x)*((x)+1))  //���β������(),�Է�������� 
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
	printf("HELLO\n");//HELLO   �궨�岻���滻˫����������� 
	printf(STR(���ַ���Ϊ%s\n),STR(string));//���ַ���Ϊstring  ��STR()���������ת��Ϊ�ַ��� 
	printf("%d\n",TOGETHER(2,50));//250 ##�ǼǺ���������������������������� 
	SHOWLIST(fish,520,3.14\n);//fish,520,3.14  �ɱ����
	PRINT(NUM = %d\n,100);//NUM = 100
	PRINT(NUM = 100\n);//NUM = 100
	return 0;
}

//��ֹ��������� 
#undef A  
#undef F

int main()
{
	fun1();
	return 0;
}
