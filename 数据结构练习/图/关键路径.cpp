#include<stdio.h>
#define max 100
int cost[max][max];
int creatcost(int cost[][max])
{
	int vexnum,arcnum,i,j,k,v1,v2,w;
	printf("�����붥�����ͱ���\n");
	scanf("%d%d",&vexnum,&arcnum);
	for(i=1;i<=vexnum;i++)
		for(j=1;j<=vexnum;j++)
			cost[i][j]=9999;    //��9999Ϊ�����
		for(k=1;k<=arcnum;k++)
		{
			printf("v1,v2,w=");
			scanf("%d%d%d",&v1,&v2,&w);
			cost[v1][v2]=w;
		}
		return vexnum;
}
void dijkstra(int cost[][max],int vexnum)
{
	int v1,i,j,w,min,v,path[max],s[max],dist[max];
	printf("����Դ�� v1:");
	scanf("%d",&v1);
	for(i=1;i<=vexnum;i++)
	{
		dist[i]=cost[v1][i];
		s[i]=0;                 //����ȷ��v�Ƿ�ȷ�������·��
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
	printf("Դ��%d�������������·����ֵ\n",v1);
	for(i=2;i<=vexnum;i++)
		if(s[i]==1)
		{
			w=i;
			while(w!=v1)
			{
				printf("%d<--",w);
				w=path[w];
			}
			printf("%d ",w);
			printf("%d\n",dist[i]);
		}
		else
		{
			printf("%d<--%d",i,v1);
			printf("9999\n");
		}
}
void main()
{
	int vexnum;
	vexnum=creatcost(cost);
	dijkstra(cost,vexnum);
}