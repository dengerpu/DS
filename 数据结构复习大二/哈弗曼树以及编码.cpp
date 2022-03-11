#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define N 20
#define M 2*N-1
typedef struct node
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffmanbitree[M+1];
void select(huffmanbitree ht,int i,int *p1,int *p2)
{
	long min1=99999;
	long min2=99999;
	for(int j=1;j<=i;j++)
	{
		if(ht[j].parent==0)    //作为一个标记，用来确定是否是从输入的数中找最小值，如果这个数已经被用过，则它的父母将不是0，确保下一次不会再挑到
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
			if(min2>ht[j].weight&&j!=(*p1))  //保证了挑到的最小数和第一次的不一样
			{
				min2=ht[j].weight;
				*p2=j;
			}
		}
	}
}
void creatbitree(huffmanbitree ht,int w[],int n)
{
	int s1,s2,i;
	for(i=1;i<=n;i++)
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
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i;ht[s2].parent=i;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
	}
}
void printhuffman(huffmanbitree ht,int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d %d %d %d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
}
void creatnode(huffmanbitree ht,int i)
{
	int j=ht[i].parent;
	if(ht[j].parent!=0)
		creatnode(ht,j);
	if(ht[j].lchild==i)
		printf("0");
	else
		printf("1");
}
void print(huffmanbitree ht,int n)
{
	for(int i=1;i<=n;i++)
	{
		creatnode(ht,i);
		printf("\n");
	}
}
void main()
{
	huffmanbitree ht;
	int w[N+1],n,i;
	printf("请输入有几个数\n");
	scanf("%d",&n);
	printf("请输入权值\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	creatbitree(ht,w,n);
	printf("输出为\n");
	printhuffman(ht,2*n-1);
	print(ht,n);
}