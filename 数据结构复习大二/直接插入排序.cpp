#include<stdio.h>
void insort(int a[],int n)   //直接插入排序，是一种稳定的排序方法，适用于待排列记录数目较少且基本有序的情况
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		a[0]=a[i];
		j=i-1;
		while(a[0]<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
}
void main()
{
	int a[11];
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	insort(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");

}