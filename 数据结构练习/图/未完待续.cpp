#include<stdio.h>
#define max 100
int creatcost(int cost[][max])
{
	int vexnum,arcnum,i,j,k,v1,v2,w;
	printf("请输入顶点和边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		for(j=1;j<=vexnun;j++)
			cost[i][j]=9999;    //设9999为无限大
		for(k=1;k<=arcnum;k++)
		{
			printf("v1,v2,w=");
			scanf("%d%d%d",&v1,&v2,&w);
			cost[v1][v2]=w;
		}
		return vexnum;
}
void dijkstra(int cost[][max])
{
	int path[max],s[max],dist[max],i,j,w,v,min,v1;  //  s数组用于确定是否确定最短路径     dist数组表示从当前求出的v0到vi的最短路径   //path数组表示路径上vi的前驱结点
	printf("输入源点 v1:\n");
	scanf("%d",&v1);
	for(i=1;i<=vexnum;i++)
	{
		dist[i]=cost[v1][i];      //初始化时，从源点v1到各点的最短路径为相应弧上的权
		s[i]=0;
		if(cost[v1][i]<9999)
			path[i]=v1;
	}
	s[v1]=1;
	for(i=1;i<=vexnum;i++)
	{
		min=9999;
		for(j=1;j<=vexnum;j++)
			if((s[j]==0)&&dist[j]<min)
			{
				min=dist[j];
				w=j;
			}
			s[w]=1;
			for(v=1;v<=vexnum;v++)
				if(s[v]==0)
					if(dist[w]+cost[w][v]<dist[v])
					{
						dist[v]=dist[w]+cost[w][v];
						path[v]=w;
					}
	}
}