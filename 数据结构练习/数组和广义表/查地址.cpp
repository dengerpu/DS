#include<stdio.h>
main()
{
	int a[10];           //一维数组计算地址方法   loc(a[i])=loc(a[1])+(n-1)*size
	printf("%x\n",a);
	printf("%x\n",&a[1]);
	printf("%x\n",&a[2]);
	int b[10][10];
	printf("%x\n",b);
	printf("%x\n",&b[0][1]);
	printf("%x\n",&b[0][2]);
	printf("%x\n",&b[1][1]);
}