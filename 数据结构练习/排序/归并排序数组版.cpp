#include<stdio.h>
void merge(int a[],int low,int mid,int high,int b[])
{
	int i,j,k;
	i=low;j=mid+1;k=low;
	while(i<=mid&&j<=high)
	{
		if(a[i]<=a[j]){b[k]=a[i];i++;}
		else
		{b[k]=a[j];j++;}
		k++;
	}
	while(i<=mid)
	{b[k]=a[i];i++;k++;}
	while(j<=high)
	{b[k]=a[j];j++;k++;}	
}
void msort(int a[],int low,int high,int c[])
{
	int b[20],mid;
	if(low==high)c[low]=a[low];
	else
	{
		mid=(low+high)/2;
		msort(a,low,mid,b);
		msort(a,mid+1,high,b);
		merge(b,low,mid,high,c);
	}
}
void mergesort(int a[],int n)
{
	msort(a,1,n,a);
}
void main()
{
	int a[11],i;
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	mergesort(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}