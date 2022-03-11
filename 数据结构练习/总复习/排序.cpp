
#include<stdio.h>
//插入类排序
void insert(int a[],int n)//1.直接插入排序
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		a[0]=a[i];
		j=i-1;
		while(a[0]<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=a[0];
	}
}
void binsert(int a[],int n)//2.折半插入排序
{
	int low,high,i,j,mid;
	for(i=2;i<=n;i++)
	{
		a[0]=a[i];
		low=1;high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(a[0]>a[mid])high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=low;j--)
			a[j+1]=a[j];
		a[low]=a[0];
	}
}
void shellinsert(int a[],int n,int d)  //3.希尔排序
{
	int i,j;
	for(i=1+d;i<=n;i++)
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
void shellsort(int a[],int length,int d[],int n)
{
	int i;
	for(i=0;i<n;i++)
		shellinsert(a,length,d[i]);
}
//交换类排序
void maopao(int a[],int n)    //4.冒泡排序
{
	int i,j,t;
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
}
int okpass(int a[],int low,int high)   //5.快速排序
{
	a[0]=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>a[0])
			high--;
		if(low<high)
		{a[low]=a[high];low++;}
		while(low<high&&a[0]>a[low])
			low++;
		if(low<high)
		{a[high]=a[low];high--;}
	}
	a[low]=a[0];
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
//选择类排序
void xuanze(int a[],int n)  //6.选择排序
{
	int i,j,t;
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
			if(a[i]<a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
}
void print(int a[])
{
	int i;
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void sift(int a[],int k,int m)   //7.堆排序
{
	int t,i,j,flag=0;
	t=a[k];
	i=k;
	j=2*i;
	while(j<=m&&!flag)
	{
		if(j+1<=m&&a[j]<a[j+1])j++;
		if(t>a[j])flag=1;
		else
		{
			a[i]=a[j];
			i=j;
			j=2*i;
		}
	}
	a[i]=t;
}
void heap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
		sift(a,i,n);
}
void heapsort(int a[],int n)
{
	int i,b;
	heap(a,n);
	for(i=n;i>=2;i--)
	{
		b=a[1];
		a[1]=a[i];
		a[i]=b;
		sift(a,1,i-1);
	}
}
void merge(int a[],int low,int mid,int high,int b[])  //8.归并排序
{
	int i,j,k;
	i=low;j=mid+1;k=low;
	while(i<=mid&&j<=high)
	{
		if(a[i]<=a[j]){b[k]=a[j];j++;}
		else {b[k]=a[i];i++;}
		k++;
	}
	while(j<=high)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}

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
	int a[11]={0,0,3,2,1,4,8,5,9,7,6},d[3]={5,3,1};
	printf("直接插入结果如下\n");
	insert(a,10);
	print(a);
	printf("折半插入结果如下\n");
	binsert(a,10);
	print(a);
	printf("希尔排序结果如下\n");
	shellsort(a,10,d,3);
	print(a);
	printf("冒泡排序结果如下\n");
	maopao(a,10);
	print(a);
	printf("快速排序结果如下\n");
	oksort(a,1,10);
	print(a);
	printf("选择排序结果如下\n");
	xuanze(a,10);
	print(a);
	printf("堆排序结果如下\n");
	heapsort(a,10);
	print(a);
	printf("归并排序结果如下\n");
	mergesort(a,10);
	print(a);
}
