#include<stdio.h>

int main(){
	
	//��־�� 
	int a=123,b=-123;
	printf("%10d\n",a);//       123   �����С���Ϊ 10 
	printf("%5d,%-5d\n",a,a);//���Ŵ�����˿��룬�Ҷ˲��ո� 
	printf("%+d,%+d\n",a,b);//+123,-123  �����������
	printf("% d,% d\n",a,b);// 123,-123  �����ֵΪ��ʱ������ո�Ϊ��ʱ��������� 
	
	int c=1,d=2,e=3;
	printf("%#d,%#o,%#x\n",c,d,e);//1,02,0x3
	
	printf("%.8s\n","�Ĵ���ѧ��ӭ�㣡");//�Ĵ���ѧ  ע��һ������ռ�����ֽ� 
	printf("%d%%\n",6);//6%
	
	//scanf����
	int num1,num2;
	scanf("%3d%3d",&num1,&num2);
	printf("��������ַ��ǣ�%d��%d",num1,num2);
	scanf("%3d%*2d%3d",&num1,&num2);
	
	 
	
	return 0;
}
