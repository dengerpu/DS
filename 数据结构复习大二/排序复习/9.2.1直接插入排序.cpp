#include<stdio.h>
#define M 100000
void InsSort(int a[],int length) //直接插入算法 /*在接下来的排序算法中a[0]均不存放元素
{
	int i,j;
	for(i=2;i<=length;i++)  //从第二个数据开始，依次插入
	{
		a[0]=a[i];j=i-1;		//a[0]即为要插入的数
		while(a[0]<a[j])		//给a[0]找一个合适的位置
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}	
}
int main()
{
	int i,n,a[M];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	InsSort(a,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
return 0;
}
