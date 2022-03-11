#include<stdio.h>
void maopaosort(int a[],int n)//冒泡排序是一种稳定的排序方法
{
	int i,j,t;
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
}
void main()
{
	int a[11];
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	maopaosort(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");

}