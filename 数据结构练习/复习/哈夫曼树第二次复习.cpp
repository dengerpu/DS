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
	int j;
	long min1=99999;
	long min2=99999;
	for(j=1;j<=i;j++)
	{
		if(ht[j].parent==0)   //��֤�˱�ѡ�����Ĳ�����ѡ
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
	printf("��ţ�	Ȩֵ��	˫�ף�	���ӣ�	�Һ��ӣ�\n");
	for(int i=1;i<=n;i++)
		printf("%d	%d	%d	%d	%d\n",i,ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
}
void creatnode(huffmanbitree ht,int i)
{
	int j=ht[i].parent ;
	if(ht[j].parent!=0)
		creatnode(ht,j);
	if(ht[j].lchild==i)
		printf("1");
	else
		printf("0");
}
void printhuff(huffmanbitree ht,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		creatnode(ht,i);
		printf("\n");
	}
}
void main()
{
	int i,n,w[N];
	huffmanbitree ht;
	printf("�����볤��\n");
	scanf("%d",&n);
	printf("������Ȩֵ\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	creat(ht,w,n);
	print(ht,2*n-1);
	printhuff(ht,n);
}