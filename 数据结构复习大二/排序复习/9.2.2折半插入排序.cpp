#include<stdio.h>
#define M 100000
void BinSort(int a[],int length)//’€∞Î≤Â»Î≈≈–Ú
{
	int i,j,low,high,mid;
	for(i=2;i<=length;i++)
	{
		a[0]=a[i];
		low=1;high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(a[0]<a[mid])
				high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=low;j--)
			a[j+1]=a[j];
		a[low]=a[0];
	}
}
int main()
{
	int i,n,a[M];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	BinSort(a,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
return 0;
}