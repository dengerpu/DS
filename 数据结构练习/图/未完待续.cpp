#include<stdio.h>
#define max 100
int creatcost(int cost[][max])
{
	int vexnum,arcnum,i,j,k,v1,v2,w;
	printf("�����붥��ͱ���\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		for(j=1;j<=vexnun;j++)
			cost[i][j]=9999;    //��9999Ϊ���޴�
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
	int path[max],s[max],dist[max],i,j,w,v,min,v1;  //  s��������ȷ���Ƿ�ȷ�����·��     dist�����ʾ�ӵ�ǰ�����v0��vi�����·��   //path�����ʾ·����vi��ǰ�����
	printf("����Դ�� v1:\n");
	scanf("%d",&v1);
	for(i=1;i<=vexnum;i++)
	{
		dist[i]=cost[v1][i];      //��ʼ��ʱ����Դ��v1����������·��Ϊ��Ӧ���ϵ�Ȩ
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