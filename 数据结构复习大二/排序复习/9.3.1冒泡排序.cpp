#include<stdio.h>
#define M 10000
void BubbleSort(int a[],int n)
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
int main()
{
	int i,n,a[M];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	BubbleSort(a,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
return 0;
}
