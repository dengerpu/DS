#include<stdio.h>
#define M 100000
void ShellInsert(int a[],int length,int d)  //Ï£¶ûÅÅĞò
{
	int i,j;
	for(i=1+d;i<=length;i++)
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
void ShellSort(int a[],int length,int d[],int n)
{
	for(int i=0;i<n;i++)
		ShellInsert(a,length,d[i]);
}
int main()
{
	int i,n,a[M],d[3]={1,2,4};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ShellSort(a,n,d,3);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
return 0;
}