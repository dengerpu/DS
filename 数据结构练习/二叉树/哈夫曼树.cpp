#include<stdio.h>
#include<malloc.h>
#define N 20
#define M 2*n-1
typedef struct node
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}htnode,huffmantree[M+1];
void creathuffmanrtree(huffmantree ht,int w[],int n)   //nΪҶ�ӽ����������w[]ΪҶ������
{
	for(int i=1;i<=n;i++)ht[i]={w[i],0,0,0};
	int m=2*n-1;
	for(i=n+1;i<=m;i++)ht[i]={0,0,0,0};
	for(i=n+1;i<=m;i++)
	{
		selsct(ht,i-1,&s1,&s2);
		h[i].weight=ht[s1].weight+w[s2].weight;
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].lchild=s1;ht[i].rchild=s2;
	}
}