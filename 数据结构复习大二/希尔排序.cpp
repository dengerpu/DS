#include<stdio.h>
void shellinsert(int a[],int length,int d)  //ϣ�����򣨲��������һ�֣������򷽷����ȶ�������n��=1000�����У�ϣ��������нϸߵ�Ч�ʣ��㷨��
{
	int i,j;
	for(i=1+d;i<=length;i++)
		if(a[i]<a[i-d])
		{
			a[0]=a[i];
			for(j=i-d;j>0&&a[0]<a[j];j-=d)
				a[j+d]=a[j];
			a[j+d]=a[0];
		}
}
void shellsort(int a[],int length,int d[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		shellinsert(a,length,d[i]);
}
void main()
{
	int a[11],d[4]={4,3,2,1};
	for(int i=1;i<=10;i++)
		scanf("%d",&a[i]);
	shellsort(a,10,d,4);
	for(i=1;i<=10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
}