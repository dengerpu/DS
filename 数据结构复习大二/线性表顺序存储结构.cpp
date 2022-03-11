//线性表顺序存储结构
#include<stdio.h>
typedef struct
{
	int a[100];
	int length;
}SeqList;
int locate(SeqList L,int e)  ///按内容查找
{
    int i=0;
	while(i<=L.length&&(L.a[i]!=e))
		i++;
	if(i<=L.length)
	{
		printf("%d在第%d个\n",e,i+1);
		return(i+1);
	}
	else
	{
		printf("没有这个数\n");
		return 0;
	}
}
int InsList(SeqList L,int i,int e)//线性表的插入运算
{
	int k;
	if(i<1||(i>L.length +2))
	{
		printf("插入不合格\n");
		return 0;
	}
	for(k=L.length ;k>=i;k--)
		L.a[k]=L.a[k-1];
	L.a[i-1]=e;
	L.length ++;
	return 1;
}
void main()
{
	int i,sum,e,b;
	SeqList L;
	printf("请输入数组长度\n");
	scanf("%d",&sum);
	L.length=sum;
	printf("请输入数据元素\n");
	for(i=0;i<sum;i++)
		scanf("%d",&L.a[i]);
	printf("请输入要查找的数\n");
	scanf("%d",&e);
	locate(L,e);
	printf("请输入要插入的数以及要插在第几个\n");
	scanf("%d%d",&e,&b);
	InsList(L,b,e);
	for(i=0;i<L.length ;i++)
		printf("%d ",L.a[i]);
}
