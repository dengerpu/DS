#include<stdio.h>
#include<stdlib.h>
#define max 1024
typedef struct
{
	int a[max];
	int length;
}linklist;
int insert(linklist *l,int i,int e)
{
	int j;
	if(i<1||i>l->length-1)
	{
		printf("插入位置不合法\n");
		return 0;
	}
	for(j=l->length;j>i-1;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
}
int dele(linklist *l,int i,int e)
{
	int j;
	if(i<1||i>l->length-1)
	{
		printf("插入位置不合法\n");
		return 0;
	}
	
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	e=l->a[i-1];
	l->length--;
}
int main()
{
	linklist s,*l=&s;
	int i,n,e,m,x,y;
	printf("请输入数组长度：\n");
	scanf("%d",&n);
	printf("请输入数值\n");
	l->length=n;
	for(i=0;i<n;i++)
		scanf("%d  ",&l->a[i]);
	printf("请输入要插入的第几个数和插入的数值：\n");
	scanf("%d%d",&e,&m);
	insert(l,e,m);
	for(i=0;i<l->length;i++)
		printf("%d  ",l->a[i]);
	printf("请输入要删除的第几个数：\n");
	scanf("%d",&x);
	dele(l,x,y);
	for(i=0;i<l->length;i++)
		printf("%d",l->a[i]);
	return 0;
}
