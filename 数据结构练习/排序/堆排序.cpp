#include<stdio.h>
void sift(int a[],int k,int m)
{
	int t,i,j,flag;
	t=a[k];
	i=k;
	j=2*i;
	flag=0;
	while(j<=m&&!flag)
	{
		if(j+1<=m&&a[j]<a[j+1]) j++;
		if(t>=a[j]) flag=1;
		else
		{
			a[i]=a[j];
			i=j;
			j=2*i;
		}
	}
	a[i]=t;
}
void heap(int a[],int n)
{
	for(int i=n/2;i>=1;--i)
		sift(a,i,n);
}
void heapsort(int a[],int n)
{
	int b,i;
	heap(a,n);
	for(i=n;i>=2;--i)
	{
		b=a[1];
		a[1]=a[i];
		a[i]=b;
		sift(a,1,i-1);
	}
}
void main()
{
	int i;
	int a[11];
	printf("请输入需要排序的10个数\n");
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	heapsort(a,10);
	printf("堆排序结果如下:\n");
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}