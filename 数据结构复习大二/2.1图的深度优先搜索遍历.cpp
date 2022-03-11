#include "stdio.h"
#define max 100
typedef int Arcell;
typedef int AdjMatrix[5][5];
typedef struct {
	char vexs[5];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
void dfs(MGraph g,int v,int visited[])  //递归深度优先搜索遍历
{
	int j;
	printf("%c ",g.vexs[v]);
	visited[v]=1;  
	for(j=0;j<g.vexnum;j++)
	{
	if(!visited[j]&&g.arcs[v][j]==1)
		dfs(g,j,visited);
	}
}

void main(){
	int v,visited[max],i;
	MGraph g={
		{'a','b','c','d','e'},
		{{0,1,0,1,0},
		{1,0,0,0,1},
		{1,0,0,1,0},
		{0,1,0,0,1},
		{1,0,0,0,0}},5,9};
		printf("请输入从哪个顶点开始遍历，0-4分别代表a和e\n");
		scanf("%d",&v);
		for(i=0;i<g.vexnum;i++)
		visited[i]=0;    //初始时，全部没有被访问过
		dfs(g,v,visited);
	for(i=0;i<g.vexnum;i++)//图中可能存在连通子图
		if(visited[i]==0)   
			dfs(g,i,visited);
}
