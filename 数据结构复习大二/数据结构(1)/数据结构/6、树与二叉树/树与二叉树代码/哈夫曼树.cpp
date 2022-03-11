#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
#define M 2*N-1
typedef struct
{
	int weight;
	int parent;
	int LChild;
	int RChild;
}HTNode,HuffmanTree[M+1];
#define N 20
#define M 2*N-1
typedef struct
{
	int weight;
	int parent;
	int LChild;
	int RChild;
}HTNode,HuffmanTree[M+1];
void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{
	int m,s1,s2;
	for(int i=1;i<=n;i++)
	{
		ht[i].weight=w[i];
		ht[i].parent=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
	}
	for(i=n+1;i<=m;i++)
	{
		Select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i; ht[s2].parent=i;
		ht[i].LChild=s1; ht[i].RChild=s2;
	}
}
typedef char * HuffmanCode[N+1];
void CtrHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
	int c,i,p,start;
	char * cd;
	cd=(char *)malloc(n* sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		c=i; p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].LChild==c)
				cd[start]='0';
			else
				cd[start]='1';
			c=p; p=ht[p].parent;
		}
		hc[i]=(char *)malloc((n-start)* sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
	char * cd;
	int 
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(int i=1;i<=n;i++)
	{
		start=n-1;
		c=i; p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].LChild==c)
				cd[start]='0';
			else
				cd[start]='1';
			c=p; p=ht[p].parent;
		}
		hc[i]=(char *)malloc((n-start)* sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}