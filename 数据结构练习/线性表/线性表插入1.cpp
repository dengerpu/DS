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
	if(i<1||i>l->length+1)
	{
		printf("插入错误\n");
		return 0;
	}
	for(j=l->length;j>=i;j--)
		l->a[j]=l->a[j-1];
	l->a[i-1]=e;
	l->length++;
}
int dele(linklist *l,int i)   //删除
{
	int j;
	if(i<1||i>l->length)
	{
		printf("删除数据错误\n");
		return 0;
	}
	for(j=i-1;j<l->length;j++)
		l->a[j]=l->a[j+1];
	l->length--;
}
int chazhao(linklist *l,int b)  //查找
{
	int i;
	for(i=0;i<l->length;i++)
		if(b==l->a[i])
		{
			printf("这是第%d个数\n",i+1);
			return i+1;
		}
		printf("没有这个数\n");
		return 0;
}
void main()
{
	int i,n,e,j,k,b;
	linklist s,*l=&s;
	printf("请输入数组长度\n");
	scanf("%d",&n);
	l->length=n;
	printf("请输入数值\n");
	for(i=0;i<n;i++)
		scanf("%d",&l->a[i]);
	printf("请输入插在第几个数，以及插入的数值\n");
	scanf("%d%d",&j,&e);
	insert(l,j,e);
	for(i=0;i<l->length;i++)
		printf("%d  ",l->a[i]);
	printf("\n");
	printf("请输入要删除数字的下标\n");
	scanf("%d",&k);
	dele(l,k);
	for(i=0;i<l->length;i++)
		printf("%d  ",l->a[i]);
	printf("\n");
	printf("请输入要查找的数\n");
	scanf("%d",&b);
	chazhao(l,b);
}