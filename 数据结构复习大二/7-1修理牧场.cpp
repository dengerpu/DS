#include<stdio.h>
#define N 10001
#define M 2*N-1
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffman[M+1];
void select(huffman ht,int n,int *s1,int *s2)
{
	int i,j,min1=99999,min2=99999;
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0)
		{
			if(ht[i].weight<min1)
			{
				min1=ht[i].weight;
				*s1=i;
			}
		}
	}
	for(j=1;j<=n;j++)
	{
		if(ht[j].parent==0)
		{
			if(ht[j].weight<min2&&*s1!=j)
			{
				min2=ht[j].weight;
				*s2=j;
			}
		}
	}
}
void huffmanbitree(huffman ht,int w[],int n)
{
	int i,s1,s2;
	for(i=1;i<=2*n-1;i++)         //哈弗曼树初始化
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].lchild=0;
		ht[i].rchild=0;
	}
	for(i=1;i<=n;i++)                //权值赋初始值
		ht[i].weight=w[i];
	for(i=n+1;i<=2*n-1;i++)
	{
		select(ht,i-1,&s1,&s2);        //挑选出两个最小的
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i;ht[s2].parent=i;
		ht[i].lchild=s1;ht[i].rchild=s2;
	}
}
int main()
{
	int i,n,w[N],sum=0;
	huffman ht;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	huffmanbitree(ht,w,n);
	for(i=n+1;i<=2*n-1;i++)
		sum+=ht[i].weight;
	printf("%d\n",sum);
	return 0;
}