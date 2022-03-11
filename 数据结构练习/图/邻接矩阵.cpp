#include<stdio.h>
#include<malloc.h>
#define max_vex 100
int creat(int cost[][max_vex])
{
	int vexnum,arcnum,i,j,k,v1,v2,e=1;
	printf("\n请输入顶点数和边数\n");
		scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		for(j=1;j<=arcnum;j++)
			cost[i][j]=0;
		for(k=0;k<arcnum;k++)
		{
			printf("v1,v2=");
			scanf("%d%d",&v1,&v2);
			//scanf("%d",&e);
			cost[v1][v2]=e;
		}
		return vexnum;
}
void main()
{
	int i,j,vexnum;
	int cost[max_vex][max_vex];
	vexnum=creat(cost);
	for(i=1;i<=vexnum;i++)
	{
		for(j=1;j<=vexnum;j++)
			printf("%d ",cost[i][j]);
		printf("\n");
	}	
}