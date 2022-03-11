#include<stdio.h>
#define max 20
typedef struct node
{
	char data;
	int arcs[max][max];
	int flag;
}Graph[max];
void dfs(Graph g,int v0)
{
	int w=-1;
	g[v0].flag=1;
	printf("->%c",g[v0].data);
	for(int i=0;i<3;i++)
		if(g[v0].arcs[v0][i]==1)
			w=i;
		while(w!=-1)
		{
			if(g[w].flag==0)
				dfs(g,w);
		}
}
void TraverseGraph(Graph g)
{
	for(int i=0;i<4;i++)
		g[i].flag=0;               //刚开始全部标记为0，表示没有访问过
	for(i=0;i<4;i++)
		if(g[i].flag==0)
			dfs(g,i);
		
}
void main()
{
	Graph g;
	for(int i=0;i<4;i++)
	{
		g[i].data=(65+i);
		g[i].arcs[4][4]={{0,1,1,0},{0,0,0,0},{0,0,0,1},{1,0,0,0}};
	}
	TraverseGraph(g);
}