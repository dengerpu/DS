#include<stdio.h>
#define max 100
int creat(int cost[max][max])
{
	int i,j,vexnum,arcnum,v1,v2;
	printf("请输入顶点数和边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		for(j=1;j<=vexnum;j++)
			cost[i][j]=0;
		for(i=0;i<arcnum;i++)
		{
			printf("v1,v2=");
			scanf("%d%d",&v1,&v2);
			cost[v1][v2]=1;
			//cost[v2][v1]=1;
		}
		return vexnum;
}
void dfs(int cost[max][max],int n)
{
for()
}
void main()
{
	int cost[max][max];
	int i,j,vexnum;
	vexnum=creat(cost);
	for(i=1;i<=vexnum;i++)
	{
		for(j=1;j<=vexnum;j++)
			printf("%3d",cost[i][j]);
		printf("\n");
	}
	
}