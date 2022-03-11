#include<stdio.h>
void main()
{
	int a[11],i,j;
	printf("请输入要排序的10个数\n");
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=10;i++)
	{
		a[0]=a[i];j=i-1;
		while(a[0]<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
	printf("直接插入排序结果如下:\n");
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}