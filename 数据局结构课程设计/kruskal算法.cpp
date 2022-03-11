#include<stdio.h>
#define max 50
typedef struct edgs
{
	int bv,ev,w;
}edges;
edges edgeset[max];
int createdgeset()
{
	int arcnum,i;
	printf("输入无向网的边数\n");
	scanf("%d",&arcnum);
	for(i=1;i<=arcnum;i++)
	{
		printf("bv,ev,w=");
		scanf("%d%d%d",&edgeset[i].bv,&edgeset[i].ev,&edgeset[i].w);	
	}
	return arcnum;
}
void sort(int n)
{
	int i,j;
	edges t;
	for(i=1;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(edgeset[i].w>edgeset[j].w)
			{
				t=edgeset[i];
				edgeset[i]=edgeset[j];
				edgeset[j]=t;
			}
}
int seeks(int set[],int v)
{
	int i=v;
	while(set[i]>0)
		i=set[i];
	return i;
}
void kruskal(int e)
{
	int set[max],v1,v2,i;
	printf("kruskal算法求最小生成树：\n");
	for(i=1;i<=max;i++)
		set[i]=0;
	i=0;
	while(i<e)
	{
		v1=seeks(set,edgeset[i].bv);
		v2=seeks(set,edgeset[i].ev);
		if(v1!=v2)
		{
			printf("(%d,%d) %d\n",edgeset[i].bv,edgeset[i].ev,edgeset[i].w);
			set[v1]=v2;
		}
		i++;
	}
}
void main()
{
	int i,arcnum;
	arcnum=createdgeset();
	sort(arcnum);
	printf("按权值由小到大输出边信息：");
	printf("\nbv ev w\n");
	for(i=1;i<=arcnum;i++)
		printf("%d %d %d\n",edgeset[i].bv,edgeset[i].ev,edgeset[i].w);
	kruskal(arcnum);
}