#include<stdio.h>
#define M 20000
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}huffman[M];
void sift(int a[],int k,int m)
{
	int t,i,j,flag;
	t=a[k];
	i=k;
	j=2*i;
	flag=0;
	while(j<=m&&!flag)
	{
		if(j+1<=m&&a[j]<a[j+1]) j++;
		if(t>=a[j]) flag=1;
		else
		{
			a[i]=a[j];
			i=j;
			j=2*i;
		}
	}
	a[i]=t;
}
void heap(int a[],int n)
{
	for(int i=n/2;i>=1;--i)
		sift(a,i,n);
}
void heapsort(int a[],int n)
{
	int b,i;
	heap(a,n);
	for(i=n;i>=2;--i)
	{
		b=a[1];
		a[1]=a[i];
		a[i]=b;
		sift(a,1,i-1);
	}
}
void huffmanbitree(huffman ht,int w[],int n)
{
	int i,s1,s2,j=1,m;
	m=n;
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

		heapsort(w,m);
		select(ht,i-1,w[j++],w[j++]);        //挑选出两个最小的
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i;ht[s2].parent=i;
		ht[i].lchild=s1;ht[i].rchild=s2;
		w[m++]=ht[i].weight;
	}
}
int main()
{
	int i,n,w[M],sum=0;
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