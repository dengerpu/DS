#include<stdio.h>
#include<malloc.h>
#define N 20
#define M 2*N-1
typedef struct node
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffmanbitree[M];
void select(huffmanbitree ht,int i,int *p1,int *p2)
{
	int j;
	long min1=99999;
	long min2=99999;
	for(j=1;j<=i;j++)
	{
		if(ht[j].parent==0)   //保证选过的不会再选
		{
			if(min1>ht[j].weight)
			{
				min1=ht[j].weight;
				*p1=j;
			}
		}
	}
	for(j=1;j<=i;j++)
	{
		if(ht[j].parent==0)
		{
			if(min2>ht[j].weight&&*p1!=j)
			{
				min2=ht[j].weight;
				*p2=j;
			}
		}
	}		
}
void creathuffman(huffmanbitree ht,int w[],int n)
{
	int i,m=2*n-1,s1,s2;
	for(i=1;i<=n;i++)
	{
		ht[i].weight=w[i];
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lchild=s1;ht[i].rchild=s2;
		ht[s1].parent=i;ht[s2].parent=i;
	}
	
}
void print(huffmanbitree ht,int n)
{
	int i;
	printf("weight:	parent:	lchild:	rchild:\n");
	for(i=1;i<=n;i++)
		printf("%d	%d	%d	%d\n",ht[i].weight,ht[i].parent ,ht[i].lchild ,ht[i].rchild );
}
void huff(huffmanbitree ht,int i,int j)
{
	j=ht[i].parent ;
	if(ht[j].lchild ==i)
		printf("1");
	else
		printf("0");
	if(ht[j].parent!=0)
	{
		i=j;
		huff(ht,i,j);
	}
}
void printhuff(huffmanbitree ht,int n)
{
	int j,a;
	for(int i=1;i<=n;i++)
	{
		a=i;
		huff(ht,i,j);
		printf("\n");
		i=a;
	}
}
void main()
{
	huffmanbitree ht;
	int i,n,w[N];
	printf("请输入叶子结点:\n");
	scanf("%d",&n);
	printf("请输入叶子结点\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	creathuffman(ht,w,n);
	print(ht,2*n-1);
	printhuff(ht,n);
}