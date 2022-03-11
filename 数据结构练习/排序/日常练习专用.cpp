#include<stdio.h>
void main()
{
	int a[11],i,j,low,high,mid,x;
	printf("请输入需要排序的10个数\n");
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=10;i++)
	{
		low=1;high=i-1;
		while(low<=high)
		{
			x=a[i];
			mid=(low+high)/2;
			if(x<a[mid])high=mid-1;
			else low=mid+1;	
		}
		for(j=i-1;j>=low;j--)
			a[j+1]=a[j];
		a[low]=x;
	}
	printf("折半插入排序结果如下：\n");
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
}