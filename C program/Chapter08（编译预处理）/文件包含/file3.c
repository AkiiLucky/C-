#include <stdio.h>
#include "file1.c"
#include "file2.c" //文件包含允许嵌套 ，但要注意 file1.c 要在 file2.c 之前出现 

int main()
{
	fun1();
	printf("%d\n",EF);//400
	return 0;
}
