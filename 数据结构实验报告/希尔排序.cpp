#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 500000
int KeyList[max];
void shellinsert(int a[],int len,int d)   //希尔排序
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
int main()
{
	clock_t start,end;
	int i,t,n,x,j=0,d[4]={8,4,2,1},b;
	srand(time(NULL));
	printf("请输入要产生的数的个数");
	scanf("%d",&n);
	b=n;
	for(i=1;i<=n;i++)
		KeyList[i]=i;
	for(i=1;i<=n;i++)          
	{
		x=rand()%n+1;
		t=KeyList[x];
		KeyList[x]=KeyList[i];
		KeyList[i]=t;
	}
	start=clock();
	shellsort(KeyList,n,d,4);
	end = clock();
	printf("共用时:%dms",(end-start)*1000/CLOCKS_PER_SEC);
	return 0;
}
