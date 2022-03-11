#include<stdio.h>
int BinSearch(int a[],int length,int k)   //折半查找,a[0]不存放元素。
{
	int low=1,high=length,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==a[mid])return mid;
		if(a[mid]>k) high=mid-1;
		else low=mid+1;
	}
	return 0;
	
}
int main()
{
	int a[100],n,i,key,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("请输入要查找的数\n");
	scanf("%d",&key);
	k=BinSearch(a,n,key);
	if(k>=1)
		printf("要查找的数为第%d个\n",k);
	else
		printf("没有查找到这个数\n");
	return 0;
}
