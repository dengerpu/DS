#include<stdio.h>
void shellinsert(int a[],int length,int d)
{
	int i,j;
	for(i=1+d;i<=length;i++)
		if(a[i]<a[i-d])
		{
			a[0]=a[i];
			for(j=i-d;j>0&&a[0]<a[j];j-=d)
				a[j+d]=a[j];
			a[j+d]=a[0];
		}
}
void shellsort(int a[],int length,int d[],int n)
{
	int i;
	for(i=0;i<n;i++)
		shellinsert(a,length,d[i]);
}
void main()
{
	int i,a[11],d[3]={5,3,1};
	printf("请输入10个需要排序的数\n");
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	shellsort(a,10,d,3);
	printf("希尔排序结果如下\n");
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}