#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffman[100];
void select(huffman ht,int i,int *s1,int *s2)
{
	long min1=999999;
	long min2=999999;
	for(int j=1;j<=i;j++)
		if(ht[j].parent==0)
		{
			if(min1>ht[j].weight)
			{
				min1=ht[j].weight;
				*s1=j;
			}
		}
		for(j=1;j<=i;j++)
			if(ht[j].parent==0)
			{
				if(min2>ht[j].weight&&*s1!=j)
				{
					min2=ht[j].weight;
					*s2=j;
				}
			}
}
void creat(huffman ht,int w[],int n)
{
	int i,s1,s2;
	for(i=1;i<=n;i++)
	{
		ht[i].weight=w[i];
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=n+1;i<=2*n-1;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=n+1;i<=2*n-1;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lchild=s1;ht[i].rchild=s2;
		ht[s1].parent=i;ht[s2].parent=i;
	}
}
void print(huffman ht,int n)
{
	for(int i=1;i<=2*n-1;i++)
		printf("%d	%d	%d	%d	\n",ht[i].weight ,ht[i].parent ,ht[i].lchild ,ht[i].rchild );
}
void creatnode(huffman ht,int i)
{
	int j=ht[i].parent ;
	if(ht[j].parent !=0)
		creatnode(ht,j);
	if(ht[j].lchild==i)
		printf("1");
	else
		printf("0");
}
void printhuff(huffman ht,int n)
{
	for(int i=1;i<=n;i++)
	{
		creatnode(ht,i);
		printf("\n");
	}
}
void main()
{
	int w[100],i,n;
	huffman ht;
	printf("请输入权值个数\n");
	scanf("%d",&n);
	printf("请输入权值\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	creat(ht,w,n);
	print(ht,n);
	printf("哈夫曼编码为:\n");
	printhuff(ht,n);

}