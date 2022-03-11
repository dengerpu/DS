#include<stdio.h>
int okpass(int a[],int low,int high)
{
  int	x=a[low];
	while(low<high)
	{
		while(low<high&&a[high]<=x)
			high--;
		if(low<high)
		{
			a[low]=a[high];
			low++;
		}
		while(low<high&&a[low]>x)
			low++;
		if(low<high)
		{
			a[high]=a[low];
			high--;
		}
	}
	a[low]=x;
	return low;
}
void oksort(int a[],int low,int high)
{
	if(low<high)
	{
		int pos=okpass(a,low,high);     //调用一趟快速排序，以枢轴元素为界划分为两个子表
		oksort(a,low,pos-1);   //对左部字表进行快速排序
		oksort(a,pos+1,high);  //对右部子表进行快速排序
	}
}
void main()
{
	int a[11],i;
	printf("请输入10个需要排序的数\n");
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	oksort(a,1,10);
	printf("快速排序结果如下\n");
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
}