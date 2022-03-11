#include<stdio.h>
#define M 100000
int Okpass(int a[],int low,int high)
{
	int x=a[low];
	while(low<high)
	{
		while(low<high&&x<=a[high])
			high--;
		if(low<high){a[low]=a[high];low++;}
		while(low<high&&a[low]<x)
			low++;
		if(low<high){a[high]=a[low];high--;}
	}
	a[low]=x;
	return low;
}
void Oksort(int a[],int low,int high)   //¿ìËÙÅÅÐò
{
	int pass;
	if(low<high)
	{
		pass=Okpass(a,low,high);
		Oksort(a,low,pass-1);
		Oksort(a,pass+1,high);
	}
}
int main()
{
	int i,n,a[M];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	Oksort(a,1,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
