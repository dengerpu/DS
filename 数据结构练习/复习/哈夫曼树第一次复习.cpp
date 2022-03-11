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
}huffmanbitree[M+1];
void select(huffmanbitree ht,int i,int *s1,int *s2)
{
	long min1=99999;
	long min2=99999;
	for(int j=1;j<=i;j++)
	{
		if(ht[j].parent==0)
		{
			if(min1>ht[j].weight)
			{
				min1=ht[j].weight;
				*s1=j;
			}
		}
	}
	for(j=1;j<=i;j++)
	{
		if(ht[j].parent==0)
		{
			if(min2>ht[j].weight&&j!=*s1)
			{
				min2=ht[j].weight;
				*s2=j;
			}
		}
	}	
}
void creat(huffmanbitree ht,int w[],int n)
{
	for(int i=1;i<=n;i++)
	{
		ht[i].weight=w[i];
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	int m=2*n-1;
	for(i=n+1;i<=m;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	int s1,s2;
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=ht[s2].parent=i;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
	}
}
void print(huffmanbitree ht,int n)   
{
	printf("weight: parent: lchild: rchild:\n");
	for(int i=1;i<=n;i++)
	{
		printf("%d	%d	%d	%d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
	}
}
void huffmannode(huffmanbitree ht,int i)
{
	int j=ht[i].parent ;
	if(ht[j].parent!=0)
		huffmannode(ht,j);
	if(ht[j].lchild==i)
		printf("1");
	else
		printf("0");
}
void printnode(huffmanbitree ht,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		huffmannode(ht,i);
		printf("\n");
	}	
}
void main()
{
	huffmanbitree ht;
	int n,i,w[N];
	printf("请输入权个数\n");
	scanf("%d",&n);
	printf("请输入权值\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	creat(ht,w,n);
	print(ht,2*n-1);
	printnode(ht,n);
}