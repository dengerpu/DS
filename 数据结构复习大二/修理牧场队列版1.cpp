#include<stdio.h>
#include<algorithm>
#define M 20001
using namespace std;
void binsort(int r[],int start,int length,int a)  //折半插入
{
	int x,low,high,mid,j;
	x=a;
	low=start,high=length-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a<r[mid])high=mid-1;
		else low=mid+1;
	}
	for(j=length-1;j>=low;--j) r[j+1]=r[j];
		r[low]=x;
	
}
int main()
{
	int a[M],w[M],front=0,rear=0,n,i,sum=0,j;//采用队列模拟哈夫曼树
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		a[rear++]=w[i];
	}
	sort(a+front,a+rear);
	if(n==1)
		sum=0;
	else
	{
		
		for(i=1;i<=n-1;i++)
		{
			j=front+1;
			a[rear++]=a[front]+a[j];
			front=front+2;
			sum+=a[rear-1];
			binsort(a,front,rear,a[rear-1]);
		}
	}	
	
	printf("%d",sum);
	return 0;
}
