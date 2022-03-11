#include<stdio.h>
#include<malloc.h>
#define max 50
int creat(int cost[max][max])
{
	int vexnum,arcnum,i,j,k,v1,v2,w;
	printf("请输入顶点数和边数\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		for(j=1;j<=vexnum;j++)
			cost[i][j]=32767;
		for(k=1;k<=arcnum;k++)
		{
			printf("v1,v2,w=");
			scanf("%d%d%d",&v1,&v2,&w);
			cost[v1][v2]=w;
			cost[v2][v1]=w;
		}
		return vexnum;
}
void prime(int cost[max][max],int vexnum)
{
	int lowcost[max],closevert[max],i,j,k,min;
	for(i=1;i<=vexnum;i++)
	{
		lowcost[i]=cost[1][i];
		closevert[i]=1;
	}
	closevert[1]=-1;
	for(i=2;i<=vexnum;i++)
	{
		min=32767;
		k=0;
		for(j=1;j<=vexnum;j++)
		{
			if(closevert[j]!=-1&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
			if(k)
			{
				printf("(%d,%d) %d",closevert[k],k,lowcost[k]);
				closevert[k]=-1;
				for(j=2;j<=vexnum;j++)
					if(closevert[j]!=-1&&cost[k][j]<lowcost[k])
					{
						lowcost[j]=cost[k][j];
						closevert[j]=k;
					}
			}
		}
	}
}
void main()
{
	int vexnum;
	int cost[max][max];
	vexnum=creat(cost);
	printf("prime算法构造的最小生成树的边及权值\n");
	prime(cost,vexnum);
}