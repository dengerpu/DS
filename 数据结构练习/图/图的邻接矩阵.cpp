#include<stdio.h>
#define max_vex 100
int creatcost(int cost[][max_vex])
{
	int vexnum,arcnum,i,j,k,v1,v2;
	printf("\n�����붥�����ͱ���:");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		for(j=1;j<=arcnum;j++)
			cost[i][j]=0;
		for(k=0;k<arcnum;k++)
		{
			printf("v1,v2=\n");
			scanf("%d%d",&v1,&v2);
			cost[v1][v2]=1;
		}
		return(vexnum);
}
main()
{
	int i,j,vexnum;
	int cost[max_vex][max_vex];
	vexnum=creatcost(cost);
	printf("����ͼ���ڽӾ���Ϊ��\n");
	for(i=1;i<=vexnum;i++)
	{
		for(j=1;j<=vexnum;j++)
			printf("%3d",cost[i][j]);
		printf("\n");
	}
}