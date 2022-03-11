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
/*void bfs(MGraph g,int v,int visited[])   //����һ��ֻ�ܱ�������ͨ��ͼ�е㣬�����Ҫ���������ͨͼ����Ҫ��ε��ã����ü��ξ��м�����ͨ��ͼ
{
	
{
	
	int queue[max],a[max];
	int front=0,rear=1,i,j,k;
	printf("%c ",g.vexs[v]);
	visited[v]=1;  //��ʾ�Ѿ������ʹ�
	queue[rear]=v;
	while(front!=rear)
	{
		front=(front+1)%max;
		v=queue[front];
		i=0;     //�൱�ڼ�¼����
		for(j=0;j<g.vexnum;j++)
			if(g.arcs[v][j]==1)
				a[i++]=j;
			k=0;
			while(k<i)
			{
				if(visited[a[k]]==0)   //���û�б����ʹ�
				{
					visited[a[k]]=1;   //��ʾ�Ѿ����ʹ�
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
	for(j=1;j<=G.vexnum-1;j++)				//����G.vexnum-1����	
	{
		v=Minum(a,G.vexnum);				//closedge[v]���ҵ���С��(u,v);
		u=a[v].adjvex; 
		printf("%d  %d\n",u,v);				//�����ǰ����������С��
		a[v].lowcost=0;
		for(i=0;i<G.vexnum;i++)				//��n-1����
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
		printf("��������ĸ����㿪ʼ������0-4�ֱ����a��e\n");
		scanf("%d",&v);
	/*	for(i=0;i<g.vexnum;i++)
		visited[i]=0;    //��ʼʱ��ȫ��û�б����ʹ�
		bfs(g,v,visited);
	for(i=0;i<g.vexnum;i++)//ͼ�п��ܴ�����ͨ��ͼ
		if(visited[i]==0)   
			bfs(g,i,visited);*/
		prime(G,v);
}
