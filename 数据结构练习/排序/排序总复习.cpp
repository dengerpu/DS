//插入类排序
//希尔排序
#include<stdio.h>
void shellinsert(int a[],int n,int d)
{
	int i,j;
	for(i=1+d;i<=n;i++)
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
void shellsort(int a[],int length,int d[],int n)
{
	int i;
	for(i=0;i<n;i++)
		shellinsert(a,length,d[i]);
}
void main()
{
	int a[11],i,d[3]={5,3,1};
	printf("请输入如10个需要排序的数\n");	
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	shellsort(a,10,d,3);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
//插入排序
#include<stdio.h>
void insert(int a[],int n)
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
	int a[11],i,d[3]={5,3,1};
	printf("请输入如10个需要排序的数\n");	
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	insert(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
//二分查找插入
#include<stdio.h>
void binsert(int a[],int n)
{
	int low,high,mid,i,j;
	for(i=2;i<=n;i++)
	{
		a[0]=a[i];
		low=1;high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(a[0]<a[mid])high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=low;j--)
			a[j+1]=a[j];
		a[low]=a[0];
	}
}
void main()
{
	int a[11],i,d[3]={5,3,1};
	printf("请输入如10个需要排序的数\n");	
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	binsert(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
//交换类排序
//冒泡排序
#include<stdio.h>
void maopao(int a[],int n)
{
	int i,j,t;
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
}
void main()
{
	int a[11],i,d[3]={5,3,1};
	printf("请输入如10个需要排序的数\n");	
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	maopao(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
//快速排序
#include<stdio.h>
int  okpass(int a[],int low,int high)
{
	a[0]=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=a[0])
			high--;
		if(low<high)
		{a[low]=a[high];low++;}
		while(low<high&&a[0]>a[low])
			low++;
		if(low<high)
		{
			a[high]=a[low];high--;
		}
	}
	a[low]=a[0];
	return low;
}
void oksort(int a[],int low,int high)
{
	int pos;
	if(low<high)
	{
		pos=okpass(a,low,high);
		oksort(a,low,pos-1);
		oksort(a,pos+1,high);
	}
}
void main()
{
	int a[11],i,d[3]={5,3,1};
	printf("请输入如10个需要排序的数\n");	
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	oksort(a,1,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}