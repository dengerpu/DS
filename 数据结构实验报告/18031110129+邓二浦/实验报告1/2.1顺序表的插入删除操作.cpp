#include<stdio.h>
#define max 100
typedef struct
{
	int a[max];
	int last;
}SeqList;
void initlist(SeqList *L)          //初始化顺序表
{
	L->last=-1;
}
int InsList(SeqList *L,int i,int e)    //插入
{
	int k;
	if((i<1)||(i>L->last+2))
	{
		printf("插入位置i值不合法");
		return 0;
	}
	if(L->last>=max-1)
	{
		printf("表已满，无法插入\n");
		return 0;
	}
	for(k=L->last;k>=i-1;k--)
		L->a[k+1]=L->a[k];
	L->a[i-1]=e;
	L->last++;
	return 1;
}
void creatlist(SeqList *L)          //创建顺序表
{
	int n,i,e;
	printf("请输入要创建顺序表的长度\n");
	scanf("%d",&n);
	printf("请输入要插入的数\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		InsList(L,i+1,e);
	}
	
}
int dellist(SeqList *L,int i,int *e)    //删除
{
	int k;
	if(i<1||i>L->last+1)
	{
		printf("删除位置不合法\n");
		return 0;
	}
	*e=L->a[i-1];
	for(k=i-1;k<L->last;k++)
		L->a[k]=L->a[k+1];
	L->last--;
	return 1;
}
void printlist(SeqList *L)             //输出顺序表
{
	int i;
	for(i=0;i<=L->last;i++)
		printf("%d ",L->a[i]);
	printf("\n");
}
int main()
{
	SeqList L;
	int i,e;
	initlist(&L);
	creatlist(&L);
	printf("创建的顺序表为:\n");
	printlist(&L);
	printf("请输入要插在第几个数以及要插入的数\n");
	scanf("%d%d",&i,&e);
	InsList(&L,i,e);
	printf("插入后的链表为:\n");
	printlist(&L);
	printf("请输入要删除第几个数\n");
	scanf("%d",&i);
	dellist(&L,i,&e);
	printf("删除后的链表为:\n");
	printlist(&L);
	return 0;
}