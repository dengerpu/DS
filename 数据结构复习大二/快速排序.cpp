#include<stdio.h>
int okpass(int a[],int low,int high)
{
	int x;
	x=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=x)
			high--;
		if(low<high){a[low]=a[high];low++;}
		while(low<high&&a[low]<x)
			low++;
		if(low<high){a[high]=a[low];high--;}
		
	}
	a[low]=x;
	return low;
}
void oksort(int a[],int low,int high)
{
	int pos;
	if(low<high)
	{
		pos=okpass(a,low,high);
		oksort(a,low,pos-1);
		oksort(a,pos+1,high);
	}
}

void main()
{
	int a[11],i;
	printf("������10����Ҫ�������\n");
	for(i=1;i<=10;i++)
		scanf("%d",&a[i]);
	oksort(a,1,10);
	printf("��������������\n");
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
}