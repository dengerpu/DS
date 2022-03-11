#include "stdio.h"
#define max 100
typedef int Arcell;
typedef int AdjMatrix[max][max];
typedef struct {
	char vexs[max];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;
typedef struct
{
int adjvex;
int lowcost;
}closedge[max];
/*void bfs(MGraph g,int v,int visited[])   //调用一次只能遍历出连通子图中点，如果需要输出整个连通图，需要多次调用，调用几次就有几个连通子图
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
}*/
int Minum(closedge a,int n)
{
	int min=a[0].lowcost,j=0;
	for(int i=1;i<n;i++)
		if(a[i].lowcost<min)
		{
		min=a[i].lowcost;
		j=i;
		}
	return j;

}
void prime(	MGraph G,int u)
{
	closedge a;
	int v,i,j;
//	a[u].adjvex=0;
	a[u].lowcost=0;
	for(i=0;i<G.vexnum;i++)
		if(i!=u)
		{
		a[i].adjvex=u;
		a[i].lowcost=G.arcs[u][i];
		}
	for(j=1;j<=G.vexnum-1;j++)				//生成G.vexnum-1条边	
	{
		v=Minum(a,G.vexnum);				//closedge[v]中找到最小边(u,v);
		u=a[v].adjvex; 
		printf("%d  %d\n",u,v);				//输出当前生成树的最小边
		a[v].lowcost=0;
		for(i=0;i<G.vexnum;i++)				//找n-1条边
			if(G.arcs[v][i]<a[i].lowcost)
			{
			a[i].lowcost=G.arcs[v][i];
			a[i].adjvex=v;
			}		
	}
}
void main(){
	int v,visited[max],i;
	MGraph G={
		{'a','b','c','d','e','f'},
		{{0,6,1,5,0,0},
		{6,0,5,0,3,0},
		{1,5,0,5,6,4},
		{5,0,5,0,0,2},
		{0,3,6,0,0,6},
		{0,0,4,2,6,0}},6,20};
		printf("请输入从哪个顶点开始遍历，0-4分别代表a和e\n");
		scanf("%d",&v);
	/*	for(i=0;i<g.vexnum;i++)
		visited[i]=0;    //初始时，全部没有被访问过
		bfs(g,v,visited);
	for(i=0;i<g.vexnum;i++)//图中可能存在连通子图
		if(visited[i]==0)   
			bfs(g,i,visited);*/
		prime(G,v);
}
