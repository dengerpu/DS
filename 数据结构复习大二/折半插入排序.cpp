#include<stdio.h>
void binsort(int a[],int length)  //折半插入排序，一种稳定的排序方法，可以减少关键词的比较次数，折半插入排序法的比较次数比直接插入排序的最差情况要好很多，但比其最好情况要差
{
	int i,low,high,mid,x,j;
	for(i=2;i<=length;i++)
	{
		x=a[i];
		low=1;high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(x<a[mid])high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=low;j--)
			a[j+1]=a[j];
		a[low]=x;
	}
}
void main()
{
	int a[11];
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	binsort(a,10);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");

}
