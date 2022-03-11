#include<stdio.h>
#define max 50
int  creat(int cost[max][max])
{
	int vexnum,arcnum,v1,v2,i,j;
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
		}
		return vexnum;
}
void main()
{
	int cost[max][max],n,i,j;
	n=creat(cost);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%3d ",cost[i][j]);
		printf("\n");
	}
}