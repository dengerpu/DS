#include<stdio.h>
#define max 1024
typedef struct
{
	int a[max];
	int length;
}linklist;
int insert(linklist *l,int i,int e)   //插入
{
	int j;
	if(i<0||i>l->length+1)
	{
		printf("输入有误\n");
		return 0;
	}
	for(j=l->length;j>=i;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
	return 0;
}
int dele(linklist *l,int i)   //删除
{
	int j;
	if(i<0||i>l->length)
	{
		printf("输入有误\n");
		return 0;
	}
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	l->length--;
	return 0;
}
int loc1(linklist *l,int i)  //按序号查找
{
	int j;
	if(i<0||i>l->length)
	{
		printf("输入有误\n");
		return 0;
	}
	for(j=0;j<l->length;j++)
		if(j+1==i)
		{
			printf("第%d个数为:%d\n",i,l->a[j]);
			return 0;
		}
		return 0;
}
int loc2(linklist *l,int e)  //按值查找
{
	int j;
	for(j=0;j<l->length;j++)
		if(l->a[j]==e)
		{
			printf("%d为第%d个数\n",e,j+1);
			return 0;
		}
			printf("没有这个数\n");
		return 0;
}
void main()
{
	linklist s;
	linklist *l=&s;
	int n,i,j,k,e;
	printf("请输入数组个数\n");
	scanf("%d",&n);
	l->length=n;
	printf("请输入数据\n");
	for(i=0;i<l->length;i++)
		scanf("%d",&l->a[i]);
	printf("请输入要插在第几个数以及插的数\n");
	scanf("%d%d",&j,&k);
	insert(l,j,k);
	for(i=0;i<l->length;i++)
		printf("%d ",l->a[i]);
	printf("\n");
	printf("请输入要删除第几个数\n");
	scanf("%d",&e);
	dele(l,e);
	for(i=0;i<l->length;i++)
		printf("%d ",l->a[i]);
	printf("\n");
	printf("请输入要查找第几个数\n");
	scanf("%d",&i);
	loc1(l,i);
	printf("请输入要查找的数\n");
	scanf("%d",&i);
	loc2(l,i);
}
