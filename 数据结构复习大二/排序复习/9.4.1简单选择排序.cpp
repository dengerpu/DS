#include<stdio.h>
#define M 10000
void SelectSort(int a[],int n)
{
	int i,j,k,t;
	for(i=1;i<=n;i++)
	{
	k=i;
	for(j=i+1;j<=n;j++)
		if(a[j]<a[i])
			k=j;
		if(k!=j){t=a[i];a[i]=a[k];a[k]=t;}

	}
}
int main()
{
	int i,n,a[M];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	SelectSort(a,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
return 0;
}
