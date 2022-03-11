#include<stdio.h>
void shellinsert(int a[],int len,int d)
{
	int i,j;
	for(i=1+d;i<=len;i++)
	{
		if(a[i]<a[i-d])
		{
			a[0]=a[i];
			for(j=i-d;j>0&&a[0]<a[j];j-=d)	
				a[j+d]=a[j];
			a[j+d]=a[0];	
		}
	}
}
void shellsort(int a[],int len,int d[],int n)
{
	for(int i=0;i<len;i++)
	{
		shellinsert(a,len,d[i]);
	}
}
void main()
{
	int a[11],d[3]={5,3,1};
	int i,len;
	printf("请输入数组长度\n");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
		scanf("%d",&a[i]);
	shellsort(a,len,d,3);
	printf("排序后结果如下\n");
	for(i=1;i<=len;i++)
		printf("%d ",a[i]);
}