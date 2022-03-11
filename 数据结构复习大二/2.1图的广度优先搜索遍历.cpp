#include "stdio.h"
#define max 100
typedef int Arcell;
typedef int AdjMatrix[5][5];
typedef struct {
	char vexs[5];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
void bfs(MGraph g,int v,int visited[])   //调用一次只能遍历出连通子图中点，如果需要输出整个连通图，需要多次调用，调用几次就有几个连通子图
{
	
{
	
	int queue[max],a[max];
	int front=0,rear=1,i,j,k;
	printf("%c ",g.vexs[v]);
	visited[v]=1;  //表示已经被访问过
	queue[rear]=v;
	while(front!=rear)
	{
		front=(front+1)%max;
		v=queue[front];
		i=0;     //相当于记录出度
		for(j=0;j<g.vexnum;j++)
			if(g.arcs[v][j]==1)
				a[i++]=j;
			k=0;
			while(k<i)
			{
				if(visited[a[k]]==0)   //如果没有被访问过
				{
					visited[a[k]]=1;   //表示已经访问过
					printf("%c ",g.vexs[a[k]]);
					rear=(rear+1)%max;
					queue[rear]=a[k];  
				}
				k++;
			}
	}
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
		bfs(g,v,visited);
	for(i=0;i<g.vexnum;i++)//图中可能存在连通子图
		if(visited[i]==0)   
			bfs(g,i,visited);
}
