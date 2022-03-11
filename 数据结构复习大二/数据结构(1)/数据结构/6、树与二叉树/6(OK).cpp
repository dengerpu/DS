//哈夫曼树及编码
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
}HTNode,HuffmanTree[N+1];
typedef char * HuffmanCode[N+1];
void Select(HuffmanTree ht,int n,int * s1,int * s2)
{
	int i,j,temp;
	for(i=1;i<=n;i++)
		if(ht[i].parent==0)
		{ * s1=i; break; }
	for(j=i+1;j<=n;j++)
		if(ht[j].parent==0)
		{ * s2=j; break; }
	for(i=1;i<=n;i++)
		if((ht[* s1].weight>ht[i].weight) && (!ht[i].parent) && (* s2)!=i)
			* s1=i;
	for(j=1;j<=n;j++)
		if((ht[* s2].weight>ht[j].weight) && (!ht[j].parent) && (* s1)!=j)
			* s2=j;
	if(ht[* s1].weight>ht[* s2].weight)
	{ temp=* s1; * s1=* s2; * s2=temp; }
}
void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{
	int i,j,m,s1,s2;
	/* 初始化哈夫曼树 */
	for(i=1;i<=n;i++)
	{
		ht[i].weight=w[i];
		ht[i].parent=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
	}
	m=2*n-1;
	for(i=n+1;i<=m;i++)
	{
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].LChild=0;
		ht[i].RChild=0;
	}	//初始化完毕
	printf("哈夫曼树的创建过程如下所示：\n");
	printf("ht 初态\n结点  weight  parent  LChild  RChild\n");
	for(i=1;i<=m;i++)
		printf("%4d%8d%8d%8d%8d\n",i,ht[i].weight,ht[i].parent,ht[i].LChild,ht[i].RChild);
	for(i=n+1;i<=m;i++)
	{	//建哈夫曼树
		Select(ht,i-1,&s1,&s2);
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[s1].parent=i; ht[s2].parent=i;
		ht[i].LChild=s1; ht[i].RChild=s2;
		printf("  结点  weight  parent  LChild  RChild\n");
		for(j=1;j<=i;j++)
			printf("%4d%8d%8d%8d%8d\n",j,ht[j].weight,ht[j].parent,ht[j].LChild,ht[j].RChild);
		printf("\nSelect : s1=%d、s2=%d\n",s1,s2);
	}
}
/* 求哈夫曼编码 */
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
	int i,c,p,start;
	char * cd;
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;	//初始化编码起始指针
		c=i;	//i从1开始，即从叶子结点开始向上倒推求编码（下标小于n的结点为叶子结点）
		p=ht[i].parent;	//p为下标为i的结点的父母结点的下标
		while(p!=0)
		{
			--start;
			if(ht[p].LChild==c)	//如果下标p的左孩子为下标为c的结点，即左分支标0
				cd[start]='0';
			else	//反之右分支标1
				cd[start]='1';
			/* 向上倒推 */
			c=p;	
			p=ht[p].parent;
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));	//为第i个编码分配结点
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}
void main()
{
	HuffmanTree ht;
	HuffmanCode hc;	//保存每个叶子结点的编码
	int w[N],n,i;
	printf("请输入叶结点数：n=");
	scanf("%d",&n);
	printf("请输入%d个结点的权值：\n",n);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	CrtHuffmanTree(ht,w,n);
	CrtHuffmanCode(ht,hc,n);
	printf("各结点的哈夫曼编码：\n");
	for(i=1;i<=n;i++)
		printf("%2d(%4d):%s\n",i,w[i],hc[i]);
	printf("\n");
}