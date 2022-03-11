#include<stdio.h>
typedef struct
{
	int key;
	int data;
}record;
void shellinsert(record r[],int length,int d)
{
	int i,j;
	for(i=1+d;i<=length;i++)
		if(r[i].key<r[i-d].key)
		{
			r[0]=r[i];
			for(j=i-d;j>0&&r[0].key<r[j].key;j-=d)
				r[j+d]=r[j];
			r[j+d]=r[0];
		}
}
void shellsort(record r[],int length,int d[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		shellinsert(r,length,d[i]);	
}
void main()
{
	int i;
	record r[20];
	int len,d[3]={5,3,1};
	printf("输入待排序记录的长度\n");
	scanf("%d",&len);
	printf("输入%d个记录的关键字值\n",len);
	for(i=1;i<=len;i++)
		scanf("%d",&r[i].key);
	shellsort(r,len,d,3);
	for(i=1;i<=len;i++)
		printf("%d ",r[i].key);
	printf("\n");
}